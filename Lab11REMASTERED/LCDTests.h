#include "SSD2119.h"


extern unsigned short cursorX;
extern unsigned short cursorY;
int x = 0;
int y = 0;
int i = 0;  

const unsigned char testSprite4BPP[] = {
 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
 0xFE, 0xDC, 0xBA, 0x98, 0x76, 0x54, 0x32, 0x1F,
 0xF1, 0x23, 0x45, 0x67, 0x89, 0xAB, 0xCD, 0xEF,
 0xFE, 0xDC, 0xBA, 0x98, 0x76, 0x54, 0x32, 0x1F,
 0xF1, 0x23, 0x45, 0x67, 0x89, 0xAB, 0xCD, 0xEF,
 0xFE, 0xDC, 0xBA, 0x98, 0x76, 0x54, 0x32, 0x1F,
 0xF1, 0x23, 0x45, 0x67, 0x89, 0xAB, 0xCD, 0xEF,
 0xFE, 0xDC, 0xBA, 0x98, 0x76, 0x54, 0x32, 0x1F,
 0xF1, 0x23, 0x45, 0x67, 0x89, 0xAB, 0xCD, 0xEF,
 0xFE, 0xDC, 0xBA, 0x98, 0x76, 0x54, 0x32, 0x1F,
 0xF1, 0x23, 0x45, 0x67, 0x89, 0xAB, 0xCD, 0xEF,
 0xFE, 0xDC, 0xBA, 0x98, 0x76, 0x54, 0x32, 0x1F,   
 0xF1, 0x23, 0x45, 0x67, 0x89, 0xAB, 0xCD, 0xEF,
 0xFE, 0xDC, 0xBA, 0x98, 0x76, 0x54, 0x32, 0x1F,
 0xF1, 0x23, 0x45, 0x67, 0x89, 0xAB, 0xCD, 0xEF,
 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF    
};    


void PrintAsciiChars(){
    unsigned char i;
    LCD_SetCursor(0, 0);
    for (i = 0x20; i < 0x7F; i++){
        LCD_PrintChar(i);
    }   
}

void BlastChars(){
    LCD_SetCursor(0, 0);
    for (;;){
        LCD_PrintChar((Random() % 96) + 0x20);
        //LCD_SetTextColor(Random() % 255, Random() % 255, Random() % 255);
    }   
}

void TestStringOutput(){
    LCD_SetCursor(0, 0);
    LCD_PrintString("This is just a test string, please ignore.\nI repeat, this is just a test string, please ignore.");
}

