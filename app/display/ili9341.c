#include "ili9341.h"
#include "HalGPIO.h"
#include "HalSPI.h"
#include "HalWait.h"
#include "Sys.h"
#include "zimo.h"

#define LCD_SIZE_WIDTH  240
#define LCD_SIZE_HEIGHT 320

#define LCD_LED_PIN    0x15 //pb5
#define LCD_RESET_PIN  0x32 //pd2
#define LCD_DC_PIN     0x2c //pc12
#define LCD_CS_PIN     0x1c //pb12

#define LCD_CHAR_WIDTH_1206  6
#define LCD_CHAR_HEIGHT_1206 12

#define LCD_CHAR_WIDTH_1608  8
#define LCD_CHAR_HEIGHT_1608 16


#if 0
const unsigned char qqimage[3200]={ /* 0X00,0X10,0X28,0X00,0X28,0X00,0X01,0X1B,*/
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XBE,0XF7,0X7D,0XEF,
0XBA,0XD6,0XB6,0XB5,0XF3,0X9C,0XB2,0X94,0XB3,0X9C,0XB2,0X94,0X34,0XA5,0XF7,0XBD,
0XFB,0XDE,0X7D,0XEF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XBE,0XF7,0XFB,0XDE,0XF3,0X9C,0XCB,0X5A,
0XC7,0X39,0X04,0X21,0X82,0X10,0X42,0X10,0X42,0X10,0X41,0X08,0X83,0X18,0X45,0X29,
0XC7,0X39,0X0C,0X63,0X75,0XAD,0X3C,0XE7,0XBE,0XF7,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X3C,0XE7,0XB2,0X94,0X08,0X42,0XC3,0X18,0X82,0X10,
0X04,0X21,0X45,0X29,0X86,0X31,0X86,0X31,0X86,0X31,0X86,0X31,0X45,0X29,0X04,0X21,
0X82,0X10,0X41,0X08,0XC3,0X18,0X08,0X42,0XF3,0X9C,0X3C,0XE7,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFB,0XDE,0X0C,0X63,0XC3,0X18,0XC3,0X18,0X45,0X29,0XC7,0X39,
0X08,0X42,0X08,0X42,0X08,0X42,0X08,0X42,0X08,0X42,0X08,0X42,0XC7,0X39,0XC7,0X39,
0X86,0X31,0X86,0X31,0X04,0X21,0X41,0X08,0X82,0X10,0XCB,0X5A,0XBA,0XD6,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFB,0XDE,0XCB,0X5A,0X82,0X10,0X45,0X29,0XC7,0X39,0X08,0X42,0X08,0X42,
0X09,0X4A,0X49,0X4A,0X49,0X4A,0X49,0X4A,0X49,0X4A,0X49,0X4A,0X08,0X42,0XC7,0X39,
0XC7,0X39,0XC7,0X39,0X86,0X31,0X45,0X29,0X83,0X18,0X00,0X00,0XC8,0X41,0X38,0XC6,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0X7D,0XEF,0X8E,0X73,0X82,0X10,0X45,0X29,0XC7,0X39,0X08,0X42,0X09,0X4A,0X8A,0X52,
0X30,0X84,0XCF,0X7B,0X8A,0X52,0X49,0X4A,0X4A,0X52,0X49,0X4A,0XCB,0X5A,0XCF,0X7B,
0X0C,0X63,0X08,0X42,0XC7,0X39,0X86,0X31,0X45,0X29,0XC3,0X18,0X00,0X00,0X49,0X4A,
0XBA,0XD6,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XF3,0X9C,0XC3,0X18,0X04,0X21,0XC7,0X39,0X08,0X42,0X49,0X4A,0X49,0X4A,0X72,0X94,
0X7D,0XEF,0X7D,0XEF,0XB2,0X94,0X4A,0X52,0X49,0X4A,0X8A,0X52,0X75,0XAD,0XBE,0XF7,
0XBA,0XD6,0X4D,0X6B,0XC7,0X39,0XC7,0X39,0X86,0X31,0X45,0X29,0XC3,0X18,0X41,0X08,
0XCF,0X7B,0X7C,0XE7,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XBA,0XD6,
0X08,0X42,0X82,0X10,0XC7,0X39,0X08,0X42,0X49,0X4A,0X49,0X4A,0X8E,0X73,0XFB,0XDE,
0XFF,0XFF,0XBE,0XF7,0XBA,0XD6,0X8E,0X73,0X08,0X42,0X30,0X84,0X3C,0XE7,0X7D,0XEF,
0XFF,0XFF,0XB6,0XB5,0X49,0X4A,0XC7,0X39,0X86,0X31,0X45,0X29,0X04,0X21,0X41,0X08,
0X45,0X29,0XB6,0XB5,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XBE,0XF7,0X71,0X8C,
0X41,0X08,0X45,0X29,0X08,0X42,0X49,0X4A,0X49,0X4A,0X4A,0X52,0XB2,0X94,0XBE,0XF7,
0XBE,0XF7,0XB2,0X94,0XCF,0X7B,0XCF,0X7B,0X49,0X4A,0XB6,0XB5,0XF3,0X9C,0X0C,0X63,
0X38,0XC6,0XBA,0XD6,0X0C,0X63,0X87,0X39,0XC7,0X39,0X86,0X31,0X45,0X29,0XC3,0X18,
0X41,0X08,0X30,0X84,0X7D,0XEF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X3C,0XE7,0XCB,0X5A,
0X41,0X08,0XC7,0X39,0X08,0X42,0X49,0X4A,0X4A,0X52,0X8A,0X52,0XF3,0X9C,0XFF,0XFF,
0X7D,0XEF,0XC7,0X39,0XC3,0X18,0X0C,0X63,0XCB,0X5A,0XB6,0XB5,0XB2,0X94,0XCB,0X5A,
0X75,0XAD,0XFA,0XD6,0X4D,0X6B,0X87,0X39,0XC7,0X39,0X86,0X31,0X45,0X29,0X04,0X21,
0X41,0X08,0X8A,0X52,0X79,0XCE,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X38,0XC6,0X86,0X31,
0X04,0X21,0XC8,0X41,0X49,0X4A,0X49,0X4A,0X4A,0X52,0X49,0X4A,0XB1,0X8C,0XBE,0XF7,
0XBE,0XF7,0XB2,0X94,0XCF,0X7B,0XCF,0X7B,0X49,0X4A,0X74,0XA5,0X7D,0XEF,0X7C,0XE7,
0XBE,0XF7,0X79,0XCE,0X0C,0X63,0XC7,0X39,0XC7,0X39,0X86,0X31,0X45,0X29,0X04,0X21,
0X82,0X10,0X45,0X29,0X75,0XAD,0XBE,0XF7,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X34,0XA5,0X82,0X10,
0X86,0X31,0X08,0X42,0X49,0X4A,0X49,0X4A,0X8A,0X52,0X49,0X4A,0X4D,0X6B,0XBA,0XD6,
0XFF,0XFF,0XFF,0XFF,0X79,0XCE,0X0D,0X63,0XC7,0X39,0XCF,0X7B,0X7D,0XEF,0XFF,0XFF,
0XFF,0XFF,0X75,0XAD,0X08,0X42,0X86,0X31,0XC7,0X39,0X86,0X31,0X45,0X29,0X45,0X29,
0XC3,0X18,0XC3,0X18,0XB2,0X94,0X7D,0XEF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XBE,0XF7,0XB2,0X8C,0X41,0X08,
0XC7,0X39,0X08,0X42,0X49,0X4A,0X49,0X4A,0X8A,0X52,0X8A,0X52,0X4A,0X4A,0XD0,0X7B,
0X7A,0XC6,0X7B,0XBE,0X90,0X6B,0XC9,0X39,0X88,0X31,0XC9,0X39,0XB3,0X84,0XBB,0XC6,
0XF8,0XB5,0XCC,0X5A,0X86,0X31,0XC7,0X39,0XC7,0X39,0X86,0X31,0X45,0X29,0X45,0X29,
0XC4,0X20,0X41,0X08,0X30,0X84,0X3C,0XE7,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X3C,0XE7,0X8A,0X4A,0XC3,0X10,
0XC7,0X39,0X08,0X42,0X49,0X4A,0X49,0X4A,0X4A,0X4A,0X4A,0X42,0X09,0X3A,0X08,0X4A,
0X09,0X6B,0X49,0X7B,0XC6,0X7A,0X05,0X83,0X46,0X83,0XC5,0X7A,0XC6,0X72,0X09,0X7B,
0X48,0X5A,0X87,0X31,0X88,0X21,0X88,0X29,0X86,0X31,0X86,0X31,0X45,0X29,0X45,0X29,
0X04,0X21,0X41,0X08,0X4A,0X4A,0XBA,0XD6,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF7,0XC5,0X82,0X50,0X05,0X41,
0XC7,0X29,0X08,0X42,0X49,0X4A,0X4A,0X42,0X49,0X4A,0X09,0X7B,0X88,0X9B,0XC6,0XB3,
0X21,0XD4,0XA0,0XDC,0XE1,0XE4,0X61,0XED,0X61,0XED,0X21,0XED,0XA0,0XE4,0X20,0XDC,
0X80,0XCB,0X43,0XAB,0XC4,0X82,0X06,0X5A,0X47,0X21,0X46,0X29,0X45,0X29,0X04,0X29,
0X04,0X19,0X82,0X10,0X82,0X18,0XF3,0X9C,0X7D,0XEF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X7D,0XEF,0X4D,0X93,0X00,0XA0,0X82,0XB8,
0XC7,0X31,0X09,0X32,0X49,0X4A,0X86,0X7A,0X43,0XC3,0X6B,0XED,0XF4,0XF6,0XEB,0XFD,
0X20,0XFD,0X20,0XFD,0X60,0XFD,0XA0,0XFD,0XA0,0XFD,0X60,0XFD,0X60,0XFD,0X20,0XFD,
0XE0,0XFC,0XA0,0XFC,0X60,0XF4,0XC1,0XDB,0X83,0X9A,0XC5,0X49,0X45,0X29,0X04,0X19,
0XC4,0X20,0X82,0X38,0X00,0X50,0XCB,0X6A,0XBA,0XD6,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFB,0XEE,0X04,0XA1,0X00,0XC0,0X00,0XF0,
0XC3,0XA0,0XC8,0X41,0X49,0X42,0X05,0X9B,0X20,0XFC,0XA4,0XFC,0X69,0XFD,0XE8,0XFD,
0X63,0XFD,0X20,0XFD,0X60,0XFD,0X60,0XFD,0X60,0XFD,0X20,0XFD,0X20,0XFD,0XE0,0XFC,
0XE0,0XFC,0XA0,0XFC,0X60,0XFC,0X20,0XFC,0X41,0XD3,0XC5,0X49,0X45,0X19,0XC4,0X38,
0X82,0X68,0X41,0X88,0X00,0X70,0X49,0X5A,0X79,0XCE,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFB,0XF6,0X82,0XC0,0X00,0XD0,0X86,0XC1,
0X46,0XF1,0X41,0XC8,0X45,0X79,0X89,0X52,0X88,0X62,0X86,0X6A,0XC6,0X7A,0XC4,0XBB,
0XE1,0XFC,0X60,0XFD,0X60,0XFD,0XA0,0XFD,0XA0,0XFD,0X60,0XFD,0X60,0XFD,0XE0,0XFC,
0X60,0XE4,0X03,0X93,0X84,0X72,0X44,0X6A,0XC5,0X41,0X45,0X29,0XC3,0X58,0X41,0XA8,
0X40,0X98,0X00,0XB0,0X00,0X60,0X0C,0X6B,0X79,0XCE,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X7D,0XEF,0XCE,0X83,0X82,0X88,0X00,0XF8,0XC4,0XD8,
0X0C,0XF3,0X8A,0XFA,0X82,0XE8,0X82,0XB0,0X45,0X69,0XC7,0X51,0X08,0X42,0X08,0X3A,
0X86,0X5A,0X83,0X9B,0XA2,0XBC,0X22,0XCD,0X21,0XCD,0XA1,0XC4,0X22,0XB4,0XC4,0X7A,
0X06,0X3A,0X86,0X29,0X45,0X29,0X05,0X31,0XC4,0X50,0X41,0X90,0X00,0XC0,0X00,0XA8,
0X00,0XA0,0X00,0XA8,0X00,0X30,0X4A,0X4A,0XBA,0XD6,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0X7D,0XEF,0X8E,0X73,0XC3,0X18,0X05,0X39,0X82,0XA8,0X00,0XF8,
0XC3,0XF8,0X4D,0XFB,0X4D,0XFB,0XC7,0XF9,0XC3,0XF0,0X82,0XD8,0XC3,0XB0,0X04,0X81,
0X45,0X61,0X46,0X51,0X86,0X49,0X86,0X49,0X46,0X41,0X45,0X41,0X45,0X41,0X45,0X41,
0X05,0X49,0X04,0X61,0X82,0X90,0X41,0XB0,0X00,0XD0,0X00,0XC8,0X00,0XA8,0X00,0XA8,
0X00,0XB8,0X41,0X58,0X82,0X10,0X82,0X10,0XB2,0X94,0XBE,0XF7,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XBE,0XF7,0XCF,0X7B,0X82,0X10,0X04,0X21,0X86,0X29,0X86,0X41,0X04,0X99,
0X40,0XE8,0X41,0XF8,0X86,0XF9,0XCB,0XFA,0X49,0XFA,0X82,0XF8,0X00,0XF8,0X00,0XF0,
0X00,0XE8,0X41,0XD8,0X41,0XD0,0X41,0XC0,0X41,0XC0,0X41,0XC0,0X41,0XC0,0X41,0XC8,
0X00,0XD0,0X00,0XE0,0X00,0XE0,0X00,0XD8,0X00,0XD0,0X00,0XB8,0X00,0XA8,0X41,0X88,
0X82,0X48,0X82,0X10,0X82,0X10,0X00,0X00,0X45,0X29,0X79,0XCE,0XFF,0XFF,0XFF,0XFF,
0XBE,0XF7,0XF3,0X9C,0X82,0X10,0XC3,0X18,0X45,0X29,0X86,0X31,0XC7,0X31,0X30,0X7C,
0XF3,0XDC,0X86,0XE1,0X00,0XF0,0X00,0XF8,0X41,0XF8,0X41,0XF8,0X00,0XF8,0X00,0XF8,
0X00,0XF8,0X00,0XF8,0X00,0XF8,0X00,0XF8,0X00,0XF8,0X00,0XF8,0X00,0XF8,0X00,0XF8,
0X00,0XE8,0X00,0XE0,0X00,0XE0,0X00,0XD8,0X00,0XC8,0X41,0XA0,0X8A,0X9A,0X0C,0X63,
0X04,0X11,0X82,0X10,0X82,0X10,0X41,0X08,0X00,0X00,0X4D,0X6B,0X7D,0XEF,0XFF,0XFF,
0XFB,0XDE,0X08,0X42,0X42,0X10,0X45,0X29,0X86,0X31,0X86,0X31,0X49,0X4A,0X38,0XBE,
0XFF,0XFF,0X38,0XD6,0X86,0XA9,0X00,0XC8,0X00,0XE0,0X00,0XF0,0X00,0XF8,0X00,0XF8,
0X00,0XF8,0X00,0XF8,0X00,0XF8,0X00,0XF8,0X00,0XF8,0X00,0XF8,0X00,0XF0,0X00,0XF0,
0X00,0XE8,0X00,0XE0,0X00,0XD0,0XC3,0X98,0X8A,0X8A,0XB2,0XA4,0XBA,0XC6,0XF7,0XB5,
0X08,0X42,0X41,0X08,0X82,0X10,0X41,0X08,0X00,0X00,0X45,0X29,0XF7,0XBD,0XFF,0XFF,
0X71,0X8C,0X41,0X08,0X04,0X21,0X45,0X29,0X86,0X31,0X86,0X31,0X0C,0X63,0X3C,0XE7,
0XFF,0XFF,0X79,0XD6,0X46,0XB9,0X00,0XE0,0X42,0XC8,0X82,0XA8,0X82,0XB0,0X41,0XD8,
0X82,0XE8,0X82,0XF0,0X41,0XE8,0X41,0XE8,0X41,0XE8,0X41,0XF0,0X41,0XE8,0X41,0XD8,
0X04,0XC1,0X08,0X92,0X4D,0X8B,0X34,0XA5,0XFB,0XC6,0XFB,0XD6,0XBA,0XCE,0X3C,0XE7,
0X30,0X84,0XC3,0X18,0X41,0X08,0X41,0X08,0X00,0X00,0X41,0X08,0XCF,0X7B,0X7D,0XEF,
0X49,0X4A,0X00,0X00,0X04,0X21,0X45,0X29,0X46,0X31,0X86,0X31,0X30,0X84,0XFF,0XFF,
0XFF,0XF7,0XF7,0XDD,0X09,0XDA,0X83,0XF8,0X01,0XF0,0X42,0XC0,0X82,0X98,0X49,0X9A,
0XF3,0XB4,0XF3,0XCC,0X71,0XBC,0X8E,0XBB,0X8E,0XBB,0X30,0XBC,0X71,0XBC,0XF3,0XBC,
0XB6,0XBD,0XFB,0XCE,0XBE,0XE7,0X7D,0XE7,0X3B,0XDF,0XBA,0XD6,0X79,0XCE,0XFB,0XDE,
0X75,0XAD,0X86,0X31,0X41,0X08,0X41,0X08,0X00,0X00,0X00,0X00,0X49,0X4A,0XFB,0XDE,
0X04,0X21,0X41,0X08,0X04,0X21,0X45,0X29,0X45,0X29,0X87,0X39,0XB2,0X94,0XFF,0XFF,
0XBE,0XF7,0X34,0XDD,0X0C,0XEB,0X09,0XFA,0X00,0XF0,0X01,0XD8,0X00,0XD8,0X8B,0XD2,
0X7D,0XE7,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XBE,0XFF,0X7D,0XEF,0XFB,0XDE,0XFB,0XDE,0XBA,0XD6,0X79,0XCE,0XBA,0XD6,
0X78,0XC6,0XC7,0X39,0X00,0X00,0X41,0X08,0X00,0X00,0X00,0X00,0XC7,0X39,0X79,0XCE,
0X00,0X00,0X82,0X10,0XC3,0X18,0X04,0X21,0X05,0X29,0X86,0X31,0XB3,0X9C,0XFF,0XFF,
0XFF,0XF7,0X75,0XDD,0XC7,0XE9,0XC7,0XF9,0X01,0XF8,0X01,0XF0,0X00,0XE8,0X49,0XE2,
0XFB,0XEE,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XBE,0XF7,0X7D,0XEF,0XFB,0XDE,0XFB,0XDE,0XBA,0XD6,0X79,0XCE,0XBA,0XD6,
0XB9,0XCE,0X08,0X42,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0XC7,0X39,0X38,0XC6,
0X00,0X00,0X82,0X10,0X82,0X10,0X04,0X21,0X04,0X21,0X45,0X29,0X30,0X84,0XFF,0XFF,
0XFF,0XFF,0X38,0XDE,0XC4,0XD0,0X00,0XF0,0X01,0XF8,0X00,0XF8,0X00,0XF0,0X08,0XD2,
0XFB,0XE6,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XBE,0XF7,0X7D,0XEF,0XFB,0XDE,0XBA,0XD6,0X79,0XCE,0X79,0XCE,0XBA,0XD6,
0X79,0XCE,0XC7,0X39,0X41,0X08,0X00,0X00,0X00,0X00,0X00,0X00,0X86,0X31,0X38,0XC6,
0X00,0X00,0X00,0X00,0XC3,0X18,0XCB,0X5A,0X86,0X31,0XC3,0X18,0XCB,0X5A,0X7D,0XEF,
0XFF,0XFF,0X7D,0XEF,0XCF,0XBB,0XC3,0XB0,0X41,0XD0,0X41,0XD0,0X82,0XB8,0X4D,0XB3,
0X7D,0XE7,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XBE,0XF7,0XBE,0XF7,0X3D,0XEF,0XFB,0XDE,0XBA,0XD6,0X79,0XCE,0X79,0XCE,0XFA,0XD6,
0XF7,0XBD,0X04,0X21,0X86,0X31,0X04,0X21,0X00,0X00,0X00,0X00,0X86,0X31,0X38,0XC6,
0X86,0X31,0XC3,0X18,0XCB,0X5A,0X75,0XAD,0XCF,0X7B,0X41,0X08,0X86,0X31,0XF7,0XBD,
0XFF,0XFF,0XFF,0XFF,0XBE,0XEF,0X74,0XB5,0X30,0X9C,0X30,0X9C,0X72,0XA4,0XBB,0XD6,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XBE,0XF7,0X7D,0XEF,0X3C,0XE7,0XFB,0XDE,0XBA,0XD6,0X79,0XCE,0X79,0XCE,0X3C,0XE7,
0X71,0X8C,0X81,0X08,0X0C,0X63,0XCF,0X7B,0X82,0X10,0X00,0X00,0X8A,0X52,0X38,0XC6,
0X75,0XAD,0X71,0X8C,0XB6,0XB5,0X3C,0XE7,0XFB,0XDE,0XC7,0X39,0X00,0X00,0XCF,0X73,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XBE,0XF7,
0X7D,0XEF,0X7D,0XEF,0X3B,0XDF,0XFA,0XD6,0X79,0XCE,0X79,0XCE,0XFB,0XDE,0XB9,0XCE,
0XC7,0X39,0XC4,0X20,0X71,0X8C,0XBA,0XD6,0X71,0X8C,0XCB,0X5A,0XB2,0X94,0XBA,0XD6,
0XFF,0XFF,0X7D,0XEF,0X7D,0XEF,0XFF,0XFF,0XFF,0XFF,0XB6,0XB5,0X46,0X29,0X05,0X19,
0X75,0XA5,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XBE,0XF7,
0X7D,0XEF,0X3C,0XE7,0XFB,0XDE,0XBA,0XD6,0X79,0XCE,0XBA,0XD6,0XFC,0XDE,0X4E,0X63,
0X42,0X08,0X0C,0X63,0XF7,0XBD,0XBE,0XF7,0XFF,0XFF,0XFB,0XDE,0XFB,0XDE,0XBE,0XF7,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF4,0X9C,0X04,0X21,
0X05,0X21,0XB6,0XA5,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XBE,0XF7,0XBE,0XF7,0X7D,0XEF,
0X3C,0XE7,0XFB,0XDE,0XBA,0XD6,0X79,0XCE,0XFB,0XDE,0XBB,0XD6,0XD1,0X73,0X83,0X18,
0X86,0X39,0X34,0X9D,0XBD,0XEF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XBE,0XFF,0X35,0XD6,0XEB,0XCC,0X43,0XB3,
0X40,0X51,0X05,0X19,0XF5,0X8C,0XBE,0XEF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XBE,0XF7,0XBE,0XF7,0X7D,0XEF,0X7D,0XEF,0X3C,0XE7,
0XFB,0XDE,0XBA,0XDE,0XBA,0XD6,0X3C,0XDF,0X3A,0XBE,0X4F,0X63,0X82,0X49,0X40,0XA3,
0X23,0XB4,0XCC,0X83,0X3A,0XBE,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XBF,0XF7,0XB5,0XBD,0X82,0X92,0X20,0XF4,0XA0,0XFC,
0X60,0XE4,0X40,0X82,0X84,0X41,0X8F,0X6B,0X77,0XAD,0X3D,0XE7,0XFF,0XFF,0XFF,0XFF,
0XFE,0XFF,0XBE,0XF7,0XBE,0XF7,0XBE,0XF7,0X7D,0XEF,0X7D,0XEF,0X3C,0XE7,0XFB,0XDE,
0XFB,0XDE,0X3D,0XE7,0XBB,0XCE,0X36,0X9D,0X0B,0X6B,0X41,0X6A,0X60,0XC4,0X20,0XFE,
0X60,0XF5,0X00,0X8B,0XC7,0X6A,0X38,0XC6,0XBE,0XF7,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X7D,0XEF,0X4B,0X7B,0X80,0XB2,0XA0,0XFC,0XA0,0XFC,
0XE0,0XFC,0XE0,0XFC,0XC0,0XCB,0XC1,0X8A,0X45,0X62,0X4D,0X6B,0XB3,0X94,0XF7,0XBD,
0X3D,0XDF,0XFF,0XF7,0XFF,0XFF,0XBE,0XF7,0X7D,0XEF,0X7D,0XEF,0X7D,0XE7,0X3D,0XDF,
0XBA,0XC6,0X75,0XA5,0X8D,0X7B,0X84,0X7A,0X40,0XB3,0XE0,0XEC,0XE0,0XFD,0XE0,0XFD,
0X60,0XF5,0X20,0XE5,0XA0,0XD4,0X0A,0X6B,0XFB,0XDE,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X7D,0XEF,0XCC,0X93,0X40,0XEB,0X60,0XFC,0XA0,0XFC,
0XE0,0XFC,0X20,0XFD,0X60,0XFD,0X20,0XF5,0XA0,0XD4,0XC0,0XBB,0X42,0X9B,0X45,0X8B,
0X6B,0X9C,0XAE,0X9C,0X71,0X8C,0XB3,0X94,0X33,0X9D,0X34,0XA5,0XF2,0XA4,0XF0,0XB4,
0XCA,0X9B,0X04,0X9B,0X40,0XBB,0X20,0XE4,0X20,0XFD,0XA0,0XFD,0XA0,0XFD,0XE0,0XFD,
0XE0,0XFD,0XE0,0XFD,0X20,0XC4,0X88,0X5A,0X38,0XBE,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X78,0XD6,0X46,0XAB,0X40,0XDB,0X20,0XF4,
0X60,0XFC,0XA0,0XFC,0XE0,0XFC,0X60,0XFD,0XA0,0XFD,0X60,0XFD,0X20,0XF5,0XA0,0XDC,
0XC0,0XB3,0XC0,0X51,0X86,0X29,0X0D,0X63,0X8F,0X7B,0X0D,0X5B,0XC7,0X41,0X01,0X82,
0X00,0XC3,0XC0,0XE3,0X60,0XFC,0XA0,0XFC,0XE0,0XFC,0XE0,0XFC,0X60,0XF5,0X60,0XF5,
0X20,0XE5,0X80,0X9B,0X86,0X62,0X30,0X84,0X79,0XCE,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X38,0XC6,0X2D,0X9C,0X05,0X93,
0X43,0XA3,0X82,0XB3,0XC2,0XBB,0XC2,0XBB,0X22,0XB4,0X82,0XA3,0X42,0X93,0XC3,0X7A,
0X85,0X62,0X0B,0X63,0X71,0X84,0XB6,0XB5,0X79,0XCE,0X79,0XC6,0XB5,0XAD,0X70,0X94,
0X4A,0X8B,0X06,0X83,0X04,0X93,0X04,0X9B,0X43,0X9B,0X43,0X9B,0X43,0X93,0X04,0X83,
0X08,0X73,0X8D,0X73,0XB3,0X94,0X79,0XCE,0X7D,0XEF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X3C,0XDF,0X38,0XBE,
0X75,0XB5,0X33,0XA5,0X33,0XA5,0XF3,0X9C,0XF3,0X9C,0XF3,0X9C,0XF3,0X94,0XF3,0X9C,
0X35,0XA5,0XF8,0XBD,0XFB,0XDE,0XBE,0XF7,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X7E,0XEF,
0XBB,0XD6,0XF8,0XBD,0XB6,0XAD,0X75,0XAD,0X34,0XA5,0X33,0X9D,0X34,0X9D,0X35,0XA5,
0XB7,0XAD,0X79,0XC6,0X3C,0XE7,0XBE,0XF7,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
};
#endif


