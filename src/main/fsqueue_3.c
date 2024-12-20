#include "main/fsqueue.h"
#include "main/fsmem.h"
#include <LIBCD.H>
#include <LIBGTE.H>
#include <LIBGPU.H>

/** bodyprog function */
extern void func_80035560(s32, s32, void*, s32);

s32 fsQueueAllocEntryData(FsQueueEntry *entry) {
  s32 result = 0;

  if (entry->allocate) {
    entry->data = fsMemAlloc(ALIGN(entry->info->numblocks * FS_BLOCK_SIZE, FS_SECTOR_SIZE));
  } else {
    entry->data = entry->external_data;
  }

  if (entry->data != 0) {
    result = 1;
  }

  return result;
}

s32 fsQueueCanRead(FsQueueEntry *entry) {
  FsQueueEntry *other;
  s32 queue_len;
  s32 overlap;
  s32 i;

  queue_len = g_FsQueue.read_idx - g_FsQueue.postload_idx;

  if (queue_len > 0) {
    i = 0;
    do {
      other = &g_FsQueue.entries[(g_FsQueue.postload_idx + i) & (FS_QUEUE_LEN - 1)];
      overlap = false;
      if (other->postload || other->allocate) {
        overlap = fsQueueDoBuffersOverlap(
          entry->data,
          ALIGN(entry->info->numblocks * FS_BLOCK_SIZE, FS_SECTOR_SIZE),
          other->data,
          other->info->numblocks * FS_BLOCK_SIZE
        );
      }
      if (overlap == true) {
        return false;
      }
      i++;
    } while (i < queue_len);
  }

  return true;
}

s32 fsQueueDoBuffersOverlap(u8 *data1, u32 size1, u8 *data2, u32 size2) {
  u32 data1_low = (u32)data1 & 0xFFFFFF;
  u32 data2_low = (u32)data2 & 0xFFFFFF;
  if ((data2_low >= data1_low + size1) || (data1_low >= data2_low + size2)) {
    return 0;
  }
  return 1;
}

s32 fsQueueTickSetLoc(FsQueueEntry* entry) {
  CdlLOC cdloc;
  CdIntToPos(entry->info->startsector, &cdloc);
  return CdControl(CdlSetloc, (u_char *)&cdloc, NULL);
}

s32 fsQueueTickRead(FsQueueEntry* entry) {
  // round up to sector boundary; masking not needed because of the `>> 11` below
  s32 num_sectors = (entry->info->numblocks * FS_BLOCK_SIZE) + FS_SECTOR_SIZE - 1;
  // overflow check?
  if (num_sectors < 0) {
    num_sectors += FS_SECTOR_SIZE - 1;
  }
  return CdRead(num_sectors >> FS_SECTOR_SHIFT, (u_long *)entry->data, CdlModeSpeed);
}

s32 fsQueueTickReset(FsQueueEntry *entry) {
  s32 result = false;

  g_FsQueue.reset_timer_0++;

  if (g_FsQueue.reset_timer_0 >= 8) {
    result = true;
    g_FsQueue.reset_timer_0 = 0;
    g_FsQueue.reset_timer_1++;
    if (g_FsQueue.reset_timer_1 >= 9) {
      if (CdReset(0) == 1) {
        g_FsQueue.reset_timer_1 = 0;
      } else {
        result = false;
      }
    }
  }

  return result;
}

INCLUDE_ASM("asm/main/nonmatchings/fsqueue_3", fsQueueTickReadPcDrv);

s32 fsQueueUpdatePostLoad(FsQueueEntry *entry) {
  s32 result;
  s32 state;
  u8 postload;

  result = 0;
  state = g_FsQueue.postload_state;

  switch (state) {
    case FSQS_POSTLOAD_INIT:
      if (entry->allocate) {
        g_FsQueue.postload_state = FSQS_POSTLOAD_SKIP;
      } else {
        g_FsQueue.postload_state = FSQS_POSTLOAD_EXEC;
      }
      break;

    case FSQS_POSTLOAD_SKIP:
      /* do nothing */
      break;

    case FSQS_POSTLOAD_EXEC:
      postload = entry->postload;
      switch (postload) {
        case FS_POSTLOAD_NONE:
          result = 1;
          break;
        case FS_POSTLOAD_TIM:
          result = fsQueuePostLoadTim(entry);
          break;
        case FS_POSTLOAD_ANM:
          result = fsQueuePostLoadAnm(entry);
          break;
        default:
          break;
      }
      break;

    default:
      break;
  }

  return result;
}

s32 fsQueuePostLoadTim(FsQueueEntry *entry) {
  TIM_IMAGE tim;
  RECT tmprect;

  OpenTIM((u_long *)entry->external_data);
  ReadTIM(&tim);

  tmprect = *tim.prect;
  if (entry->extra.image.u != 0xFF) {
    // this cursed contraption just extracts the XY from the tpage value
    // for some reason specifically byte loads are used and this is the only way I can get it to match
    // maybe tpage is actually stored as u8[2] for some reason
    // same as tmprect.x = (entry->extra.image.tpage & 0x0F) * 64
    tmprect.x = entry->extra.image.u + ((*(((u8*)&entry->extra.image.tpage) + 1) & 0xF) << 6);
    // same as tmprect.y = (entry->extra.image.tpage & 0x10) * 16
    tmprect.y = entry->extra.image.v + ((*(((u8*)&entry->extra.image.tpage) + 1) << 4) & 0x100);
  }

  LoadImage(&tmprect, tim.paddr);

  if (tim.caddr != NULL) {
    tmprect = *tim.crect;
    if (entry->extra.image.clut_x != -1) {
      tmprect.x = entry->extra.image.clut_x;
      tmprect.y = entry->extra.image.clut_y;
    }
    LoadImage(&tmprect, tim.caddr);
  }

  return true;
}

s32 fsQueuePostLoadAnm(FsQueueEntry* entry) {
  func_80035560(entry->extra.anm.field_00, entry->extra.anm.field_04, entry->external_data, entry->extra.anm.field_08);
  return true;
}
