/***********************************************************************
 *
 *  Copyright (C) Opticon Sensors Europe B.V.
 *
 ***********************************************************************/

#ifndef __LIB_H__
#define __LIB_H__



 /*
 *--------------------------------------
 *  read() write() support
 *--------------------------------------
 */
#if defined OPH1004  ||  defined PX25  || defined PX30 || defined H13_COLOR
	#include <unistd.h>
	#include <fcntl.h>

#ifndef O_BINARY
	#define O_BINARY        0x00    /*   binary file                 */
#endif
#endif


 /*
 *--------------------------------------
 *  General definitions
 *--------------------------------------
 */
#define OK                  0
#define ERROR               -1
#define ON                  1
#define OFF                 0
#define YES                 1
#define NO                  0
#define TRUE                1
#define FALSE               0
#define DISABLE             0
#define ENABLE				1

#define NG					100
#define STANDBY				2

/*
 *--------------------------------------
 *  ASCII definitions
 *--------------------------------------
 */
#define SOH             0x01
#define STX             0x02
#define ETX             0x03
#define EOT             0x04
#define ENQ             0x05
#define ACK             0x06
#define BEL             0x07
#define BS              0x08
#define HT              0x09
#define LF              0x0A
#define VT              0x0B
#define FF              0x0C
#define CR              0x0D
#define SO              0x0E
#define SI              0x0F
#define DLE             0x10
#define DC1             0x11
#define DC2             0x12
#define DC3             0x13
#define DC4             0x14
#define NAK             0x15
#define SYN             0x16
#define ETB             0x17
#define CAN_CHAR        0x18
#define EM              0x19
#define SUB             0x1A
#define ESC             0x1B
#define FS              0x1C
#define GS              0x1D
#define RS              0x1E
#define US              0x1F
#define SP              0x20
#define DEL             0x7F

/*
 *--------------------------------------
 *  Keyboard functions
 *--------------------------------------
 */
#define TRIGGER_KEY     0x80
#define UP_KEY          0x81
#define DOWN_KEY        0x82
#define Q1_KEY          UP_KEY
#define Q2_KEY          DOWN_KEY
#define	ENT_KEY			0x83
#define CLR_KEY			0x84
#define BS_KEY			0x85
#define LEFT_KEY		0x86
#define RIGHT_KEY		0x87
#define SHIFT_KEY		0x88

#define F1_KEY          0x90
#define F2_KEY          0x91
#define F3_KEY          0x92
#define F4_KEY          0x93
#define SHIFT_F1_KEY    0x94
#define SHIFT_F2_KEY    0x95
#define SHIFT_F3_KEY    0x96
#define SHIFT_F4_KEY    0x97
#define PWR_KEY          0xFF

/*
 *--------------------------------------
 *  scnanner functions
 *--------------------------------------
 */
/* bar code ID member */
/*
 * Constants for id member
 */
#define EAN13           0x01
#define UPCA            0x02
#define EAN8            0x03
#define UPCE            0x04
#define UPCE1			0x05
#define ISBN			0x06
#define ISSN			0x07
#define ISMN			0x08
#define CODE39          0x09
#define CODABAR         0x0A
#define NW7             CODABAR
#define D2OF5           0x0B                    // industrial 2 of 5
#define I2OF5           0x0C                    // interleaved 2 of 5
#define CODE93          0x0D
#define CODE128         0x0E
#define MSI_PLESSEY     0x0F
#define IATA            0x10
#define UK_PLESSEY      0x11
#define TELEPEN         0x12
#define M2OF5           0x13
#define CHINPOST        0x14
#define NW7_ABC         0x15
#define NW7_CX          0x16
#define SCODE           0x17
#define LAETUS          0x18
#define TRIOPTIC        LAETUS
#define C39_FA          0x19                    // Full ascii
#define C39_IT          0x1A                    // Italian pharma code
#define EAN128          0x1B

#define RSS_14          0x1C
#define RSS_LIMITED     0x1D
#define RSS_EXPANDED    0x1E

#define PDF417          0x1F
#define CCC_COMPOSITE   0x20

#define MICRO_PDF417    0x21
#define CCA_COMPOSITE   0x22
#define CCB_COMPOSITE   0x23

#define CODE11          0x24

#define EAN128_CCC      0x25                    // EAN-128 with CC-C composite
#define CODE3OF5        0x26                    // Code 3 of 5 A.K.A. Korean Postal Code

