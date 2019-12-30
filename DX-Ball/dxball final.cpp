#include "iGraphics.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int m_x = 0, m_y = 0, score=0;
char sc[10];
int Page =1;
int SetTimer1;
int SetTimer2, SetTimer3, SetTimer4;
char Lf[10], Lv[10];
int T=0;
char Tm[10];
int Time=0;
int isPause=0;
int L=3;


/*
	function iDraw() is called again and again by the system.
*/


//int page =1;
int bar_x=430;
int bar_y=0;

void bar(){
	iSetColor(0,0,255);
	iFilledRectangle(bar_x,bar_y,100,16);
}


///Level 1 brick//
int br_x[]={70,121,172,223,274,325,376,427,478,529,580,631,682,733,784,835,121,172,223,274,325,376,427,478,529,580,631,682,733,784,172,223,274,325,376,427,478,529,580,631,682,733};
int br_y[]={550,550,550,550,550,550,550,550,550,550,550,550,550,550,550,550,524,524,524,524,524,524,524,524,524,524,524,524,524,524,498,498,498,498,498,498,498,498,498,498,498,498};
int b[42], g[42], r[42];
int fl[]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

//Level 2 brick//
int br_x2[]={121,172,223,274,325,376,427,478,529,580,631,682,733,784,70,121,172,223,274,325,376,427,478,529,580,631,682,733,784,835,172,223,274,325,376,427,478,529,580,631,682,733,223,274,325,376,427,478,529,580,631,682};
int br_y2[]={550,550,550,550,550,550,550,550,550,550,550,550,550,550,524,524,524,524,524,524,524,524,524,524,524,524,524,524,524,524,498,498,498,498,498,498,498,498,498,498,498,498,472,472,472,472,472,472,472,472,472,472};
int b2[52], g2[52], r2[52];
int fl2[]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};


int ball_x=430;
int ball_y=24;

void ball(){
	iSetColor(0,0,255);
	iFilledCircle(ball_x,ball_y,8,100);
}

int ballDirection =1,randomNumber;
void ballMovement(){
	//ball goes under
	if(ball_y <= -32){
		L--;
		ball_x=430;
		ball_y=50;
		//T=0;
		ballDirection=2;
		if(L==0){
		Page=3;
		iPauseTimer(SetTimer1);
		iPauseTimer(SetTimer2);
		}
		//exit(0);
		//
	}
	//bar hit
	if (ball_y==16){
		int ballMidpoint = ball_x;

		if(ballMidpoint >= bar_x && ballMidpoint <= bar_x+25){
			ballDirection =1;
		}
		else if(ballMidpoint >= bar_x+75 && ballMidpoint <= bar_x+100){
			ballDirection =2;
		}
		else if(ballMidpoint > bar_x+25 && ballMidpoint < bar_x+75){
			ballDirection=5;

		}
	}
	//
  if (ball_x <= 0){

	  if(ballDirection==1){
		  ballDirection=2;
	  }
	  else if(ballDirection==3){ 
		  ballDirection=4;
	  }
  }
	  else if(ball_x >= 960){

		  if (ballDirection==2){
			  ballDirection=1;
		  }
	  else if (ballDirection==4){
		  ballDirection=3;
	  }
}  //start of up
	  else if(ball_y >= 640){
		  randomNumber = rand() % 3+1;
		  if(randomNumber==1){
			  ballDirection=3;
		  }
		  else if(randomNumber == 2){
			  ballDirection=4; 
		  } 
		  else{
			  ballDirection =6;
		  }
	  }
	  //end of up
	  if(ballDirection==1){
		  ball_x -= 4;
		  ball_y += 4;
	  }
	  else if(ballDirection==2){
		  ball_x += 4;
		  ball_y += 4;
	  }
	  else if(ballDirection==3){
		  ball_x -= 4;
		  ball_y -= 4;
	  }
	  else if(ballDirection==4){
		  ball_x += 4;
		  ball_y -= 4;
	  }
	  else if(ballDirection==5){
		  ball_y += 4;
	  }
	  else if(ballDirection==6){
		  ball_y -= 4;
	  }
}

void timer()
{
	T++;
}


void ShowTime(){
	sprintf(Tm,"Time: %d", T);
	iText(850,450,Tm, GLUT_BITMAP_TIMES_ROMAN_24);
}

