#ifndef Basic_h
#define Basic_h
#define Hash_table_length 2048
#define HashExact 0
#define HashAlpha 1
#define HashBeta 2
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
typedef struct{
    int x;
    int y;
}Position;
typedef struct{
Position from;
Position to;
int value;
}Move;
typedef struct{
int chessboard[6][6];
int white;
int black;
}Chessboard;
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
Chessboard chessboard_info;
int depth;
int alpha;
int beta;
int minimaxplayer;
int value;
int tid;
}Para;
typedef struct{
    int value;
    int best_move;
}Result;
typedef struct{
    int choice_1;
    int choice_2;
}choice;
typedef struct{
    Rool *rool;
    int index;
}role;
typedef struct{
    Move_List *h;
    int who;
}Para_1;
void visualize_board(Chessboard chessboard);
void visualize(Move_List *h);
int judge(Chessboard chessboard);

int max(int a,int b);
int mini(int a,int b);
void update(int alpha);
void fvisualize_board(Chessboard chessboard_test,int tid,int depth,int val);
#endif