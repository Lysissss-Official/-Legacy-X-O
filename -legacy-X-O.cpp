#include<cstdio>
#include<windows.h>
#include<WinBase.h>
#include<time.h>
#include<conio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
int mat[20][20]={0},player;
int dx[]={0,1,1};
int dy[]={1,0,1};
int x,y;

void gotoxy(int x,int y)
{
    HANDLE hout=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X=x;
    pos.Y=y;
    SetConsoleCursorPosition(hout,pos);
}

void drawchessboard()//画出棋盘边缘行列数字 
{
	int i;
	cout<<"  ";
	for(i=0;i<10;i++)
	{
		if(i==9)
		{
			cout<<i<<endl;
		}
		else
		{
			cout<<i<<" ";
		}
	}
	for(i=0;i<10;i++)
	{
		cout<<i<<endl;
	}
	cout<<"--------------------"<<endl;
}

void printchessboard()
{
	for(int i=0;i<=9;i++)
	{
		for(int j=0;j<=9;j++)
		{
			int xx=2*j+2,yy=i+1;
			gotoxy(xx,yy);
			if(mat[i][j]==0)		putch(' ');
			else if(mat[i][j]==1)	putch('O');
			else					putch('X');
		}
	}
}

int Judge_End()//判断游戏是否结束，返回0表示没有结束；返回1表示1号玩家胜利；返回2表示2号玩家胜利 
{
	int i,j,k,l;
	short u1,u2;
	u1=u2=0;
	for(i=0;i<10;i++)//判断横向 
	{
		u1=u2=0;
		for(j=0;j<10;j++)
		{
			if(mat[i][j]==1)
			{
				u2=0;
				u1++;
			}
			else if(mat[i][j]==2)
			{
				u1=0;u2++;
			}
			else if(mat[i][j]==0)
			{
				u1=0;u2=0;
			}
			if(u1==5)
			{
				system("cls");
				cout<<"1号玩家胜利!"<<endl;
				return 1;
			}
			else if(u2==5)
			{
				system("cls");
				cout<<"2号玩家胜利!"<<endl;
				return 2;
			}
		}
	}
	u1=u2=0;
	for(i=0;i<10;i++)//判断竖向 
	{
		u1=u2=0;
		for(j=0;j<10;j++)
		{
			if(mat[j][i]==1)
			{
				u2=0;
				u1++;
			}
			else if(mat[j][i]==2)
			{
				u1=0;
				u2++;
			}
			else if(mat[j][i]==0)
			{
				u1=0;u2=0;
			}
			if(u1==5)
			{
				system("cls");
				cout<<"1号玩家胜利!"<<endl;
				return 1;
			}
			else if(u2==5)
			{
				system("cls");
				cout<<"2号玩家胜利!"<<endl;
				return 2;
			}
		}
	}
	u1=u2=0;
	for(i=0;i<6;i++)//判断左斜向 
	{
		u1=u2=0;
		for(j=0;j<=10;j++)
		{
			if(mat[i+j][j]==1)
			{
				u2=0;
				u1++;
			}
			else if(mat[i+j][j]==2)
			{
				u1=0;
				u2++;
			}
			else if(mat[i+j][j]==0)
			{
				u1=0;u2=0;
			}
			if(u1==5)
			{
				system("cls");
				cout<<"1号玩家胜利!"<<endl;
				return 1;
			}
			else if(u2==5)
			{
				system("cls");
				cout<<"2号玩家胜利!"<<endl;
				return 2;
			}
		}
		u1=u2=0;
		for(j=0;j<=10;j++)
		{
			if(mat[j][j+i]==1)
			{
				u2=0;
				u1++;
			}
			else if(mat[j][j+i]==2)
			{
				u1=0;
				u2++;
			}
			else if(mat[j][j+i]==0)
			{
				u1=0;u2=0;
			}
			if(u1==5)
			{
				system("cls");
				cout<<"1号玩家胜利!"<<endl;
				return 1;
			}
			else if(u2==5)
			{
				system("cls");
				cout<<"2号玩家胜利!"<<endl;
				return 2;
			}
		}
	}
	u1=u2=0;
	for(i=0;i<=10;i++)//判断右斜向 
	{
		u1=u2=0;
		for(j=9;j>=0;j--)
		{
			if(mat[j][i+(9-j)]==1)
			{
				u2=0;
				u1++;
			}
			else if(mat[j][i+(9-j)]==2)
			{
				u1=0;u2++;
			}
			else if(mat[j][i+(9-j)]==0)
			{
				u1=0;u2=0;
			}
			if(u1==5)
			{
				system("cls");
				cout<<"1号玩家胜利!"<<endl;
				return 1;
			}
			else if(u2==5)
			{
				system("cls");
				cout<<"2号玩家胜利!"<<endl;
				return 2;
			}
		}
		u1=u2=0;
		for(j=9;j>=0;j--)
		{
			if(mat[9-i-(9-j)][9-j]==1)
			{
				u2=0;
				u1++;
			}
			else if(mat[9-i-(9-j)][9-j]==2)
			{
				u1=0;u2++;
			}
			else if(mat[9-i-(9-j)][9-j]==0)
			{
				u1=0;u2=0;
			}
			if(u1==5)
			{
				system("cls");
				cout<<"1号玩家胜利!"<<endl;
				return 1;
			}
			else if(u2==5)
			{
				system("cls");
				cout<<"2号玩家胜利!"<<endl;
				return 2;
			}
		}
	}
	return 0;
}

void readxy()
{
	int i,j;
	if(player==0)
	{
		system("color F1");
	}
	else
	{
		system("color F2");
	}
	gotoxy(0,12);
	printf("%d号玩家操作，请输入落子坐标：                   \n",player+1);
	while(1)
	{
		cin>>x>>y;
		gotoxy(0,13);
		cout<<"                                          ";
		gotoxy(0,14);
		cout<<"                                          ";
		gotoxy(0,15);
		cout<<"                                          ";
		gotoxy(0,16);
		cout<<"                                          ";
    	if(x>=10||y>=10||x<0||y<0)
    	{
    		gotoxy(0,12);
    		cout<<player+1<<"号玩家不能落在（"<<x<<","<<y<<"）位置，请重新输入:          "<<endl;
    		continue;
		}
		else if(mat[x][y]!=0)
		{
			gotoxy(0,12);
    		cout<<player+1<<"号玩家不能落在（"<<x<<","<<y<<"）位置，请重新输入:          "<<endl;
    		continue;
		}
		else
		{
			mat[x][y]=player+1;
			break;
		}
	}
	player+=1;
	player%=2;
}

int main()
{
	drawchessboard();
	player=0;
	while(1)
	{
		readxy();//读取玩家输入的不同坐标
		printchessboard();//打印棋盘 
		if(Judge_End()!=0)
		{
			break;
		}
	}
	return 0;
}

