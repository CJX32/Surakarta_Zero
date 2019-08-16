#include "Search_Engine.h"
#include <pthread.h>
extern int chessboard[6][6];
extern int who;
int Alpha_Beta(int depth, int alpha, int beta, int minimaxplayer,int chessboard_test[][6],Hash_Move *p)
{

    int hashf=HashAlpha;
    if (depth <= 0 || judge(chessboard_test))
    {
    
        int value=Evaluate_test(chessboard_test,minimaxplayer);
       // Hash_store(p,HashExact,depth,value,chessboard_test);
        return value;
    }
    int value=Hash_Hit(p,depth,alpha,beta,chessboard_test);
    if(value!=-2147483648)
    return value;
    int flag, val,origin;

     Move_List *h = (Move_List *)malloc(sizeof(Move_List));
     h->flag=0;
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
int Alpha_Beta_PVS(int depth, int alpha, int beta, int minimaxplayer,int chessboard_test[][6],Hash_Move *p)
{
    int fFoundPv=0;
    int hashf=HashAlpha;
    if (depth <= 0 || judge(chessboard_test))
    {
    
        int value=Evaluate_test(chessboard_test,minimaxplayer);
       // Hash_store(p,HashExact,depth,value,chessboard_test);
        return value;
    }
    int value=Hash_Hit(p,depth,alpha,beta,chessboard_test);
    if(value!=-2147483648)
    return value;
    int flag, val,origin;

     Move_List *h = (Move_List *)malloc(sizeof(Move_List));
     h->flag=0;
     Move_Generate(h, minimaxplayer,chessboard_test);
  
     
        for (int a = 0; a < h->flag; a++)
        {

            origin = chessboard_test[h->list[a].to.x][h->list[a].to.y];
            chessboard_test[h->list[a].from.x][h->list[a].from.y] = 0;
            chessboard_test[h->list[a].to.x][h->list[a].to.y] = minimaxplayer;
            if(fFoundPv){
              val = -Alpha_Beta(depth - 1, -alpha-1, -alpha, -minimaxplayer, chessboard_test,p);
              if((val > alpha) && (val < beta)) { 
              val = -Alpha_Beta(depth - 1, -beta, -alpha,-minimaxplayer,chessboard_test,p);
              }
            }     
            else
            {
            val = -Alpha_Beta(depth - 1, -beta, -alpha, -minimaxplayer, chessboard_test,p);
            }
            chessboard_test[h->list[a].to.x][h->list[a].to.y] = origin;
            chessboard_test[h->list[a].from.x][h->list[a].from.y] = minimaxplayer;
            if(val>=beta){
            Hash_store(p,HashBeta,depth,beta,chessboard_test);
            return beta;
            }

            if(val>alpha){
            hashf=HashExact;
            alpha=val;
            fFoundPv=1;
            }
        }
        free(h);
        Hash_store(p,hashf,depth,alpha,chessboard_test);
        return alpha;
    
}
int Alpha_Beta_Null_Move(int depth, int alpha, int beta, int minimaxplayer,int chessboard_test[][6],Hash_Move *p)
{
    static int count;
    count++;
    int hashf=HashAlpha;
    if (depth <= 0 || judge(chessboard_test))
    {
    
        int value=Evaluate(chessboard_test,minimaxplayer);
       // Hash_store(p,HashExact,depth,value,chessboard_test);
        return value;
    }
    int value=Hash_Hit(p,depth,alpha,beta,chessboard_test);
    if(value!=-2147483648)
    return value;
    int flag, val,origin;
    {
     Move_List *h = (Move_List *)malloc(sizeof(Move_List));
     h->flag=0;
     Move_Generate(h, -minimaxplayer,chessboard_test);
     for (int a = 0; a < h->flag; a++)
        {
       origin = chessboard_test[h->list[a].to.x][h->list[a].to.y];
            chessboard_test[h->list[a].from.x][h->list[a].from.y] = 0;
            chessboard_test[h->list[a].to.x][h->list[a].to.y] = -minimaxplayer;
             val = -Alpha_Beta(depth - 1-2 , -beta, -beta+1, minimaxplayer, chessboard_test,p);
            chessboard_test[h->list[a].to.x][h->list[a].to.y] = origin;
            chessboard_test[h->list[a].from.x][h->list[a].from.y] = -minimaxplayer;
            if(val>=beta)
            return beta;
        }

    }

     Move_List *h = (Move_List *)malloc(sizeof(Move_List));
     h->flag=0;
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
int Alpha_Beta_new(int depth, int alpha, int beta, int minimaxplayer,int chessboard_test[][6],Hash_Move *p)
{
    static int count;
    count++;
    int hashf=HashAlpha;
    int best_move=0;
    if (depth == 0 || judge(chessboard_test))
    {
        int value=Evaluate_test(chessboard_test,minimaxplayer);
       
       // Hash_store(p,HashExact,depth,value,chessboard_test);
        return value;
    }
    int value=Hash_Hit(p,depth,alpha,beta,chessboard_test);
    if(value!=-2147483648)
    return value;
    int flag, val,origin;
     Move_List *h = (Move_List *)malloc(sizeof(Move_List));
     h->flag=0;
     Move_Generate(h, minimaxplayer,chessboard_test);
  
     printf("%d\n",h->flag);
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
            best_move=a;
            }
        }
        free(h);
     

         printf("%d\n",alpha);
        Hash_store(p,hashf,depth,alpha,chessboard_test);
        return best_move;
    
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
int Quies(int alpha, int beta,int minimaxplayer,int chessboard_test[][6]){
 
int val = Evaluate(chessboard_test,minimaxplayer);
if (val >= beta) {
    return beta;
}
if (val > alpha) {
alpha = val;
}
 Move_List *h = (Move_List *)malloc(sizeof(Move_List));
     h->flag=0;
 Generate_Move_Attack(h,minimaxplayer,chessboard_test);
 int origin;
   for (int a = 0; a < h->flag; a++)
        {

            origin = chessboard_test[h->list[a].to.x][h->list[a].to.y];
            chessboard_test[h->list[a].from.x][h->list[a].from.y] = 0;
            chessboard_test[h->list[a].to.x][h->list[a].to.y] = minimaxplayer;
             val = -Quies(-beta, -alpha,-minimaxplayer,chessboard_test);
            chessboard_test[h->list[a].to.x][h->list[a].to.y] = origin;
            chessboard_test[h->list[a].from.x][h->list[a].from.y] = minimaxplayer;
  if (val >= beta) {
   return beta;
 }
    if (val > alpha) {
   alpha = val;
  }
 }
  return alpha;
}
void AI(int depth){
    Hash_Move *p;
    
      
       int alpha=-2147483640,beta=2147483640;
   
       p=(Hash_Move *)malloc((Hash_table_length)*sizeof(Hash_Move));
       Hash_Table_Init(p);
        int a=Alpha_Beta_new(depth,alpha,beta,-1,chessboard,p);
        Move_List *h = (Move_List *)malloc(sizeof(Move_List));
        h->flag = 0;
        Move_Generate(h, who,chessboard);
    
        printf("a=%d flag=%d %d\nfrom%d %d to%d %d\n",a,h->flag,chessboard[h->list[a].from.x][h->list[a].from.y],h->list[a].from.x,h->list[a].from.y,h->list[a].to.x,h->list[a].to.y);
        chessboard[h->list[a].from.x][h->list[a].from.y]=0;
        chessboard[h->list[a].to.x][h->list[a].to.y]=who;

}