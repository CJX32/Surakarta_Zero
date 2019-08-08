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
       // Hash_store(p,HashExact,depth,value,chessboard_test);
        return value;
    }
    //int value=Hash_Hit(p,depth,alpha,beta,chessboard_test);
    //if(value!=-2147483648)
    //return value;
    int flag, val,origin;
     Move_List *h = (Move_List *)malloc(sizeof(Move_List));
     
     Move_Generate(h, minimaxplayer,chessboard_test);
  
     
        for (int a = 0; a < h->flag; a++)
        {

            origin = chessboard_test[h->list[a].to.x][h->list[a].to.y];
            chessboard_test[h->list[a].from.x][h->list[a].from.y] = 0;
            chessboard_test[h->list[a].to.x][h->list[a].to.y] = minimaxplayer;
            val = -Alpha_Beta(depth - 1, -beta, -alpha, -minimaxplayer, chessboard_test,p);
            chessboard_test[h->list[a].to.x][h->list[a].to.y] = origin;
            chessboard_test[h->list[a].from.x][h->list[a].from.y] = minimaxplayer;
            if(val>=beta){
            Hash_store(p,HashBeta,depth,beta,chessboard_test);
            return beta;
            }
            if(val>alpha){
            hashf=HashExact;
            alpha=val;
            }
        }
        free(h);
        Hash_store(p,hashf,depth,alpha,chessboard_test);
        return alpha;
    
}
Result Alpha_Beta_test(int depth, int alpha, int beta, int minimaxplayer,int chessboard_test[][6],Hash_Move *p,int best)
{
    Result answer;
    answer.best_move=0;
    static int count;
    count++;
    int hashf=HashAlpha;
    int best_move=0;
    if (depth == 0 || judge(chessboard_test))
    {
        int value=Evaluate_test(chessboard_test);
       // Hash_store(p,HashExact,depth,value,chessboard_test);
        answer.value=value;
        return answer;
    }
    int value=Hash_Hit(p,depth,alpha,beta,chessboard_test);
    if(value!=-2147483648){
     answer.value=value;
        return answer;
    }
    int flag, val,origin;
     Move_List *h = (Move_List *)malloc(sizeof(Move_List));

     Move_Generate(h, minimaxplayer,chessboard_test);
     switch_move(h,best);
     
        for (int a = 0; a < h->flag; a++)
        {

            origin = chessboard_test[h->list[a].to.x][h->list[a].to.y];
            chessboard_test[h->list[a].from.x][h->list[a].from.y] = 0;
            chessboard_test[h->list[a].to.x][h->list[a].to.y] = minimaxplayer;
            val = -Alpha_Beta(depth - 1, -beta, -alpha, -minimaxplayer, chessboard_test,p);
            chessboard_test[h->list[a].to.x][h->list[a].to.y] = origin;
            chessboard_test[h->list[a].from.x][h->list[a].from.y] = minimaxplayer;
            if(val>=beta){
            Hash_store(p,HashBeta,depth,beta,chessboard_test);
            answer.value=beta;
            return answer;
            }
            if(val>alpha){
            answer.best_move=a;
            hashf=HashExact;
            alpha=val;
            }
        }
        free(h);
        Hash_store(p,hashf,depth,alpha,chessboard_test);
        answer.value=alpha;
        return answer;
    
}

void *Alpha_Beta_pth(void *Arguement)
{
    Para *arg = (Para *)Arguement;
    Hash_Move *p=(Hash_Move *)malloc(Hash_table_length*sizeof(Hash_Move));

    Hash_Table_Init(p);
    arg->value = -Alpha_Beta(arg->depth, -arg->beta,-arg->alpha, arg->minimaxplayer, arg->chessboard,p);
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
    
  

        int flag, eval, miniEval = 2147483640, origin;

        Move_List *h = (Move_List *)malloc(sizeof(Move_List));
        h->flag = 0;
        Move_Generate(h, minimaxplayer,chessboard);

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
            arg[a].chessboard[h->list[a].to.x][h->list[a].to.y] = minimaxplayer;
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
        
        for(int a = 0; a < h->flag; a++)
        {  
         
            if(arg[a].value>alpha){
                best_choice=a;
            alpha=arg[a].value;
            }

        }
        free(h);
        return alpha;      //注意还原 return best_choice
    
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
