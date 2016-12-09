#include"shapes.h"
#include <iostream>
#include "intalizeView.h"
#include <conio.h>
#include <Windows.h>
#include <ctime>
#include <cstdlib>   //to use rand function


using namespace std;

int mat[30][20];
int empty[4][20];
int update[30][20];
int temp[30][20];

static int three_only = 0;

void drawp(int x, int y)                  
{

	if( (x >= 0 && x < 30) && (y >= 0 && y < 20))
		mat[x][y] = 1;
}


void remove_0_draw_1()
{
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (mat[i][j] == 1 && update[i][j] == 1)       //dont romove which was drawn
				continue;
			else                                         //remove only zero from update and draw the rest
			{
				
				mat[i][j] = 0; //-> remove the old to draw the new
			}
		}


	}

}


void draw_shape_N(int num_of_shape,int x, int y, int& r, int & end)
{                                      

	switch (num_of_shape)
	{                                              // ##
	case 1:                                      // ## 


		if (r == 1 || r == 3)
		{

			remove_0_draw_1();


			drawp(x + 1, y + 0);
			drawp(x + 1, y + 1);
			drawp(x + 0, y + 1);
			drawp(x + 0, y + 2);

			end = 28;


		}
		else if (r == 2 || r == 4)
		{
			remove_0_draw_1();

			drawp(x + 0, y + 0);
			drawp(x + 1, y + 0);
			drawp(x + 1, y + 1);
			drawp(x + 2, y + 1);

			end = 27;



		}
		break;
	case 2:                                // ##
	                                    	// ##
		if (r == 1 || r == 3)
		{
			remove_0_draw_1();

			drawp(x + 0, y + 0);
			drawp(x + 0, y + 1);
			drawp(x + 1, y + 1);
			drawp(x + 1, y + 2);
			end = 28;


		}
		else if (r == 2 || r == 4)
		{
			remove_0_draw_1();


			drawp(x + 0, y + 1);
			drawp(x + 1, y + 1);
			drawp(x + 1, y + 0);
			drawp(x + 2, y + 0);
			end = 27;


		}

		break;
	case 3:                                              // ##
		                                                 // ##
		if (r == 1)
		{



			remove_0_draw_1();


			drawp(x + 0, y + 0);
			drawp(x + 0, y + 1);
			drawp(x + 1, y + 0);
			drawp(x + 1, y + 1);
			end = 28;
		}

		break;

	case 4:                                          // #
		                                            // ###

		if (r == 1)
		{


			remove_0_draw_1();


			drawp(x + 0, y + 1);
			drawp(x + 1, y + 0);
			drawp(x + 1, y + 1);
			drawp(x + 1, y + 2);

			end = 28;
		}
		else if (r == 2)
		{
			remove_0_draw_1();


			drawp(x + 0, y + 0);
			drawp(x + 1, y + 0);
			drawp(x + 2, y + 0);
			drawp(x + 1, y + 1);

			end = 27;

		}
		else if (r == 3)
		{

			remove_0_draw_1();
			drawp(x + 0, y + 0);
			drawp(x + 0, y + 1);
			drawp(x + 0, y + 2);
			drawp(x + 1, y + 1);
			end = 28;

		}
		else if (r == 4)
		{


			remove_0_draw_1();

			drawp(x + 1, y + 0);
			drawp(x + 0, y + 1);
			drawp(x + 1, y + 1);
			drawp(x + 2, y + 1);
			end = 27;
		}


		break;
	case 5:                                             // ###
	                                                 	// #

		if (r == 1)
		{


			remove_0_draw_1();


			drawp(x + 0, y + 0);
			drawp(x + 0, y + 1);
			drawp(x + 0, y + 2);
			drawp(x + 1, y + 0);

			end = 28;
		}
		else if (r == 2)
		{
			remove_0_draw_1();


			drawp(x + 0, y + 0);
			drawp(x + 0, y + 1);
			drawp(x + 1, y + 1);
			drawp(x + 2, y + 1);

			end = 27;

		}
		else if (r == 3)
		{

			remove_0_draw_1();
			drawp(x + 0, y + 2);
			drawp(x + 1, y + 0);
			drawp(x + 1, y + 1);
			drawp(x + 1, y + 2);
			end = 28;

		}
		else if (r == 4)
		{


			remove_0_draw_1();

			drawp(x + 0, y + 0);
			drawp(x + 1, y + 0);
			drawp(x + 2, y + 0);
			drawp(x + 2, y + 1);
			end = 27;
		}


		break;
	case 6:                                             // ###
	                                                      // #

		if (r == 1)
		{
			remove_0_draw_1();


			drawp(x + 0, y + 0);
			drawp(x + 0, y + 1);
			drawp(x + 0, y + 2);
			drawp(x + 1, y + 2);

			end = 28;



		}
		else if (r == 2)
		{
			remove_0_draw_1();


			drawp(x + 0, y + 1);
			drawp(x + 1, y + 1);
			drawp(x + 2, y + 1);
			drawp(x + 2, y + 0);

			end = 27;


		}
		else if (r == 3)
		{

			remove_0_draw_1();


			drawp(x + 0, y + 0);
			drawp(x + 1, y + 0);
			drawp(x + 1, y + 1);
			drawp(x + 1, y + 2);

			end = 28;

		}
		else if (r == 4)
		{


			remove_0_draw_1();

			drawp(x + 0, y + 0);
			drawp(x + 0, y + 1);
			drawp(x + 1, y + 0);
			drawp(x + 2, y + 0);
			end = 27;
		}


		break;
	case 7:                                      // #### 


		if (r == 1 || r == 3)
		{
			remove_0_draw_1();

			drawp(x + 0, y + 0);
			drawp(x + 0, y + 1);
			drawp(x + 0, y + 2);
			drawp(x + 0, y + 3);

			end = 29;


		}
		else if (r == 2 || r == 4)
		{
			remove_0_draw_1();

			drawp(x + 0, y + 0);
			drawp(x + 1, y + 0);
			drawp(x + 2, y + 0);
			drawp(x + 3, y + 0);

			end = 26;



		}
		break;                                  //  #
	case 8:                                     //  #      madfa3


		if (r == 1 || r == 3)
		{
			remove_0_draw_1();

			drawp(x + 0, y + 0);
			drawp(x + 1, y + 0);
			
          	end = 28;

		}

		else if (r == 2 || r == 4)
		{
			remove_0_draw_1();

			drawp(x + 0, y + 0);
			drawp(x + 0, y + 1);

			end = 29;


		}
		break;
	}



 

}
	
