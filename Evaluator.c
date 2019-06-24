#include "Evaluator.h"
extern int chessboard[6][6];
extern int who;
int chessboard_value[6][6]={
{5,20,20,20,20,5},
{20,30,50,50,30,20},
{20,50,40,40,50,20},
{20,50,40,40,50,20},
{20,30,50,50,30,20},
{5,20,20,20,20,5}
 };
int greenPotential[16]={84,91,35,35,-20,25,-25,45,-45,-45,-84,20,-91,-35,-35};
int look_for[16][2]={
{0,2},
{2,0},
{0,3},
{2,5},
{3,0},
{5,2},
{5,3},
{3,5},

{1,0},
{0,1},
{0,4},
{1,5},
{4,0},
{5,1},
{4,5},
{5,4},
};
int look_for_intersection[8][2]={
{2,2},
{2,3},
{3,2},
{3,3},

{1,1},
{1,4},
{4,1},
{4,4},
};
int Evaluate(void){
int value=0;
//第一步，棋子的数量
value+=count()*100;
//第二步，棋子的位置价值
value+=position_value();

//
value+=greenpotential();
return value;
}

int count(void){
    int count=0;
    for(int a=0;a<6;a++){
        for(int b=0;b<6;b++){
          if(chessboard[a][b]==who)
          count++;
          else if(chessboard[a][b]==-who)
          count--;
        }
    }
    return count;
}
int position_value(void)
{
    int value = 0;
    for (int a = 0; a < 6; a++)
    {
        for (int b = 0; b < 6; b++)
        {
            if (chessboard[a][b] == who)
                value += chessboard_value[a][b];
            else if (chessboard[a][b] == -who)
                value -= chessboard_value[a][b];
        }
    }
    return value;
}
int greenpotential(void){
int value=0;
for(int a=0;a<8;a+=2){
  if(chessboard[look_for_intersection[a/2][0]][look_for_intersection[a/2][1]]==who){
  if(chessboard[look_for[a][0]][look_for[a][1]]==0&&chessboard[look_for[a+1][0]][look_for[a+1][1]]==0 )
  value+=greenPotential[0];
  else if(chessboard[look_for[a][0]][look_for[a][1]]==-who&&chessboard[look_for[a+1][0]][look_for[a+1][1]]==-who)   
  value+=greenPotential[1];
  else if((chessboard[look_for[a][0]][look_for[a][1]]==who||chessboard[look_for[a+1][0]][look_for[a+1][1]]==who)&&(chessboard[look_for[a][0]][look_for[a][1]]==0||chessboard[look_for[a+1][0]][look_for[a+1][1]]==0))
  value+=greenPotential[2];
  else if(chessboard[look_for[a][0]][look_for[a][1]]==who&&chessboard[look_for[a+1][0]][look_for[a+1][1]]==who)
  value+=greenPotential[4];
  }
  else if(chessboard[look_for_intersection[a/2][0]][look_for_intersection[a/2][1]]==0)
  {  if(chessboard[look_for[a][0]][look_for[a][1]]==who&&chessboard[look_for[a+1][0]][look_for[a+1][1]]==who)
     value+=greenPotential[5];
     else if(chessboard[look_for[a][0]][look_for[a][1]]==-who&&chessboard[look_for[a+1][0]][look_for[a+1][1]]==-who)   
     value+=greenPotential[6];
     else if((chessboard[look_for[a][0]][look_for[a][1]]==who||chessboard[look_for[a+1][0]][look_for[a+1][1]]==who)&&(chessboard[look_for[a][0]][look_for[a][1]]==0||chessboard[look_for[a+1][0]][look_for[a+1][1]]==0))
     value+=greenPotential[7];
    else if((chessboard[look_for[a][0]][look_for[a][1]]==-who||chessboard[look_for[a+1][0]][look_for[a+1][1]]==-who)&&(chessboard[look_for[a][0]][look_for[a][1]]==0||chessboard[look_for[a+1][0]][look_for[a+1][1]]==0))
     value+=greenPotential[9];
}
else if(chessboard[look_for_intersection[a/2][0]][look_for_intersection[a/2][1]]==-who){
 if(chessboard[look_for[a][0]][look_for[a][1]]==0&&chessboard[look_for[a+1][0]][look_for[a+1][1]]==0 )
  value+=greenPotential[11];
else if(chessboard[look_for[a][0]][look_for[a][1]]==-who&&chessboard[look_for[a+1][0]][look_for[a+1][1]]==-who)   
  value+=greenPotential[12];
else if(chessboard[look_for[a][0]][look_for[a][1]]==who&&chessboard[look_for[a+1][0]][look_for[a+1][1]]==who)
  value+=greenPotential[13];
else if((chessboard[look_for[a][0]][look_for[a][1]]==who||chessboard[look_for[a+1][0]][look_for[a+1][1]]==who)&&(chessboard[look_for[a][0]][look_for[a][1]]==0||chessboard[look_for[a+1][0]][look_for[a+1][1]]==0))
  value+=greenPotential[14];
}
}
  
return value;
}