#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Move_Generator.h"
#include "test.h"
#include "Search_Engine.h"
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
Orbit inside_orbit,*Inside_Orbit=&inside_orbit;
Orbit outside_orbit,*Outside_Orbit=&outside_orbit;
Orbit_Index Inside_Orbit_Index[6][6];
Orbit_Index Outside_Orbit_Index[6][6];
int main(void){
    who=-1;
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

 
 
 /*Move_List *h,head;
 h=&head;
 h->flag=0;
 Move_Generate(h,1);
 printf("%d\n",h->flag);
visualize(h);*/
 
/*FILE *fp;
fp=fopen("/Users/bluesky/Desktop/Surakarta_2/testMoveGenerate.txt","r");
test(fp);*/


/* FILE *fp;
fp=fopen("./Data/testAlphaBeta\ 1.txt","r");
if(fp==NULL){
printf("open Error\n");
return 0;
}
test_alpha_beta(fp);*/


/*for(int a=1;a<9;a++){
  printf("depth=%d ",a);
 
printf("%d\n",Alpha_Beta(a,-2147483648, 2147483647, 1));
  }*/
 
    return 0;
}