void draw_mat()                                // cout only
{

		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

		int col = 2;
		for (int i = 0; i < 30; i++)
		{
			gotoxy(33, col);
			for (int j = 0; j < 20; j++)
			{
				if (mat[i][j] == 1)
				{
					
						SetConsoleTextAttribute(h, 17);
						cout << "#";
				}
				else
				{
					SetConsoleTextAttribute(h,120 );
					cout << ":";
				}
			}

			col++;

		}
	}





bool check_collision(int num_shape, int rotate, int x, int y)      //check  down collision in update;
{
	                                                   
	switch (num_shape)                               
	{
	  case 1:

			  if (rotate == 1||rotate==3)
			  {
				  if (update[x + 1][y + 0] == 1 || update[x + 1][y + 1] == 1 || update[x + 0][y + 2] == 1)
					  return false;
				  else

				  {
					  return true;
				  }

				

			  }

			  else if (rotate == 2 || rotate == 4)
			  {
				  if (update[x + 1][y + 0] == 1 || update[x + 2][y + 1] == 1)

					  return false;
				  else
				  {
					  return true;
				  }

				 
			  }
	  case 2:
			   if (rotate ==1||rotate==3)
			  {
				   if (update[x + 0][y + 0] == 1 || update[x + 1][y + 1] == 1 || update[x + 1][y + 2])
					   return false;
				   else
				   {
					   return true;
				   }
				

			  }
			   if (rotate == 2 || rotate == 4)
			   {
				   if (update[x + 2][y + 0] == 1 || update[x + 1][y + 1] == 1)
					   return false;
				   else
				   {
					   return true;
				   }
				  

			  }
			  break;
	  case 3:
		  if (rotate == 1 )
		  {
			  if (update[x + 1][y + 0] == 1 || update[x + 1][y + 1])
				  return false;
			  else
			  {
				  return true;
			  }



		  }
		  break;
	  case 4:

		  if (rotate == 1)
		  {
			  if (update[x + 1][y + 0] == 1 || update[x + 1][y + 1] == 1 || update[x + 1][y + 2] == 1)

				  return false;
			  else
			  {
				  return true;
			  }

		  }

		  else if (rotate == 2)
		  {
			  if (update[x + 2][y + 0] == 1 || update[x + 1][y + 1] == 1 )
				  return false;
			  else
			  {
				  return true;
			  }

		  }

		  else if (rotate == 3)
		  {
			  if (update[x + 0][y + 0] == 1 || update[x + 1][y + 1] == 1 || update[x + 0][y + 2] == 1)
				  return false;
			  else
			  {
				  return true;
			  }

		  }
		  else if (rotate == 4)
		  {
			  if (update[x + 1][y + 0] == 1 || update[x + 2][y + 1] == 1 )
				  return false;
			  else
			  {
				  return true;
			  }

		  }
		  break;
	  case 5:

		  if (rotate == 1)
		  {
			  if (update[x + 1][y + 0] == 1 || update[x + 0][y + 1] == 1 || update[x + 0][y + 2] == 1)

				  return false;
			  else
			  {
				  return true;
			  }

		  }

		  else if (rotate == 2)
		  {
			  if (update[x + 0][y + 0] == 1 || update[x + 2][y + 1] == 1)
				  return false;
			  else
			  {
				  return true;
			  }

		  }

		  else if (rotate == 3)
		  {
			  if (update[x + 1][y + 0] == 1 || update[x + 1][y + 1] == 1 || update[x + 1][y + 2] == 1)
				  return false;
			  else
			  {
				  return true;
			  }

		  }
		  else if (rotate == 4)
		  {
			  if (update[x + 2][y + 0] == 1 || update[x + 2][y + 1] == 1)
				  return false;
			  else
			  {
				  return true;
			  }

		  }
		  break;
	  case 6:

		  if (rotate == 1)
		  {
			  if (update[x + 0][y + 0] == 1 || update[x + 0][y + 1] == 1 || update[x + 1][y + 2] == 1)

				  return false;
			  else
			  {
				  return true;
			  }

		  }

		  else if (rotate == 2)
		  {
			  if (update[x + 2][y + 0] == 1 || update[x + 2][y + 1] == 1)
				  return false;
			  else
			  {
				  return true;
			  }

		  }

		  else if (rotate == 3)
		  {
			  if (update[x + 1][y + 0] == 1 || update[x + 1][y + 1] == 1 || update[x + 1][y + 2] == 1)
				  return false;
			  else
			  {
				  return true;
			  }

		  }
		  else if (rotate == 4)
		  {
			  if (update[x + 0][y + 1] == 1 || update[x + 2][y + 0] == 1)
				  return false;
			  else
			  {
				  return true;
			  }

		  }
		  break;
	  case 7:                                             

		  if (rotate == 1 || rotate == 3)
		  {
			  if (update[x + 0][y + 0] == 1 || update[x + 0][y + 1] == 1 || update[x + 0][y + 2] == 1 || update[x + 0][y + 3] == 1)
				  return false;
			  else

			  {
				  return true;
			  }



		  }

		  else if (rotate == 2 || rotate == 4)
		  {
			  if (update[x + 3][y + 0] == 1 )

				  return false;
			  else
			  {
				  return true;
			  }


		  }
		  break;
	  case 8:                          // the lazer

		  if (rotate == 1 || rotate == 3)
		  {
			  if (update[x + 1][y + 0] ==1)
				  return false;
			  else

			  {
				  return true;
			  }



		  }

		  else if (rotate == 2 || rotate == 4)
		  {
			  if (update[x + 0][y + 0] == 1 || update[x + 0][y + 1] == 1)

				  return false;
			  else
			  {
				  return true;
			  }


		  }

	    

	



	}
}


