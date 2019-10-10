#include "Search_Engine.h"
#include <pthread.h>
extern Chessboard chessboard;
extern int who;
int tid_num;
int alpha_index,beta_index;
pthread_rwlock_t lock;
int Alpha_Beta(int depth, int alpha, int beta, int minimaxplayer,Chessboard chessboard_test,Hash_Move *p)
{
    
    int hashf=HashAlpha;
    if (depth <= 0 || judge(chessboard_test))
    {
    
        int value=Evaluate_test(chessboard_test,minimaxplayer);
       // Hash_store(p,HashExact,depth,value,chessboard_test);
    
        return value;
    }
   /* int value=Hash_Hit(p,depth,alpha,beta,chessboard_test);
    if(value!=-2147483648)
    return value;*/
    int flag, val,origin;

     Move_List *h = (Move_List *)malloc(sizeof(Move_List));
     h->flag=0;
     Move_Generate(h, minimaxplayer,chessboard_test);

     
        for (int a = 0; a < h->flag; a++)
        {

            origin = chessboard_test.chessboard[h->list[a].to.x][h->list[a].to.y];
            
            chessboard_test.chessboard[h->list[a].from.x][h->list[a].from.y] = 0;
            chessboard_test.chessboard[h->list[a].to.x][h->list[a].to.y] = minimaxplayer;
            if(origin==-minimaxplayer)
            {
                if(-minimaxplayer==1)
                chessboard_test.black-=1;
                else
                chessboard_test.white-=1;
            }
            

            val = -Alpha_Beta(depth - 1, -beta, -alpha, -minimaxplayer, chessboard_test,p);
               if(origin==-minimaxplayer)
            {
                if(-minimaxplayer==1)
                chessboard_test.black+=1;
                else
                chessboard_test.white+=1;
            }
            chessboard_test.chessboard[h->list[a].to.x][h->list[a].to.y] = origin;
            chessboard_test.chessboard[h->list[a].from.x][h->list[a].from.y] = minimaxplayer;
            if(val>=beta){
           // Hash_store(p,HashBeta,depth,beta,chessboard_test);
            return beta;
            }

            if(val>alpha){
            hashf=HashExact;
            alpha=val;

            }
        }
       // printf("%d depth=%d %d  \n",h->flag,depth,alpha);
        free(h);
       // Hash_store(p,hashf,depth,alpha,chessboard_test);

        return alpha;
    
}
int Alpha_Beta_PVS(int depth, int alpha, int beta, int minimaxplayer,Chessboard chessboard_test,Hash_Move *p)
{
    int fFoundPv=0;
    int hashf=HashAlpha;
    if (depth <= 0 || judge(chessboard_test))
    {
    
        int value=Evaluate_test(chessboard_test,minimaxplayer);
       // Hash_store(p,HashExact,depth,value,chessboard_test);
        return value;
    }
  //  int value=Hash_Hit(p,depth,alpha,beta,chessboard_test);
  //  if(value!=-2147483648)
   // return value;
    int flag, val,origin;

     Move_List *h = (Move_List *)malloc(sizeof(Move_List));
     h->flag=0;
     Move_Generate(h, minimaxplayer,chessboard_test);
  
     
        for (int a = 0; a < h->flag; a++)
        {

            origin = chessboard_test.chessboard[h->list[a].to.x][h->list[a].to.y];
            chessboard_test.chessboard[h->list[a].from.x][h->list[a].from.y] = 0;
            chessboard_test.chessboard[h->list[a].to.x][h->list[a].to.y] = minimaxplayer;
               if(origin==-minimaxplayer)
            {
                if(-minimaxplayer==1)
                chessboard_test.black-=1;
                else
                chessboard_test.white-=1;
            }
            if(fFoundPv){
              val = -Alpha_Beta_PVS(depth - 1, -alpha-1, -alpha, -minimaxplayer, chessboard_test,p);
              if((val > alpha) && (val < beta)) { 
              val = -Alpha_Beta_PVS(depth - 1, -beta, -alpha,-minimaxplayer,chessboard_test,p);
              }
            }   
            else
            {
    
            val = -Alpha_Beta_PVS(depth - 1, -beta, -alpha, -minimaxplayer, chessboard_test,p);
            }
               if(origin==-minimaxplayer)
            {
                if(-minimaxplayer==1)
                chessboard_test.black+=1;
                else
                chessboard_test.white+=1;
            }
            chessboard_test.chessboard[h->list[a].to.x][h->list[a].to.y] = origin;
            chessboard_test.chessboard[h->list[a].from.x][h->list[a].from.y] = minimaxplayer;
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
        if(depth==7)
        printf("alpha=%d\n",alpha);
        return alpha;
    
}
int Alpha_Beta_Null_Move(int depth, int alpha, int beta, int minimaxplayer,Chessboard chessboard_test,Hash_Move *p)
{
    static int count;
    count++;
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
    {
     Move_List *h = (Move_List *)malloc(sizeof(Move_List));
     h->flag=0;
     Move_Generate(h, -minimaxplayer,chessboard_test);
     for (int a = 0; a < h->flag; a++)
        {
       origin = chessboard_test.chessboard[h->list[a].to.x][h->list[a].to.y];
            chessboard_test.chessboard[h->list[a].from.x][h->list[a].from.y] = 0;
            chessboard_test.chessboard[h->list[a].to.x][h->list[a].to.y] = -minimaxplayer;
               if(origin==minimaxplayer)
            {
                if(minimaxplayer==1)
                chessboard_test.black-=1;
                else
                chessboard_test.white-=1;
            }
             val = -Alpha_Beta(depth - 1-2 , -beta, -beta+1, minimaxplayer, chessboard_test,p);
                if(origin==minimaxplayer)
            {
                if(minimaxplayer==1)
                chessboard_test.black+=1;
                else
                chessboard_test.white+=1;
            }
            chessboard_test.chessboard[h->list[a].to.x][h->list[a].to.y] = origin;
            chessboard_test.chessboard[h->list[a].from.x][h->list[a].from.y] = -minimaxplayer;
            if(val>=beta)
            return beta;
        }

    }

     Move_List *h = (Move_List *)malloc(sizeof(Move_List));
     h->flag=0;
     Move_Generate(h, minimaxplayer,chessboard_test);
  
     
        for (int a = 0; a < h->flag; a++)
        {

            origin = chessboard_test.chessboard[h->list[a].to.x][h->list[a].to.y];
            chessboard_test.chessboard[h->list[a].from.x][h->list[a].from.y] = 0;
            chessboard_test.chessboard[h->list[a].to.x][h->list[a].to.y] = minimaxplayer;
               if(origin==-minimaxplayer)
            {
                if(-minimaxplayer==1)
                chessboard_test.black-=1;
                else
                chessboard_test.white-=1;
            }
            val = -Alpha_Beta(depth - 1, -beta, -alpha, -minimaxplayer, chessboard_test,p);
               if(origin==-minimaxplayer)
            {
                if(-minimaxplayer==1)
                chessboard_test.black+=1;
                else
                chessboard_test.white+=1;
            }
            chessboard_test.chessboard[h->list[a].to.x][h->list[a].to.y] = origin;
            chessboard_test.chessboard[h->list[a].from.x][h->list[a].from.y] = minimaxplayer;
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
int Alpha_Beta_PVS_Multi_Thread(int depth, int alpha,int beta, int minimaxplayer,Chessboard chessboard_test,Hash_Move *p)
{

    int fFoundPv=0;
    int hashf=HashAlpha;
    int count=0;
    if (depth <= 0 || judge(chessboard_test))
    {
      
        int value=Evaluate_test(chessboard_test,minimaxplayer);
     //  Hash_store(p,HashExact,depth,value,chessboard_test);
        return value;
    }
    //int value=Hash_Hit(p,depth,alpha,beta,chessboard_test);
    //if(value!=-2147483648)
    //return value;
    int flag, val,origin;

     Move_List *h = (Move_List *)malloc(sizeof(Move_List));
     h->flag=0;
     Move_Generate(h, minimaxplayer,chessboard_test);
  
     
        for (int a = 0; a < h->flag; a++)
        {

            origin = chessboard_test.chessboard[h->list[a].to.x][h->list[a].to.y];
            chessboard_test.chessboard[h->list[a].from.x][h->list[a].from.y] = 0;
            chessboard_test.chessboard[h->list[a].to.x][h->list[a].to.y] = minimaxplayer;
               if(origin==-minimaxplayer)
            {
                if(-minimaxplayer==1)
                chessboard_test.black-=1;
                else
                chessboard_test.white-=1;
            }
            pthread_rwlock_rdlock(&lock);
            if(alpha_index>beta){
              beta=alpha_index;
            }
            pthread_rwlock_unlock(&lock);
            if(fFoundPv){
              val = -Alpha_Beta_PVS(depth - 1, -alpha-1, -alpha, -minimaxplayer, chessboard_test,p);
              if((val > alpha) && (val < beta)) { 
              val = -Alpha_Beta_PVS(depth - 1, -beta, -alpha,-minimaxplayer,chessboard_test,p);
              }
            }    
           else
            {
            val = -Alpha_Beta_PVS(depth - 1, -beta, -alpha, -minimaxplayer, chessboard_test,p);
            }
               if(origin==-minimaxplayer)
            {
                if(-minimaxplayer==1)
                chessboard_test.black+=1;
                else
                chessboard_test.white+=1;
            }
            chessboard_test.chessboard[h->list[a].to.x][h->list[a].to.y] = origin;
            chessboard_test.chessboard[h->list[a].from.x][h->list[a].from.y] = minimaxplayer;
            pthread_rwlock_rdlock(&lock);
            if(alpha_index>beta){
              beta=alpha_index;
            }
            pthread_rwlock_unlock(&lock);
            if(val>=beta){
            Hash_store(p,HashBeta,depth,beta,chessboard_test);
            update(alpha);
            return beta;
            }

            if(val>alpha){
            hashf=HashExact;
            alpha=val;
            fFoundPv=1;
            update(alpha);
            }
        }
        free(h);
        Hash_store(p,hashf,depth,alpha,chessboard_test);
        return alpha;
    
}
int Alpha_Beta_new(int depth, int alpha, int beta, int minimaxplayer,Chessboard chessboard_test,Hash_Move *p)
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
   /* int value=Hash_Hit(p,depth,alpha,beta,chessboard_test);
    if(value!=-2147483648)
    return value;*/

    int flag, val,origin;
     Move_List *h = (Move_List *)malloc(sizeof(Move_List));
     h->flag=0;

 
 
     Move_Generate(h, minimaxplayer,chessboard_test);


        for (int a = 0; a < h->flag; a++)
        {

            origin = chessboard_test.chessboard[h->list[a].to.x][h->list[a].to.y];
            chessboard_test.chessboard[h->list[a].from.x][h->list[a].from.y] = 0;
            chessboard_test.chessboard[h->list[a].to.x][h->list[a].to.y] = minimaxplayer;
               if(origin==-minimaxplayer)
            {
                if(-minimaxplayer==1)
                chessboard_test.black-=1;
                else
                chessboard_test.white-=1;
            }

           val = -Alpha_Beta_Multi_Thread(depth - 1,  -minimaxplayer,-beta, -alpha,  chessboard_test);
           //val=-Alpha_Beta_PVS(depth-1,-beta,-alpha,-minimaxplayer,chessboard_test,p);
            //val=-Alpha_Beta(depth-1,-beta,-alpha,-minimaxplayer,chessboard_test,p);
               if(origin==-minimaxplayer)
            {
                if(-minimaxplayer==1)
                chessboard_test.black+=1;
                else
                chessboard_test.white+=1;
            }
            chessboard_test.chessboard[h->list[a].to.x][h->list[a].to.y] = origin;
            chessboard_test.chessboard[h->list[a].from.x][h->list[a].from.y] = minimaxplayer;
             if(val>=beta){
        //    Hash_store(p,HashBeta,depth,beta,chessboard_test);
           
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
       // printf("best_move=%d\n",best_move);

        return best_move;
    
}
void *Alpha_Beta_pth(void *Arguement)
{

    Para *arg = (Para *)Arguement;
    Hash_Move *p=(Hash_Move *)malloc(Hash_table_length*sizeof(Hash_Move));
    
    Hash_Table_Init(p);
    arg->value = -Alpha_Beta_PVS_Multi_Thread(arg->depth, -2147483646,2147483647, arg->minimaxplayer, arg->chessboard_info,p);
   // printf("arg->value=%d\n",arg->value);
    pthread_exit(0);
}
int Alpha_Beta_Multi_Thread(int depth, int minimaxplayer,int alpha,int beta,Chessboard Chessboard_test)
{

    int best_choice;
   if(judge(Chessboard_test)==1)
  return -9999;
  else if(judge(Chessboard_test)==2)
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
        {
            tid_num=h->flag;
           
        }
        alpha_index=-2147483646;
        beta_index=2147483647;
        pthread_rwlockattr_t lock_attr;
        pthread_rwlockattr_init(&lock_attr);
       pthread_rwlock_init(&lock,&lock_attr);
        for (int a = 0; a < h->flag; a++)
        {
            arg[a].chessboard_info.black=0;
            arg[a].chessboard_info.white=0;
            for (int d = 0; d < 6; d++)
            {
                for (int b = 0; b < 6; b++)
                {
                    arg[a].chessboard_info.chessboard[d][b] = Chessboard_test.chessboard[d][b];
                    if(Chessboard_test.chessboard[d][b]==1)
                   arg[a].chessboard_info.black+=1;
                   else if(Chessboard_test.chessboard[d][b]==-1)
                   arg[a].chessboard_info.white+=1;
                }
            }
            origin= arg[a].chessboard_info.chessboard[h->list[a].to.x][h->list[a].to.y];
            arg[a].chessboard_info.chessboard[h->list[a].from.x][h->list[a].from.y] = 0;
            arg[a].chessboard_info.chessboard[h->list[a].to.x][h->list[a].to.y] = minimaxplayer;
                if(origin==-minimaxplayer)
            {
                if(-minimaxplayer==1)
                 arg[a].chessboard_info.black-=1;
                else
               arg[a].chessboard_info.white-=1;
            }
         
            arg[a].depth = depth - 1;
            arg[a].minimaxplayer = -minimaxplayer;
           
        }
         for (int a = 0; a < h->flag; a++){
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
        pthread_rwlock_destroy(&lock);
        free(h);
        return alpha;      //注意还原 return best_choice
    
}
}
int Quies(int alpha, int beta,int minimaxplayer,Chessboard chessboard_test){
 
int val = Evaluate_test(chessboard_test,minimaxplayer);
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

            origin = chessboard_test.chessboard[h->list[a].to.x][h->list[a].to.y];
            chessboard_test.chessboard[h->list[a].from.x][h->list[a].from.y] = 0;
            chessboard_test.chessboard[h->list[a].to.x][h->list[a].to.y] = minimaxplayer;
               if(origin==-minimaxplayer)
            {
                if(-minimaxplayer==1)
                chessboard_test.black-=1;
                else
                chessboard_test.white-=1;
            }
             val = -Quies(-beta, -alpha,-minimaxplayer,chessboard_test);
                if(origin==-minimaxplayer)
            {
                if(-minimaxplayer==1)
                chessboard_test.black+=1;
                else
                chessboard_test.white+=1;
            }
            chessboard_test.chessboard[h->list[a].to.x][h->list[a].to.y] = origin;
            chessboard_test.chessboard[h->list[a].from.x][h->list[a].from.y] = minimaxplayer;
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
  
        int a=Alpha_Beta_new(depth,alpha,beta,who,chessboard,p);
        Move_List *h = (Move_List *)malloc(sizeof(Move_List));
        h->flag = 0;
        Move_Generate(h, who,chessboard);

       // printf("a=%d\n",a);
       // printf("flag=%d\n",h->flag);
        if( chessboard.chessboard[h->list[a].to.x][h->list[a].to.y]==-who)
        {
            if(who==1)
            chessboard.white-=1;
            else
            chessboard.black-=1;
            
        }
        chessboard.chessboard[h->list[a].from.x][h->list[a].from.y]=0;
        chessboard.chessboard[h->list[a].to.x][h->list[a].to.y]=who;
     // printf("from%d %d to%d %d\n",h->list[a].from.x,h->list[a].from.y,h->list[a].to.x,h->list[a].to.y);
    //printf("white=%d,black=%d\n",chessboard.white,chessboard.black);
      record(h->list[a].from.x,h->list[a].from.y,h->list[a].to.x,h->list[a].to.y);
}