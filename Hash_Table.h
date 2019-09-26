#ifndef Hash_Table_h
#define Hash_Table_h
#include <stdio.h>
#include <stdlib.h>
#include "Basic.h"
uint64_t rand64(void);
uint64_t Hash_Key(Chessboard chessboard_test);
void Hash_store(Hash_Move *p,int type,int depth,int value,Chessboard chessboard_test);
int Hash_Hit(Hash_Move *p,int depth,int alpha,int beta,Chessboard chessboard_test);
#endif