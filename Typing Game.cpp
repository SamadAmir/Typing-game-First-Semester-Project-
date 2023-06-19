#ifndef _INC_INTRO
#define _INC_INTRO


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
#include<time.h>
#include<fcntl.h>
#include<unistd.h>
#include<dos.h>


void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Intro(){
	const char *txt = " TYPING TUTOR";
int x = 39;
int c = 22;
	for(int j=0;j<x-1;j++){
		gotoxy(x-j,10);
		printf("%c",c);
		gotoxy(x+j,10);
		printf("%c",c);
		usleep(25000);
	}

	for(int i = 0;i<9;i++){
		for(int j=0;j<x-1;j++){
			gotoxy(x-j,9-i);
			printf("%c",c+2);
			gotoxy(x+j,9-i);
			printf("%c",c+2);
			gotoxy(x-j,9+i);
			printf("%c",c+3);
			gotoxy(x+j,9+i);
			printf("%c",c+3);
		}
		usleep(30000);
		for(int k=0;k<x-1;k++){
			gotoxy(x-k,9-i);
			printf(" ");
			gotoxy(x+k,9-i);
			printf(" ");
			gotoxy(x-k,9+i);
			printf(" ");
			gotoxy(x+k,9+i);
			printf(" ");
			}	
		
	}		
		for(int l=0;l<x;l++){
		gotoxy(x-l,1);
		printf("%c",c);
		gotoxy(x+l,1);
		printf("%c",c);
		gotoxy(x-l,17);
		printf("%c",c);
		gotoxy(x+l,17);
		printf("%c",c);
		}

for(int j=0;j<9;j++){
		gotoxy(x,10-j);
		printf("%c",c);
		gotoxy(x,10+j-1);
		printf("%c",c);
		usleep(25000);
	}

for(int i = 0;i<x-1;i++){
		for(int j=0;j<8;j++){
			gotoxy(x-i,9-j);
			printf("%c",c+5);
			gotoxy(x+i,9-j);
			printf("%c",c+4);
			gotoxy(x-i,9+j);
			printf("%c",c+5);
			gotoxy(x+i,9+j);
			printf("%c",c+4);
		}
		usleep(25000);
		for(int k=0;k<8;k++){
			gotoxy(x-i,9-k);
			printf(" ");
			gotoxy(39-i,8);
			printf("%c",txt[6-i]);
			gotoxy(x+i,9-k);
			printf(" ");
			gotoxy(x-i,9+k);
			printf(" ");
			if(i <8){
			gotoxy(39+i,8);
			printf("%c",txt[6+i]);}
			gotoxy(x+i,9+k);
			printf(" ");
			}	
		
	}		

	for(int l=0;l<9;l++){
		gotoxy(1,9-l);
		printf("%c",c);
		gotoxy(77,9-l);
		printf("%c",c);
		gotoxy(1,9+l);
		printf("%c",c);
		gotoxy(77,9+l);
		printf("%c",c);
		}

gotoxy(0,19);
 printf("PRESS ANY KEY TO CONTINUE ...");
 getch();
}

#endif


static int x=1;//used for x cursor co-ordinate

#define pos gotoxy(33,x++) /*for cursor movement*/

#define ln  printf(".......................");
//.......................................................................................................................................................................
//.......................................................................................................................................................................
void delay(unsigned int mseconds)//function for delay
{
    clock_t goal=mseconds+clock();
    while(goal>clock());
}

int a = 0 ; // one time call
//.............................................................................................................................................................................
void setcolor(int ForgC) //function to change setcolor
 {
 WORD wColor;

  HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO csbi;

                       //We use csbi for the wAttributes word.
 if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
 {
                 //Mask out all but the background attribute, and add in the forgournd color
      wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
      SetConsoleTextAttribute(hStdOut, wColor);
 }
 return;
 }