//写寄存器
static void ili9341WriteReg(uint8_t regval)
{ 
    HalGPIOSetLevel(LCD_CS_PIN, 0);  //LCD_CS=0
    HalGPIOSetLevel(LCD_DC_PIN, 0);
    HalSPIReadWrite(HAL_SPI_PORT_2, regval);
    HalGPIOSetLevel(LCD_CS_PIN, 1);  //LCD_CS=1	   		 
}

//写数据16B
static void ili9341WriteData(uint16_t data)
{
 	HalGPIOSetLevel(LCD_CS_PIN, 0);  //LCD_CS=0
	HalGPIOSetLevel(LCD_DC_PIN, 1);	
	HalSPIReadWrite(HAL_SPI_PORT_2, (uint8_t)(data >> 8));
	HalSPIReadWrite(HAL_SPI_PORT_2, (uint8_t)data);
	//HalSPIDmaWrite((uint8_t *)&data, sizeof(uint16_t));
	HalGPIOSetLevel(LCD_CS_PIN, 1);  //LCD_CS=1		
}

static void ili9341DmaWriteData(uint8_t *data, uint16_t len)
{
 	HalGPIOSetLevel(LCD_CS_PIN, 0);  //LCD_CS=0
	HalGPIOSetLevel(LCD_DC_PIN, 1);	

	HalSPIDmaWrite(data, len);
	HalGPIOSetLevel(LCD_CS_PIN, 1);  //LCD_CS=1		
}


