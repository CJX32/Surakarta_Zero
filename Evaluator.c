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
int Evaluate(){
int value=0;
//第一步，棋子的数量
value+=count(who)*100;
//第二步，棋子的位置价值
value+=position_value(who);


return value;
}

int count(){
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
int position_value()
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