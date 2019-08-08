#include "Search_Engine.h"
#include <pthread.h>
extern int chessboard[6][6];
extern int who;
int Alpha_Beta(int depth, int alpha, int beta, int minimaxplayer,int chessboard_test[][6],Hash_Move *p)
{
    static int count;
    count++;
    int hashf=HashAlpha;
    if (depth == 0 || judge(chessboard_test))
    {
        int value=Evaluate_test(chessboard_test);
        //Hash_store(p,HashExact,depth,value,chessboard_test);
        return value;
    }
    //int value=Hash_Hit(p,depth,alpha,beta,chessboard_test);
    //if(value!=-2147483648)
   // return value;
    if (minimaxplayer == who)
    {

        int flag, eval, maxEval = -2147483640, origin;

         Move_List *h = (Move_List *)malloc(sizeof(Move_List));
         h->flag = 0;
        Move_Generate(h, who,chessboard_test);

        for (int a = 0; a < h->flag; a++)
        {
            origin = chessboard_test[h->list[a].to.x][h->list[a].to.y];
            chessboard_test[h->list[a].from.x][h->list[a].from.y] = 0;
            chessboard_test[h->list[a].to.x][h->list[a].to.y] = who;
            eval = Alpha_Beta(depth - 1, alpha, beta, -minimaxplayer, chessboard_test,p);
            maxEval = max(maxEval, eval);
            alpha = max(alpha, eval);
            chessboard_test[h->list[a].to.x][h->list[a].to.y] = origin;
            chessboard_test[h->list[a].from.x][h->list[a].from.y] = who;
             if (beta <= alpha){
                Hash_store(p,HashAlpha,depth,alpha,chessboard_test);
                break;
             }
        }
        free(h);
       Hash_store(p,HashExact,depth,maxEval,chessboard_test);
        return maxEval;
    }
    else
    {

        int flag, eval, miniEval = 2147483640, origin, test, test_1;

        Move_List *h = (Move_List *)malloc(sizeof(Move_List));
        h->flag = 0;
        Move_Generate(h, -who,chessboard_test);

        for (int a = 0; a < h->flag; a++)
        {

            origin = chessboard_test[h->list[a].to.x][h->list[a].to.y];
            chessboard_test[h->list[a].from.x][h->list[a].from.y] = 0;
            chessboard_test[h->list[a].to.x][h->list[a].to.y] = -who;
            eval = Alpha_Beta(depth - 1, alpha, beta, -minimaxplayer, chessboard_test,p);
            miniEval = mini(miniEval, eval);
            beta = mini(beta, eval);
            chessboard_test[h->list[a].to.x][h->list[a].to.y] = origin;
            chessboard_test[h->list[a].from.x][h->list[a].from.y] = -who;
             if (beta <= alpha){
            Hash_store(p,HashBeta,depth,beta,chessboard_test);
            break;
             } 
        }
        free(h);
         Hash_store(p,HashExact,depth,miniEval,chessboard_test);
        return miniEval;
    }
}
void *Alpha_Beta_pth(void *Arguement)
{
    Para *arg = (Para *)Arguement;
    Hash_Move *p=(Hash_Move *)malloc(Hash_table_length*sizeof(Hash_Move));

    Hash_Table_Init(p);
    arg->value = Alpha_Beta(arg->depth, arg->alpha,arg->beta, arg->minimaxplayer, arg->chessboard,p);
    pthread_exit(0);
}
int Alpha_Beta_Multi_Thread(int depth, int minimaxplayer,int alpha,int beta)
{
    int best_choice;
   if(judge(chessboard)==1)
  return -9999;
  else if(judge(chessboard)==2)
  return 9999;
  else{
    if (minimaxplayer == who)
    {

        int flag, eval, maxEval = -2147483640, origin;

        Move_List *h = (Move_List *)malloc(sizeof(Move_List));
        h->flag = 0;
        Move_Generate(h, who,chessboard);
        pthread_t tids[h->flag];
        Para arg[h->flag];
        pthread_attr_t attr;
        pthread_attr_init(&attr);

        for (int a = 0; a < h->flag; a++)
        {

            for (int a = 0; a < h->flag; a++)
        {
           
            
            for (int d = 0; d < 6; d++)
            {
                for (int b = 0; b < 6; b++)
                {
                    arg[a].chessboard[d][b] = chessboard[d][b];
                }
            }
              arg[a].chessboard[h->list[a].from.x][h->list[a].from.y] = 0;
             arg[a].chessboard[h->list[a].to.x][h->list[a].to.y] = who;
            arg[a].alpha=alpha;
            arg[a].beta=beta;
            arg[a].depth = depth - 1;
            arg[a].minimaxplayer = -minimaxplayer;
            pthread_create(&tids[a], &attr, Alpha_Beta_pth, &arg[a]);
       
        }
        for (int a = 0; a < h->flag; a++)
        {
            pthread_join(tids[a], NULL);
        }
        for (int a = 0; a < h->flag; a++)
        {
            if(arg[a].value>maxEval)
            best_choice=a;
            maxEval = max(maxEval, arg[a].value);
            
        }
       
    }
     free(h);
     return maxEval;
    }
    else
    {

        int flag, eval, miniEval = 2147483640, origin;

        Move_List *h = (Move_List *)malloc(sizeof(Move_List));
        h->flag = 0;
        Move_Generate(h, -who,chessboard);

        pthread_t tids[h->flag];
        Para arg[h->flag];
        pthread_attr_t attr;
        pthread_attr_init(&attr);
        for (int a = 0; a < h->flag; a++)
        {
            
            for (int d = 0; d < 6; d++)
            {
                for (int b = 0; b < 6; b++)
                {
                    arg[a].chessboard[d][b] = chessboard[d][b];
                }
            }
            arg[a].chessboard[h->list[a].from.x][h->list[a].from.y] = 0;
            arg[a].chessboard[h->list[a].to.x][h->list[a].to.y] = -who;
            arg[a].alpha=alpha;
            arg[a].beta=beta;
            arg[a].depth = depth - 1;
            arg[a].minimaxplayer = -minimaxplayer;
            pthread_create(&tids[a], &attr, Alpha_Beta_pth, &arg[a]);
           
        }

        for (int a = 0; a < h->flag; a++)
        {
            pthread_join(tids[a], NULL);
        }
      

        for (int a = 0; a < h->flag; a++)
        {
            if(arg[a].value<miniEval)
            best_choice=a;
            miniEval = mini(miniEval, arg[a].value);
        }
        free(h);
        return  miniEval;
    }
}
}
void AI(int depth){
        int a=Alpha_Beta_Multi_Thread(depth,1,-20000000,200000000);
        Move_List *h = (Move_List *)malloc(sizeof(Move_List));
        h->flag = 0;
        Move_Generate(h, who,chessboard);
        chessboard[h->list[a].from.x][h->list[a].from.y]=0;
        chessboard[h->list[a].to.x][h->list[a].to.y]=who;

}
int Alpha_Beta_new(int depth, int alpha, int beta, int minimaxplayer,int chessboard_test[][6],Hash_Move *p)
{
    static int count;
    count++;
    int hashf=HashAlpha;
    if (depth == 0 || judge(chessboard_test))
    {  
      
        int value=Evaluate_test(chessboard_test);
         visualize_board();
       printf("depth=%d value=%d\n",depth,value);
        //Hash_store(p,HashExact,depth,value,chessboard_test);
        return value;
        
    }
    //int value=Hash_Hit(p,depth,alpha,beta,chessboard_test);
    //if(value!=-2147483648)
   // return value;
    if (minimaxplayer == who)
    {

        int flag, eval, maxEval = -2147483640, origin;

         Move_List *h = (Move_List *)malloc(sizeof(Move_List));
         h->flag = 0;
        Move_Generate(h, who,chessboard_test);

        for (int a = 0; a < h->flag; a++)
        {
            origin = chessboard_test[h->list[a].to.x][h->list[a].to.y];
            chessboard_test[h->list[a].from.x][h->list[a].from.y] = 0;
            chessboard_test[h->list[a].to.x][h->list[a].to.y] = who;
            eval = Alpha_Beta_new(depth - 1, alpha, beta, -minimaxplayer, chessboard_test,p);
            maxEval = max(maxEval, eval);
            alpha = max(alpha, eval);
            chessboard_test[h->list[a].to.x][h->list[a].to.y] = origin;
            chessboard_test[h->list[a].from.x][h->list[a].from.y] = who;
           if(beta<=alpha)
           break;
        }
        free(h);
       Hash_store(p,HashExact,depth,maxEval,chessboard_test);
       visualize_board();
       printf("depth=%d value=%d\n",depth,maxEval);
        return maxEval;
    }
    else
    {

        int flag, eval, miniEval = 2147483640, origin, test, test_1;

        Move_List *h = (Move_List *)malloc(sizeof(Move_List));
        h->flag = 0;
        Move_Generate(h, -who,chessboard_test);

        for (int a = 0; a < h->flag; a++)
        {

            origin = chessboard_test[h->list[a].to.x][h->list[a].to.y];
            chessboard_test[h->list[a].from.x][h->list[a].from.y] = 0;
            chessboard_test[h->list[a].to.x][h->list[a].to.y] = -who;
            eval = Alpha_Beta_new(depth - 1, alpha, beta, -minimaxplayer, chessboard_test,p);
            miniEval = mini(miniEval, eval);
            beta = mini(beta, eval);
            chessboard_test[h->list[a].to.x][h->list[a].to.y] = origin;
            chessboard_test[h->list[a].from.x][h->list[a].from.y] = -who;
           if(beta<=alpha)
           break;
        }
        free(h);
         Hash_store(p,HashExact,depth,miniEval,chessboard_test);
         visualize_board();
       printf("depth=%d value=%d",depth,miniEval);
        return miniEval;
    }
}