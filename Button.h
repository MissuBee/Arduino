#ifndef _Button_H_
#define _Button_H_

#include "Arduino.h"

#define PullUp 							High
#define PullDown 						Low

#define PUp								High
#define PDown							Low

#define PullUpInternal					2 

#define CURRENT 						0
#define PREVIOUS 						1
#define CHANGED 						2

#define Non								255

#define DebounceDelay					5000

struct ButtonStruct
{
	unsigned char Pin;
	unsigned char State;
	unsigned char Mode;
	
	unsigned long PressedStartTime;
};

extern struct ButtonStruct SW0,SW1,SW2,SW3,SW4,SW5,SW6,SW7;

void ButtonBegin(unsigned char PinS0,unsigned char PinS1,unsigned char PinS2,unsigned char PinS3,unsigned char PinS4,unsigned char PinS5,unsigned char PinS6,unsigned char PinS7,unsigned char ModeS0,unsigned char ModeS1,unsigned char ModeS2,unsigned char ModeS3,unsigned char ModeS4,unsigned char ModeS5,unsigned char ModeS6,unsigned char ModeS7);
unsigned char ButtonIsPressed(unsigned char Pin);

#endif