//写数据8B
static void ili9341WriteDataByte(uint8_t data)
{
	HalGPIOSetLevel(LCD_CS_PIN, 0); //LCD_CS=0
	HalGPIOSetLevel(LCD_DC_PIN, 1);				    	   
	HalSPIReadWrite(HAL_SPI_PORT_2, data);	
	HalGPIOSetLevel(LCD_CS_PIN, 1);  //LCD_CS=1   			 
}	

//开始写GRAM
static void ili9341WriteRamPrepare(void)
{
    ili9341WriteReg(0X2C);  //写入GRAM
}

//LCD开启显示        ILI9341
void Ili9341LCDDisplayOn(void)
{                                           
    ili9341WriteReg(0X29); //26万色显示开启
}         
//LCD关闭显示        ILI9341
void Ili9341LCDDisplayOff(void)
{           
    ili9341WriteReg(0X28);//关闭显示 
}

//从ILI93xx读出的数据为GBR格式，而我们写入的时候为RGB格式。
//通过该函数转换
//c:GBR格式的颜色值
//返回值：RGB格式的颜色值
static uint16_t bgr2rgb(uint16_t c)
{
        uint16_t  r,g,b,rgb;   
        b=(c>>0)&0x1f;
        g=(c>>5)&0x3f;
        r=(c>>11)&0x1f;         
        rgb=(b<<11)+(g<<5)+(r<<0);                 
        return(rgb);
}   

