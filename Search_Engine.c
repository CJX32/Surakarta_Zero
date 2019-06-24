#include "Search_Engine.h"
#include <pthread.h>
extern int chessboard[6][6];
extern int who;
int Alpha_Beta(int depth, int alpha, int beta, int minimaxplayer)
{
    if (depth == 0 || judge())
    {
       
       return Evaluate();
    }
    if (minimaxplayer == who)
    {

        int flag, eval, maxEval = -2147483640, origin;

        Move_List *h, head;
        h = &head;
        h->flag = 0;
        Move_Generate(h, who);

        for (int a = 0; a < h->flag; a++)
        {
           
            origin = chessboard[h->list[a].to.x][h->list[a].to.y];
            chessboard[h->list[a].from.x][h->list[a].from.y] = 0;
            chessboard[h->list[a].to.x][h->list[a].to.y] = who;
            eval = Alpha_Beta(depth - 1, alpha, beta, -minimaxplayer);
            maxEval = max(maxEval, eval);
            alpha = max(alpha, eval);
            chessboard[h->list[a].to.x][h->list[a].to.y] = origin;
            chessboard[h->list[a].from.x][h->list[a].from.y] = who;

            if (beta <= alpha)
                break;
        }

        return maxEval;
    }
    else
    {

        int flag, eval, miniEval = 2147483647, origin, test, test_1;

        Move_List *h, head;
        h = &head;
        h->flag = 0;
        Move_Generate(h, -who);

        for (int a = 0; a < h->flag; a++)
        {
           
            origin = chessboard[h->list[a].to.x][h->list[a].to.y];
            chessboard[h->list[a].from.x][h->list[a].from.y] = 0;
            chessboard[h->list[a].to.x][h->list[a].to.y] = -who;
            eval = Alpha_Beta(depth - 1, alpha, beta, -minimaxplayer);
            miniEval = mini(miniEval, eval);
            beta = mini(beta, eval);
            chessboard[h->list[a].to.x][h->list[a].to.y] = origin;
            chessboard[h->list[a].from.x][h->list[a].from.y] = -who;
             if (beta <= alpha)
                break;
        }

        return miniEval;
    }
}






int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
int mini(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}