#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Move_Generator.h"
#include "test.h"
#include "Search_Engine.h"
#include "Evaluator.h"
#include "Initialization.h"
#define Black_Chess 1
#define White_Chess -1
int chessboard[6][6]={
{0, -1 ,-1 ,-1, 0 ,0 },
{-1 ,0, 0 ,0 ,0 ,0 },
{0, 0 ,0 ,0 ,0 ,0 },
{0, 0 ,0 ,-1 ,-1 ,0 },
{1 ,0 ,0 ,0 ,-1 ,0 },
{0 ,0 ,0 ,1 ,0 ,0 },
};
int who;

uint64_t Hash_Board[6][6][2];
Orbit inside_orbit,*Inside_Orbit=&inside_orbit;
Orbit outside_orbit,*Outside_Orbit=&outside_orbit;
Orbit_Index Inside_Orbit_Index[6][6];
Orbit_Index Outside_Orbit_Index[6][6];
int main(void){
   /* who=-1;
    Move_List *h;
    int count=0,flag;
    double duration;
     
    clock_t start,stop;
    start=clock();
    while(count<=10000000)
    {count++;
     h=(Move_List *)malloc(100*sizeof(Move));
     Move_Generate(h,1);
     free(h);
     h=(Move_List *)malloc(100*sizeof(Move));
     Move_Generate(h,-1);
     free(h);
    }
    stop=clock();
    duration=((double)(stop-start))/CLOCKS_PER_SEC;
    printf("time=%.1lfs\n",duration);
*/

 who=-1;
/* FILE *fp;
fp=fopen("/Users/bluesky/Desktop/Surakarta_Zero/Data/testMoveGenerate.txt","r");
test(fp);*/

Hash_Board_Init(Hash_Board);

 FILE *fp;
fp=fopen("/users/bluesky/desktop/surakarta_zero/Data/testAlphaBeta1.txt","r");
if(fp==NULL){
printf("open Error\n");
return 0;
}
test_alpha_beta(fp);


    
    return 0;
}
