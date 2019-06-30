#ifndef Search_Engine_h
#define Search_Engine_h
#include <stdlib.h>
#include <pthread.h>
#include "Evaluator.h"
#include "Move_Generator.h"
#include "Basic.h"
int Alpha_Beta(int depth,int alpha,int beta,int minimaxplayer,int chessboard[][6]);
void *Alpha_Beta_pth(void  *Para);
int Alpha_Beta_Multi_Thread(int depth,int minimaxplayer);
#endif