void RandomRectangles(){
    LCD_DrawRect(Random() % 200, Random() % 160, Random() % 160, Random() %100, convertColor(Random()%3 * 127, Random()%3 * 127, Random()%3 * 127));
}
void InitializeBars(){
			LCD_DrawFilledRect(17, 90, 32, (240-90), convertColor(0,0,255));
			LCD_DrawFilledRect(49, 120, 32, (240-120), convertColor(0,255,0));
			LCD_DrawFilledRect(81, 50, 32, (240-50), convertColor(255,0,0));
			LCD_DrawFilledRect(113, 81, 32, (240-78), convertColor(0,0,255));
			LCD_DrawFilledRect(145, 76, 32, (240-76), convertColor(0,255,0));
			LCD_DrawFilledRect(177, 130, 32, (240-130), convertColor(255,0,0));
			LCD_DrawFilledRect(209, 40, 32, (240-40), convertColor(0,0,255));
			LCD_DrawFilledRect(241, 110, 32, (240-110), convertColor(0,255,0));
			LCD_DrawFilledRect(273, 140, 32, (240-140), convertColor(255,0,0));

}
void dlay(){
	int j;
	while(j < 2500){
		j +=1;
	}
	j = 0;
}
int y1,y2,y3,y4,y5,y6,y7,y8,y9;
int slowflag;
void MovingColorBars(){
		dlay();
		dlay();
		dlay();
		dlay();
		dlay();
		dlay();
		//first bar
		if(rand()% 2 == 1){
			if ( y1 > -90){
				int a = 3;
				LCD_DrawFilledRect(17, 90+y1, 32, a, convertColor(0,0,255));
				y1 =  y1- a;
			}
		}
		else{
			if( y1 < 60){
				int b = 3;
				LCD_DrawFilledRect(17, 90+y1, 32, b, convertColor(0,0,0));
				y1 = y1 + b;
			}
		}
	//second bar
		if(rand()% 2 == 1){
			if (y2 > -90){
				int a = 3;
				LCD_DrawFilledRect(49, 120+y2, 32, a, convertColor(0,255,0));
				y2 = y2-a;
			}
		}
		else{
			if(y2 < 80){
				int b = 3;
				LCD_DrawFilledRect(49, 120+y2, 32, b, convertColor(0,0,0));
				y2 = y2 + b;
			}
		}
	//third bar
		if(rand()% 2 == 1){
			if (y3 > -40){
				int a = 3;
				LCD_DrawFilledRect(81, 50+y3, 32, a, convertColor(255,0,0));
				y3 = y3-a;
			}
		}
		else{
			if(y3 < 120){
				int b = 3;
				LCD_DrawFilledRect(81, 50+y3, 32, b, convertColor(0,0,0));
				y3 = y3 + b;
			}
		}
		//fourth bar
		if(rand()% 2 == 1){
			if (y4 > -40){
				int a = 3;
				LCD_DrawFilledRect(113, 81+y4, 32, a, convertColor(0,0,255));
				y4 = y4-a;
			}
		}
		else{
			if(y4 < 110){
				int b = 3;
				LCD_DrawFilledRect(113, 81+y4, 32, b, convertColor(0,0,0));
				y4 = y4 + b;
			}
		}
		//fifth bar
		if(rand()% 2 == 1){
			if (y5 > -130){
				int a = 3;
				LCD_DrawFilledRect(145, 76+y5, 32, a, convertColor(0,255,0));
				y5 = y5-a;
			}
		}
		else{
			if(y5 < 80){
				int b = 3;
				LCD_DrawFilledRect(145, 76+y5, 32, b, convertColor(0,0,0));
				y5 = y5 + b;
			}
		}
		//sixth bar
		if(rand()% 2 == 1){
			if (y6 > -40){
				int a = 3;
				LCD_DrawFilledRect(177, 130+y6, 32, a, convertColor(255,0,0));
				y6 = y6-a;
			}
		}
		else{
			if(y6 < 40){
				int b = 3;
				LCD_DrawFilledRect(177, 130+y6, 32, b, convertColor(0,0,0));
				y6 = y6 + b;
			}
		}
		//seventh bar
		if(rand()% 2 == 1){
			if (y7 > -40){
				int a = 3;
				LCD_DrawFilledRect(209, 40+y7, 32, a, convertColor(0,0,255));
				y7 = y7-a;
			}
		}
		else{
			if(y7 < 40){
				int b = 3;
				LCD_DrawFilledRect(209, 40+y7, 32, b, convertColor(0,0,0));
				y7 = y7 + b;
			}
		}
		//eigth bar
		if(rand()% 2 == 1){
			if (y8 > -10){
				int a = 3;
				LCD_DrawFilledRect(241, 110+y8, 32, a, convertColor(0,255,0));
				y8 = y8-a;
			}
		}
		else{
			if(y8 < 10){
				int b = 3;
				LCD_DrawFilledRect(241, 110+y8, 32, b, convertColor(0,0,0));
				y8 = y8 + b;
			}
		}
		//ninth bar
		if(rand()% 2 == 1){
			if (y9 > -100){
				int a = 3;
				LCD_DrawFilledRect(273, 140+y9, 32, a, convertColor(255,0,0));
				y9 = y9-a;
			}
		}
		else{
			if(y9 < 70){
				int b = 3;
				LCD_DrawFilledRect(273, 140+y9, 32, b, convertColor(0,0,0));
				y9 = y9 + b;
			}
		}
}