bool IS_Clear_Row()
{
	bool check = false;
	int c=0;
	int j;
	for (int i = 0; i < 30; i++)    // rows
	 {
		for ( j = 0; j < 20; j++)   // col
		{
			if (mat[i][j] == 1)
				c++;
		}
		if (c == 20)                             // if you find a row all element is one
		{
			for (int l = 0; l < 20; l++)        
				mat[i][l] = 0;                    //clear this row and
			for (int h = i -1; h >= 0; h--)
			{
				for (int f = 0; f < 20; f++)
				{
					if (mat[h][f] == 1)
					{ 
						mat[h][f] = 0;
						mat[h + 1][f] = 1;

					}
				}
			}

			check=true;
			c = 0;
		}
		else
		{
			c = 0;
		}

	}
	return check;
}

bool IS_GameOver()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	int c = 0;

	for (int j = 0; j < 20; j++)
	{
		if (update[c][j] == 1)
		{
			SetConsoleTextAttribute(h, 15);
			gotoxy(57, 19);
			cout << " Game Over ";
			return true;
		}
	}
				
	
		
			return false;
	

}


void update_1()
{
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 20; j++)
			update[i][j] = 0;
	}
}



void access_update()
{
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			update[i][j] = mat[i][j];
		}
	}
}


void out()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(h, 15);
	gotoxy(0, 10);
	for (int i = -34; i < 30; i++)
	{
		for (int j = -4; j < 24; j++)
		{
			if (j==20)
				cout <<" "<<update[i][j];
			else
		
			cout << update[i][j];
		}
		cout << endl;
		if (i == -5 | i == -1)
			cout << endl;
	}

}
void zero_empty()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 20; j++)
			empty[i][j] = 0;
	}
}

