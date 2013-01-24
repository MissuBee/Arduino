#include "Button.h"

struct ButtonStruct SW0,SW1,SW2,SW3,SW4,SW5,SW6,SW7;

void ButtonBegin(unsigned char PinS0,unsigned char PinS1,unsigned char PinS2,unsigned char PinS3,unsigned char PinS4,unsigned char PinS5,unsigned char PinS6,unsigned char PinS7,unsigned char ModeS0,unsigned char ModeS1,unsigned char ModeS2,unsigned char ModeS3,unsigned char ModeS4,unsigned char ModeS5,unsigned char ModeS6,unsigned char ModeS7)
{
	SW0.Pin = PinS0;
	SW1.Pin = PinS1;
	SW2.Pin = PinS2;
	SW3.Pin = PinS3;
	SW4.Pin = PinS4;
	SW5.Pin = PinS5;
	SW6.Pin = PinS6;
	SW7.Pin = PinS7;	

	PinMode(SW0.Pin,InPut);
	PinMode(SW1.Pin,InPut);
	PinMode(SW2.Pin,InPut);
	PinMode(SW3.Pin,InPut);
	PinMode(SW4.Pin,InPut);
	PinMode(SW5.Pin,InPut);
	PinMode(SW6.Pin,InPut);
	PinMode(SW7.Pin,InPut);

	SW0.Mode = ModeS0;
	SW1.Mode = ModeS1;
	SW2.Mode = ModeS2;
	SW3.Mode = ModeS3;
	SW4.Mode = ModeS4;
	SW5.Mode = ModeS5;
	SW6.Mode = ModeS6;
	SW7.Mode = ModeS7;
		
	if(SW0.Mode == PullUpInternal)
	{
		DigitalWrite(SW0.Pin,High);
	}
	if(SW1.Mode == PullUpInternal)
	{
		DigitalWrite(SW1.Pin,High);
	}
	if(SW2.Mode == PullUpInternal)
	{
		DigitalWrite(SW2.Pin,High);
	}
	if(SW3.Mode == PullUpInternal)
	{
		DigitalWrite(SW3.Pin,High);
	}
	if(SW4.Mode == PullUpInternal)
	{
		DigitalWrite(SW4.Pin,High);
	}
	if(SW5.Mode == PullUpInternal)
	{
		DigitalWrite(SW5.Pin,High);
	}
	if(SW6.Mode == PullUpInternal)
	{
		DigitalWrite(SW6.Pin,High);
	}
	if(SW7.Mode == PullUpInternal)
	{
		DigitalWrite(SW7.Pin,High);
	}

	SW0.State = 0;
	SW1.State = 0;
	SW2.State = 0;
	SW3.State = 0;
	SW4.State = 0;
	SW5.State = 0;
	SW6.State = 0;
	SW7.State = 0;	

	BitWrite(SW0.State,CURRENT,!SW0.Mode);
	BitWrite(SW1.State,CURRENT,!SW1.Mode);
	BitWrite(SW2.State,CURRENT,!SW2.Mode);
	BitWrite(SW3.State,CURRENT,!SW3.Mode);
	BitWrite(SW4.State,CURRENT,!SW4.Mode);
	BitWrite(SW5.State,CURRENT,!SW5.Mode);
	BitWrite(SW6.State,CURRENT,!SW6.Mode);
	BitWrite(SW7.State,CURRENT,!SW7.Mode);
}

