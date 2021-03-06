#include <stdint.h>
//#include "inc/tm4c123gh6pm.h"
#include "Switch.h"
#include "DAC.h"
#include "PLL.h"
#include "Timer0A.h"
#include "SysTick.h"

#include "lm4f120h5qr.h"
#include "SSD2119.h"
#include "random.h"
#include "LCDTests.h"

#define NVIC_EN0_INT4           0x00000010  // Interrupt 4 enable
#define F16HZ (50000000/16)

extern struct Songs *strobePtr;
void Music_Play(const unsigned short, int, const struct Songs* song, int);
extern uint32_t play, rewind, mode, pause;
extern const unsigned short Trumpet[32], Horn[32],Wave[32],Flute[32],dt[32];
int instrument = 0;

//--HeartBeat_Init--
//Initialize PF2 Onboard Heartbeat
void HeartBeat_Init(void){
	                                   // activate port F
  SYSCTL_RCGCGPIO_R |= 0x20;
  while((SYSCTL_PRGPIO_R&0x0020) == 0){};// ready?
  GPIO_PORTF_DIR_R |= 0x04;        // make PF2 out (built-in LED)
  GPIO_PORTF_AFSEL_R &= ~0x04;     // disable alt funct on PF2
  GPIO_PORTF_DEN_R |= 0x04;        // enable digital I/O on PF2
                                   // configure PF2 as GPIO
  GPIO_PORTF_PCTL_R = (GPIO_PORTF_PCTL_R&0xFFFFF0FF)+0x00000000;
  GPIO_PORTF_AMSEL_R = 0;          // disable analog functionality on PF
	}


extern unsigned short Time;

	
int main(void){
	HeartBeat_Init();
	DAC_Init(1024);							// initialize with command: Vout = Vref
	Timer0A_Init(dt[0]);
	LCD_Init();  
    // Initialize RNG
  Random_Init(121213);
    // Initialize touchscreen GPIO
  Touch_Init();
	//lenPush = 1;
  //for(i=0; i<50; i=i+1){
	InitializeBars();
  for(i=0; i<400; i=i+1){
	MovingColorBars();
	}
	for(i=0; i<400; i=i+1){
		DestabilizeBars();
	}
	for(i=0; i<350; i=i+1){
		FinishBars();
	}
	for(i=0; i<1000; i=i+1){
     Random4BPPTestSprite();
  }
	LCD_ColorFill(convertColor(0, 0, 0));
	Buttons_Init();
	play = 0;
	while(1){
			if (instrument == 0){
				Music_Play(Wave[0], 64, strobePtr, 35);		
			}
			if (instrument == 1){
				Music_Play(Trumpet[0], 32, strobePtr, 35);
			}
			if (instrument == 2){
				Music_Play(Flute[0], 32, strobePtr, 35);
			}
	}
}