/*
lcddev.width=240;
lcddev.height=320;
lcddev.wramcmd=0X2C;
lcddev.setxcmd=0X2A;
lcddev.setycmd=0X2B; 

*/
//设置光标位置
static void ili9341SetCursor(uint16_t xpos, uint16_t ypos)
{
    ili9341WriteReg(0X2A);  //set x
	ili9341WriteDataByte(xpos>>8); 
	ili9341WriteDataByte(xpos&0XFF);
    //ili9341WriteDataByte((LCD_SIZE_WIDTH - 1) >> 8);
    //ili9341WriteDataByte(LCD_SIZE_WIDTH - 1);
	ili9341WriteReg(0X2B);  //set y
	ili9341WriteDataByte(ypos>>8); 
	ili9341WriteDataByte(ypos&0XFF);
    //ili9341WriteDataByte((LCD_SIZE_HEIGHT - 1) >> 8);
    //ili9341WriteDataByte((uint8_t)(LCD_SIZE_HEIGHT - 1));
} 	  

static void ili9341LCDOpenWindow( uint16_t x , uint16_t y , uint16_t width , uint16_t height )
{   
    //列地址控制设置，  
    ili9341WriteReg(0x2A); 
    //列设置指令     
    ili9341WriteDataByte(x>>8);
    //先高8位后低8位    
    ili9341WriteDataByte(x & 0xff);    
    ili9341WriteDataByte((x+width-1)>>8);  
    ili9341WriteDataByte((x+width-1) & 0xff);      
    //行地址控制设置，  
    ili9341WriteReg(0x2B); 
    //行设置指令 
    ili9341WriteDataByte(y>>8);
    //先高8位后低8位    
    ili9341WriteDataByte(y & 0xff);    
    ili9341WriteDataByte((y+height-1)>>8); 
    ili9341WriteDataByte((y+height-1) & 0xff);
}