/*** ADD ON +2 ***/
#define ADD_ON_2        0x40
#define EAN13_2         0x41
#define UPCA_2          0x42
#define EAN8_2          0x43
#define UPCE_2          0x44
#define UPCE1_2         0x45
#define CODE128_2       0x4E                    // the same group CODE-128

/*** ADD ON +5 ***/
#define ADD_ON_5        0x80
#define EAN13_5         0x81
#define UPCA_5          0x82
#define EAN8_5          0x83
#define UPCE_5          0x84
#define UPCE1_5         0x85
#define CODE128_5       0x8E                    // the same group CODE-128

#define PARTIAL_READ	0x40
#define ADD_ON_MASK     0xC0
#define MENU_CODE       0xF0                    // OSE Code-39 Menu label
#define MENU_CODE_PDF   0xF1                    // OSE (u)PDF417 Menu label
#define MENU_CODE_C128  0xF2                    // OSE Code-128 Menu label

/* ScannerPower */
#define TRIGGER             2
#define SINGLE              3
#define MULTIPLE            4
#define CONTINUOUS          5
#define SUSPEND				6
#define RESUME				7

/*
 *--------------------------------------
 *  Display / Power management functions
 *--------------------------------------
 */
#if defined OPH1004 || defined PX30
#define DISP_WIDTH  	128
#define DISP_HEIGHT 	128
#elif defined H13_COLOR
#define DISP_WIDTH  	176
#define DISP_HEIGHT 	220
#elif defined PX25 || defined PX35
#define DISP_WIDTH  	112
#define DISP_HEIGHT 	64
#endif

/* setfont */
#define TINY_FONT           0x01
#define SMALL_FONT          0x02
#define MEDIUM_FONT         0x03
#define LARGE_FONT          0x04
#define HUGE_FONT    		0x05
#define USER_FONT           0x06
#define FILE_FONT           0x07

/* cursor */
#define BLINKING            2
#define AUTOWRAP            3
#define NOWRAP              4
#define DOICONS				5
#define NOICONS				6


/* DisplayDirection */
#define DISP_NORMAL         0
#define DISP_REVERSE        1

/* backlight / autopowerdown */
#define OFF                 0
#define ON                  1
#define TOGGLE              2
#define RESET               3
#define AUTO                4
#define NOW                 5
#define SUSPEND             6
#define RESUME              7
#define RETURN_TIME         8

#define LOW_BL				1
#define MEDIUM_BL			2
#define HIGH_BL				3

/* RGB values for some colors */
#define RGB_WHITE   0xFFFFFF
#define RGB_RED     0xFF0000
#define RGB_GREEN   0x00FF00
#define RGB_BLUE    0x0000FF
#define RGB_MAGENTA 0xFF00FF
#define RGB_CYAN    0x00FFFF
#define RGB_YELLOW  0xFFFF00
#define RGB_BLACK   0x000000

/* Setpixel values */
#define CLEAR_PIXEL			0x00
#define SET_PIXEL			0x01
#define INVERT_PIXEL		0x02
#define INVERT              0x02
#define WHITE_4C			0x0A
#define LIGHT_GRAY_4C		0x0B
#define DARK_GRAY_4C		0x0C
#define BLACK_4C			0x0D

/* BitBlt operations */
#define WRITE_TO_SCREEN							0
#define TRANSPARENT								1
#define READ_BACK								2
#define MONOCHROME								3
#define WRITE_COLOR								4
#define MONOCHROME_PACKED						5
#define MONOCHROME_PACKED_TRANSPARANT_NO_SHADOW	6
#define MONOCHROME_PACKED_TRANSPARANT			7
#define REFRESH									8
#define MONOCHROME_NO_SHADOW					9
#define WRITE_TO_SCREEN_NO_SHADOW				10
#define TRANSPARENT_NO_SHADOW					11
#define WRITE_COLOR_NO_SHADOW					12
#define MONOCHROME_PACKED_NO_SHADOW				13

/*
 *--------------------------------------
 *  Led/sound functions
 *--------------------------------------
 */
/* GoodRead */
#define RED					0x01
#define GREEN				0x02
#define ORANGE				(RED|GREEN)
#define RED_FLASH			0x10
#define GREEN_FLASH			0x20
#define ORANGE_FLASH		(RED_FLASH|GREEN_FLASH)

#define FOREVER             -1

/*
 * definitions for sound volume level
 */
#define VOFF                0
#define VLOW                1
#define VSTANDARD           8
#define VMEDIUM             32
#define VHIGH               127

/*
 * definitions for sound tone duration
 */
#define TCLICK              1
#define TSHORT              3
#define TSTANDARD           5
#define TLONG               10
#define TVLONG              20