//.................................................................................................................................................................................
void sett();//sets time limit for playing game
int t=30;
int c=0;
char name[15];
void getscore(int score,int speed,int level);
void startgame();  //to start the game
void scorecard();  //to update high score
void About_me();
void help();
//...............................................................................................................................................................................
void rectangle(int x,int y,int l,int b)//to create a rectangle
{
    int i,m;
    gotoxy(x,y);
	 printf("%c",201);
    for(i=x+1;i<l-1;i++)
    {
        gotoxy(i,y);
        printf("%c",205);
    }
    gotoxy(i,y); printf("%c",187);
    for (m=y+1;m<b;m++)
    {
        gotoxy(x,m);
        for(i=x;i<l;i++)
        {
            if(i==x||i==l-1)
            {
                gotoxy(i,m); printf("%c",186);
            }

        }

    }

    gotoxy(x,m); printf("%c",200);
    for(i=x+1;i<l-1;i++)
    {
        gotoxy(i,m);
        printf("%c",205);
    }
    gotoxy(i,m); printf("%c",188);
}

//................................................................................................................................................................................
//			main function

int main()
{	system("COLOR ");
	if ( a== 0)
	{
	Intro();
	a++;
	}
    
	int ch;
	time_t t;
	time(&t);
	x=1;
	system("cls");
	pos;
	setcolor(15) ;//color of welcome to typing game
	printf("welcome to typing game ");
	setcolor(207) ;//color of time
	pos;
	printf("%s",ctime(&t));
	pos;
    ln pos;
	if(c==0)
	   {	printf("Enter player's name::");
		    gets(name);
	   }
	   c++;
	pos;
	ln pos;
		printf("#..MAIN MENU..#");
		pos;
		ln
		pos;
		printf("1.startgame");
		pos;
		printf("2.scorecard");
		pos;
		printf("3.Set the time limit::");
		pos;
		printf("4.Help");
		pos;
		printf("5.About me");
		pos;
		printf("0.exit");
		pos;
		printf("Enter your choice::");
		scanf("%d",&ch);
		pos;
		switch(ch)
		{       case 1:startgame();break;
			case 2:scorecard();break;
			case 3:sett();main();
			case 4:help();break;
			case 5:About_me();break;
			case 0:system("cls");gotoxy(17,10);
			printf("Thanks for Playing !!");delay(1000);exit(1);
			default:main();
		}

getch();
}
//.....................end of main function.................................

			   //startgame
