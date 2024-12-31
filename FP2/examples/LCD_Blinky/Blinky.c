/*----------------------------------------------------------------------------
 * Name:    Blinky.c
 * Purpose: LED Flasher and Graphic Demo
 * Note(s): 
 *----------------------------------------------------------------------------
 * This file is part of the uVision/ARM development tools.
 * This software may only be used under the terms of a valid, current,
 * end user licence from KEIL for a compatible version of KEIL software
 * development tools. Nothing else gives you the right to use this software.
 *
 * This software is supplied "AS IS" without warranties of any kind.
 *
 * Copyright (c) 2008-2011 Keil - An ARM Company. All rights reserved.
 *----------------------------------------------------------------------------*/
                  
#include <LPC17xx.H>                    /* NXP LPC17xx definitions            */
#include "string.h"
#include "GLCD.h"
#include "LED.h"
#include <stdio.h>
#include "KBD.h"
#include "type.h"
#include "images.h"
#include <stdlib.h>
#include "usb.h"
#include "usbcfg.h"
#include "usbhw.h"
#include "usbcore.h"
#include "usbaudio.h"

#define __FI        1                      /* Font index 16x24               */
#define DEL_DN		20

extern unsigned char ClockLEDOn;
extern unsigned char ClockLEDOff;
extern unsigned char ClockANI;


//GAME GLOBALS
int ranum;
int i=0;
int raFlag = 0;
int endFlag = 100;
int cvsheight = 210;
int cvswidth = 240;


int temp = 0;
int selector = 0;


	int gravity = 10;
  int bY=0;
  int bX=100;
  int rockX=120;
  int rockY=150;
  int counter=100;
  int score=0;
  int ballheight=30;
	int ballwidth=29;
  int rockheight=60;
	int rockwidth=57;


void delay(int g){
int p,b;
int i = 0;
for (p = 0; p < g; p++){
b = p+1;
}
}

int delayUntilRi(){
  int p,b;
	while(get_button() !=  KBD_RIGHT){
		if(get_button() ==  KBD_DOWN){
		return(1);
		}
			b = p+1;
		
	}
	return(2);
}

void playAudio(){
while(get_button() != KBD_DOWN){
	GLCD_Clear  (White);
    GLCD_SetBackColor(Blue);
    GLCD_SetTextColor(Yellow);
    GLCD_DisplayString(0, 0, 1, "Note-ify  ");
		usbmain();

}
return;

}