/*
 * definitions for sound tone
 */
#define SPAUSE              1
#define SERROR              100
#define SLOW                1000
#define SMEDIUM             2500
#define SHIGH               3500

/* ischarging */
#define OFF_CRADLE          0
#define CHARGING            1
#define ON_CRADLE           2           /* in cradle and charging is complete */
#define CHARGING_DISABLED   3           /* in cradle and not able to charge for various reasons */
										/* (i.e. when using dry cell battery, temperature is out of range, charging process is initializing */

/*
 *--------------------------------------
 *  Memory/file functions
 *--------------------------------------
 */
/*  file system */
#define D_NAME              8
#define D_EXT               3

#define ERR_NOT_SUPPORTED   (-2)
#define ERR_PARAMETER       (-3)
#define ERR_NOT_INSERTED    (-4)
#define ERR_NOT_FORMAT      (-5)

/*
 *--------------------------------------
 * Serial communication functions
 *--------------------------------------
 */
#define COM0                    0   /*  UART                 		*/
#define COM1                    1   /*  IrDA                 		*/
#define COM2                    2   /*  IrDA Cradle          		*/
#define COM3                    3   /*  Bluetooth SPP/Master 		*/
#define COM4                    4   /*  Bluetooth DUN        		*/
#define COM5                    5   /*  Bluetooth SPP/Slave  		*/
#define COM6                    6   /*  Bluetooth SPP/Master(no connection)*/
#define COM7                    7   /*  IEEE802.15.4         		*/
#define COM8                    8   /*  Reserved           			*/
#define COM9                    9   /*  Reserved     				*/
#define COM10                  10   /*  Reserved     				*/
#define COM11                  11   /*  Reserved      				*/

/*
 * definitions for xmodem receive
 */
#define XMR_OK              0
#define XMR_CREATE_ERR      1
#define XMR_POLL_ERR        2
#define XMR_ABORT_ERR       3
#define XMR_BLOCK_ERR       4
#define XMR_CRC_ERR         5
#define XMR_CHECKSUM_ERR    6
#define XMR_WRITE_ERR       7
#define XMR_RESPONSE_ERR    8
#define XMR_MEM_ERR         9

/*
 * definitions for xmodem transmit
 */
#define XMT_OK              0
#define XMT_OPEN_ERR        1
#define XMT_RESPONSE_ERR    2
#define XMT_POLL_ERR        3
#define XMT_READ_ERR        4
#define XMT_ACK_ERR1        5
#define XMT_ACK_ERR2        6
#define XMT_MEM_ERR         7



#define ERR_USER_BREAK      -3
#define ERR_EOT_HOST        -5
#define ERR_HOST_REQ        -6
#define ERR_OPEN_FILE       -8
#define ERR_WRITE_FILE      -9
#define ERR_READ_FILE       -10
#define ERR_OUT_SYNC        -12
#define ERR_ALOC_MEM        -13
#define ERR_BCC_FAIL        -2          // checksum error (internal)
#define ERR_TIME_OUT        -4          // time out error (internal)
#define ERR_HOST_LOST       -7          // time out on first char (internal)
#define ERR_NAK_RECV        -11         // NAK received from host (internal)

/*
 *  Defines for the two disks (if available)
 */
#define RAM_DISK            0
#define INTERNAL_DISK       1
#define DRIVE_A             RAM_DISK
#define DRIVE_C             INTERNAL_DISK

/*
 ***********************************************************************
 *  Type Define
 ***********************************************************************
 */
struct barcode
{
    char *text;
    int length;
    int id;
    int min;
    int max;
};

struct time
{
    unsigned char ti_hour;
    unsigned char ti_min;
    unsigned char ti_sec;
};

struct date
{
    unsigned int  da_year;
    unsigned char da_day;
    unsigned char da_mon;
};

struct ffblk
{
    char name[D_NAME+1];
    char ext[D_EXT+1];
    int filesize;
    char search_name[D_NAME+1];
    char search_ext[D_EXT+1];
    int slot;
    int drive;
};

//-------------------------------------------------------------------
//---------------------- Prototypes ---------------------------------
//-------------------------------------------------------------------

