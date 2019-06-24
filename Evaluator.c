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
int Evaluate(void){
int value=0;
//第一步，棋子的数量
value+=count()*100;
//第二步，棋子的位置价值
value+=position_value();


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
  






}