static uint8_t getCharFront(uint8_t id, uint8_t pos, uint8_t width)
{    
    if(width == 24)
    {
        return asc2_4824[id][pos];
    }
    else if(width == 12)
    {
        return asc2_2412[id][pos];
    }
    else
    {
        return 0;
    }
}

/****************************************************************************************
	*@brief		字符显示函数
	*@param		x,y,ASILL,color
	*@retvel	无
*****************************************************************************************/
static void ili9341LCDDisplaychar(uint16_t x, uint16_t y, 
                                    uint16_t ASILL, uint16_t chrwth, uint16_t chrhgt,
                                    uint16_t color)
{
	int8_t page,column,i,temp;
    int8_t n, cycle = 1;
    uint8_t realWth = chrwth;
	i = ASILL - ' ' ; 

    if(chrwth > 8)
    {
        cycle = (chrwth + 7) / 8;
        realWth = 8;
    }
	ili9341LCDOpenWindow( x , y , chrwth , chrhgt); 
	ili9341WriteRamPrepare(); //存储器写指令
	
	for(page = 0; page < chrhgt; page++)
	{
	    
        for(n = 0; n < cycle; n++)
        {
            temp = getCharFront(i, n + page * cycle, chrwth);//取字模   
            
            for(column = 0; column < realWth; column++)
    		{
    			if(temp & 0x80)
    				ili9341WriteData(color);
    			else
    				ili9341WriteData(LCD_COLOR_BLACK); //背景
    			temp<<=1 ; 
    		}//写完一行
        }
		
	}//写完一个字符	
}