bool check_limit_Right(int num_of_shape, int r, int x, int y)   // check if there is shape besides the shape from right which move
{
	switch (num_of_shape)
	{
	case 1:
		if (r == 1 || r == 3)                         //ok
		{
			if (update[x + 0][y + 3] == 1 || y == 17)

				return false;
			else
				return true;


		}
		else if (r == 2 || r == 4)                    //ok
		{
			if (update[x + 1][y + 2] == 1 || update[x + 2][y + 2] == 1 || update[x + 0][y + 1] == 1 || y == 18)

				return false;
			else
				return true;


		}
		break;

	case 2:
		if (r == 1 || r == 3)
		{
			if (update[x + 0][y + 2] == 1 || update[x + 1][y + 3] == 1 || y == 17)

				return false;
			else
				return true;


		}
		else if (r == 2 || r == 4)                  //ok
		{
			if (update[x + 0][y + 2] == 1 || update[x + 1][y + 2] == 1 || y == 18)

				return false;
			else
				return true;


		}

		break;
	case 3:
		if (r == 1)
		{
			if (update[x + 0][y + 2] == 1 || update[x + 1][y + 2] == 1 || y == 18)

				return false;
			else
				return true;


		}
		break;

	case 4:

		if (r == 1)
		{
			if (update[x + 0][y + 2] == 1 || update[x + 1][y + 3] == 1 || y == 17)

				return false;
			else
				return true;


		}
		else if (r == 2)                                                     //ok
		{
			if (update[x + 0][y + 1] == 1 || update[x + 1][y + 2] == 1 || y == 18)

				return false;
			else
				return true;


		}
		else if (r == 3)                                                     //ok
		{
			if (update[x + 0][y + 3] == 1 || y == 17)

				return false;
			else
				return true;


		}
		else if (r == 4)                                                     //ok
		{
			if (update[x + 0][y + 2] == 1 || update[x + 1][y + 2] == 1 || update[x + 2][y + 2] == 1 || y == 18)

				return false;
			else
				return true;


		}

		break;
	case 5:

		if (r == 1)
		{
			if (update[x + 0][y + 3] == 1 || y == 17)

				return false;
			else
				return true;


		}
		else if (r == 2)                                                     //ok
		{
			if (update[x + 0][y + 2] == 1 || update[x + 1][y + 2] == 1 || update[x + 2][y + 2] == 1 || y == 18)

				return false;
			else
				return true;


		}
		else if (r == 3)                                                     //ok
		{
			if (update[x + 0][y + 3] == 1 || update[x + 1][y + 3] == 1 || y == 17)

				return false;
			else
				return true;


		}
		else if (r == 4)                                                     //ok
		{
			if (update[x + 0][y + 1] == 1 || update[x + 1][y + 1] == 1 || update[x + 2][y + 2] == 1 || y == 18)

				return false;
			else
				return true;


		}

		break;

	case 6:

		if (r == 1)
		{
			if (update[x + 0][y + 3] == 1 || update[x + 1][y + 3] == 1 || y == 17)

				return false;
			else
				return true;


		}
		else if (r == 2)                                                     //ok
		{
			if (update[x + 0][y + 2] == 1 || update[x + 1][y + 2] == 1 || update[x + 2][y + 2] == 1 || y == 18)

				return false;
			else
				return true;


		}
		else if (r == 3)                                                     //ok
		{
			if (update[x + 1][y + 3] == 1 || y == 17)

				return false;
			else
				return true;


		}
		else if (r == 4)                                                     //ok
		{
			if (update[x + 0][y + 2] == 1 || y == 18)

				return false;
			else
				return true;


		}

		break;

	case 7:
		if (r == 1 || r == 3)                         //ok
		{
			if (update[x + 0][y + 4] == 1 || y == 16)

				return false;
			else
				return true;


		}
		else if (r == 2 || r == 4)                    //ok
		{
			if (update[x + 0][y + 1] == 1 || update[x + 1][y + 1] == 1 || update[x + 2][y + 1] == 1 || update[x + 3][y + 1] == 1 || y == 19)

				return false;
			else
				return true;


		}
		break;
	case 8:
		if (r == 1 || r == 3)                         //ok
		{
			if (update[x + 0][y + 1] == 1 || update[x + 1][y + 1] == 1 || y == 19)

				return false;
			else
				return true;


		}
		else if (r == 2 || r == 4)                    //ok
		{
			if (update[x + 0][y + 2] == 1 || y == 18)

				return false;
			else
				return true;


		}
		break;
	}

		
	
}


