#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
#include <ctime>
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
using namespace std;
bool gameover;
int height=25,width=35;
int headX,headY,fruitX,fruitY,score=0;
int tailX[100],tailY[100],taillength=0;
enum direction {
	STOP=0,LEFT,RIGHT,UP,DOWN
};
direction dir;
void setup()
{
	srand(time(NULL));
	gameover=false;
	dir=STOP;
	headX=width/2;
	headY=height/2;
	fruitX = rand() % width;
    fruitY = rand() % height;
}
void looks()
{
	int i,j;
	system("cls");
    for(i=0;i<width+2;i++) cout << "#"; cout << endl;
    for(i=0;i<height;i++)
    {
        for(j=0;j<width;j++)
        {
            if(j==0) cout << "#";
            if (i==headY && j==headX) cout << "O";
            else if (i==fruitY && j==fruitX) cout << "F";
            else 
            {
            	int printflag=0;
            	for(int w=0;w<taillength;w++)
            	{
            		if(tailX[w]==j && tailY[w]==i) {
            			printflag=1;
            			cout<<"o";
					}
				}
				if(printflag==0) cout<<" ";
			}
            if (j==width-1) cout << "#";
        }
        cout << endl;
    }
 
    for (i=0;i<width+2;i++) cout << "#";
    cout<<endl;
    cout<<"\nScore:"<<score<<endl;
}
void inputs()
{
	if(_kbhit())
	{
		switch(_getch())
		{
			case 'a':
			case KEY_LEFT:
				dir = LEFT;
				break;	
			case 'w':
			case KEY_UP:
				dir = UP;
				break;		
			case 's':	
			case KEY_DOWN:
				dir = DOWN;
				break;	
			case 'd':
			case KEY_RIGHT:
				dir = RIGHT;
				break;	
			case 'x':
				gameover=true;
				break;		
		}
	}
}
void logic()
{
	int prevX=tailX[0];
	int prevY=tailY[0];
	tailX[0]=headX;
	tailY[0]=headY;
	int prevXX,prevYY,i;
	for(i=1;i<taillength;i++)
	{
		prevXX=tailX[i];
		prevYY=tailY[i];
		tailX[i]=prevX;
		tailY[i]=prevY;
		prevX=prevXX;
		prevY=prevYY;
	}
	switch (dir)
    {
    case LEFT:
        headX--;
        break;
    case RIGHT:
        headX++;
        break;
    case UP:
        headY--;
        break;
    case DOWN:
        headY++;
        break;
    default:
        break;
    }
	if(headX>width || headX<0 || headY>height || headY<0) gameover=true;
	for(i=0;i<taillength;i++) if(headX==tailX[i] && headY==tailY[i]) gameover=true;
	if(headX==fruitX && headY==fruitY){
		score+=10;
		fruitX = rand() % width;
    	fruitY = rand() % height;
    	taillength++;
	} 
}

int main(){
	setup();
	while(!gameover)
	{	
		looks();	
		inputs();
		logic();
		Sleep(20);
	}
	cout<<"\n\n\n!!!!GAME OVER!!!!\n\n\n";
	return 0;
}
