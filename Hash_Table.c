#include "Hash_Table.h"
extern uint64_t Hash_Board[6][6][2];
uint64_t rand64(void)
{
    return rand() ^ ((uint64_t)rand() << 15) ^ ((uint64_t)rand() << 30) ^ ((uint64_t)rand() << 45) ^ ((uint64_t)rand() << 60);
};

uint64_t Hash_Key(Chessboard chessboard_test)
{
    uint64_t result = 0;
    for (int a = 0; a < 6; a++)
    {
        for (int b = 0; b < 6; b++)
        {
            if (chessboard_test.chessboard[a][b] == 1)
            {
                result = result ^ Hash_Board[a][b][0];
            }
            else if (chessboard_test.chessboard[a][b] == -1)
            {
                result = result ^ Hash_Board[a][b][1];
            }
        }
    }
    return result;
}
void Hash_store(Hash_Move *p,int type,int depth,int value,Chessboard chessboard_test){
    uint64_t key=Hash_Key(chessboard_test);
    Hash_Move *operate=&p[key&(Hash_table_length-1)];
    if(operate->depth>=depth)
        return ;                                                                              //初始化的时候将所有数组内元素的depth赋值为0；
    operate->key=Hash_Key(chessboard_test);
    operate->type=type;
    operate->depth=depth;
    operate->value=value;
}

int Hash_Hit(Hash_Move *p,int depth,int alpha,int beta,Chessboard chessboard_test){
    uint64_t key=Hash_Key(chessboard_test);
    Hash_Move *operate=&p[key&(Hash_table_length-1)];
    if(operate->key==key){
        if(operate->depth>=depth){
            if(operate->type==HashExact){
               return operate->value;
            }
            if ((operate->type == HashAlpha) && (operate->value <= alpha)){
                return alpha;
           }
            if ((operate->type == HashBeta) && (operate->value >= beta)) {
                return beta;
            }
    }
    }
    return -2147483648;
}
