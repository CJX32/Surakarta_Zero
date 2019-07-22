#ifdef Initialization_h
#define Initialization_h
#include <stdlib.h>
#include "Basic.h"
#include "Hash_Table.h"
void Chessboard_Init(int chessboard[][6]);
void Hash_Board_Init(uint64_t Hash_Board[6][6][2]);
void Hash_Table_Init(Hash_Move *p);
#endif