#ifndef Initialization_h
#define Initialization_h
#include <stdlib.h>
#include "Hash_Table.h"
#include "Basic.h"
void Hash_Board_Init(uint64_t Hash_Board[6][6][2]);
void Hash_Table_Init(Hash_Move *p);
void Chessboard_Init(Chessboard chessboard);
void Move_List_Init();
#endif