void 	DestabilizeBars(){
		dlay();
		dlay();
		dlay();
			if( y1 < 130){
				int b = 1;
				LCD_DrawFilledRect(17, 90+y1, 32, b, convertColor(0,0,0));
				y1 = y1 + b;
			}
			if(y2 < 100){
				int b = 1;
				LCD_DrawFilledRect(49, 120+y2, 32, b, convertColor(0,0,0));
				y2 = y2 + b;
			}
			if(y3 < 170){
				int b = 1;
				LCD_DrawFilledRect(81, 50+y3, 32, b, convertColor(0,0,0));
				y3 = y3 + b;
			}
			if(y4 < 139){
				int b = 1;
				LCD_DrawFilledRect(113, 81+y4, 32, b, convertColor(0,0,0));
				y4 = y4 + b;
			}
			if(y5 < 144){
				int b = 1;
				LCD_DrawFilledRect(145, 76+y5, 32, b, convertColor(0,0,0));
				y5 = y5 + b;
			}
			if(y6 < 90){
				int b = 1;
				LCD_DrawFilledRect(177, 130+y6, 32, b, convertColor(0,0,0));
				y6 = y6 + b;
			}
			if(y7 < 180){
				int b = 1;
				LCD_DrawFilledRect(209, 40+y7, 32, b, convertColor(0,0,0));
				y7 = y7 + b;
			}
			if(y8 < 110){
				int b = 1;
				LCD_DrawFilledRect(241, 110+y8, 32, b, convertColor(0,0,0));
				y8 = y8 + b;
			}
			if(y9 < 80){
				int b = 1;
				LCD_DrawFilledRect(273, 140+y9, 32, b, convertColor(0,0,0));
				y9 = y9 + b;
			}
}
void FinishBars(){
		dlay();
		dlay();
		dlay();
			if( y1 > -90){
				int a = 1;
				LCD_DrawFilledRect(17, 90+y1, 32, a, convertColor(0,0,255));
				y1 = y1 - a;
			}
			if(y2 > -120){
				int a = 1;
				LCD_DrawFilledRect(49, 120+y2, 32, a, convertColor(0,255,0));
				y2 = y2 - a;
			}
			if(y3 > -50){
				int a = 1;
				LCD_DrawFilledRect(81, 50+y3, 32, a, convertColor(255,0,0));
				y3 = y3 - a;
			}
			if(y4 > -81){
				int a = 1;
				LCD_DrawFilledRect(113, 81+y4, 32, a, convertColor(0,0,255));
				y4 = y4 - a;
			}
			if(y5 > -76){
				int a = 1;
				LCD_DrawFilledRect(145, 76+y5, 32, a, convertColor(0,255,0));
				y5 = y5 - a;
			}
			if(y6 >-130){
				int a = 1;
				LCD_DrawFilledRect(177, 130+y6, 32, a, convertColor(255,0,0));
				y6 = y6 - a;
			}
			if(y7 > -40){
				int a = 1;
				LCD_DrawFilledRect(209, 40+y7, 32, a, convertColor(0,0,255));
				y7 = y7 - a;
			}
			if(y8 > -110){
				int a = 1;
				LCD_DrawFilledRect(241, 110+y8, 32, a, convertColor(0,255,0));
				y8 = y8 - a;
			}
			if(y9 > -140){
				int a = 1;
				LCD_DrawFilledRect(273, 140+y9, 32, a, convertColor(255,0,0));
				y9 = y9 - a;
			}
}
void RandomColorFill(){
    long i;
    //long color = convertColor(Random() % 255,Random() % 255,Random() % 255);        
    long color = convertColor(255,Random() % 255,Random() % 255);         
    for(i = 0; i < (320 * 240); i++)
    {
        LCD_WriteData(color);
    }    
}

void BWWaitFill(){
    LCD_ColorFill(convertColor(255,255,255));
    for (i = 0; i < 5000000; i++) {}
    LCD_ColorFill(convertColor(0,0,0));
    for (i = 0; i < 5000000; i++) {}            
}

void LineSpin(){
    long color = convertColor(Random() % 256,Random() % 256,Random() % 256);
    for (x = 0; x < 320; x++){
        LCD_DrawLine(160, 120, x, 0, color);
    }
    color = convertColor(Random() % 256,Random() % 256,Random() % 256);        
    for (y = 0; y < 240; y++) {
        LCD_DrawLine(160, 120, 320, y, color);
    }
    color = convertColor(Random() % 256,Random() % 256,Random() % 256);        
    for (x = 320; x > 0; x--){
        LCD_DrawLine(160, 120, x, 240, color);
    }
    color = convertColor(Random() % 256,Random() % 256,Random() % 256);        
    for (y = 240; y > 0; y--) {
        LCD_DrawLine(160, 120, 0, y, color);
    }
}

