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

void MovingColorBars(){
    LCD_DrawPixelRGB(x, y, 0, 0, 255);
    LCD_DrawPixelRGB(x+30, y, 0, 255, 0);
    LCD_DrawPixelRGB(x+60, y, 255, 0, 0);

    x++;
    y++;
    if (x > 320) { x = 0; };
    if (y > 240) { y = 0; };    
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