void playGame1(){
		GLCD_Clear  (Black);
		GLCD_DisplayString(0, 0, 1, "Mitt Hit!     ");
		ranum = (rand() % (5 - 1 + 1) + 1);
		
	  while (get_button() !=  KBD_DOWN){
			for(i=0; i<ranum; i++ ){
		GLCD_Bitmap (  80,   50, 150,  113, MHS_PIXEL_DATA); //x then y
		delay(30000);
			}
			raFlag = (rand() % (3 - 2 + 1) + 2);
			switch (raFlag){
				case 2:
					GLCD_Clear  (Black);
					for(i=0; i<endFlag; i++){//endFlag originally 100 loops difficulty
					GLCD_DisplayString(0, 0, 1, "RIGHT!      ");
					GLCD_Bitmap (  80,   50, 150,  87, MHR_PIXEL_DATA); //x then y
					delay(30000);
						if(get_button() ==  KBD_RIGHT){
							GLCD_SetBackColor(White);
							GLCD_SetTextColor(Blue);
							GLCD_DisplayString(0, 0, 1, "GOOD!      ");
							GLCD_Bitmap (  80,   50, 150,  89, MHRH_PIXEL_DATA); //x then y
							delay(30000000);
							endFlag-=20;
						break;
						} 
						else if(i == (endFlag-1)){
							GLCD_SetBackColor(White);
							GLCD_SetTextColor(Blue);
							GLCD_DisplayString(0, 0, 1, "MISSED! TRY HARDER      ");
							GLCD_DisplayString(1, 0, 1, "-END OF GAME-      ");
							GLCD_Bitmap (  80,   50, 150,  113, MHW_PIXEL_DATA); //x then y
							delay(30000000);
							endFlag=100; //reset difficulty for future replay
							return;
						}
					}
					break;
				case 3:
				GLCD_Clear  (Black);
				for(i=0; i<endFlag; i++){//endFlag originally 100 
					GLCD_DisplayString(0, 0, 1, "LEFT!      ");
					GLCD_Bitmap (  80,   50, 150,  88, MHL_PIXEL_DATA); 
					delay(30000);
					if(get_button() ==  KBD_LEFT){
							GLCD_SetBackColor(White);
							GLCD_SetTextColor(Blue);
							GLCD_DisplayString(0, 0, 1, "CORRECT!      ");
							GLCD_Bitmap (  80,   50, 150,  91, MHLH_PIXEL_DATA); //x then y
							delay(30000000);
							endFlag-=20;
						break;
						} 
						else if(i == (endFlag-1)){
							GLCD_SetBackColor(White);
							GLCD_SetTextColor(Blue);
							GLCD_DisplayString(0, 0, 1, "MISSED! TRY HARDER     ");
							GLCD_DisplayString(1, 0, 1, "-END OF GAME-      ");
							GLCD_Bitmap (  80,   50, 150,  113, MHW_PIXEL_DATA); //x then y
							delay(30000000);
							endFlag=100; //reset difficulty for future replay
							return;
						}
					}
				break;
			}
		}
		GLCD_Clear  (White); //down pressed
		
}

void showGalery(){
	
while(get_button() !=  KBD_DOWN){
    GLCD_Clear  (White);
    GLCD_SetBackColor(Blue);
    GLCD_SetTextColor(Yellow);
    GLCD_DisplayString(0, 0, 1, "The Very Hungry        ");
		GLCD_DisplayString(1, 0, 1, "    Caterpillar    ");
    GLCD_Bitmap (  100,   50, 150, 112, TVHCPG1_PIXEL_DATA); //x then y
    temp=delayUntilRi();
		if(temp==1)
			return;
    GLCD_Clear  (White);
		GLCD_DisplayString(0, 0, 1, "The Very Hungry    ");
		GLCD_DisplayString(1, 0, 1, "    Caterpillar    ");
    GLCD_Bitmap (  100,   50, 150, 112, TVHCPG2_PIXEL_DATA);
    temp=delayUntilRi();
		if(temp==1){
			temp=0;
			return;
		}
    GLCD_Clear  (White);
		GLCD_DisplayString(0, 0, 1, "The Very Hungry    ");
		GLCD_DisplayString(1, 0, 1, "    Caterpillar    ");
    GLCD_Bitmap (  100,   50, 150, 112, TVHCPG3_PIXEL_DATA);
    temp=delayUntilRi();
		if(temp==1){
			temp=0;
			return;
		}
    GLCD_Clear  (White);
		GLCD_DisplayString(0, 0, 1, "The Very Hungry    ");
		GLCD_DisplayString(1, 0, 1, "        Caterpillar        ");
    GLCD_Bitmap (  100,   50, 150, 112, TVHCPG4_PIXEL_DATA);
    temp=delayUntilRi();
		if(temp==1){
			temp=0;
			return;
		}
		GLCD_Clear  (White);
		GLCD_DisplayString(0, 0, 1, "The Very Hungry    ");
		GLCD_DisplayString(1, 0, 1, "    Caterpillar    ");
    GLCD_Bitmap (  100,   50, 150, 113, TVHCPG5_PIXEL_DATA);
    temp=delayUntilRi();
		if(temp==1){
			temp=0;
			return;
		}
    }
		GLCD_Clear  (White);

}


