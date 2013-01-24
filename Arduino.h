#ifndef ARDUINO_H
#define ARDUINO_H

#include <htc.h>
#include <pic.h>

#define _XTAL_FREQ                              16000000

#define ClockCyclesPerMicroSecond()				(_XTAL_FREQ / 4000000)
#define ClockCyclesToMicroSeconds(x)			((x * 4) / (_XTAL_FREQ / 1000000))

#define PinA0                                   0
#define PinA1                                   1
#define PinA2                                   2
#define PinA3                                   3
#define PinA4                                   4
#define PinA5                                   5
#define PinA6                                   6
#define PinA7                                   7

#define PinB0                                   8
#define PinB1                                   9
#define PinB2                                   10
#define PinB3                                   11
#define PinB4                                   12
#define PinB5                                   13
#define PinB6                                   14
#define PinB7                                   15

#define PinC0                                   16
#define PinC1                                   17
#define PinC2                                   18
#define PinC3                                   19
#define PinC4                                   20
#define PinC5                                   21
#define PinC6                                   22
#define PinC7                                   23

#define PinD0                                   24
#define PinD1                                   25
#define PinD2                                   26
#define PinD3                                   27
#define PinD4                                   28
#define PinD5                                   29
#define PinD6                                   30
#define PinD7                                   31

#define PinE0                                   32
#define PinE1                                   33
#define PinE2                                   34


#define A0                                      0
#define A1                                      1
#define A2                                      2
#define A3                                      3
#define A4                                      4
#define A5                                      5
#define A6                                      6
#define A7                                      7

#define B0                                      8
#define B1                                      9
#define B2                                      10
#define B3                                      11
#define B4                                      12
#define B5                                      13
#define B6                                      14
#define B7                                      15

#define C0                                      16
#define C1                                      17
#define C2                                      18
#define C3                                      19
#define C4                                      20
#define C5                                      21
#define C6                                      22
#define C7                                      23

#define D0                                      24
#define D1                                      25
#define D2                                      26
#define D3                                      27
#define D4                                      28
#define D5                                      29
#define D6                                      30
#define D7                                      31

#define E0                                      32
#define E1                                      33
#define E2                                      34

#define BIN										2
#define HEX										16
#define DEC										10

#define True                                    1
#define False                                   0

#define High                                    1
#define Low                                     0

#define InPut                                   1
#define OutPut                                  0

#define LSBFIRST 								0
#define MSBFIRST 								1

#define PA                                      0
#define PB                                      1
#define PC                                      2
#define PD                                      3
#define PE                                      4

#define NOT_A_PIN                               0
#define NOT_A_PORT                              0

#define Non										255

#define uchar									unsigned char

extern const volatile unsigned char DigitalPinToBitMaskPGM[];
extern const volatile unsigned char DigitalPinToPortPGM[];

extern const volatile unsigned char PortToInputPGM[];
extern const volatile unsigned char PortToOutputPGM[];
extern volatile unsigned char PortToModePGM[];

#define PinToBitMask(Pin)                       DigitalPinToBitMask(Pin)

#define PinToInPutMask(Pin)                     PortInputRegister(DigitalPinToPort(Pin))
#define PinToOutPutMask(Pin)                    PortOutputRegister(DigitalPinToPort(Pin))
#define PinToModeMask(Pin)                      PortModeRegister(DigitalPinToPort(Pin))

#define PinIsModeInPut(Base,Mask)               ((*(Base)) |= (Mask))
#define PinIsModeOutPut(Base,Mask)              ((*(Base)) &= ~(Mask))

#define PinIsHigh(Base,Mask)                    ((*(Base)) |= (Mask))
#define PinIsLow(Base,Mask)                     ((*(Base)) &= ~(Mask))

#define PinIsRead(Base,Mask)                    ((*(Base)) & (Mask)) ? 1 : 0

#define DigitalPinToPort(Pin)                   DigitalPinToPortPGM[Pin]
#define DigitalPinToBitMask(Pin)                DigitalPinToBitMaskPGM[Pin]

#define PortOutputRegister(Pin)                 (volatile int *)PortToOutputPGM[Pin]
#define PortInputRegister(Pin)                  (volatile int *)PortToInputPGM[Pin]
#define PortModeRegister(Pin)                   (volatile int *)PortToModePGM[Pin]


















#define TickGetDiff(a, b)  ((unsigned int)(a < b) ? (((unsigned int)0xFFFF - b) + a + 1) : (a - b))

#ifndef BCDToDec
#define BCDToDec(Var)							((Var >> 4)*10+(Var & 0x0F))
#endif

#ifndef DecToBCD
#define DecToBCD(Var)		                	(((Var/10)<<4)+(Var%10))
#endif

#ifndef BitRead
#define BitRead(Value,Bit)						(((Value) >> (Bit)) & 0x01)
#endif

#ifndef BitSet
#define BitSet(Value, Bit) 						(Value = Value | (0x01 << Bit))
#endif

#ifndef BitClear
#define BitClear(Value, Bit) 					(Value = Value & ~(0x01 << Bit))
#endif

#ifndef BitWrite
#define BitWrite(Value, Bit,BitValue) 			(BitValue ? BitSet(Value,Bit) : BitClear(Value,Bit))
#endif

#ifndef TwoByteToDec
#define TwoByteToDec(High,Low)					(10 * High + Low)
#endif

void Init(void);
void Setup(void);
void Loop(void);
unsigned char ShiftIn(unsigned char dataPin,unsigned char clockPin,unsigned char bitOrder);
void ShiftOut(unsigned char dataPin,unsigned char clockPin,unsigned char bitOrder,unsigned char val);

extern unsigned int TickTimer;
extern volatile unsigned long Timer0OverflowCount;

void Interrupts(void);
void NoInterrupts(void);

unsigned long Millis();
unsigned long Micros(void);

#define Delay_ms(x)								Delay(x)
#define Delay_us(x)								__delay_us(x)
#define DelayMicroSeconds(x)					__delay_us(x)			
void Delay(unsigned long ms);



void LedBlink(unsigned char Pin);

void PinMode(unsigned char Pin,unsigned char State);
void DigitalWrite(unsigned char Pin,unsigned char State);
unsigned char DigitalRead(unsigned char pin);


#endif