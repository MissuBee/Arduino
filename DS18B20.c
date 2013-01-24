#include "DS18B20.h"

struct DS18B20Struct             DS18B20;	

void DS18B20Begin(unsigned char Pin)
{
	DS18B20.Tick = 0;
	OneWireBegin(Pin);
}

unsigned char DS18B20FindDevices(void)
{
	return OneWireFindDevices();
}

void DS18B20ReadScratchPad(unsigned char Number)
{
	OneWireReset();
	OneWireSelect(Number);
	OneWireWrite(READSCRATCH);
	
	DS18B20.ScratPad[TEMP_LSB] = OneWireRead();
	DS18B20.ScratPad[TEMP_MSB] = OneWireRead();
	DS18B20.ScratPad[HIGH_ALARM_TEMP] = OneWireRead();
	DS18B20.ScratPad[LOW_ALARM_TEMP] = OneWireRead();
	DS18B20.ScratPad[CONFIGURATION] = OneWireRead();
	DS18B20.ScratPad[INTERNAL_BYTE] = OneWireRead();
	DS18B20.ScratPad[COUNT_REMAIN] = OneWireRead();
	DS18B20.ScratPad[COUNT_PER_C] = OneWireRead();
	DS18B20.ScratPad[SCRATCHPAD_CRC] = OneWireRead();
	
	OneWireReset();
}

void DS18B20WriteScratchPad(unsigned char Number)
{
	OneWireReset();
	OneWireSelect(Number);
	OneWireWrite(WRITESCRATCH);
	
	OneWireWrite(DS18B20.ScratPad[HIGH_ALARM_TEMP]);
	OneWireWrite(DS18B20.ScratPad[LOW_ALARM_TEMP]);
	OneWireWrite(DS18B20.ScratPad[CONFIGURATION]);
	
	OneWireWrite(COPYSCRATCH);
	OneWireReset();
}

void DS18B20ReadTemperture(unsigned char Number)
{

	DS18B20Convert();		
	DS18B20ReadScratchPad(Number);  
	CalulatorTemperture();
}

void DS18B20Convert(void)
{
	OneWireReset();
	OneWireWrite(0xCC);
	OneWireWrite(0x44);
}

void CalulatorTemperture()
{
	if((DS18B20.ScratPad[1] & 0x80) == SignNeg)
	    DS18B20.Sign = SignPos;
	else
	    DS18B20.Sign = SignNeg;
	
	DS18B20.Whole =  ((DS18B20.ScratPad[TEMP_MSB] & 0x07) << 4) | (DS18B20.ScratPad[TEMP_LSB] >> 4);
	
	switch (DS18B20.ScratPad[CONFIGURATION] & 0x03)
	{
	   case RESOLUTION09Bit:
	   {
	      break;
	   }
	   case RESOLUTION10Bit:
	   {
	      break;
	   }
	   case RESOLUTION11Bit:
	   {
	      break;
	   }
	   case RESOLUTION12Bit:
	   {
	      DS18B20.Fract = 625 * (DS18B20.ScratPad[TEMP_LSB] & 0x0F);
	      if(((DS18B20.Fract / 100) % 10) >= 5)
	         DS18B20.Fract = (DS18B20.Fract / 1000) + 1;
	      else
	         DS18B20.Fract = (DS18B20.Fract / 1000);
	      break;
	   }
	}
}

void DS18B20GetTemp(void)
{
    DS18B20Convert();

    OneWireReset();
    OneWireWrite(0xCC);
    OneWireWrite(0xBE);

    DS18B20.ScratPad[TEMP_LSB] = OneWireRead();
    DS18B20.ScratPad[TEMP_MSB] = OneWireRead();
    DS18B20.ScratPad[HIGH_ALARM_TEMP] = OneWireRead();
    DS18B20.ScratPad[LOW_ALARM_TEMP] = OneWireRead();
    DS18B20.ScratPad[CONFIGURATION] = OneWireRead();
    DS18B20.ScratPad[INTERNAL_BYTE] = OneWireRead();
    DS18B20.ScratPad[COUNT_REMAIN] = OneWireRead();
    DS18B20.ScratPad[COUNT_PER_C] = OneWireRead();
    DS18B20.ScratPad[SCRATCHPAD_CRC] = OneWireRead();

    if((DS18B20.ScratPad[1] & 0x80) == SignNeg)
        DS18B20.Sign = SignPos;
    else
        DS18B20.Sign = SignNeg;

    DS18B20.Whole = ((DS18B20.ScratPad[TEMP_MSB] & 0x07) << 4) | (DS18B20.ScratPad[TEMP_LSB] >> 4);

    switch (DS18B20.ScratPad[CONFIGURATION] & 0x03)
    {
        case RESOLUTION09Bit:
        {
           break;
        }
        case RESOLUTION10Bit:
        {
           break;
        }
        case RESOLUTION11Bit:
        {
           break;
        }
        case RESOLUTION12Bit:
        {
           DS18B20.Fract = 625 * (DS18B20.ScratPad[TEMP_LSB] & 0x0F);
           if(((DS18B20.Fract / 100) % 10) >= 5)
              DS18B20.Fract = (DS18B20.Fract / 1000) + 1;
           else
              DS18B20.Fract = (DS18B20.Fract / 1000);
           break;
        }
    }
    //XLCDPrintXY(DS18B20.Sign ? " " : "-",Line1,Col1);
    //XLCDPrintNumberXY(DS18B20.Whole,DEC,Line1,Col2);
    //XLCDPrint(".");
    //XLCDPrintNumber(DS18B20.Fract,DEC);
}
















