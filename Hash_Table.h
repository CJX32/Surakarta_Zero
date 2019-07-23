#ifndef Hash_Table_h
#define Hash_Table_h
#include <stdio.h>
#include <stdlib.h>
#include "Basic.h"
uint64_t rand64(void);
uint64_t Hash_Key(int chessboard_test[][6],uint64_t  Hash_Board[6][6][2]);
void Hash_store(Hash_Move *p,int type,int depth,int value,uint64_t board[6][6][2],int chessboard_test[][6]);
int Hash_Hit(Hash_Move *p,int depth,int alpha,int beta,uint64_t board[6][6][2],int chessboard_test[][6]);
#endif