#ifndef Search_Engine_h
#define Search_Engine_h
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include "Evaluator.h"
#include "Move_Generator.h"
#include "Hash_Table.h"
#include "Initialization.h"
#include "Basic.h"
#include "Sort.h"
#include "Record.h"
int Alpha_Beta(int depth, int alpha, int beta, int minimaxplayer,Chessboard chessboard_test,Hash_Move *p);
int Alpha_Beta_PVS(int depth, int alpha, int beta, int minimaxplayer,Chessboard chessboard_test,Hash_Move *p);
int Alpha_Beta_PVS_Multi_Thread(int depth, int alpha,int beta, int minimaxplayer,Chessboard chessboard_test,Hash_Move *p);
void *Alpha_Beta_pth(void  *Para);
int Alpha_Beta_Multi_Thread(int depth, int minimaxplayer,int alpha,int beta,Chessboard Chessboard_test);
int Alpha_Beta_new(int depth, int alpha, int beta, int minimaxplayer,Chessboard chessboard_test,Hash_Move *p);
int Alpha_Beta_Null_Move(int depth, int alpha, int beta, int minimaxplayer,Chessboard chessboard_test,Hash_Move *p);
int Quies(int alpha, int beta,int minimaxplayer,Chessboard chessboard_test);
void AI(int depth);
#endif