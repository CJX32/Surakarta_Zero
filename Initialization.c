#include "Initialization.h"
extern Chessboard chessboard;
extern Move_List battle_record;
void Chessboard_Init(void){
    for(int a=0;a<6;a++){
        for(int b=0;b<6;b++){
            if(a<2)
                chessboard.chessboard[a][b]=1;
            else if(a>=4)
                chessboard.chessboard[a][b]=-1;
            else
                chessboard.chessboard[a][b]=0;
        }
    }
chessboard.black=12;
chessboard.white=12;
printf("init=%d init=%d\n",chessboard.black,chessboard.white);
}

void Hash_Board_Init(uint64_t Hash_Board[6][6][2])
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
p[a].depth=0;
}
/*void Move_List_Init(){
    battle_record.flag=0;
    battle_record.list=(Move *)malloc(100*sizeof(Move));
}
*/