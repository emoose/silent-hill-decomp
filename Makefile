# Names and Paths

GAME_NAME		:= SLUS-00707
MAIN_NAME   	:= SLUS_007.07
SEG_1_NAME		:= SILENT
SEG_2_NAME		:= HILL

OVERLAY_BODYPROG_NAME	:= BODYPROG.BIN
OVERLAY_B_KONAMI_NAME	:= B_KONAMI.BIN
OVERLAY_STREAM_NAME		:= STREAM.BIN

ROM_DIR			:= rom
IMAGE_DIR		:= $(ROM_DIR)/image
BUILD_DIR       := build
TOOLS_DIR       := tools
ASSETS_DIR		:= assets

TARGET_BOOT		:= $(BUILD_DIR)/$(MAIN_NAME)
TARGET_BODYPROG := $(BUILD_DIR)/$(OVERLAY_BODYPROG_NAME)
TARGET_B_KONAMI := $(BUILD_DIR)/$(OVERLAY_B_KONAMI_NAME)
TARGET_STREAM := $(BUILD_DIR)/$(OVERLAY_STREAM_NAME)

# Source Definitions

ASM_DIR_BOOT	:= asm/main asm/main/data
C_DIR_BOOT		:= src/main src/main/psxsdk/libspu src/main/psxsdk/libsn src/main/psxsdk/libgpu src/main/psxsdk/libetc src/main/psxsdk/libcd src/main/psxsdk/libc src/main/psxsdk/libapi
BIN_DIR_BOOT	:= assets/main