//..........................................................................
void startgame()
{       int score=0,level=1,mode=32,count=0;
        clock_t begin;
	    int time_spent,speed;
		int r,letter,ch;
        rectangle(0,0,70,15);
	    delay(500);

	system("cls");
	srand(time(NULL)); //initilizes random function and speed with time
	x=2;
	pos;
	setcolor(15);
	printf("#select the Mode#");
	pos;
	ln
	pos;
	printf("1.Easy mode#");
	pos;
	printf("2.Normal mode#");
	pos;
	printf("3.hard mode#");
	pos;
	printf("4.Back to main menu#");
	pos;
	scanf("%d",&level);
	if(level==4)
	main();

	else

	{     if(level==1)    //boundary addition for uppercase alphabet
	       mode=65;
	     if(level==2)    //boundary addition for lowercase
		mode=97;
	     if(level==3)    //condition for mixed case
		mode=32;
		
		begin=clock();
		//mode is for difficulty level
		while(1)
		{       system("cls");
			time_spent=(int)(clock()-begin)/CLOCKS_PER_SEC;
			if(time_spent>=t)
			break;
			r=rand()%100;
			r=r%26+mode;
			gotoxy(20,8);
			printf("....Type the following character....");
			gotoxy(36,11) ;
			printf(" %c",r); //prints random character

			letter=getch();

			if(letter!=r)
			break;
			else
			{       count++;
				score=score+10;
				gotoxy(28,9);
				printf("score=%d",score);//prints score
				gotoxy(37,9);
				printf("time_spent=%d sec",time_spent);//prints time spent during game

				if(level==1)
				delay(400);
				if(level==2)
				delay(200);
				if(level==3)
				delay(100);

			} //end of else
		}//end of while
		gotoxy(26,x);

		delay(400);

		setcolor(5); //blue text color
		++x;
		pos;
		speed=(count*60)/time_spent ;
	       //	symbol=2;
		if(time_spent<t-1)
		printf("Game Over ! Better luck next time");
		else
		{       setcolor(11);
			printf("Times up !Game over! Improve your speed Dude!");
			pos;
			setcolor(5);
			if((speed>=40)&&(speed<=50))
			{	printf("Good Work !Keep it up!");pos;

				printf("You got silver medal");
			}
			else
			if(speed>50)
			{
				printf("Nice work! You got Gold medal");
			}
			else
			printf("Huh! You got nothing ! Improve please..");
		}
		pos;
		printf("Total score is ::%d",score);
		pos;

		printf("Your net speed=%d letter per minute",speed);

		getscore(score,speed,level);//saves data to file
		++x;
		pos;
		printf("1.# play again #");
		pos;

		printf("2.# main menu #");pos;
		printf("3.exit"); pos;
		printf("Enter your choice::");
		scanf("%d",&ch);
		switch(ch)
		{
		      case 1:startgame();break; //recursive call
		      case 2:main(); break;
		      case 3:system("cls");gotoxy(17,10);printf("Thanks for Playing !");delay(1000);exit(1);
		      default:pos;printf("wrong choice!");pos;
				main();
		}

	}

}
//......................end of start game function..........................
//...........................sett function starts..........................
void sett()  //set time limit
{
	int ch;
	system("cls");
	//rectangle(0,0,70,15);
	setcolor(11);
	x=5;
	pos;
	printf("Set the time limit for game in minute::");
	pos;
	ln
	pos;
	printf("press 0 for half minute") ;pos;
	printf("press 1 for 1 minute"); pos;
	printf("press 2 for 2 minute");pos;
	scanf("%d",&ch);
	switch(ch)
	{
		case 0:t=30;break;
		case 1:t=60;break;
		case 2:t=120;break;
		default:main();
	}
}
//....................sett function ends....................................
//........................................................................
void help()
{
	system("cls");
//	rectangle(0,0,70,15);
	gotoxy(7,5);
	setcolor(6);
	printf("#......Rules of the Game......#");gotoxy(7,6);
	printf("=>Enter your name as player name");gotoxy(7,7);
	printf("=>Set the time limit under option 3 in main menu(default limit is 30 sec)");gotoxy(7,8);
	printf("=>select the level and get started :");gotoxy(7,9);
	printf("=>Characters are displayed and you have to type them as fast as you can..");gotoxy(7,10);
	printf("=>Avoid incorrect typing otherwise game will be over..");
	getch();
	main();
}
void About_me()
{       system("cls");
	printf("INTRODUCTION\n");
	printf("============\n");
	printf("Hello This is Samad here and presenting you my first semester project on C language :) totally beginner here so  ignore the mistakes lol :D");
       getch();
       main();
}
//.........................................................................
void getscore(int score,int speed,int level)
{
	FILE *fp;
	fp=fopen("file.txt","a");
	pos;
	if(fp==NULL)
	printf("error in opening file");
	fprintf(fp,"\nname=%s   score=%d    speed=%d    level=%d",name,score,speed,level);
	fclose(fp);
	pos;
	printf("scorecard updated");
}
void scorecard()
{      
	 int ch;
	FILE *fp;
	system("cls");
	//rectangle(0,0,70,15);
	
	x=3;
	printf("\t\t\t....The scores are...\n");
	fp=fopen("file.txt","r");
	while((ch=fgetc(fp))!=EOF)
	{	
		printf("%c",ch);
	}
	getch();
	main();
}