//level1
void collision()
{
	for(int i=0; i<42; i++){
		if(fl[i]==1 && ball_x+8>=br_x[i] && ball_x-8<=br_x[i]+50 && ball_y+8>=br_y[i] && ball_y-8<=br_y[i]+25){
			fl[i]=0;
			score+=(r[i]+g[i]+b[i])%10+2;

			if(score>20){
				Page =4;
				ball_x=430;
		        ball_y=24;
			}

			if(ballDirection == 1){
				ballDirection =4;
			}
			else if(ballDirection == 2){
			    ballDirection=3;
			}
			else if(ballDirection == 4){
			      ballDirection = 1;
				}
			else if (ballDirection ==3){
					ballDirection= 2;
			}
			else if (ballDirection ==5){
					ballDirection= 6;
			}
			else if (ballDirection ==6){
					ballDirection= 5;
			}
			
			
		}
	}
}

void collision2()
{
	for(int i=0; i<52; i++){
		if(fl2[i]==1 && ball_x+8>=br_x2[i] && ball_x-8<=br_x2[i]+50 && ball_y+8>=br_y2[i] && ball_y-8<=br_y2[i]+25){
			fl2[i]=0;
			score+=(r2[i]+g2[i]+b2[i])%10+2;

			//if(score>=250){
				//Page=4;

			if(ballDirection == 1){
				ballDirection =4 ;
			}
			else if(ballDirection == 2){
			    ballDirection=3;
			}
			else if(ballDirection == 3){
			      ballDirection = 2;
				}
			else if (ballDirection ==4){
					ballDirection= 1;
			}
			else if (ballDirection ==5){
					ballDirection= 6;
			}
			else if (ballDirection ==6){
					ballDirection= 5;
			}
		
		}
	}
}

//Level 1
void brick()
{
	int i;
	for(i=0; i<42; i++){
		iSetColor(r[i], g[i], b[i]);
		if(fl[i]==1)iFilledRectangle(br_x[i], br_y[i], 50, 25);
	}
	
}


//Level 2
void brick2()
{
	int i;
	for(i=0; i<52; i++){
		iSetColor(r2[i], g2[i], b2[i]);
		if(fl2[i]==1)iFilledRectangle(br_x2[i], br_y2[i], 50, 25);
	}
	
}



