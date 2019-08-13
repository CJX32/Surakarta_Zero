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
int who=-1;
uint64_t Hash_Board[6][6][2];

int main(void){

{
Hash_Board_Init(Hash_Board);
FILE *fp;
fp=fopen("/Users/bluesky/Desktop/Surakarta_Zero/Data/testAlphaBeta1.txt","r");
if(fp==NULL){
printf("open Error\n");
return 0;
}
test_alpha_beta(fp);
}


}
