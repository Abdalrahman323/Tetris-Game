
void drawp(int x , int y);                                                //  to draw each cell in the mat   
void draw_shape_N(int num_of_shape, int x, int y, int& rotate, int &end); //  to intalize  mat
void draw_mat();                                                          //  display  mat
void update_1();                                                          //  to intalize the update
void access_update();                                                     // access mat in update after each collision
bool check_collision (int num_shape,int rotate,int x,int y);              // to check if the shape hit anthor shape
void remove_0_draw_1();                                                   // each iteration remove the old to draw the new
bool IS_Clear_Row();                                                      // to check if the user complete a row
bool IS_GameOver();                                                       // to check if the game end
int rand_shape();                                                         // to generat num_of_shape each once
 void out();

 //void zero_empty();
bool check_limit_Right(int num_of_shape, int r, int x, int y);            
bool check_limit_Left(int num_of_shape, int r, int x, int y);
bool lazer(int rotate,int y,int x);
void intalize_three_only();



