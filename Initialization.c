#include "Initialization.h"
extern uint64_t Hash_Board[6][6][2];
extern int chessboard[6][6];
void Chessboard_Init(int chessboard[][6]){
    for(int a=0;a<6;a++){
        for(int b=0;b<6;b++){
            if(a<2)
                chessboard[a][b]=1;
            else if(a>=4)
                chessboard[a][b]=-1;
            else
                chessboard[a][b]=0;
        }
    }
    
}
void Hash_Board_Init(void)
{
    for (int a = 0; a < 6; a++)
    {
        for (int b = 0; b < 6; b++)
        {
            for (int c = 0; c < 2; c++)
            {
                Hash_Board[a][b][c] = rand64();
            }
        }
    }
}
void Hash_Table_Init(Hash_Move *p){
for(int a=0;a<Hash_table_length;a++)
p[a]->depth=0;
}