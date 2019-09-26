#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include "Move_Generator.h"
#include "test.h"
#include "Search_Engine.h"
#include "Evaluator.h"
#include "Initialization.h"
#include "Game_AI.h"
#include "Sort.h"
#include "Run.h"
#include "Record.h"
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
FILE *battle;
Move_List battle_record;
char path[70]="/Users/bluesky/Desktop/Surakarta_Zero/Battle/record.txt";
int main(void){
/*
FILE *index_fp=fopen("/Users/bluesky/Desktop/Surakarta_Zero/Battle/index.txt","r");
int index;
fscanf(index_fp,"%d",&index);
index_fp=fopen("/Users/bluesky/Desktop/Surakarta_Zero/Battle/index.txt","w");
fprintf(index_fp,"%d",index+1);
record_pre(index);
fclose(index_fp);

int count=0;
Chessboard_Init(chessboard);
while(count<=1){
run();
count++;
printf("%d\n",count);
printf("end\n");
}*/
{    who=-1;
    Move_List *h;
    int count=0,flag;
    double duration;
     
    clock_t start,stop;
    start=clock();
    while(count<=10000000)
    {count++;
     h=(Move_List *)malloc(100*sizeof(Move));
     Move_Generate(h,1,chessboard);
     free(h);
     h=(Move_List *)malloc(100*sizeof(Move));
     Move_Generate(h,-1,chessboard);
     free(h);
    }
    stop=clock();
    duration=((double)(stop-start))/CLOCKS_PER_SEC;
    printf("time=%.1lfs\n",duration);

}
/*{
 FILE *fp;
fp=fopen("/Users/bluesky/Desktop/Surakarta_Zero/Data/testMoveGenerate.txt","r");
test_MT(fp);
}*/
}
