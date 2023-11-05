#include "StdTypes.h"
#include "Utils.h"
#include "Padel.h"
#include "LCD_Interface.h"
#include "DIO_Interface.h"
#include "Hamoksha_Story.h"

/****************GVARS & CHARS & FLAGS*********/
extern u8 end_padel_flag;
extern u8  Hamoksha[8] ;
extern u8 score1;
extern u8 score2;
u8 display_flag=0;

u8 Hamoksha_Dance1[8] = {
	0B00100,
	0B01010,
	0B10100,
	0B01110,
	0B00101,
	0B00100,
	0B01110,
	0B10001
};

u8 Hamoksha_Dance2[8] = {
	0B00100,
	0B01010,
	0B00101,
	0B01110,
	0B10100,
	0B00100,
	0B01110,
	0B10001
};

u8 heart[] = {
	0B00000,
	0B00000,
	0B11011,
	0B11111,
	0B11111,
	0B01110,
	0B00100,
	0B00000
};
/**************************************/
void story_Init(void)
{
	DIO_Init();
	LCD_Init();
	LCD_CustomerChar(HAMOKSHA,Hamoksha);
	LCD_CustomerChar(HAMOKSHA_DANCE1,Hamoksha_Dance1);
	LCD_CustomerChar(HAMOKSHA_DANCE2,Hamoksha_Dance2);
	LCD_CustomerChar(HEART,heart);
}

void story_Runnable(void)
{
	if (display_flag==0)
	entrance_display();
	else if (display_flag==1)
	speach();
	else if (display_flag==2)
	party();
	else if (display_flag==3)
	speach2();
	else if (display_flag==4)
	{
		static u16 c=1;
		
		Padel_Runnable();
		if (c==1)
		{
			LCD_GoTo(4,0);
			LCD_WriteString("p1:          p2:");
		}
		c++;
		
		if (end_padel_flag)
		{
			LCD_Clear();
			display_flag=5;
			c=1;
			score1=0;
			score2=0;
		}
	}
	else if (display_flag==5)
	game_res();
	else if (display_flag==6)
	speach3();
	
	
	
	
}

void entrance_display(void)
{
	LCD_WriteChar(HAMOKSHA);
	LCD_GoTo(1,3);
	LCD_WriteString("    Hello!      ");
	LCD_GoTo(2,1);
	_delay_ms(500);
	LCD_WriteString("This is Hamoksha. ");
	LCD_WriteChar(4);
	LCD_GoTo(3,1);
	_delay_ms(500);
	LCD_WriteString("I'll talk with you");
	LCD_GoTo(4,1);
	LCD_WriteString("about my Story.");
	_delay_ms(2000);
	LCD_Clear();
	display_flag=1;
}

void speach(void)
{
	LCD_WriteString("After my graduation ");
	LCD_GoTo(2,0);
	_delay_ms(500);
	LCD_WriteString("from faculty of");
	LCD_GoTo(3,0);
	_delay_ms(500);
	LCD_WriteString("Engineering idecided");
	LCD_GoTo(4,0);
	LCD_WriteString("to have some fun.");
	_delay_ms(2000);
	LCD_Clear();
	
	LCD_WriteString("so i made a party  ");
	LCD_GoTo(2,0);
	_delay_ms(500);
	LCD_WriteString("with my friends ");
	LCD_GoTo(3,0);
	_delay_ms(500);
	LCD_WriteString("celebrating the end");
	LCD_GoTo(4,0);
	LCD_WriteString("of this journey.");
	_delay_ms(2000);
	LCD_Clear();
	display_flag=2;
}

void party(void)
{
	static u8 c=1;
	if(c==1)
	{
		LCD_WriteString("  Hamoksha's Party");
		_delay_ms(500);
	}
	party_dis(HAMOKSHA);
	party_dis(HAMOKSHA_DANCE1);
	party_dis(HAMOKSHA);
	party_dis(HAMOKSHA_DANCE2);
	c++;
	if (c%6==0)
	{
		LCD_Clear();
		display_flag=3;
		c=1;
	}
	
}

