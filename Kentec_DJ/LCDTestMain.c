#include "lm4f120h5qr.h"
#include "SSD2119.h"
#include "PLL.h"
#include "random.h"
#include "LCDTests.h"

int main(void){unsigned long i=0;
  // Set the clocking to run at 80MHz from the PLL.
		PLL_Init();
    // Initialize LCD
		LCD_Init();  
    // Initialize RNG
    Random_Init(121213);
    // Initialize touchscreen GPIO
    Touch_Init();
		Buttons_Init();
      
    for(;;) {
      touchDebug();
    }
    
}