void printfTest(){
    unsigned char x = 51;
    LCD_SetCursor(0,0);
    printf("hihi %s %c %d\nDecimal: %d\nHex:     %x\nBinary:  %b\n", "Bob", 'a', x, i, i, i);
    i++;
}

void charTest(){
    unsigned char i = 0;
    
    LCD_Goto(0,0);
    //for(i=0;i<52;i++){    
        printf("%d", i%10);
    //}
    //LCD_Goto(2,0);
    //for(i=0;i<27;i++){    
    //    printf("%d", i%10);
    //    LCD_Goto(2, i+1);
    //}
}

void sizeofStuff(){
    printf("Size of       INT: %d\n", sizeof(int));
    printf("Size of      CHAR: %d\n", sizeof(char));
    printf("Size of     SHORT: %d\n", sizeof(short));
    printf("Size of      LONG: %d\n", sizeof(long));
    printf("Size of     FLOAT: %d\n", sizeof(float));
    printf("Size of    DOUBLE: %d\n", sizeof(double));
}

void RandomCircle(){
    LCD_DrawFilledCircle(Random()%280 + 20, Random()%200 + 20, 20, Random()%0xFFFF);    
}

void CircleButtons(unsigned short x, unsigned short y, unsigned short radius, short color){
	LCD_DrawFilledCircle(x, y, radius, color);
}
void Buttons_Init(){
	//Top Row Buttons
		//LCD_DrawFilledRect(0, 0, 80, 80, convertColor(255,36,36));
	//Middle Row Buttons	
		LCD_DrawFilledRect(0, 80, 80, 80, convertColor(255,255,36)); //Yellow Button
		LCD_DrawFilledRect(80, 80, 80, 80, convertColor(255,36,36)); //Red Button
		LCD_DrawFilledRect(160, 80, 80, 80, convertColor(36,39,255)); //Blue Button
		LCD_DrawFilledRect(240, 80, 80, 80, convertColor(36,255,36)); //Green Button
	//Bottom Row Buttons	
		LCD_DrawFilledRect(0, 160, 80, 80, convertColor(255,36,36)); //Red Button
		LCD_DrawFilledRect(80, 160, 80, 80, convertColor(36,39,255)); //Blue Button
		LCD_DrawFilledRect(160, 160, 80, 80, convertColor(36,255,36)); //Green Button
		LCD_DrawFilledRect(240, 160, 80, 80, convertColor(255,255,36)); //Yellow Button
		//CircleButtons(50, 200, 35, convertColor(255,36,36));
		//CircleButtons(125, 200, 35, convertColor(36,39,255));
		//CircleButtons(200, 200, 35, convertColor(36,255,36));
		//CircleButtons(275, 200, 35, convertColor(255,255,36));
		//CircleButtons(200, 120, 30, convertColor(255,36,36));
		//CircleButtons(200, 200, 30, convertColor(255,36,36));
		//CircleButtons(275, 120, 30, convertColor(255,36,36));
		//CircleButtons(275, 200, 30, convertColor(255,36,36));
}
void Random4BPPTestSprite(){
    LCD_DrawImage(testSprite4BPP, Random()%304, Random()%224, 16, 16, 4);
}



/////////////////////////////////////////////// TOUCHSCREEN STUFF ////////////////////////////////////

