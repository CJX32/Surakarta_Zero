#include "Hash_Table.h"
extern uint64_t Hash_Board[6][6][2];
extern int chessboard[6][6];
uint64_t rand64(void)
{
    return rand() ^ ((uint64_t)rand() << 15) ^ ((uint64_t)rand() << 30) ^ ((uint64_t)rand() << 45) ^ ((uint64_t)rand() << 60);
};
void initialize_Hash_Board(void)
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
uint64_t Hash_Key(void)
{
    uint64_t result = 0;
    for (int a = 0; a < 6; a++)
    {
        for (int b = 0; b < 6; b++)
        {
            if (chessboard[a][b] == 1)
            {
                result = result ^ Hash_Board[a][b][0];
            }
            else if (chessboard[a][b] == -1)
            {
                result = result ^ Hash_Board[a][b][1];
            }
        }
    }
    return result;
}
uint64_t Hash_hit(uint64_t  key,int depth,int type){

}