// Operating system functions
void autopowerdown(int what, unsigned long time);
int backlight(int what, unsigned short time);
unsigned int batteryvoltage(void);
int checktime(struct time *timep);
int checkdate(struct date *datep);
int comopen(unsigned int port);
int comclose(unsigned int port);
int contrast(int value);
unsigned long coreleft(void);			// Returns memory left on the file system
unsigned long Heap_CoreLeft(void);		// Returns memory left on Heap
void cursor(int mode);
void delay(int time);
void download(void);
void downloadapplication(int port);
int downpressed(void);
void drawline(int x1,int y1,int x2,int y2,int mode);
int endtimer(void);
int findnext(struct ffblk *ffblk);
int findfirst(const char *fname,struct ffblk *ffblk);
int flipscreen(int mode);
void format(void);
long fsize(const char *filename);
int getcom(int timeout);
short getdate(struct date *dp);
void getfontsize(unsigned int *height, unsigned int *width);
unsigned long GetSystemTime(void);
unsigned int getterminalid(void);
unsigned int GetTickCount(void);
short gettime(struct time *tp);
void goodreadled(int on_off, int time);
void gotoxy(int x, int y);
void idle(void);
int isBuzzerOn(void);
int ischarging(void);
unsigned int kbhit(void);
int loaddisplay(char *filename);
int neto_receive(char (*filename)[12 + 3 + 1], const char *term_id, int tkey, int ypos);
int neto_receive2(char (*filename)[12 + 3 + 1], const char *term_id, unsigned int timeout, int tkey, int ypos);
int neto_transmit(char (*filename)[12 + 3 + 1], int file_count, const char *term_id, int tkey, int ypos);
int neto_transmit2(char (*filename)[12 + 3 + 1], int file_count, const char *term_id, unsigned int timeout, int tkey, int ypos);
int powereddown(void);
void printsymbol(unsigned int data);
void putcom(int data);
unsigned int readbarcode(struct barcode *barcodep);
void resetkey(void);
void resetreceive(void);
int runapplfromfile(char *filename);
int savedisplay(char *filename);
int scanneroff(void);
void scannerpower(int mode, int time);
void set_offset(int offset);
void SetAlarm(struct time *timep, unsigned short onoff);
int setdate(struct date *dp);
int setecho(int echomode);
int setfont(unsigned int type, unsigned char *font_ptr);
void setpixel(int x, int y, int state);
void SetSystemTime(unsigned long);
void setterminalid(unsigned int id);
void SetTickCount(unsigned int value);
int settime(struct time *timep);
void showpicture(int x_offs, int y_offs, const unsigned char *ptr);
void sound(int time, int vol, ...);
void starttimer(unsigned int timevalue);
int systemsetting(const char *string);
int timervalue(void);
int triggerpressed(void);
int uppressed(void);
int wherex(void);
int wherey(void);
int xmodemreceive(const char *filename);
int xmodemtransmit(const char *filename);
void backlightlvl(int bl_level);
void BitBlt(unsigned short start_x, unsigned short start_y, unsigned short end_x, unsigned short end_y, unsigned char *ptr, unsigned short mode);
void ShowBMP(int x_offs, int y_offs, unsigned short mode, unsigned char *bmp);
long SetTextColor(long rgb);
long SetBackColor(long rgb);
long SetCursorColor(long rgb);
void FillRect(unsigned short start_x, unsigned short start_y, unsigned short end_x, unsigned short end_y, unsigned long color);
void DrawCircle(int x, int y, int radius, int color);
void FillCircle(int x, int y, int radius, int color);
void DrawEllipse(int x, int y, int radius_x, int radius_y, int color);
void FillEllipse(int x, int y, int radius_x, int radius_y, int color);
void ScrollUp(unsigned short height);


// Versions
void version_os(char os[10]);		// DEPRECATED!!
void version_rom(char rom[10]);		// DEPRECATED!!

char *GetOsVersion(void);
char *GetBootVersion(void);

// Special functions that are not mentioned in the manual.

// Flash
int GetFlashSize(void);
void eraseblock(int block_nr);
void erasesector(int sector_nr);
void programbyte(unsigned char *address, unsigned char d);
void programword(unsigned short data, unsigned short *address);
void programbuffer(unsigned char *src, unsigned char *dest, unsigned int len);

// Interrupts
void DisableInts(void);
void EnableInts(void);

// Heartbeat
void InstallHeartbeatHandler(unsigned long handler);
void RemoveHeartbeatHandler(unsigned long handler);

// Key
void WaitKey(void);

// RTC
short setdatetime(struct date *datep, struct time *timep);
short getdatetime(struct date *dp, struct time *tp);

// Filesystem
long lseek(int handle, long offset, int orgin);
long tell(int handle);
int chsize(int handle, long size);
#define far_malloc malloc						// void *far_malloc (unsigned long nbytes);
int set_default_drive(int drive);


