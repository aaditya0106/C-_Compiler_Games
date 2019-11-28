#include <iostream>
#include <bits/stdc++.h>
#include <cstdlib>
#include <conio.h>
#include <ctime>
using namespace std;
int board[4][4]={0}, score=0;
bool gameover=false;
enum direction 
{
	STOP=0,LEFT,RIGHT,UP,DOWN
};
direction dir;
bool checkFullBox()
{
	bool flag=true;
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(board[i][j]==0){ flag=false; break; }
		}
	}
	return flag;
}
int anyMoveLeft()
{
	int i,j,flag=1;
	for(i=0;i<4;i++){
		for(j=0;j<3;j++){
			if(board[i][j]==board[i][j+1]){
				flag=0;
				break;
			}
		}
		if(flag==0) break;
	}
	if(flag==1){
		for(i=0;i<3;i++){
			for(j=0;j<4;j++){
				if(board[i][j]==board[i+1][j]){
					flag=0;
					break;
				}
			}
			if(flag==0) break;
		}
	}
	return flag;
}
int randomIndex(int x)
{
	int index;
	index=rand()%x + 0;
	return index;
}
void generateNewIndex()
{
	int flag=1;
	if(!checkFullBox()){
		while(flag){
			int i=randomIndex(4);
			int j=randomIndex(4);
			if(board[i][j]==0){
				int y=rand()%10;
				if(y==6) board[i][j]=4;
				else board[i][j]=2;
				flag=0;
			}
		}
	}
}
void moveLeft()
{
	int i,j,k;
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			if(!board[i][j]){
				for(k=j+1;k<4;k++){
					if(board[i][k]){
						board[i][j]=board[i][k];
						board[i][k]=0;
						break;
					}
				}
			}
		}
	}
}
void moveRight()
{
	int i,j,k;
	for(i=0;i<4;i++){
		for(j=3;j>=0;j--){
			if(!board[i][j]){
				for(k=j-1;k>=0;k--){
					if(board[i][k]){
						board[i][j]=board[i][k];
						board[i][k]=0;
						break;
					}
				}
			}
		}
	}
}
void moveUp()
{
	int i,j,k;
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			if(!board[j][i]){
				for(k=j+1;k<4;k++){
					if(board[k][i]){
						board[j][i]=board[k][i];
						board[k][i]=0;
						break;
					}
				}
			}
		}
	}
}
void moveDown()
{
	int i,j,k;
	for(i=0;i<4;i++){
		for(j=3;j>=0;j--){
			if(!board[j][i]){
				for(int k=j-1;k>=0;k--){
					if(board[k][i]){
						board[j][i]=board[k][i];
						board[k][i]=0;
						break;
					}
				}
            }
        }
    }
}
void sumLeft()
{
	int i,j,k;
	for(i=0;i<4;i++){
		for(j=0;j<3;j++){
			if(board[i][j] && board[i][j]==board[i][j+1]){
				board[i][j]=board[i][j] + board[i][j+1];
				board[i][j+1]=0;
				score+=board[i][j];
			}
		}
	}
}
void sumRight()
{
	int i,j,k;
	for(i=0;i<4;i++){
		for(j=3;j>0;j--){
			if(board[i][j] && board[i][j]==board[i][j-1]){
				board[i][j]=board[i][j] + board[i][j-1];
				board[i][j-1]=0;
				score=score + board[i][j];
			}
		}
	}
}
void sumUp()
{
	int i,j,k;
	for(i=0;i<4;i++){
		for(j=0;j<3;j++){
			if(board[j][i] && board[j][i]==board[j+1][i]){
				board[j][i]=board[j][i] + board[j+1][i];
				board[j+1][i]=0;
				score+=board[j][i];
			}
		}
	}
}
void sumDown()
{
	int i,j,k;
	for(i=0;i<4;i++){
		for(j=3;j>0;j--){
			if(board[j][i] && board[j][i]==board[j-1][i]){
				board[j][i]=board[j][i] + board[j-1][i];
				board[j-1][i]=0;
				score+=board[j][i];
			}
		}
	}
}
int maxCheck()
{
	int i,j,max=0;
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			if(board[i][j]>max) max=board[i][j];
		}
	}
	return max;
}
void gameWin()
{
	cout<<"CONGRATULATIONS!!! YOU WON THE GAME!!!\n\n\n";
	cout<<"\t\t\tSCORE :: "<<score<<endl<<endl;
}
void gameLose()
{
	cout<<"OOPS!! YOU DIDN'T MAKE IT THIS TIME!! BETTER LUCK NEXT TIME!!!\n\n\n";
	cout<<"\t\t\t\tSCORE :: "<<score<<endl<<endl;
}
void setup()
{
	int i=randomIndex(4);
	int j=randomIndex(4);
	board[i][j]=2;
	i=randomIndex(4);
	j=randomIndex(4);
	board[i][j]=2;
}
void looks()
{
	int i,j;
	system("cls");
	cout<<"SCORE :: "<<score<<endl<<endl;
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			cout<<setw(8)<<board[i][j]<<setw(8)<<"|"<<setw(8);
		}
		cout<<endl<<endl<<endl;
	}
	cout<<"\n\n\n";
}
void inputs()
{
	char inp;
	cin>>inp;
	switch(inp)
	{
		case 'a':
			dir = LEFT;
			break;	
		case 'w':
			dir = UP;
			break;		
		case 's':	
			dir = DOWN;
			break;	
		case 'd':
			dir = RIGHT;
			break;	
		case 'q':
			gameover=true;
			break;		
		}
}
void logic()
{
	switch (dir)
    {
    case LEFT:
        moveLeft();
        sumLeft();
        moveLeft();
        generateNewIndex();
        break;
    case RIGHT:
        moveRight();
        sumRight();
        moveRight();
        generateNewIndex();
        break;
    case UP:
        moveUp();
        sumUp();
        moveUp();
        generateNewIndex();
        break;
    case DOWN:
        moveDown();
        sumDown();
        moveDown();
        generateNewIndex();
        break;
    default:
        break;
    }
    if(maxCheck()==2048) gameWin();
    else if(checkFullBox()){
    	if(anyMoveLeft()) {
    		gameover=true;
		}
	}
}
int main(){
	srand(time(NULL));
	setup();
	while(!gameover)
	{	
		looks();	
		inputs();
		logic();
	}
	gameLose();
	return 0;
}