int checkCol(){
  //returns 1 if collission occurs
  if((bX-ballwidth)<=(cvswidth+ballwidth-5) && (bY<=(rockY+ballwidth-5)) && (bY>=rockY-rockwidth+15))
  return 1;
  else {
    return 0;
  }
}

void nextLvl(){
  score++;
  bY=(rand() % (30 - (cvsheight-ballwidth) + 10) + 50);
  bX=240;
  gravity-=5;
}

void playGame2(){
  
  GLCD_Clear  (Black);
  GLCD_DisplayString(0, 0, 1, "Rocket Steer");
  while(get_button() !=  KBD_SELECT){
      // redraw background, rocket and the asteroid

          GLCD_Clear  (Black);
          GLCD_Bitmap (  rockX,   rockY, 60,  57, REDROCKET3_PIXEL_DATA); //x then y
          GLCD_Bitmap (  bX,   bY, 30,  29, ASTEROID_PIXEL_DATA); //x then y
          delay(300000);
         // GLCD_DisplayString(0, 0, 1, "SCORE: ", score);//

            if(checkCol()==1){
              //SHOW YOU LOST
              GLCD_SetBackColor(White);
              GLCD_SetTextColor(Blue);
              GLCD_DisplayString(1, 0, 1, "HIT!      ");
              GLCD_DisplayString(2, 0, 1, "-GAME OVER-      ");
             // GLCD_DisplayString(3, 0, 1, "Final Score: ", score);
              delay(30000000);
              endFlag=100; //reset difficulty for future replay
							 raFlag = 0;
							 bX=0;
							 rockX=120;
							 rockY=150;
							 score=0;
							counter=100;
              return;
            }else if((bX-ballwidth)==cvswidth){
              nextLvl();
            }
            if((get_button() ==  KBD_UP) && rockY!=230){
              rockY-=5;
            }else if((get_button() ==  KBD_DOWN) && rockY!=0){
            rockY+=5;
            }
            bX -= gravity;
      }
		GLCD_Clear  (White); //down pressed
    //return;
}
////////////////END OF GAME 2


	void selectorChoose(char inc){
	if (selector==0 && inc=='p'){
	selector=1;//gal
	GLCD_SetBackColor(White);
  GLCD_SetTextColor(Blue);
	GLCD_DisplayString(5, 0, 1, ">Read Book  ");
  GLCD_DisplayString(6, 0, 1, " Note-ify  ");
	GLCD_DisplayString(7, 0, 1, " Mitt Hit!       ");
	GLCD_DisplayString(8, 0, 1, " Rocket Steer!");
	}
	if (selector==1 && inc=='p'){
	selector=2;//aud
	GLCD_SetBackColor(White);
  GLCD_SetTextColor(Blue);
	GLCD_DisplayString(5, 0, 1, " Read Book  ");
  GLCD_DisplayString(6, 0, 1, ">Note-ify  ");
	GLCD_DisplayString(7, 0, 1, " Mitt Hit!       ");
	GLCD_DisplayString(8, 0, 1, " Rocket Steer!");
}
	if (selector==2 && inc=='p'){
	selector=3;//game
	GLCD_SetBackColor(White);
  GLCD_SetTextColor(Blue);
	GLCD_DisplayString(5, 0, 1, " Read Book  ");
  GLCD_DisplayString(6, 0, 1, " Note-ify  ");
	GLCD_DisplayString(7, 0, 1, ">Mitt Hit!       ");
	GLCD_DisplayString(8, 0, 1, " Rocket Steer!");
	}
	if (selector==3 && inc=='p'){
	selector=4;//game 2
	GLCD_SetBackColor(White);
  GLCD_SetTextColor(Blue);
	GLCD_DisplayString(5, 0, 1, " Read Book  ");
  GLCD_DisplayString(6, 0, 1, " Note-ify  ");
	GLCD_DisplayString(7, 0, 1, " Mitt Hit!       ");
	GLCD_DisplayString(8, 0, 1, ">Rocket Steer!");
	}
  if (selector==4 && inc=='p'){
	selector=4;//game
	GLCD_SetBackColor(White);
  GLCD_SetTextColor(Blue);
	GLCD_DisplayString(5, 0, 1, " Read Book  ");
  GLCD_DisplayString(6, 0, 1, " Note-ify  ");
	GLCD_DisplayString(7, 0, 1, " Mitt Hit!       ");
	GLCD_DisplayString(8, 0, 1, ">Rocket Steer!");
	}
	if (selector==0 && inc=='m'){
	selector=0;
	GLCD_SetBackColor(White);
  GLCD_SetTextColor(Blue);
	GLCD_DisplayString(5, 0, 1, " Read Book  ");
  GLCD_DisplayString(6, 0, 1, " Note-ify  ");
	GLCD_DisplayString(7, 0, 1, " Mitt Hit!       ");
	GLCD_DisplayString(8, 0, 1, " Rocket Steer!");
	}
	if (selector==1 && inc=='m'){
	selector=1;
	GLCD_SetBackColor(White);
  GLCD_SetTextColor(Blue);
	GLCD_DisplayString(5, 0, 1, ">Read Book  ");
  GLCD_DisplayString(6, 0, 1, " Note-ify  ");
	GLCD_DisplayString(7, 0, 1, " Mitt Hit!       ");
	GLCD_DisplayString(8, 0, 1, " Rocket Steer!");
	}
	if (selector==2 && inc=='m'){
	selector=1;
	GLCD_SetBackColor(White);
  GLCD_SetTextColor(Blue);
	GLCD_DisplayString(5, 0, 1, " Read Book  ");
  GLCD_DisplayString(6, 0, 1, ">Note-ify  ");
	GLCD_DisplayString(7, 0, 1, " Mitt Hit!       ");
	GLCD_DisplayString(8, 0, 1, " Rocket Steer!");
	}
	if (selector==3 && inc=='m'){
	selector=2;
	GLCD_SetBackColor(White);
  GLCD_SetTextColor(Blue);
	GLCD_DisplayString(5, 0, 1, " Read Book  ");
  GLCD_DisplayString(6, 0, 1, ">Note-ify  ");
	GLCD_DisplayString(7, 0, 1, " Mitt Hit!       ");
	GLCD_DisplayString(8, 0, 1, " Rocket Steer!");
	}
  if (selector==4 && inc=='m'){
	selector=3;
	GLCD_SetBackColor(White);
  GLCD_SetTextColor(Blue);
	GLCD_DisplayString(5, 0, 1, " Read Book  ");
  GLCD_DisplayString(6, 0, 1, " Note-ify  ");
	GLCD_DisplayString(7, 0, 1, ">Mitt Hit!       ");
	GLCD_DisplayString(8, 0, 1, " Rocket Steer!");
	}

	}





