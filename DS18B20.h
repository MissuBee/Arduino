#ifndef _DS18B20_H_
#define _DS18B20_H_

#include "OneWire.h"

struct DS18B20Struct
{

   unsigned char ScratPad[9];

   char Sign;
   unsigned char Whole;
   int Fract;
   unsigned char Tick;
};

extern struct DS18B20Struct             DS18B20;

#define DS18S20MODEL                    0x10
#define DS18B20MODEL                    0x28
#define DS1822MODEL                     0x22

#define STARTCONVO                      0x44  // Tells device to take a temperature reading and put it on the scratchpad
#define COPYSCRATCH                     0x48  // Copy EEPROM
#define READSCRATCH                     0xBE  // Read EEPROM
#define WRITESCRATCH                    0x4E  // Write to EEPROM
#define RECALLSCRATCH                   0xB8  // Reload from last known
#define READPOWERSUPPLY                 0xB4  // Determine if device needs parasite power
#define ALARMSEARCH                     0xEC  // Query bus for devices with an alarm condition


#define TEMP_LSB                        0
#define TEMP_MSB                        1
#define HIGH_ALARM_TEMP                 2
#define LOW_ALARM_TEMP                  3
#define CONFIGURATION                   4
#define INTERNAL_BYTE                   5
#define COUNT_REMAIN                    6
#define COUNT_PER_C                     7
#define SCRATCHPAD_CRC                  8


#define TEMP_9_BIT                      0x1F //  9 bit
#define TEMP_10_BIT                     0x3F // 10 bit
#define TEMP_11_BIT                     0x5F // 11 bit
#define TEMP_12_BIT                     0x7F // 12 bit

#define SignPos                         0x00
#define SignNeg                         0x80

#define RESOLUTION09Bit                 0x00
#define RESOLUTION10Bit                 0x01
#define RESOLUTION11Bit                 0x02
#define RESOLUTION12Bit                 0x03

#define ByteLSB                                 0
#define ByteMSB                                 1
#define ByteTL                                  2
#define ByteTH                                  3
#define ByteConfig                              4
#define ByteCRC                                 8

void DS18B20Convert(void);
void CalulatorTemperture();

void DS18B20Begin(unsigned char Pin);
unsigned char DS18B20FindDevices(void);
void DS18B20ReadScratchPad(unsigned char Number);
void DS18B20WriteScratchPad(unsigned char Number);
void DS18B20ReadTemperture(unsigned char Number);

void DS18B20GetTemp(void);

#endif