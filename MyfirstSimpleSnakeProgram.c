#include<stdio.h>        
#include<windows.h>       
#include<stdlib.h>        
#include<conio.h>        
#include<time.h>
#include<unistd.h>


int gameover,score,flag;
void gotoxy();
void Welcome();
void Draw();
void Food();
void Logic();

struct coordinate
{
	int x;
	int y;
};
typedef struct coordinate coordinate;
coordinate food,snake;



int main()
{
	snake.x=45;
	snake.y=20;
	gameover=0;
	score=0;
	Welcome();
	Food();
	do
	{
		Draw();
		Logic();
	}
	while(gameover!=1);
	
}


void Logic()
{
	if(kbhit())
	{
		switch(getch())
		{
			case 'a':
				flag=1;
				break;
			case 's':
				flag=2;
				break;
			case 'd':
				flag=3;
				break;
			case 'w':
				flag=4;
				break;
			case 'x':
				break;
		}
	}
	
	sleep(0.01);
	switch(flag)
	{
		case 1:
			snake.x--;
			break;
		case 2:
			snake.y++;
			break;
		case 3:
			snake.x++;
			break;
		case 4:
			snake.y--;
			break;
		default:
			break;
	}
	
	
	if (snake.x<=20||snake.x>=70||snake.y<=10||snake.y>=30)
	gameover=1;
	
	if (snake.x==food.x&&snake.y==food.y)
	{
	
	    food.x=rand()%70;
	    if(food.x<=20)
	       food.x+=21;
	    food.y=rand()%30;
	    if(food.y<=10)
	       food.y+=11;
	    score+=10;
    }
	
}













void Food()
{
	time_t t;
	t=time(0);
	srand(t);
	food.x=rand()%70;
	if(food.x<=20)
	   food.x+=21;
	food.y=rand()%30;
	if(food.y<=10)
	   food.y+=11;
    if(food.x==0)
    {
        food.x=rand()%70;
        if(food.x<=20)
            food.x+=21;
        food.y=rand()%30;
        if(food.y<=10)
            food.y+=11;
    }
    
}


void Draw()
{
	system("cls");
	int i,j;
	for(i=10;i<=30;i++)
	{
		gotoxy(20,i);
		printf("|");
		gotoxy(70,i);
		printf("|");
	}
	for(j=20;j<=70;j++)
	{
		gotoxy(j,10);
		printf("_");
		gotoxy(j,30);
		printf("|");
	}
	gotoxy(20,9);
	printf("Score=%d",score);
	gotoxy(50,9);
	printf("Life=1");
	gotoxy(snake.x,snake.y);
	printf("0");
	gotoxy(food.x,food.y);
	printf("*");
	gotoxy(20,31);
	printf("Tap X to quit game");
}


void Welcome()
{
	int i,j;
	char a[10]="WELCOME";
	gotoxy(40,10);
	for(i=0;a[i]!='\0';i++)
	{
		for(j=0;j<=100000000;j++);
		printf("%c",a[i]);
	}
	
	for(i=0;i<=1000000000;i++);
	   {
	   	gotoxy(30,12);
	   	printf("Tay Any Key To Enter In The Game");
	   }
	   getch();
	   system("cls");
	   gotoxy(40,10);
	   printf("Loading.....");
	   gotoxy(40,11);
	   for(i=0;i<=10;i++)
	   {
	   	for(j=0;j<=100000000;j++);
	   	printf("%c",199);
	   }
	   system ("cls");
	   gotoxy(40,10);
	   printf("Tap Enter");
	   getch();
}


void gotoxy(int x,int y)
{
	HANDLE a;
	COORD b;
	b.X=x;
	b.Y=y;
	a=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(a,b);
}