S_FILES_BOOT	:= $(foreach dir,$(ASM_DIR_BOOT),$(wildcard $(dir)/*.s))
C_FILES_BOOT	:= $(foreach dir,$(C_DIR_BOOT),$(wildcard $(dir)/*.c))
BIN_FILES_BOOT	:= $(foreach dir,$(BIN_DIR_BOOT),$(wildcard $(dir)/*.bin))

O_FILES_BOOT	:= $(foreach file,$(S_FILES_BOOT),$(BUILD_DIR)/$(file).o) \
					$(foreach file,$(C_FILES_BOOT),$(BUILD_DIR)/$(file).o) \
					$(foreach file,$(BIN_FILES_BOOT),$(BUILD_DIR)/$(file).o)

ASM_DIR_BODYPROG	:= asm/bodyprog asm/bodyprog/data
C_DIR_BODYPROG		:= src/bodyprog src/bodyprog/view src/bodyprog/libsd src/bodyprog/psxsdk/libapi src/bodyprog/psxsdk/libc src/bodyprog/psxsdk/libcard src/bodyprog/psxsdk/libcd src/bodyprog/psxsdk/libgpu src/bodyprog/psxsdk/libgs src/bodyprog/psxsdk/libgte src/bodyprog/psxsdk/libpad src/bodyprog/psxsdk/libspu
BIN_DIR_BODYPROG	:= assets/bodyprog

S_FILES_BODYPROG	:= $(foreach dir,$(ASM_DIR_BODYPROG),$(wildcard $(dir)/*.s))
C_FILES_BODYPROG	:= $(foreach dir,$(C_DIR_BODYPROG),$(wildcard $(dir)/*.c))
BIN_FILES_BODYPROG	:= $(foreach dir,$(BIN_DIR_BODYPROG),$(wildcard $(dir)/*.bin))

O_FILES_BODYPROG	:= $(foreach file,$(S_FILES_BODYPROG),$(BUILD_DIR)/$(file).o) \
					$(foreach file,$(C_FILES_BODYPROG),$(BUILD_DIR)/$(file).o) \
					$(foreach file,$(BIN_FILES_BODYPROG),$(BUILD_DIR)/$(file).o)

ASM_DIR_B_KONAMI	:= asm/b_konami asm/b_konami/data
C_DIR_B_KONAMI		:= src/b_konami
BIN_DIR_B_KONAMI	:= assets/b_konami

S_FILES_B_KONAMI	:= $(foreach dir,$(ASM_DIR_B_KONAMI),$(wildcard $(dir)/*.s))
C_FILES_B_KONAMI	:= $(foreach dir,$(C_DIR_B_KONAMI),$(wildcard $(dir)/*.c))
BIN_FILES_B_KONAMI	:= $(foreach dir,$(BIN_DIR_B_KONAMI),$(wildcard $(dir)/*.bin))

O_FILES_B_KONAMI	:= $(foreach file,$(S_FILES_B_KONAMI),$(BUILD_DIR)/$(file).o) \
					$(foreach file,$(C_FILES_B_KONAMI),$(BUILD_DIR)/$(file).o) \
					$(foreach file,$(BIN_FILES_B_KONAMI),$(BUILD_DIR)/$(file).o)

ASM_DIR_STREAM	:= asm/stream asm/stream/data
C_DIR_STREAM		:= src/stream src/stream/psxsdk/libds src/stream/psxsdk/libpress
BIN_DIR_STREAM	:= assets/stream

S_FILES_STREAM	:= $(foreach dir,$(ASM_DIR_STREAM),$(wildcard $(dir)/*.s))
C_FILES_STREAM	:= $(foreach dir,$(C_DIR_STREAM),$(wildcard $(dir)/*.c))
BIN_FILES_STREAM	:= $(foreach dir,$(BIN_DIR_STREAM),$(wildcard $(dir)/*.bin))

O_FILES_STREAM	:= $(foreach file,$(S_FILES_STREAM),$(BUILD_DIR)/$(file).o) \
					$(foreach file,$(C_FILES_STREAM),$(BUILD_DIR)/$(file).o) \
					$(foreach file,$(BIN_FILES_STREAM),$(BUILD_DIR)/$(file).o)

ASM_DIRS_ALL	:= $(ASM_DIR_BOOT) $(ASM_DIR_BODYPROG) $(ASM_DIR_B_KONAMI) $(ASM_DIR_STREAM)
C_DIRS_ALL		:= $(C_DIR_BOOT) $(C_DIR_BODYPROG) $(C_DIR_B_KONAMI) $(C_DIR_STREAM)
BIN_DIRS_ALL	:= $(BIN_DIR_BOOT) $(BIN_DIR_BODYPROG) $(BIN_DIR_B_KONAMI) $(BIN_DIR_STREAM)

# Tools
PYTHON          := python3
WINE            := wine
CPP             := cpp
CROSS			:= mips-linux-gnu
AS              := $(CROSS)-as -EL
LD              := $(CROSS)-ld -EL
OBJCOPY         := $(CROSS)-objcopy
CC_PSYQ_36     	:= $(WINE) $(TOOLS_DIR)/psyq/3.6/CC1PSX.EXE # 2.7.2.SN.1
CC_PSYQ_41      := $(WINE) $(TOOLS_DIR)/psyq/4.1/CC1PSX.EXE	# cygnus-2.7.2-970404
CC_PSYQ_43      := $(WINE) $(TOOLS_DIR)/psyq/4.3/CC1PSX.EXE # 2.8.1 SN32
CC_PSYQ_46      := $(WINE) $(TOOLS_DIR)/psyq/4.6/CC1PSX.EXE # 2.95
#CC              := $(TOOLS_DIR)/psyq/272/cc1 # Native 2.7.2
CC		:= $(CC_PSYQ_43)
SPLAT           := $(PYTHON) $(TOOLS_DIR)/splat/split.py
EXTRACT			:= $(TOOLS_DIR)/extractDisk.sh
MASPSX_DIR      := $(TOOLS_DIR)/maspsx
MASPSX_APP      := $(MASPSX_DIR)/maspsx.py
MASPSX          := $(PYTHON) $(MASPSX_APP) --expand-div --aspsx-version=2.79

# Flags
OPT_FLAGS       := -O2
INCLUDE_CFLAGS	:= -Iinclude
AS_FLAGS        := -G 0 -march=r3000 -mtune=r3000 -Iinclude --no-pad-sections
D_FLAGS       	:= -D_LANGUAGE_C
CC_FLAGS        := -G 0 -mips1 -mcpu=3000 -mgas -msoft-float $(OPT_FLAGS) -fgnu-linker
CPP_FLAGS       := -undef -Wall -lang-c $(DFLAGS) $(INCLUDE_CFLAGS) -nostdinc
OBJCOPY_FLAGS   := -O binary

# Rules
default: all

all: dirs $(TARGET_BOOT) $(TARGET_BODYPROG) $(TARGET_B_KONAMI) $(TARGET_STREAM) check

check: $(TARGET_BOOT)
	cat $(ROM_DIR)/sha1/$(MAIN_NAME).sha1
	sha1sum $(TARGET_BOOT)
	cat $(ROM_DIR)/sha1/$(OVERLAY_BODYPROG_NAME).sha1
	sha1sum $(TARGET_BODYPROG)
	cat $(ROM_DIR)/sha1/$(OVERLAY_B_KONAMI_NAME).sha1
	sha1sum $(TARGET_B_KONAMI)
	cat $(ROM_DIR)/sha1/$(OVERLAY_STREAM_NAME).sha1
	sha1sum $(TARGET_STREAM)

extract:
	$(EXTRACT) $(GAME_NAME) $(IMAGE_DIR) $(ROM_DIR) $(ASSETS_DIR)

generate:
	$(SPLAT) $(MAIN_NAME).yaml
	$(SPLAT) $(OVERLAY_BODYPROG_NAME).yaml
	$(SPLAT) $(OVERLAY_B_KONAMI_NAME).yaml
	$(SPLAT) $(OVERLAY_STREAM_NAME).yaml

dirs:
	$(foreach dir,$(ASM_DIRS_ALL) $(C_DIRS_ALL) $(BIN_DIRS_ALL),$(shell mkdir -p $(BUILD_DIR)/$(dir)))

clean:
	rm -rf $(BUILD_DIR)

clean-rom:
	find rom -maxdepth 1 -type f -delete

reset:
	rm -rf asm
	rm -rf assets
	rm -rf linker
	rm -rf meta/*auto*.txt 

setup: | clean reset clean-rom extract generate

regenerate: | clean reset generate

# bootloader
$(TARGET_BOOT): $(TARGET_BOOT).elf
	$(OBJCOPY) $(OBJCOPY_FLAGS) $< $@

$(TARGET_BOOT).elf: $(O_FILES_BOOT)
	$(LD) -Map $(TARGET_BOOT).map -T linker/$(MAIN_NAME).ld -T meta/undefined_symbols_auto.main.txt -T meta/undefined_functions_auto.main.txt -T meta/undefined_symbols.main.txt --no-check-sections -o $@

main: dirs $(TARGET_BOOT)

# bodyprog / main overlay
$(TARGET_BODYPROG): $(TARGET_BODYPROG).elf
	$(OBJCOPY) $(OBJCOPY_FLAGS) $< $@

$(TARGET_BODYPROG).elf: $(O_FILES_BODYPROG)
	$(LD) -Map $(TARGET_BODYPROG).map -T linker/$(OVERLAY_BODYPROG_NAME).ld -T meta/undefined_symbols_auto.bodyprog.txt -T meta/undefined_functions_auto.bodyprog.txt -T meta/undefined_symbols.bodyprog.txt --no-check-sections -o $@

bodyprog: dirs $(TARGET_BODYPROG)

# b_konami
$(TARGET_B_KONAMI): $(TARGET_B_KONAMI).elf
	$(OBJCOPY) $(OBJCOPY_FLAGS) $< $@

$(TARGET_B_KONAMI).elf: $(O_FILES_B_KONAMI)
	$(LD) -Map $(TARGET_B_KONAMI).map -T linker/$(OVERLAY_B_KONAMI_NAME).ld -T meta/undefined_symbols_auto.b_konami.txt -T meta/undefined_functions_auto.b_konami.txt -T meta/undefined_symbols.b_konami.txt --no-check-sections -o $@

b_konami: dirs $(TARGET_B_KONAMI)

# stream
$(TARGET_STREAM): $(TARGET_STREAM).elf
	$(OBJCOPY) $(OBJCOPY_FLAGS) $< $@

$(TARGET_STREAM).elf: $(O_FILES_STREAM)
	$(LD) -Map $(TARGET_STREAM).map -T linker/$(OVERLAY_STREAM_NAME).ld -T meta/undefined_symbols_auto.stream.txt -T meta/undefined_functions_auto.stream.txt -T meta/undefined_symbols.stream.txt --no-check-sections -o $@

stream: dirs $(TARGET_STREAM)

# generate objects
$(BUILD_DIR)/%.i: %.c
	$(CPP) -P -MMD -MP -MT $@ -MF $@.d $(CPP_FLAGS) -o $@ $<

$(BUILD_DIR)/%.c.s: $(BUILD_DIR)/%.i
	$(CC) $(CC_FLAGS) -o $@ $<

$(BUILD_DIR)/%.c.o: $(BUILD_DIR)/%.c.s
	$(MASPSX) $< | $(AS) $(AS_FLAGS) -o $@

$(BUILD_DIR)/%.s.o: %.s
	$(AS) $(AS_FLAGS) -o $@ $<

$(BUILD_DIR)/%.bin.o: %.bin
	$(LD) -r -b binary -o $@ $<

### Settings
.SECONDARY:
.PHONY: all clean default
SHELL = /bin/bash -e -o pipefail