/*----------------------------------------------------------------------------
  Main Program
 *----------------------------------------------------------------------------*/
int main (void) {                       /* Main Program                       */
  LED_Init ();
  GLCD_Init();
  KBD_Init();

	GLCD_Clear(White);                         /* Clear graphical LCD display   */
  GLCD_SetBackColor(Blue);
  GLCD_SetTextColor(Yellow);
  GLCD_DisplayString(0, 0, 1, " COE718                ");
	GLCD_SetTextColor(White);
  GLCD_DisplayString(1, 0, 1, " Final Project         ");
  GLCD_DisplayString(2, 0, 1, " Shadman Ahmed        ");
	GLCD_SetBackColor(White);
  GLCD_SetTextColor(Blue);

	GLCD_DisplayString(5, 0, 1, " Read Book  ");
  GLCD_DisplayString(6, 0, 1, " Note-ify  ");
	GLCD_DisplayString(7, 0, 1, " Mitt Hit!       ");
	GLCD_DisplayString(8, 0, 1, ">Rocket Steer!");

	//SysTick_Config(SystemCoreClock/100);

while(1){
//CHECK SELECTOR VALUES
	if (get_button() ==  KBD_DOWN){
	selectorChoose('p');
	}
		if (get_button() ==  KBD_UP){
	selectorChoose('m');
	}

	if (get_button() ==  KBD_SELECT){
//case
		switch (selector){
			case 1:
				if (get_button() ==  KBD_SELECT){
					LED_On(0);
					LED_On(1);
					LED_Off(2);
					LED_Off(3);
					LED_Off(4);
					LED_Off(5);
					GLCD_SetBackColor(White);
					GLCD_SetTextColor(Blue);
				GLCD_DisplayString(10, 0, 1, "Read Book  ");
				showGalery();
				GLCD_Clear  (White);
				}
				break;

			case 2:
				if (get_button() ==  KBD_SELECT){
					LED_On(2);
					LED_On(3);
					LED_Off(0);
					LED_Off(1);
					LED_Off(4);
					LED_Off(5);
					while(get_button() !=  KBD_DOWN){
					GLCD_Clear  (White);
					GLCD_DisplayString(6, 0, 1, " Note-ify              ");
					playAudio();
					}
					GLCD_Clear  (White);
					break;
				}
				break;
			case 3:
				if (get_button() ==  KBD_SELECT){
					LED_On(4);
					LED_Off(5);
					LED_Off(0);
					LED_Off(1);
					LED_Off(2);
					LED_Off(3);
					GLCD_Clear  (White);
					GLCD_SetBackColor(White);
					GLCD_SetTextColor(Blue);
				GLCD_DisplayString(1, 0, 1, "     Mitt Hit! ");
				GLCD_DisplayString(3, 0, 1, ">When Coach signals,");
				GLCD_DisplayString(4, 0, 1, "  hit that mitt!");
				GLCD_DisplayString(5, 0, 1, "> Response has");
				GLCD_DisplayString(6, 0, 1, "to be faster ");
				GLCD_DisplayString(7, 0, 1, "each round.");
					delay(30000000);//exactly 1s
				GLCD_DisplayString(8, 0, 1, "   -----3-----    ");
					delay(30000000);//exactly 1s
				GLCD_DisplayString(8, 0, 1, "    ----2----  ");
					delay(30000000);//exactly 1s
				GLCD_DisplayString(8, 0, 1, "      --1--  ");
					delay(30000000);//exactly 1s
				playGame1();
				GLCD_Clear  (White);
				}
				break;
        case 4:
  				if (get_button() ==  KBD_SELECT){
  					LED_On(5);
  					LED_Off(4);
  					LED_Off(0);
  					LED_Off(1);
  					LED_Off(2);
  					LED_Off(3);
  					GLCD_Clear  (White);
  					GLCD_SetBackColor(White);
  					GLCD_SetTextColor(Blue);
  				GLCD_DisplayString(1, 0, 1, "     Rocket Steer  ");
  				GLCD_DisplayString(3, 0, 1, "> Dodge the asteroid");
  				GLCD_DisplayString(5, 0, 1, "> Response has");
  				GLCD_DisplayString(6, 0, 1, "to be faster ");
  				GLCD_DisplayString(7, 0, 1, "each round.");
  					delay(30000000);//exactly 1s
  				GLCD_DisplayString(8, 0, 1, "   -----3-----    ");
  					delay(30000000);//exactly 1s
  				GLCD_DisplayString(8, 0, 1, "    ----2----  ");
  					delay(30000000);//exactly 1s
  				GLCD_DisplayString(8, 0, 1, "      --1--  ");
						delay(30000000);
  				playGame2();
  				GLCD_Clear  (White);
  				}
  				break;
		}
	}
		}


/******************************************************************************
**                            End Of File
******************************************************************************/
}