bool check_limit_Left(int num_of_shape, int r, int x, int y)   // check if there is shape besides the shape from left which move
{
	switch (num_of_shape)
	{
	case 1:
		if (r == 1 || r == 3)                         //ok
		{
			if (update[x + 0][y + 0] == 1 || update[x + 1][y - 1] == 1 || y == 0)

				return false;
			else
				return true;


		}
		else if (r == 2 || r == 4)                    //ok
		{
			if (update[x + 0][y - 1] == 1 || update[x + 1][y - 1] == 1 || y == 0)

				return false;
			else
				return true;


		}
		break;

	case 2:
		if (r == 1 || r == 3)
		{
			if (update[x + 0][y - 1] == 1 || y == 0)

				return false;
			else
				return true;


		}
		else if (r == 2 || r == 4)                  //ok
		{
			if (update[x + 0][y + 0] == 1 || update[x + 1][y - 1] == 1 || update[x + 2][y - 1] == 1 || y == 0)

				return false;
			else
				return true;


		}

		break;
	case 3:
		if (r == 1)
		{
			if (update[x + 0][y - 1] == 1 || update[x + 1][y - 1] == 1 || y == 0)

				return false;
			else
				return true;


		}
		break;
	case 4:

		if (r == 1)
		{
			if (update[x + 0][y + 0] == 1 || update[x + 1][y - 1] == 1 || y == 0)

				return false;
			else
				return true;


		}
		else if (r == 2)                                                     //ok
		{
			if (update[x + 0][y - 1] == 1 || update[x + 1][y - 2] == 1 || update[x + 2][y - 1] == 1 || y == 0)

				return false;
			else
				return true;


		}
		else if (r == 3)                                                     //ok
		{
			if (update[x + 0][y - 1] == 1 || y == 0)

				return false;
			else
				return true;


		}
		else if (r == 4)                                                     //ok
		{
			if (update[x + 0][y + 0] == 1 || update[x + 1][y - 1] == 1 || y == 0)

				return false;
			else
				return true;


		}

		break;
	case 5:

		if (r == 1)
		{
			if (update[x + 0][y - 1] == 1 || update[x + 1][y - 1] == 1 || y == 0)

				return false;
			else
				return true;


		}
		else if (r == 2)                                                     //ok
		{
			if (update[x + 0][y - 1] == 1 || y == 0)

				return false;
			else
				return true;


		}
		else if (r == 3)                                                     //ok
		{
			if (update[x + 1][y - 1] == 1 || y == 0)

				return false;
			else
				return true;


		}
		else if (r == 4)                                                     //ok
		{
			if (update[x + 0][y - 1] == 1 || update[x + 1][y - 1] == 1 || update[x + 2][y - 1] == 1 || y == 0)

				return false;
			else
				return true;


		}

		break;
	case 6:

		if (r == 1)
		{
			if (update[x + 0][y - 1] == 1 || y == 0)

				return false;
			else
				return true;


		}
		else if (r == 2)                                                     //ok
		{
			if (update[x + 0][y + 0] == 1 || update[x + 1][y + 0] == 1 || update[x + 2][y - 1] == 1 || y == 0)

				return false;
			else
				return true;


		}
		else if (r == 3)                                                     //ok
		{
			if (update[x + 0][y - 1] == 1 || update[x + 1][y - 1] == 1 || y == 0)

				return false;
			else
				return true;


		}
		else if (r == 4)                                                     //ok
		{
			if (update[x + 0][y - 1] == 1 || update[x + 1][y - 1] == 1 || update[x + 2][y - 1] == 1 || y == 0)

				return false;
			else
				return true;


		}

		break;

	case 7:
		if (r == 1 || r == 3)                         //ok
		{
			if (update[x + 0][y - 1] == 1 || y == 0)

				return false;
			else
				return true;


		}
		else if (r == 2 || r == 4)                    //ok
		{
			if (update[x + 0][y - 1] == 1 || update[x + 1][y - 1] == 1 || update[x + 2][y - 1] == 1 || update[x + 3][y - 1] == 1 || y == 0)

				return false;
			else
				return true;


		}
		break;
	case 8:
		if (r == 1 || r == 3)                         //ok
		{
			if (update[x + 0][y - 1] == 1 || update[x + 1][y - 1] == 1 || y == 0)

				return false;
			else
				return true;


		}
		else if (r == 2 || r == 4)                    //ok
		{
			if (update[x + 0][y - 1] == 1 || y == 0)

				return false;
			else
				return true;


		}
		break;


	}
}

int rand_shape()
{
	int r;
	srand(time(0));

	r = rand() % 8+1 ;
	//r = 8;
	return r;

}

bool lazer(int rotate,int y,int x)
{                          
	if (three_only < 3)           //      0 or 1 or 2
	{

		if (rotate == 1 || rotate == 3)
		{
			for (int i = y + 3; i < 30; i++)
			{
				mat[i][x] = 0;
				update[i][x] = 0;

			}

		}
		else if (rotate == 2 || rotate == 4)
		{
			for (int i = x + 2; i < 20; i++)
			{
				mat[y][i] = 0;
				update[y][i] = 0;

			}
			for (int i = 0; i < x; i++)
			{
				mat[y][i] = 0;
				update[y][i] = 0;

			}

		}
		PlaySound(TEXT("Laser.wav"), NULL, SND_ASYNC);
		
		three_only++;

		return true;
		
		
	}

	return false;

}
void intalize_three_only()
{
	three_only = 0;
}