void ShowGameOver(){
	//if(Page==3){

        iRectangle(380,500,200,100);
		iText(400,550,"GAME OVER",GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(255,0,0);
		iRectangle(380,350,200,100);
		iSetColor(255,182,193);
		sprintf(sc,"Your score is: %d", score);
		iRectangle(380,200, 300, 100);
		iText(445,250, sc,GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(255,0,0);
		iText(400,400,"START AGAIN",GLUT_BITMAP_TIMES_ROMAN_24);

	//}
}

void ShowLife(){
	sprintf(Lf,"Life: 0%d", L);
	iSetColor(255,0,0);
	iText(850,420,Lf, GLUT_BITMAP_TIMES_ROMAN_24);
	//sprintf(Lv,"Level: 0%d", level);
	iSetColor(255,0,0);
	iText(1256,550,Lv, GLUT_BITMAP_TIMES_ROMAN_24);
}

void iDraw()
{
	iClear();
	if(Page==1){
		//iShowBMP(0,0,"Main page.bmp");
		iSetColor(52, 9,251 );
		iFilledRectangle(380,500,200,100);
		iSetColor(255,0,0);
		iText(445,550,"PLAY",GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(52,9,251);
		iFilledRectangle(380,350,200,100);
		iSetColor(255,0,0);
		iText(420,390,"TOP SCORE",GLUT_BITMAP_TIMES_ROMAN_24);
		iPauseTimer(SetTimer1);
		iPauseTimer(SetTimer2);
		
	}
	
	if(Page==2) {
	bar();
	ball();
	brick();
    ShowTime();
	ShowLife();
	sprintf(sc, "Score: %d", score);
	iSetColor(255,255,255);
	iText(850,480,sc, GLUT_BITMAP_TIMES_ROMAN_24);
	
	iPauseTimer(SetTimer4);
	iResumeTimer(SetTimer2);
	}

	if(Page==4){
	bar();
	ball();
	brick2();
    ShowTime();
	ShowLife();
	sprintf(sc, "Score: %d", score);
	iSetColor(255,255,255);
	iText(850,480,sc, GLUT_BITMAP_TIMES_ROMAN_24);

	iPauseTimer(SetTimer2);
	iResumeTimer(SetTimer4);
	}

	if(Page==3){

		ShowGameOver();
	}
	
}



/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
    //code
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	printf("Button Number %d %d\n", mx,my);
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if(mx>380 && mx<580 && my>500 && my<600 && Page==1){//Click on Play in Main Menu
			Page=2;
			L=3;
			
			ball_x=430;
			ball_y=24;
			T=0;
			ballDirection=1;
			score=0;
			for(int i=0; i<42; i++)fl[i]=1;
			iResumeTimer(SetTimer1);
			iResumeTimer(SetTimer2);
			iResumeTimer(SetTimer3);
		}
		if (mx>380 && mx <577 && my>353 && my<454 && Page==3){// Click on start in Game Over Screen
			
			L=3;
			Page=2;
			ball_x=430;
			ball_y=24;
			T=0;
			ballDirection=1;
			score=0;
			for(int i=0; i<42; i++)fl[i]=1;
			iResumeTimer(SetTimer1);
			iResumeTimer(SetTimer2);
			iResumeTimer(SetTimer3);
	    }
		if  (mx>380 && mx <577 && my>503 && my<600 && Page==3){// Click on  Game Over in Game Over Screen
			Page=1;

		}
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
}

/*
	function iPassiveMouseMove is called when user hovers the mouse pointer in the screen
	(mx,my) is the coordinate of mouse pointer
*/
void iPassiveMouseMove(int mx,int my){

}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	if(Page==2 && key=='p'){
		isPause++;
		if(isPause%2==0)
		{
			iResumeTimer(SetTimer1);
			iResumeTimer(SetTimer2);
			iResumeTimer(SetTimer3);
		}
		else
		{
			iPauseTimer(SetTimer1);
			iPauseTimer(SetTimer2);
			iPauseTimer(SetTimer3);
		}
	}
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{
		exit(0);
	}
	if((key == GLUT_KEY_DOWN)||(key == GLUT_KEY_PAGE_DOWN))
	{

	}
	if((key == GLUT_KEY_UP)||(key == GLUT_KEY_PAGE_UP))
	{

	}
	if(isPause%2==0 && key == GLUT_KEY_LEFT && bar_x >= 0)
	{
		bar_x-=16;
	}
	 else if(isPause%2==0 && key == GLUT_KEY_RIGHT && bar_x <= 850)
	{
		bar_x+=16;
	}
	//place your codes for other keys herek
}
void color1(){
int re, gr, bl, i; 
	re=rand()%256; gr=rand()%256; bl=rand()%256;
	for(i=0; i<16; i++){
		r[i]=re; b[i]=bl; g[i]=gr;
	}
	re=rand()%256; gr=rand()%256; bl=rand()%256;
	for(i=16; i<30; i++){
		r[i]=re; b[i]=bl; g[i]=gr;
	}
	re=rand()%256; gr=rand()%256; bl=rand()%256;
	for(i=30; i<42; i++){
		r[i]=re; b[i]=bl; g[i]=gr;
	}
}

void color2(){
int re1, gr1, bl1, i; 
	re1=rand()%256; gr1=rand()%256; bl1=rand()%256;
	for(i=0; i<14; i++){
		r2[i]=re1; b2[i]=bl1; g2[i]=gr1;
	}
	re1=rand()%256; gr1=rand()%256; bl1=rand()%256;
	for(i=14; i<30; i++){
		r2[i]=re1; b2[i]=bl1; g2[i]=gr1;
	}
	re1=rand()%256; gr1=rand()%256; bl1=rand()%256;
	for(i=30; i<42; i++){
		r2[i]=re1; b2[i]=bl1; g2[i]=gr1;
	}
	re1=rand()%256; gr1=rand()%256; bl1=rand()%256;
	for(i=42; i<52; i++){
		r2[i]=re1; b2[i]=bl1; g2[i]=gr1;
	}
}

int main()
{  
    color1();
	color2();
	SetTimer1=iSetTimer(8,ballMovement);
	SetTimer2=iSetTimer(1,collision);
	SetTimer4=iSetTimer(1,collision2);
	SetTimer3=iSetTimer(1000,timer);
	srand(time(NULL));
	iInitialize(960,640,"dx ball");
	return 0;
}