void party_dis(u8 adress)
{
	LCD_GoTo(2,8);
	LCD_WriteChar(adress);
	LCD_WriteChar(adress);
	LCD_WriteChar(adress);
	LCD_GoTo(4,8);
	LCD_WriteChar(adress);
	LCD_WriteChar(adress);
	LCD_WriteChar(adress);
	_delay_ms(100);
	
	LCD_GoTo(2,8);
	LCD_WriteChar(' ');
	LCD_WriteChar(' ');
	LCD_WriteChar(' ');
	LCD_GoTo(4,8);
	LCD_WriteChar(' ');
	LCD_WriteChar(' ');
	LCD_WriteChar(' ');
	_delay_ms(100);
}

void speach2(void)
{
	LCD_WriteString("After this great ");
	LCD_GoTo(2,0);
	_delay_ms(500);
	LCD_WriteString("party i went to play");
	LCD_GoTo(3,0);
	_delay_ms(500);
	LCD_WriteString("padel with my friend ");
	LCD_GoTo(4,0);
	LCD_WriteString("7azal2oom ");
	_delay_ms(2000);
	LCD_Clear();
	display_flag=4;
}

void game_res(void)
{
	LCD_WriteString("The winner is ......");
	LCD_GoTo(4,5);
	_delay_ms(1000);
	
	if (end_padel_flag==1)
	{
		LCD_WriteString("Hamoksha ");
		LCD_WriteChar(HEART);
		_delay_ms(2000);
		LCD_Clear();
		
		LCD_WriteString("i was very glad to");
		LCD_GoTo(2,0);
		_delay_ms(500);
		LCD_WriteString("win the game between");
		LCD_GoTo(3,0);
		_delay_ms(500);
		LCD_WriteString("me and 7azal2oom");
		LCD_GoTo(4,0);
		LCD_WriteString("it was a nice game.");
		LCD_WriteChar(HEART);
		_delay_ms(2000);
		LCD_Clear();
	}
	
	
	else if (end_padel_flag==2)
	{
		LCD_WriteString("7azal2oom ");
		LCD_WriteChar(HEART);
		_delay_ms(2000);
		LCD_Clear();
		
		LCD_WriteString("although i lost this");
		LCD_GoTo(2,0);
		_delay_ms(500);
		LCD_WriteString("game between me and");
		LCD_GoTo(3,0);
		_delay_ms(500);
		LCD_WriteString("7azal2oom, it was a");
		LCD_GoTo(4,0);
		LCD_WriteString("nice game.");
		LCD_WriteChar(HEART);
		LCD_WriteChar(HEART);
		LCD_WriteChar(HEART);
		_delay_ms(2000);
		LCD_Clear();
	}
	display_flag=6;
	end_padel_flag=0;
}

void speach3(void)
{
	LCD_WriteString("After spending such");
	LCD_GoTo(2,0);
	_delay_ms(500);
	LCD_WriteString("great time, i wanted");
	LCD_GoTo(3,0);
	_delay_ms(500);
	LCD_WriteString("to join NTI, so i ");
	LCD_GoTo(4,0);
	LCD_WriteString("worked very hard to  ");
	_delay_ms(2000);
	LCD_Clear();
	
	LCD_WriteString(" be selected.");
	LCD_GoTo(2,0);
	_delay_ms(500);
	LCD_WriteString("And here i'm talking");
	LCD_GoTo(3,0);
	_delay_ms(500);
	LCD_WriteString("with you from NTI ");
	LCD_GoTo(4,0);
	LCD_WriteString("through my 1st proj.");
	_delay_ms(2000);
	LCD_Clear();
	
	LCD_WriteString("Thanks for your");
	LCD_GoTo(2,0);
	_delay_ms(500);
	LCD_WriteString("time i appreciate");
	LCD_GoTo(3,0);
	_delay_ms(500);
	LCD_WriteString("your interest.");
	LCD_GoTo(4,6);
	for (u8 k=0;k<6;k++)
	{
		LCD_WriteChar(HEART);
		_delay_ms(50);
	}
	_delay_ms(1500);
	LCD_Clear();
	display_flag=0;
}