/****************************************************************************************
	*@brief		字符串显示函数
	*@param		x,y,ASILL,color
	*@retvel	无
*****************************************************************************************/
void Ili9341LCDDisplayString(uint16_t x, uint16_t y, uint16_t cwidth, uint16_t cheigh, uint8_t *string, uint16_t color)
{

	while(*string != '\0')
	{
		if(x>(240 - cwidth))//检测是否到了一行的最末尾，若是切换到第二行显示
		{
			x = 0 ; 
			y += cheigh ; 
		}
		else if(y>(320 - cheigh))//检测是否到了最后一行，若是切换到始地址开始显示
		{
			x=0 ; 
			y=0; 
		}
		ili9341LCDDisplaychar(x, y, *string, cwidth, cheigh, color) ; 
		x += cwidth ;//显示完一个字符，列地址自动增加
		string++ ; //显示的字符自增
	}
}

//画点
static void ili9341DrawPoint(uint16_t x, uint16_t y)
{
	ili9341SetCursor(x,y);		
	ili9341WriteReg(0X2C);  //写入GRAM
	ili9341WriteData(0x0000); //画笔颜色
} 

static void ili9341FastDrawPoint(uint16_t x, uint16_t y, uint16_t color)
{                    
        ili9341WriteReg(0x2A); 
        ili9341WriteData(x>>8); 
        ili9341WriteData(x&0XFF);         
        ili9341WriteReg(0x2B); 
        ili9341WriteData(y>>8); 
        ili9341WriteData(y&0XFF);
                 
        ili9341WriteReg(0X2C);//开始写入GRAM
        ili9341WriteData(color); 
}  


static void ili9341LCDFill(uint16_t xsta, uint16_t ysta, uint16_t xend, uint16_t yend, uint16_t color)
{          
        uint16_t i,j;
        uint16_t xlen = 0;        

        xlen = xend - xsta + 1;           
        for(i = ysta; i <= yend; i++)
        {
            ili9341SetCursor(xsta,i);      //设置光标位置 
            ili9341WriteRamPrepare();     //开始写入GRAM          
            for(j=0;j<xlen;j++)
                ili9341WriteData(color);        
        }
                                              
}  