unsigned char ButtonIsPressed(unsigned char Pin)
{
	if(Pin == SW0.Pin)
	{
		BitWrite(SW0.State,PREVIOUS,BitRead(SW0.State,CURRENT));
	
	    if (DigitalRead(SW0.Pin) == SW0.Mode)
		{
	        BitWrite(SW0.State,CURRENT,False);
	    } 
		else 
		{
	        BitWrite(SW0.State,CURRENT,True);
	    }
	
	    if (BitRead(SW0.State,CURRENT) != BitRead(SW0.State,PREVIOUS))
		{	    			   
	        BitWrite(SW0.State,CHANGED,True);
	    }
		else
		{
	       BitWrite(SW0.State,CHANGED,False);
	    }
		
		if (BitRead(SW0.State,CURRENT) != BitRead(SW0.State,PREVIOUS))
		{
			if((SW0.Mode == PullDown) & (BitRead(SW0.State,CURRENT) == 0))
			{	   	
				return True;
			}
			if((SW0.Mode == PullUp) & (BitRead(SW0.State,CURRENT) == 1))
			{
				return True;
			}		
		}	
	}

	if(Pin == SW1.Pin)
	{
		BitWrite(SW1.State,PREVIOUS,BitRead(SW1.State,CURRENT));
	
	    if (DigitalRead(SW1.Pin) == SW1.Mode)
		{
	        BitWrite(SW1.State,CURRENT,False);
	    } 
		else 
		{
	        BitWrite(SW1.State,CURRENT,True);
	    }
	
	    if (BitRead(SW1.State,CURRENT) != BitRead(SW1.State,PREVIOUS))
		{
	        BitWrite(SW1.State,CHANGED,True);
	    }
		else
		{
	       BitWrite(SW1.State,CHANGED,False);
	    }
		
		if (BitRead(SW1.State,CURRENT) != BitRead(SW1.State,PREVIOUS))
		{
			if((SW1.Mode == PullDown) & (BitRead(SW1.State,CURRENT) == 0))
			{
				return True;
			}
			if((SW1.Mode == PullUp) & (BitRead(SW1.State,CURRENT) == 1))
			{
				return True;
			}
		}			
	}

	if(Pin == SW2.Pin)
	{
		BitWrite(SW2.State,PREVIOUS,BitRead(SW2.State,CURRENT));
	
	    if (DigitalRead(SW2.Pin) == SW2.Mode)
		{
	        BitWrite(SW2.State,CURRENT,False);
	    } 
		else 
		{
	        BitWrite(SW2.State,CURRENT,True);
	    }
	
	    if (BitRead(SW2.State,CURRENT) != BitRead(SW2.State,PREVIOUS))
		{
	        BitWrite(SW2.State,CHANGED,True);
	    }
		else
		{
	       BitWrite(SW2.State,CHANGED,False);
	    }
		
		if (BitRead(SW2.State,CURRENT) != BitRead(SW2.State,PREVIOUS))
		{
			if((SW2.Mode == PullDown) & (BitRead(SW2.State,CURRENT) == 0))
			{
				return True;
			}
			if((SW2.Mode == PullUp) & (BitRead(SW2.State,CURRENT) == 1))
			{
				return True;		
			}
		}	
	}

	if(Pin == SW3.Pin)
	{
		BitWrite(SW3.State,PREVIOUS,BitRead(SW3.State,CURRENT));
	
	    if (DigitalRead(SW3.Pin) == SW3.Mode)
		{
	        BitWrite(SW3.State,CURRENT,False);
	    } 
		else 
		{
	        BitWrite(SW3.State,CURRENT,True);
	    }
	
	    if (BitRead(SW3.State,CURRENT) != BitRead(SW3.State,PREVIOUS))
		{
	        BitWrite(SW3.State,CHANGED,True);
	    }
		else
		{
	       BitWrite(SW3.State,CHANGED,False);
	    }
		
		if (BitRead(SW3.State,CURRENT) != BitRead(SW3.State,PREVIOUS))
		{
			if((SW3.Mode == PullDown) & (BitRead(SW3.State,CURRENT) == 0))
			{
				return True;
			}
			if((SW3.Mode == PullUp) & (BitRead(SW3.State,CURRENT) == 1))
			{
				return True;	
			}
		}		
	}

	if(Pin == SW4.Pin)
	{
		BitWrite(SW4.State,PREVIOUS,BitRead(SW4.State,CURRENT));
	
	    if (DigitalRead(SW4.Pin) == SW4.Mode)
		{
	        BitWrite(SW4.State,CURRENT,False);
	    } 
		else 
		{
	        BitWrite(SW4.State,CURRENT,True);
	    }
	
	    if (BitRead(SW4.State,CURRENT) != BitRead(SW4.State,PREVIOUS))
		{
	        BitWrite(SW4.State,CHANGED,True);
	    }
		else
		{
	       BitWrite(SW4.State,CHANGED,False);
	    }
		
		if (BitRead(SW4.State,CURRENT) != BitRead(SW4.State,PREVIOUS))
		{
			if((SW4.Mode == PullDown) & (BitRead(SW4.State,CURRENT) == 0))
			{
				return True;
			}
			if((SW4.Mode == PullUp) & (BitRead(SW5.State,CURRENT) == 1))
			{
				return True;	
			}
		}		
	}

	if(Pin == SW5.Pin)
	{
		BitWrite(SW5.State,PREVIOUS,BitRead(SW5.State,CURRENT));
	
	    if (DigitalRead(SW5.Pin) == SW5.Mode)
		{
	        BitWrite(SW5.State,CURRENT,False);
	    } 
		else 
		{
	        BitWrite(SW5.State,CURRENT,True);
	    }
	
	    if (BitRead(SW5.State,CURRENT) != BitRead(SW5.State,PREVIOUS))
		{
	        BitWrite(SW5.State,CHANGED,True);
	    }
		else
		{
	       BitWrite(SW5.State,CHANGED,False);
	    }
		
		if (BitRead(SW5.State,CURRENT) != BitRead(SW5.State,PREVIOUS))
		{
			if((SW5.Mode == PullDown) & (BitRead(SW5.State,CURRENT) == 0))
			{
				return True;
			}
			if((SW5.Mode == PullUp) & (BitRead(SW5.State,CURRENT) == 1))
			{
				return True;
			}
		}			
	}

	if(Pin == SW6.Pin)
	{
		BitWrite(SW6.State,PREVIOUS,BitRead(SW6.State,CURRENT));
	
	    if (DigitalRead(SW6.Pin) == SW6.Mode)
		{
	        BitWrite(SW6.State,CURRENT,False);
	    } 
		else 
		{
	        BitWrite(SW6.State,CURRENT,True);
	    }
	
	    if (BitRead(SW6.State,CURRENT) != BitRead(SW6.State,PREVIOUS))
		{
	        BitWrite(SW6.State,CHANGED,True);
	    }
		else
		{
	       BitWrite(SW6.State,CHANGED,False);
	    }
		
		if (BitRead(SW6.State,CURRENT) != BitRead(SW6.State,PREVIOUS))
		{
			if((SW6.Mode == PullDown) & (BitRead(SW6.State,CURRENT) == 0))
			{
				return True;
			}
			if((SW6.Mode == PullUp) & (BitRead(SW6.State,CURRENT) == 1))
			{
				return True;	
			}
		}		
	}

	if(Pin == SW7.Pin)
	{
		BitWrite(SW7.State,PREVIOUS,BitRead(SW7.State,CURRENT));
	
	    if (DigitalRead(SW7.Pin) == SW7.Mode)
		{
	        BitWrite(SW7.State,CURRENT,False);
	    } 
		else 
		{
	        BitWrite(SW7.State,CURRENT,True);
	    }
	
	    if (BitRead(SW7.State,CURRENT) != BitRead(SW7.State,PREVIOUS))
		{
	        BitWrite(SW7.State,CHANGED,True);
	    }
		else
		{
	       BitWrite(SW7.State,CHANGED,False);
	    }
		
		if (BitRead(SW7.State,CURRENT) != BitRead(SW7.State,PREVIOUS))
		{
			if((SW7.Mode == PullDown) & (BitRead(SW7.State,CURRENT) == 0))
			{
				return True;
			}
			if((SW7.Mode == PullUp) & (BitRead(SW7.State,CURRENT) == 1))
			{
				return True;	
			}
		}		
	}
	return False;	
}