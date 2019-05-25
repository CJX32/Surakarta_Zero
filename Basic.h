#ifndef Basic_h
#define Basic_h
#include <stdio.h>
typedef struct position{
    int x;
    int y;
}Position;
typedef struct move{
Position from;
Position to;
}Move;
typedef struct orbit{
Position node;
int arc;
int next;
int pre;
}Orbit;
typedef  struct orbit_index{
int amount;
int node_1;
int node_2;
}Orbit_Index;
typedef struct rool{
int chess;
Position from;
}Rool;
typedef struct move_list{
    Move list[100];
    int  flag;
}Move_List;
typedef struct alphabeta{
int depth;
int alpha;
int beta;
int minimaxplayer;
}AlphaBeta_data;
int count_chess(int  who);
void visualize_board();
void visualize(Move_List *h);
#endif