//清屏
static void ili9341DisplayClear(uint16_t color)
{
	uint32_t i;     
    //static uint8_t disColor[2];
    //memset(disColor, 0xf8, sizeof(disColor));
    //disColor[0] = 0xf8;
    //disColor[1] = 0xf8;
    /*
    for(i = 0; i < 320; i++)
    {
        disColor[i] = 0x00f8;
    }
    */
    
	ili9341SetCursor(0x0000, 0x0000);	//éè??1a±ê???? 
	ili9341WriteReg(0X2C); 
    //ili9341DmaWriteData((uint8_t *)qqimage, sizeof(qqimage));
#if 0   

    for(i = 0; i < 240; i++)
    {
        ili9341DmaWriteData(disColor, sizeof(disColor));
    }
#endif

	for(i = 0; i < LCD_SIZE_WIDTH * LCD_SIZE_HEIGHT; i++)
	{
		//ili9341WriteData(color);
		ili9341WriteData(color);
	}
}
#if 0
void showimage(uint16_t x,uint16_t y) //??ê?40*40í???
{  
	uint16_t i,j,k;
	uint16_t da;
	k=0;
	for(i=0;i<40;i++)
	{	
		ili9341SetCursor(x,y+i);
        ili9341WriteReg(0X2C);  
		//LCD_WriteRAM_Prepare();     			//?aê?D′è?GRAM	
		for(j=0;j<40;j++)
		{
			da=qqimage[k*2+1];
			da<<=8;
			da|=qqimage[k*2]; 
			ili9341WriteData(da);					
			k++;  			
		}
	}
}


void showqq()
{ 
	uint16_t x,y; 
	x=0;
	y=75;
	while(y<LCD_SIZE_HEIGHT)
	{
		x=0;
		while(x<LCD_SIZE_WIDTH)
		{
			showimage(x,y);	
			x+=40;
		}
		y+=40;
	 }	  
}
#endif

//初始化寄存器
static void configILI9341(void)
{
#if 0
    /*  Power control B (CFh)  */
	ili9341WriteReg(0xCF);
	ili9341WriteDataByte(0x00);
	ili9341WriteDataByte(0x81);
	ili9341WriteDataByte(0x30);
	
	/*  Power on sequence control (EDh) */
	ili9341WriteReg(0xED);
	ili9341WriteDataByte(0x64);
	ili9341WriteDataByte(0x03);
	ili9341WriteDataByte(0x12);
	ili9341WriteDataByte(0x81);
	
	/*  Driver timing control A (E8h) */
	ili9341WriteReg(0xE8);
	ili9341WriteDataByte(0x85);
	ili9341WriteDataByte(0x10);
	ili9341WriteDataByte(0x78);
	
	/*  Power control A (CBh) */
	
	ili9341WriteReg(0xCB);
	ili9341WriteDataByte(0x39);
	ili9341WriteDataByte(0x2C);
	ili9341WriteDataByte(0x00);
	ili9341WriteDataByte(0x34);
	ili9341WriteDataByte(0x02);
	
	/* Pump ratio control (F7h) */
	
	ili9341WriteReg(0xF7);
	ili9341WriteDataByte(0x20);
	
	/* Driver timing control B */
	
	ili9341WriteReg(0xEA);
	ili9341WriteDataByte(0x00);
	ili9341WriteDataByte(0x00);
	
	/* Frame Rate Control (In Normal Mode/Full Colors) (B1h) */
	
	ili9341WriteReg(0xB1);
	ili9341WriteDataByte(0x00);
	ili9341WriteDataByte(0x1B);
	
	/*  Display Function Control (B6h) */
	
	ili9341WriteReg(0xB6);
	ili9341WriteDataByte(0x0A);
	ili9341WriteDataByte(0xA2);
	
	/* Power Control 1 (C0h) */
	
	ili9341WriteReg(0xC0);
	ili9341WriteDataByte(0x35);
	
	/* Power Control 2 (C1h) */
	
	ili9341WriteReg(0xC1);
	ili9341WriteDataByte(0x11);
	
	/* VCOM Control 1(C5h) */
	ili9341WriteReg(0xC5);
	ili9341WriteDataByte(0x45);
	ili9341WriteDataByte(0x45);
	
	/*  VCOM Control 2(C7h)  */
	ili9341WriteReg(0xC7);
	ili9341WriteDataByte(0xA2);
	
	/* Enable 3G (F2h) */
	ili9341WriteReg(0xF2);
	ili9341WriteDataByte(0x00);
	
	/* Gamma Set (26h) */
	ili9341WriteReg(0x26);
	ili9341WriteDataByte(0x01);
	
	
	/* Positive Gamma Correction */
	ili9341WriteReg(0xE0); //Set Gamma
	ili9341WriteDataByte(0x0F);
	ili9341WriteDataByte(0x26);
	ili9341WriteDataByte(0x24);
	ili9341WriteDataByte(0x0B);
	ili9341WriteDataByte(0x0E);
	ili9341WriteDataByte(0x09);
	ili9341WriteDataByte(0x54);
	ili9341WriteDataByte(0xA8);
	ili9341WriteDataByte(0x46);
	ili9341WriteDataByte(0x0C);
	ili9341WriteDataByte(0x17);
	ili9341WriteDataByte(0x09);
	ili9341WriteDataByte(0x0F);
	ili9341WriteDataByte(0x07);
	ili9341WriteDataByte(0x00);
	
	/* Negative Gamma Correction (E1h) */
	ili9341WriteReg(0XE1); //Set Gamma
	ili9341WriteDataByte(0x00);
	ili9341WriteDataByte(0x19);
	ili9341WriteDataByte(0x1B);
	ili9341WriteDataByte(0x04);
	ili9341WriteDataByte(0x10);
	ili9341WriteDataByte(0x07);
	ili9341WriteDataByte(0x2A);
	ili9341WriteDataByte(0x47);
	ili9341WriteDataByte(0x39);
	ili9341WriteDataByte(0x03);
	ili9341WriteDataByte(0x06);
	ili9341WriteDataByte(0x06);
	ili9341WriteDataByte(0x30);
	ili9341WriteDataByte(0x38);
	ili9341WriteDataByte(0x0F);
	
	/* memory access control set */
	
	ili9341WriteReg(0x36); 	
	ili9341WriteDataByte(0xC8);    /*êú?á  ×óé???μ?(?eμ?)μ?óò????(??μ?)é¨?è·?ê?*/
	
	
	/* column address control set */
	ili9341WriteReg(0X2A); 
	ili9341WriteDataByte(0x00);
	ili9341WriteDataByte(0x00);
	ili9341WriteDataByte(0x00);
	ili9341WriteDataByte(0xEF);
	
	/* page address control set */
	
	ili9341WriteReg(0X2B); 
	ili9341WriteDataByte(0x00);
	ili9341WriteDataByte(0x00);
	ili9341WriteDataByte(0x01);
	ili9341WriteDataByte(0x3F);
	
	/*  Pixel Format Set (3Ah)  */
	
	ili9341WriteReg(0x3a); 
	ili9341WriteDataByte(0x55);
#endif
#if 1
#if 1
    ili9341WriteReg(0xCB);  
    ili9341WriteDataByte(0x39); 
    ili9341WriteDataByte(0x2C); 
    ili9341WriteDataByte(0x00); 
    ili9341WriteDataByte(0x34); 
    ili9341WriteDataByte(0x02); 

    ili9341WriteReg(0xCF);  
    ili9341WriteDataByte(0x00); 
    ili9341WriteDataByte(0XC1); 
    ili9341WriteDataByte(0X30); 

    ili9341WriteReg(0xE8);  
    ili9341WriteDataByte(0x85); 
    ili9341WriteDataByte(0x00); 
    ili9341WriteDataByte(0x78); 

    ili9341WriteReg(0xEA);  
    ili9341WriteDataByte(0x00); 
    ili9341WriteDataByte(0x00); 

    ili9341WriteReg(0xED);  
    ili9341WriteDataByte(0x64); 
    ili9341WriteDataByte(0x03); 
    ili9341WriteDataByte(0X12); 
    ili9341WriteDataByte(0X81); 

    ili9341WriteReg(0xF7);  
    ili9341WriteDataByte(0x20); 
#endif
//
    ili9341WriteReg(0xC0);    //Power control 
    ili9341WriteDataByte(0x23);   //VRH[5:0] 

    ili9341WriteReg(0xC1);    //Power control 
    ili9341WriteDataByte(0x10);   //SAP[2:0];BT[3:0] 

    ili9341WriteReg(0xC5);    //VCM control 
    ili9341WriteDataByte(0x3e); //??±è?èμ÷?ú
    ili9341WriteDataByte(0x28); 

    ili9341WriteReg(0xC7);    //VCM control2 
    ili9341WriteDataByte(0x86);  //--

    ili9341WriteReg(0x36);    // Memory Access Control 
    ili9341WriteDataByte(0x48); //C8	   //48 68êú?á//28 E8 oá?á

    ili9341WriteReg(0x3A);    
    ili9341WriteDataByte(0x55); 

    ili9341WriteReg(0xB1);    
    ili9341WriteDataByte(0x00);  
    ili9341WriteDataByte(0x18); 

    ili9341WriteReg(0xB6);    // Display Function Control 
    ili9341WriteDataByte(0x08); 
    ili9341WriteDataByte(0x82);
    ili9341WriteDataByte(0x27);  

    ili9341WriteReg(0xF2);    // 3Gamma Function Disable 
    ili9341WriteDataByte(0x00); 

    ili9341WriteReg(0x26);    //Gamma curve selected 
    ili9341WriteDataByte(0x01); 

    ili9341WriteReg(0xE0);    //Set Gamma 
    ili9341WriteDataByte(0x0F); 
    ili9341WriteDataByte(0x31); 
    ili9341WriteDataByte(0x2B); 
    ili9341WriteDataByte(0x0C); 
    ili9341WriteDataByte(0x0E); 
    ili9341WriteDataByte(0x08); 
    ili9341WriteDataByte(0x4E); 
    ili9341WriteDataByte(0xF1); 
    ili9341WriteDataByte(0x37); 
    ili9341WriteDataByte(0x07); 
    ili9341WriteDataByte(0x10); 
    ili9341WriteDataByte(0x03); 
    ili9341WriteDataByte(0x0E); 
    ili9341WriteDataByte(0x09); 
    ili9341WriteDataByte(0x00); 

    ili9341WriteReg(0XE1);    //Set Gamma 
    ili9341WriteDataByte(0x00); 
    ili9341WriteDataByte(0x0E); 
    ili9341WriteDataByte(0x14); 
    ili9341WriteDataByte(0x03); 
    ili9341WriteDataByte(0x11); 
    ili9341WriteDataByte(0x07); 
    ili9341WriteDataByte(0x31); 
    ili9341WriteDataByte(0xC1); 
    ili9341WriteDataByte(0x48); 
    ili9341WriteDataByte(0x08); 
    ili9341WriteDataByte(0x0F); 
    ili9341WriteDataByte(0x0C); 
    ili9341WriteDataByte(0x31); 
    ili9341WriteDataByte(0x36); 
    ili9341WriteDataByte(0x0F); 
#endif
    ili9341WriteReg(0x11);    //Exit Sleep 
    HalWaitMs(120);
			
    ili9341WriteReg(0x29);    //Display on 
    
	ili9341DisplayClear(LCD_COLOR_BLACK); //corlor
	//showqq();
}

