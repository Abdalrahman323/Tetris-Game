#include <iostream>
#include "intalizeView.h"
#include "shapes.h"
#include <Windows.h>
#include <conio.h>
#include <MMSystem.h>


#define _WIN32_WINNT 0x0500
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
using namespace std;
int check_down_coll(int num_of_shape, int ver, int hor, int rotate, int end);
int y = -2, x = 5, rotat = 1, e = 0;
int speed =300 ;
int wait = 100;
int counter = 0;
int num_of_shape;
int next_shape, current_shape;
char ch;
int main()
{
HWND console = GetConsoleWindow();
RECT r;
GetWindowRect(console, &r);   //stores the console's current dimensions

  //MoveWindow(window_handle, x, y, width, height, redraw_window);
MoveWindow(console, r.left, r.top, 900, 600, TRUE);

	intalizeView();
  intalize_Second_Board();   //of score && level

  intalize_next_shape_arr();

	update_1();
	int tempy = y; int tempx = x;

	next_shape = rand_shape();
	current_shape = rand_shape();
	
	while (true)
	{
		counter++;
		
		draw_Next_shape(next_shape);	
		display_next_shape_arr();


		y = -2; x = 10; rotat = 1;
		while (true)
		{
			if (check_collision(current_shape, rotat, y, x) == false)
				break;
			

			draw_shape_N(current_shape, y, x, rotat, e);
			draw_mat();                                                 //display the mat

	  // if you want to view what happen actually just uncomment this and resize the window above to larger size say(1500 ,1500)
	  //		out(); 
			
				if (GetAsyncKeyState(VK_RIGHT) && check_limit_Right(current_shape, rotat, y, x))////if the user want to move or rotate the shape ///
				{


					x++;
					PlaySound(TEXT("ARROW.wav"), NULL, SND_ASYNC);

					continue;
				}


				if (GetAsyncKeyState(VK_LEFT) && check_limit_Left(current_shape, rotat, y, x))
				{
					x--;
					PlaySound(TEXT("ARROW.wav"), NULL, SND_ASYNC);

					continue;
				}

				if (GetAsyncKeyState(VK_UP) && current_shape != 3 && check_limit_Left(current_shape, rotat, y, x) && check_limit_Right(current_shape, rotat, y, x))
				{                    // to dont't allow the user to rotate when there is a shape besides it
					rotat++;
					if (rotat == 5)
						rotat = 1;
					PlaySound(TEXT("ARROW.wav"), NULL, SND_ASYNC);
					continue;
				}

				if (GetAsyncKeyState(VK_DOWN))
				{
					PlaySound(TEXT("ARROW.wav"), NULL, SND_ASYNC);

					if (y == e)
						break;
					y++; continue;

				}

				if (GetAsyncKeyState(VK_SPACE))
			{
				if (current_shape == 8  && lazer(rotat, y, x))         // to use laser 3 times only
					{
						Sleep(200);
						//apply the lazer effect
					}
				else
                   {
						y = check_down_coll(current_shape, y, x, rotat, e);
						PlaySound(TEXT("Drop.wav"), NULL, SND_ASYNC);
						continue;
					}


				}
				

			

		

	if (y == e)
		  break;

			y++;

			Sleep(speed);
		}

		Sleep(wait);

		current_shape = next_shape;
		next_shape = rand_shape();

		if (IS_Clear_Row())             //when you clear a raw you gain 1 score or when you fall 7 shapes down
		{
			PlaySound(TEXT("Connect.wav"), NULL, SND_SYNC);

			Edit_Score(speed);                     // ok test
		}
		
		if (counter%5==0)                     // ok test
			Edit_Score(speed);

		
		access_update();

		

		intalize_three_only();

	  if( IS_GameOver())
	  break;
	
	}
		gotoxy(0, 0);
	

	
	
	
	
	return 0;
}





int check_down_coll(int num_of_shape, int ver, int hor, int rotate, int end)
{
	for (int i =ver; i <=end; i++)
	{

		
		if (!check_collision(num_of_shape,rotate,i,hor))
			return i-1;
	}

	return end;

}
	