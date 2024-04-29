#ifndef _LIBCD_H_
#define _LIBCD_H_

/*
 * CD-ROM Mode (used int CdlSetmode)
 */
#define CdlModeStream  0x100    /* Normal Streaming                     */
#define CdlModeStream2 0x120    /* SUB HEADER information includes      */
#define CdlModeSpeed	0x80	/* 0: normal speed	1: double speed	*/
#define CdlModeRT	0x40	/* 0: ADPCM off		1: ADPCM on	*/
#define CdlModeSize1	0x20	/* 0: 2048 byte		1: 2340byte	*/
#define CdlModeSize0	0x10	/* 0: -			1: 2328byte	*/
#define CdlModeSF	0x08	/* 0: Channel off	1: Channel on	*/
#define CdlModeRept  	0x04	/* 0: Report off	1: Report on	*/
#define CdlModeAP	0x02	/* 0: AutoPause off	1: AutoPause on */
#define CdlModeDA	0x01	/* 0: CD-DA off		1: CD-DA on	*/

/*
 * Status Contents
 */
#define CdlStatPlay		0x80	/* playing CD-DA */
#define CdlStatSeek		0x40	/* seeking */
#define CdlStatRead		0x20	/* reading data sectors */
#define CdlStatShellOpen	0x10	/* once shell open */
#define CdlStatSeekError	0x04	/* seek error detected */
#define CdlStatStandby		0x02	/* spindle motor rotating */
#define CdlStatError		0x01	/* command error detected */

/*
 * Macros for CdGetDiskType()
 */
#define CdlStatNoDisk	0
#define CdlOtherFormat	1
#define CdlCdromFormat	2

/*
 * CD-ROM Primitive Commands
 */
#define CdlNop		0x01
#define CdlSetloc	0x02
#define CdlPlay		0x03
#define CdlForward	0x04
#define CdlBackward	0x05
#define CdlReadN	0x06
#define CdlStandby	0x07
#define CdlStop		0x08
#define CdlPause	0x09
#define CdlMute		0x0b
#define CdlDemute	0x0c
#define CdlSetfilter	0x0d
#define CdlSetmode	0x0e
#define CdlGetparam	0x0f
#define CdlGetlocL	0x10
#define CdlGetlocP	0x11
#define CdlGetTN	0x13
#define CdlGetTD	0x14
#define CdlSeekL	0x15
#define CdlSeekP	0x16
#define CdlReadS	0x1B

/*
 * Interrupts
 */
#define CdlNoIntr	0x00	/* No interrupt */
#define CdlDataReady	0x01	/* Data Ready */
#define CdlComplete	0x02	/* Command Complete */
#define CdlAcknowledge	0x03	/* Acknowledge (reserved) */
#define CdlDataEnd	0x04	/* End of Data Detected */
#define CdlDiskError	0x05	/* Error Detected */

/*
 *	Callback
 */

typedef void (*CdlCB)(u_char,u_char *);

/*
 *	Location
 */
typedef struct {
	u_char minute;		/* minute (BCD) */
	u_char second;		/* second (BCD) */
	u_char sector;		/* sector (BCD) */
	u_char track;		/* track (void) */
} CdlLOC;

/*
 *	Attenuator
 */
typedef struct {
	u_char	val0;		/* volume for CD(L) -> SPU (L) */
	u_char	val1;		/* volume for CD(L) -> SPU (R) */
	u_char	val2;		/* volume for CD(R) -> SPU (L) */
	u_char	val3;		/* volume for CD(R) -> SPU (R) */
} CdlATV;	

/*
 *	Low Level File System for CdSearchFile() 
 */
#define CdlMAXFILE	64	/* max number of files in a directory */
#define CdlMAXDIR	128	/* max number of total directories */
#define CdlMAXLEVEL	8	/* max levels of directories */

typedef struct {
	CdlLOC	pos;		/* file location */
	u_long	size;		/* file size */
	char	name[16];	/* file name (body) */
} CdlFILE;

int CdInit();
int CdStatus();
int CdMode();
int CdLastCom();
CdlLOC *CdLastPos();
int CdReset(int mode);
void CdFlush();
int CdSetDebug(int level);
char *CdComstr(u_char com);
char *CdIntstr(u_char intr);
int CdSync(int mode, u_char *result);
int CdReady(int mode, u_char *result);
CdlCB CdSyncCallback(CdlCB func);
CdlCB CdReadyCallback(CdlCB func);
int CdControl(u_char com, u_char *param, u_char *result);
int CdControlF(u_char com, u_char *param);
int CdControlB(u_char com, u_char *param, u_char *result);
int CdMix(CdlATV *vol);
int CdGetSector(void *madr, int size);
int CdGetSector2(void* madr, int size);
void (*CdDataCallback(void (*func)()));
int CdDataSync(int mode);
CdlLOC *CdIntToPos(int i, CdlLOC *p);
int CdPosToInt(CdlLOC *p);
void CdReadBreak();
int CdRead(int sectors, u_long *buf, int mode);
int CdReadSync(int mode, u_char *result);
CdlCB CdReadCallback(CdlCB func);

CdlFILE *CdSearchFile(CdlFILE *fp, char *name);
int CdRead2(long mode);

void StSetRing(u_long *ring_addr, u_long ring_size);
void StUnSetRing();
int StGetBackloc(CdlLOC *loc);
void StSetStream(u_long mode, u_long start_frame, u_long end_frame, void (*func1)(), void (*func2)());
u_long StFreeRing(u_long* base);
u_long StGetNext(u_long** addr, u_long** header);

void StCdInterrupt();


extern int StCdIntrFlag; // not included in SDK docs/headers, but movie player sample code (and moviesys) uses it...

#endif /* _LIBCD_H_ */
