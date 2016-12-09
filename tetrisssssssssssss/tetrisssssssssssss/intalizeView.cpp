#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <conio.h>

using namespace std;
static int score=0;
static int level=1;

int next_shape_arr[8][10];

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}
void intalizeView()
{
	gotoxy(1, 3); cout << "    CONTROLES";
	gotoxy(1, 4); cout << "===================";
	gotoxy(1, 6);
	cout << "LEFT,RIGHT -> MOVE ";
	gotoxy(1, 7);
	cout << "DOWN       -> SPEED ";
	gotoxy(1, 8);
	cout << "SPACE      -> DROP THE SHAPE ";
	gotoxy(1, 9);
	cout << "           -> use  laser shape ";
	gotoxy(1, 10);
	cout << "              3 times only ";


	


	//gotoxy(3, 7);
	//cout << "READY";
	gotoxy(3, 12);

	for (int i = 5; i >= 0; i--)
	{ 
		gotoxy(3, 12);
		cout << i;
		gotoxy(3, 14);
		Sleep(1000);


	}
	gotoxy(3, 12);
	cout <<" ";
                                                     //the width of the bucket is 20
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	                                               // the legnth =30
	                                                // mat[30][20]      yes
	SetConsoleTextAttribute(h, 136);
	                                                // 2 is shift to down
	for (int i = 0; i < 31; i++)                  // 31 loop row  the board
	{
		if (i == 30)                         //   will draw the last raw
		{
			gotoxy(32, i + 2);
			for (int j = 0; j < 22; j++)
				cout << "#";
		}
		else                          // will draw 30 str 0 ->29
		{
			gotoxy(32, i + 2);
			cout << "#";
			gotoxy(53, i + 2);
			cout << "#";
		}

	}
	



}
void intalize_Second_Board()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(h, 5);

	gotoxy(57, 11); cout << "NEXT SHAPE";

	SetConsoleTextAttribute(h, 7);

	gotoxy(57, 14); cout << "LEVEL :";
	gotoxy(66, 14); cout << level;

	
	gotoxy(57, 15); cout << "SCORE :";
	gotoxy(66, 15); cout << score;

}


void Edit_Level()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 7);
	level++;
	gotoxy(66, 14); cout << level;

}

void Edit_Score(int & speed)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 7);
	score++;
	if (score % 10 == 0)
	{
      Edit_Level();
	  speed -= 40;
	}
	gotoxy(66, 15); cout << score;
}



void intalize_next_shape_arr()
{

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 10; j++)
			next_shape_arr[i][j] = 0;

	}

}

void display_next_shape_arr()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	int row = 2;
	
	for (int i = 0; i < 8; i++)
	{
		gotoxy(57, row);
		for (int j = 0; j < 10; j++)
		{
			if (next_shape_arr[i][j] == 1)
			{
				SetConsoleTextAttribute(h, 85);

				cout << "#";
			}
			else
			{
				SetConsoleTextAttribute(h, 119);

				cout << " ";
			}
		}
		row++;
		
	}
}


void draw_Next_shape(int num_of_shape)
{
	int x = 3;
	int y = 4;
	switch (num_of_shape)
	{
	case 1:
		intalize_next_shape_arr();
		next_shape_arr[x + 1][y + 0] = 1;
		next_shape_arr[x + 1][y + 1] = 1;
		next_shape_arr[x + 0][y + 1] = 1;
		next_shape_arr[x + 0][y + 2] = 1;
		break;
	case 2:
		intalize_next_shape_arr();
		next_shape_arr[x + 0][y + 0] = 1;
		next_shape_arr[x + 0][y + 1] = 1;
		next_shape_arr[x + 1][y + 1] = 1;
		next_shape_arr[x + 1][y + 2] = 1;
		break;
	case 3:
			intalize_next_shape_arr();
			next_shape_arr[x + 0][y + 0] = 1;
			next_shape_arr[x + 0][y + 1] = 1;
			next_shape_arr[x + 1][y + 0] = 1;
			next_shape_arr[x + 1][y + 1] = 1;
			break;
	case 4:
		intalize_next_shape_arr();
		next_shape_arr[x + 0][y + 1] = 1;
		next_shape_arr[x + 1][y + 0] = 1;
		next_shape_arr[x + 1][y + 1] = 1;
		next_shape_arr[x + 1][y + 2] = 1;
		
		break;
	case 5:
		intalize_next_shape_arr();
		next_shape_arr[x + 0][y + 0] = 1;
		next_shape_arr[x + 0][y + 1] = 1;
		next_shape_arr[x + 0][y + 2] = 1;
		next_shape_arr[x + 1][y + 0] = 1;
		break;
	case 6:
		intalize_next_shape_arr();
		next_shape_arr[x + 0][y + 0] = 1;
		next_shape_arr[x + 0][y + 1] = 1;
		next_shape_arr[x + 0][y + 2] = 1;
		next_shape_arr[x + 1][y + 2] = 1;
		
		break;
	case 7:
		intalize_next_shape_arr();
		next_shape_arr[x + 0][y -1] = 1;
		next_shape_arr[x + 0][y + 0] = 1;
		next_shape_arr[x + 0][y + 1] = 1;
		next_shape_arr[x + 0][y + 2] = 1;

		break;
	case 8:
		intalize_next_shape_arr();
		next_shape_arr[x + 0][y +0] = 1;
		next_shape_arr[x + 1][y + 0] = 1;
		

		break;

		
	}
	
	
}