long yVal = 0;
long xVal = 0;
long z1Val = 0;
long z2Val = 0;
long Touched = 0;
long TouchCounter = 0;
long TouchR2C1 = 0;
long TouchR2C2 = 0;
long TouchR2C3 = 0;
long TouchR2C4 = 0;
long TouchR3C1 = 0;
long TouchR3C2 = 0;
long TouchR3C3 = 0;
long TouchR3C4 = 0;
long firstfac = 0;
long secondfac = 0;
long yValold = 0;
long randomcolor;
void touchDebug(){
        long temp, blahX, blahY; 
     
        // do stuff every however often here
        yVal = Touch_ReadY();      // 24-14
        xVal = Touch_ReadX();      // 29-16
        z1Val = Touch_ReadZ1();
        z2Val = Touch_ReadZ2();

        temp = Touch_GetCoords();
        blahX = (temp >> 16);
        blahY = temp & 0xFFFF;
				//This phrase is needed for all print statements.
				LCD_Goto(0,0);
				printf("TC = %d\n",
					TouchCounter);
				printf("R2C1 = %d R2C2 = %d R2C3 = %d R2C4 = %d\n",
					TouchR2C1,TouchR2C2,TouchR2C3,TouchR2C4);
				printf("R3C1 = %d R3C2 = %d R3C3 = %d R3C4 = %d\n",
					TouchR3C1,TouchR3C2,TouchR3C3,TouchR3C4);
		if(yVal > 270+yValold  || yVal < yValold-270){			
				if(yVal != 376){	
					if(yVal != 0){
					firstfac = 0;
					secondfac = 0;
					}
			}
			if (firstfac == 0) {
					firstfac = 1;
					yValold = yVal;
						}
			if(firstfac == 1 && secondfac == 0){
        TouchCounter++;
        if(TouchCounter >= 100){
            TouchCounter = 0;
            Touched = 0;
        }
				//specific if statements for location of touch:
				
				//Row 2 (Middle)
				//Row 2(Middle) Column 1(Left Edge) Corner
				if(blahX < 295 && blahX > 235){
					if(blahY <235 && blahY > 210){
						TouchR2C1++;
						randomcolor = convertColor(Random() % 255,Random() % 255,255);
						LCD_DrawFilledRect(0, 80, 80, 80, randomcolor);
					}
				}
				//Row 2(Middle) Column 2(Left of Middle) Corner
				if(blahX < 225 && blahX > 180){
					if(blahY <210 && blahY > 170){
						TouchR2C2++;
						randomcolor = convertColor(Random() % 255,Random() % 255,Random() % 255);
						LCD_DrawFilledRect(80, 80, 80, 80, randomcolor);
					}
				}
				//Row 2(Middle) Column 3(Right of Middle) Corner
				if(blahX < 170 && blahX > 125){
					if(blahY <196 && blahY > 160){
						TouchR2C3++;
						randomcolor = convertColor(255,Random() % 255,Random() % 255);
						LCD_DrawFilledRect(160, 80, 80, 80, randomcolor);
					}
				}
				//Row 2(Middle) Column 4(Right Edge) Corner
				if((blahX < 110) && (blahX > 80)){
					if((200 > blahY)&&(blahY > 165)){
						TouchR2C4++;
						randomcolor = convertColor(Random() % 255,255,Random() % 255);
						LCD_DrawFilledRect(240, 80, 80, 80, randomcolor);
					}
				}
				
				//Row 3(Bottom)
				//Row 3(Bottom) Column 1(Left Edge) Corner
				if(blahX < 290 && blahX > 235){
					if(blahY <305 && blahY > 260){
						TouchR3C1++;
						randomcolor = convertColor(Random() % 255,Random() % 255,Random() % 255);
						LCD_DrawFilledRect(0, 160, 80, 80, randomcolor);
					}
				}
				//Row 3(Bottom) Column 2(Left of Middle) Corner
				if(blahX < 215 && blahX > 185){
					if(blahY <280 && blahY > 230){
						TouchR3C2++;
						randomcolor = convertColor(255,Random() % 255,Random() % 255);
						LCD_DrawFilledRect(80, 160, 80, 80, randomcolor);
					}
				}
				//Row 3(Bottom) Column 3(Right of Middle) Corner
				if(blahX < 170 && blahX > 120){
					if(blahY <260 && blahY > 230){
						TouchR3C3++;
						randomcolor = convertColor(Random() % 255,255,Random() % 255);
						LCD_DrawFilledRect(160, 160, 80, 80, randomcolor);
					}
				}
				//Row 3(Bottom) Column 4(Right Edge) Corner
				if((110 > blahX) && (blahX > 80)){
					if((260 > blahY) && (blahY > 220)){
						TouchR3C4++;
						randomcolor = convertColor(Random() % 255,Random() % 255,255);
						LCD_DrawFilledRect(240, 160, 80, 80, randomcolor);
					}
				}
				secondfac = 1;
				}			

			yValold = yVal;
			}
			printf("xVal:%d     yVal:%d     \nxPos:%d     yPos:%d    ", xVal, yVal, blahX, blahY);
}

void Print_TouchCoords(void){
//    int temp;
//    temp = Touch_GetCoords();
   
//    LCD_Goto(0,0);
//    printf("xVal = %d  \nyVal = %d   \n%d", temp.x, temp.y, n);
    
}


