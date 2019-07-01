#include "Search_Engine.h"
#include <pthread.h>
extern int chessboard[6][6];
extern int who;
int Alpha_Beta(int depth, int alpha, int beta, int minimaxplayer, int chessboard_test[][6])
{
    if (depth == 0 || judge())
    {
        return Evaluate_test(chessboard_test);
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
            eval = Alpha_Beta(depth - 1, alpha, beta, -minimaxplayer, chessboard_test);
            maxEval = max(maxEval, eval);
            alpha = max(alpha, eval);
            chessboard[h->list[a].to.x][h->list[a].to.y] = origin;
            chessboard[h->list[a].from.x][h->list[a].from.y] = who;
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
            eval = Alpha_Beta(depth - 1, alpha, beta, -minimaxplayer, chessboard_test);
            miniEval = mini(miniEval, eval);
            beta = mini(beta, eval);
            chessboard[h->list[a].to.x][h->list[a].to.y] = origin;
            chessboard[h->list[a].from.x][h->list[a].from.y] = -who;
        }

        return miniEval;
    }
}
void *Alpha_Beta_pth(void *Arguement)
{
    Para *arg = (Para *)Arguement;
    arg->value = Alpha_Beta(arg->depth, arg->alpha, arg->beta, arg->minimaxplayer, arg->chessboard);
    pthread_exit(0);
}
int Alpha_Beta_Multi_Thread(int depth, int minimaxplayer)
{

    if (minimaxplayer == who)
    {

        int flag, eval, maxEval = -2147483640, origin;

        Move_List *h = (Move_List *)malloc(sizeof(Move_List *));
        h->flag = 0;
        Move_Generate(h, who);
        pthread_t tids[h->flag];
        Para arg[h->flag];
        pthread_attr_t attr;
        pthread_attr_init(&attr);

        for (int a = 0; a < h->flag; a++)
        {

            origin = chessboard[h->list[a].to.x][h->list[a].to.y];
            chessboard[h->list[a].from.x][h->list[a].from.y] = 0;
            chessboard[h->list[a].to.x][h->list[a].to.y] = who;
            for (int a = 0; a < 6; a++)
            {
                for (int b = 0; b < 6; b++)
                {
                    arg[a].chessboard[a][b] = chessboard[a][b];
                }
            }
            arg[a].alpha = -2147483648;
            arg[a].beta = 2147483647;
            arg[a].depth = depth - 1;
            arg[a].minimaxplayer = minimaxplayer;
            pthread_create(&tids[a], &attr, Alpha_Beta_pth, &arg[a]);
            chessboard[h->list[a].to.x][h->list[a].to.y] = origin;
            chessboard[h->list[a].from.x][h->list[a].from.y] = who;
        }
        for (int a = 0; a < h->flag; a++)
        {
            pthread_join(tids[a], NULL);
        }
        for (int a = 0; a < h->flag; a++)
        {
            maxEval = max(maxEval, arg[a].value);
        }
        return maxEval;
    }
    else
    {

        int flag, eval, miniEval = 2147483640, origin;

        Move_List *h = (Move_List *)malloc(sizeof(Move_List *));
        h->flag = 0;
        Move_Generate(h, -who);
        pthread_t tids[h->flag];
        Para arg[h->flag];
        pthread_attr_t attr;
        pthread_attr_init(&attr);
        int original[6][6];
        for (int a = 0; a < 6; a++)
        {
            for (int b = 0; b < 6; b++)
            {
                original[a][b] = chessboard[a][b];
            }
        }
        for (int a = 0; a < h->flag; a++)
        {
            origin = chessboard[h->list[a].to.x][h->list[a].to.y];
            chessboard[h->list[a].from.x][h->list[a].from.y] = 0;
            chessboard[h->list[a].to.x][h->list[a].to.y] = who;
            for (int d = 0; d < 6; d++)
            {
                for (int b = 0; b < 6; b++)
                {
                    arg[a].chessboard[d][b] = chessboard[d][b];
                }
            }
            arg[a].alpha = -2147483648;
            arg[a].beta = 2147483647;
            arg[a].depth = depth - 1;
            arg[a].minimaxplayer = minimaxplayer;
            pthread_create(&tids[a], &attr, Alpha_Beta_pth, &arg[a]);
            chessboard[h->list[a].to.x][h->list[a].to.y] = origin;
            chessboard[h->list[a].from.x][h->list[a].from.y] = -who;
           
        }

        for (int a = 0; a < h->flag; a++)
        {
            pthread_join(tids[a], NULL);
        }
        for (int a = 0; a < 6; a++)
        {
            for (int b = 0; b < 6; b++)
            {
                if (original[a][b] != chessboard[a][b])
                {
                    printf("depth=%d Big Error!!\n\n", depth);
                    for (int c = 0; c < 6; c++)
                    {
                        for (int d = 0; d < 6; d++)
                        {
                            if (chessboard[c][d] == -1)
                                printf("2 ");
                            else
                                printf("%d ", chessboard[c][d]);
                        }
                        printf("\n");
                    }
                    printf("\n");

                    for (int c = 0; c < 6; c++)
                    {
                        for (int d = 0; d < 6; d++)
                        {
                            if (original[c][d] == -1)
                                printf("2 ");
                            else
                                printf("%d ", original[c][d]);
                        }
                        printf("\n");
                    }
                    exit(0);
                }
            }
        }

        for (int a = 0; a < h->flag; a++)
        {
            miniEval = mini(miniEval, arg[a].value);
        }
        return miniEval;
    }
}
