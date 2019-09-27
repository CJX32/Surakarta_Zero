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
Chessboard chessboard;
int who=-1;
uint64_t Hash_Board[6][6][2];
FILE *battle;
Move_List battle_record;
char path[70]="/Users/bluesky/Desktop/Surakarta_Zero/Battle/record.txt";
int main(void){
   double duration;
    clock_t start,stop;
    start=clock();
{Hash_Board_Init(Hash_Board);

 FILE *fp;
fp=fopen("/Users/bluesky/Desktop/Surakarta_Zero/Data/testAlphaBeta1.txt","r");
if(fp==NULL){
printf("open Error\n");
return 0;
}
test_alpha_beta(fp);
}
    stop=clock();
    duration=((double)(stop-start))/CLOCKS_PER_SEC;
    printf("time=%.1lfs\n",duration);
 /*   {
FILE *fp;
fp=fopen("/Users/bluesky/Desktop/Surakarta_Zero/Data/testMoveGenerate.txt","r");
test(fp);
}*/

}
