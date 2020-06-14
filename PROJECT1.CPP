#include<iostream.h>
#include   <conio.h>
#include<graphics.h>
#include  <string.h>
#include   <stdio.h>
#include <process.h>
//Checking for horizontal 1's
int checkh1(int A[5][9])
{
	int count1=0;
	for(int i=4;i>0;i--)
	{
		for(int j=0;j<9;j++)
		{
			if(A[i][j]==1)
			{
				count1++;
			}
			else
			{
				count1=0;
			}
			if(count1==4)
			{
				break;
			}
		}
		if(count1==4)
		{
			break;
		}
	}
	if(count1==4)
	{

		return 1;
	}
	return 0;

}
//Checking for horizontal 2's
int checkh2(int A[5][9])
{
	int count2=0;
	for(int i=4;i>0;i--)
	{
		for(int j=0;j<9;j++)
		{
			if(A[i][j]==2)
			{
				count2++;
			}
			else
			{
				count2=0;
			}
			if(count2==4)
			{
				break;
			}
		}
		if(count2==4)
		{
			break;
		}
	}
		if(count2==4)
		{

			return 2;
		}
	return 0;
}
//Checking for verical 1's
int checkv1(int A[5][9])
{
	int count11=0;
	for(int i=0;i<9;i++)
	{
		for(int j=4;j>=0;j--)
		{
			if(A[j][i]==1)
			{
				count11++;
			}
			else
			{
				count11=0;
			}
			if(count11==4)
			{
				break;
			}
		}
		if(count11==4)
		{
			break;
		}
	}
	if(count11==4)
	{

		return 1;
	}
	return 0;
}
//Checking for vertical 2's
int checkv2(int A[5][9])
{
	int count22=0;
	for(int i=0;i<9;i++)
	{
		for(int j=4;j>=0;j--)
		{
			if(A[j][i]==2)
			{
				count22++;
			}
			else
			{
				count22=0;
			}
			if(count22==4)
			{
				break;
			}
		}
		if(count22==4)
		{
			break;
		}

	}
	if(count22==4)
	{

		return 2;
	}
	return 0;
}
//The main function
void main()
{
	again:
	clrscr();
	char a,e;
	char p1[7],p2[7];
	//Start screen
	cout<<'\t'<<'\t'<<'\t'<<'\t'<<"    CONNECT:4"<<endl;
	cout<<'\t'<<'\t'<<'\t'<<"         A FUN GAME FOR 2"<<endl;
	cout<<'\n';
	cout<<"           Rules:"<<'\n';
	cout<<"           1.This game is for 2 players ONLY!!"<<endl;
	cout<<"           2.Players should be above 7 yrs of age ;)"<<endl;
	cout<<"           3.The players should be human"<<endl;
	cout<<"           4.PLEASE enter only nos. while playing the main game"<<endl;
	cout<<"           5.You can only win by getting four 1's/2's in a horizontal or a "<<endl;
	cout<<"             vertical line"<<endl;
	cout<<'\n'<<'\t'<<'\t'<<"     PRESS ANY CHAR. AND ENTER TO CONTINUE "<<endl;
	cin>>a;
	if(cin.get()=='\n')
	{
		clrscr();
		cout<<'\n'<<'\n'<<'\n';
		cout<<"                   Enter player 1 name:";
		gets(p1);
		cout<<'\n';
		cout<<"                   Enter player 2 name:";
		gets(p2);
		cout<<'\n';
		//THE ACTUAL GAME
		clrscr();
		int A[5][9];
		for(int i=0;i<5;i++)
		{
			for(int j=0;j<9;j++)
			{
				A[i][j]=0;
			}
		}
		int b,c,d=1;
		int co1=4,co2=4,co3=4,co4=4,co5=4,co6=4,co7=4,co8=4,co9=4;
		start:
		clrscr();
		for(i=31,c=1;i<49,c<10;i++,c++)
		{
		i++;
		gotoxy(i,5);
		cout<<c<<"  ";

		}
		gotoxy(32,5);

		for(i=32;i<50;i++)
		{
			gotoxy(i,6);
			cout<<"-";
			gotoxy(i,12);
			cout<<"-";

		}
		for( i=0,b=7,c=30;i<5;i++,b++)
		{
			gotoxy(c,b);
			cout<<"|                   |";
		}
		for(i=0, b=7;i<5;i++,b++)
		{
			gotoxy(32,b);
			for(int j=0;j<9;j++)
			{
				cout<<A[i][j]<<" ";
			}
			cout<<'\n';
		}
		if(checkh1(A)==1)
		{
			getch();
			clrscr();
			gotoxy(32,6);
			cout<<"CONGRATULATIONS ";
			puts(p1);
			gotoxy(35,7);
			cout<<" YOU WONN!"<<endl;
			gotoxy(30,8);
			cout<<"Do u want to play again(Y/N):"<<endl;
			cin>>e;
			if(e=='y'||e=='Y')
			{
				goto again;
			}
			else
			{
				exit(0);
			}
		}
		if(checkv1(A)==1)
		{
			getch();
			clrscr();
			gotoxy(32,6);
			cout<<"CONGRATULATIONS ";
			puts(p1);
			gotoxy(35,7);
			cout<<" YOU WONN!"<<endl;
			gotoxy(30,8);
			cout<<"Do u want to play again(Y/N):"<<endl;
			cin>>e;
			if(e=='y'||e=='Y')
			{
				goto again;
			}
			else
			{
				exit(0);
			}
		}
		if(checkh2(A)==2)
		{       getch();
			clrscr();
			gotoxy(32,6);
			cout<<"CONGRATULATIONS ";
			puts(p2);
			gotoxy(35,7);
			cout<<" YOU WONN!"<<endl;
			gotoxy(30,8);
			cout<<"Do u want to play again(Y/N):"<<endl;
			cin>>e;
			if(e=='y'||e=='Y')
			{
				goto again;
			}
			else
			{
				exit(0);
			}
		}
		if(checkv2(A)==2)
		{
			clrscr();
			gotoxy(32,6);
			cout<<"CONGRATULATIONS ";
			puts(p2);
			gotoxy(35,7);
			cout<<" YOU WONN!"<<endl;
			gotoxy(30,8);
			cout<<"Do u want to play again(Y/N):"<<endl;
			cin>>e;
			if(e=='y'||e=='Y')
			{
				goto again;
			}
			else
			{
				exit(0);
			}
		}
		int n1,n2;
		//Checking for player 1
		if(d==1)
		{
			puts(p1);
			cout<<" enter your choice:"<<endl;
			cin>>n1;
			if(n1==1)
			{
				A[co1][0]=1;
				co1--;
			}
			else if(n1==2)
			{
				A[co2][1]=1;
				co2--;
			}
			else if(n1==3)
			{
				A[co3][2]=1;
				co3--;
			}
			else if(n1==4)
			{
				A[co4][3]=1;
				co4--;
			}
			else if(n1==5)
			{
				A[co5][4]=1;
				co5--;
			}
			else if(n1==6)
			{
				A[co6][5]=1;
				co6--;
			}
			else if(n1==7)
			{
				A[co7][6]=1;
				co7--;
			}
			else if(n1==8)
			{
				A[co8][7]=1;
				co8--;
			}
			else if(n1==9)
			{
				A[co9][8]=1;
				co9--;
			}
			else
			{
				clrscr();
				gotoxy(30,8);
				cout<<"Enter only nos between 1 to 9"<<endl;
				getch();
				goto start;
			}
			d++;
			if(co1==-1&&co2==-1&&co3==-1&&co4==-1&&co5==-1&&co6==-1&&co7==-1&&co8==-1&&co9==-1)
			{
				clrscr();
				gotoxy(32,8);
				cout<<"IT IS A DRAW"<<endl;
				gotoxy(32,9);
				cout<<"Do you want to continue?(Y/N)"<<endl;
				cin>>e;
				if(e=='Y'||e=='y')
				{
					goto again;
				}
				else
				{
					exit(0);
				}
			}
			goto start;
		}
		//Checking for player 2
		else if(d==2)
		{
			puts(p2);
			cout<<" enter your choice:"<<endl;
			cin>>n2;
			if(n2==1)
			{
				A[co1][0]=2;
				co1--;
			}
			else if(n2==2)
			{
				A[co2][1]=2;
				co2--;
			}
			else if(n2==3)
			{
				A[co3][2]=2;
				co3--;
			}
			else if(n2==4)
			{
				A[co4][3]=2;
				co4--;
			}
			else if(n2==5)
			{
				A[co5][4]=2;
				co5--;
			}
			else if(n2==6)
			{
				A[co6][5]=2;
				co6--;
			}
			else if(n2==7)
			{
				A[co7][6]=2;
				co7--;
			}
			else if(n2==8)
			{
				A[co8][7]=2;
				co8--;
			}
			else if(n2==9)
			{
				A[co9][8]=2;
				co9--;
			}
			else
			{
				clrscr();
				gotoxy(30,8);
				cout<<"Enter nos. between 1 to 9"<<endl;
				getch();
				goto start;
			}
			d--;
			if(co1==-1&&co2==-1&&co3==-1&&co4==-1&&co5==-1&&co6==-1&&co7==-1&&co8==-1&&co9==-1)
			{
				clrscr();
				gotoxy(32,8);
				cout<<"IT IS A DRAW"<<endl;
				gotoxy(32,9);
				cout<<"Do you want to continue?(Y/N)"<<endl;
				cin>>e;
				if(e=='Y'||e=='y')
				{
					goto again;
				}
				else
				{
					exit(0);
				}
			}
			goto start;
		}

	}
	else
	{
		clrscr();
		gotoxy(32,5);
		cout<<"READ THE LAST LINE AGAIN"<<endl;
		getch();
		goto again;
	}
	getch();
}