static void restartILI9341(void)
{
    HalGPIOSetLevel(LCD_RESET_PIN, 0);
    //delay 50ms
    HalWaitMs(50);
    HalGPIOSetLevel(LCD_RESET_PIN, 1);
    //delay 120ms
    HalWaitMs(120);

    //ILI9341ReadID();
    configILI9341();
}

void ILI9341Initialize(void)
{
    HalGPIOConfig(LCD_LED_PIN, HAL_IO_OUTPUT);
    HalGPIOConfig(LCD_RESET_PIN, HAL_IO_OUTPUT);
    HalGPIOConfig(LCD_DC_PIN, HAL_IO_OUTPUT);
    HalGPIOConfig(LCD_CS_PIN, HAL_IO_OUTPUT);

    HalGPIOSetLevel(LCD_RESET_PIN, 1);
    HalGPIOSetLevel(LCD_LED_PIN, 1);
    HalGPIOSetLevel(LCD_DC_PIN, 0);
    HalGPIOSetLevel(LCD_CS_PIN, 0);
#if 1

    restartILI9341();
#endif
    HalGPIOSetLevel(LCD_LED_PIN, 0);

    Ili9341LCDDisplayString(0, 0, 24, 48, "FriBoxPAC2", LCD_COLOR_GRAY);
    //Ili9341LCDDisplayString(0, 24, "56789", LCD_COLOR_BLACK, CHAR_SIZE_TYPE_1608);

}

void ILI9341Poll(void)
{
}

