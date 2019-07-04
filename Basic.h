#ifndef Basic_h
#define Basic_h
#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int x;
    int y;
}Position;
typedef struct{
Position from;
Position to;
}Move;
typedef struct{
Position node;
int arc;
int next;
int pre;
}Orbit;
typedef  struct{
int amount;
int node_1;
int node_2;
}Orbit_Index;
typedef struct{        
int chess;
Position from;
}Rool;
typedef struct{
    Move list[100];
    int  flag;
}Move_List;
typedef struct{
int depth;
int minimaxplayer;
}AlphaBeta_data;
typedef struct{
uint64_t key;
int depth;
int type;
int value;
}Hash_Move;
typedef struct{
int chessboard[6][6];
int depth;
int alpha;
int beta;
int minimaxplayer;
int value;
}Para;
#define Hash_table_length 134217728   
#define HashExact 0
#define HashAlpha 1
#define HashBeta 2
void visualize_board();
void visualize(Move_List *h);
int judge(int chessboard_test[][6]);
int max(int a,int b);
int mini(int a,int b);
#endif