// Comms
void putstring(unsigned char* string);
#define PutString(x) putstring(x)				// for compatibility. 
void putnstring(unsigned char* string, unsigned short len  );

// Power.c
void SoftReset(void);

//ADC
unsigned short GetTemperature(void);
unsigned short GetSubBatteryVoltage(void);
unsigned short GetLcdVoltage(void);
unsigned short GetCalibVoltage(void);
unsigned short GetBatteryVoltage(void);
#define GetBatteryVoltage_mV	GetBatteryVoltage


// BlueTooth
unsigned char *GetBltAddress(void);
unsigned char *GetBltPin(void);
void SetBltAddress(const char *address);
void SetBltPin(const char *pincode);
unsigned char *GetBltLocalName( void );
void SetBltLocalName(const char *localname );

int	blt_is_connected( void );

typedef struct
{
	char			bd_address[13];
	char			name[20];
	unsigned long 	address_l;
	unsigned long 	address_h;
	unsigned char 	page_scan_rpt_mode;
	unsigned char 	page_scan_period_mode;
	unsigned short 	clock_offset;
}device_info;

int blt_discovery( device_info *dev_inf, int abortkey );
void blt_unpair(void);

typedef int (*pin_callback) (char* pin, int* len );
void SetBltPinCallback(pin_callback cb);

#define VERSION_INFO  	__attribute__ (( section (".app_version")))				// Use to add version info to  the application header ( 16 byte maximum )

#define CRADLE_ABORT			0x0100
#define ANY_KEYS_ABORT			0x0200

// Define return states
#define COMM_OK					(0)		// Communication OK
#define ERR_PR_NO_RESPONSE		(-1)	// No response
#define ERR_PR_CRC				(-2)	// CRC-16 error
#define ERR_PR_CMD_MISMATCH		(-3)	// Wrong command received
#define ERR_PR_FRAME_LENGTH		(-4)	// Frame length error
#define ERR_PR_SESSION_ID		(-5)	// Session ID mismatch
#define ERR_PR_SENDING_FRAME	(-6)	// Error sending frame
#define ERR_PR_OPEN_FILE		(-7)	// Cannot open or create the requested file
#define ERR_PR_READ_FROM_FILE	(-8)	// Cannot read from file
#define ERR_PR_WRITE_TO_FILE	(-9)	// cannot write to file
#define ERR_PR_WRONG_BLOCK		(-10)	// Requested the wrong block number
#define ERR_PR_FILE_SIZE		(-11)	// Error in filesizes
#define ERR_PR_POLL_COMMAND		(-12)	// unexpected poll command
#define ERR_PR_FILE_UNAVAILABLE	(-13)	// File cannot be found on the terminal
#define ERR_PR_LINE_BUSY		(-14)	// An other terminal is already communicating
#define ERR_PR_TIME_DATE		(-15)	// Error in the time or date when it is being set

#define ERR_PR_USER_ABORT		(-20)	// User aborted the protocol.

#define SUCC_COMPLETE			1		// 

// Defines for STATUS that are used in the callback
#define STAT_GET_TIME_DATE		1
#define STAT_SET_TIME_DATE		2
#define STAT_GET_OS_VERSION		3
#define STAT_GET_APPL_VERSION	4
#define STAT_XMIT_FILE_TO_PC	5
#define STAT_RECV_FILE_FROM_PC	6
#define STAT_LIST_FILES			7

// Callback function prototype
typedef void (*pOnOseCommInfo)( int status, int errorsuccess, int progress, const char *info );

//-------------------------------------------------------------------------------------------------------
// long OseComm( long sessionID, int terminateKey, const char *appVersion, pOnOseCommInfo OnOseCommInfo )
//
// Blocking function that wait for the PC to start the communication
// 
// long sessionID -		communication identification number 
//						valid range from 0 til 16777215 ( 0x000000 til 0xFFFFFF )
//						if sessionID matches -1 the a sessionID is generated by the terminal per session
//
// int terminateKey -	terminate key, when this key is pressed the protocol is aborted
// 
// const char *appVersion - A string holding the application version. when no version string
//							or an empty version string is used the terminal will send an unknown
//							to a get application version command.
//
//	pOnOseCommInfo OnOseCommInfo - Callback function that gets the status, error and progress information
//
// return:	COMM_OK
//			ERR_PR_USER_ABORT
//
//-------------------------------------------------------------------------------------------------------
long OseComm( long sessionID, int terminateKey, const char *appVersion, pOnOseCommInfo OnOseCommInfo );


#endif		// __LIB_H__
