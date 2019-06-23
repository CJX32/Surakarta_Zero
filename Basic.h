#ifndef Basic_h
#define Basic_h
#include <stdio.h>
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
int alpha;
int beta;
int minimaxplayer;
}AlphaBeta_data;
void visualize_board();
void visualize(Move_List *h);
int judge(void);
#endif