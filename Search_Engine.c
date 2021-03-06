#include "Search_Engine.h"
#include <pthread.h>
extern Chessboard chessboard;
extern int who;
int tid_num;
int *alphas,*betas;
pthread_rwlock_t lock;
FILE *fout;
extern int k1,k2,k3,k4;
int Alpha_Beta(int depth, int alpha, int beta, int minimaxplayer,Chessboard chessboard_test,Hash_Move *p)
{
    
    int hashf=HashAlpha;
    if (depth <= 0 || judge(chessboard_test))
    {
    
        int value=Evaluate(chessboard_test,minimaxplayer);
       // Hash_store(p,HashExact,depth,value,chessboard_test);
       // printf("depth=%d value=%d\n",depth,value);
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
          // if(depth>=5)
           // printf("update %d alpha %d depth=%d\n",val,alpha,depth);
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
    
        int value=Evaluate(chessboard_test,minimaxplayer);
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
    
            if(depth==5)
            val = -Alpha_Beta_Null_Move(depth - 1, -beta, -alpha, -minimaxplayer, chessboard_test,p);
            else
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
  
        return alpha;
    
}
int Alpha_Beta_Null_Move(int depth, int alpha, int beta, int minimaxplayer,Chessboard chessboard_test,Hash_Move *p)
{
 
    int hashf=HashAlpha;
    if (depth <= 0 || judge(chessboard_test))
    {
    
        int value=Evaluate(chessboard_test,minimaxplayer);
       // Hash_store(p,HashExact,depth,value,chessboard_test);
        return value;
    }
   // int value=Hash_Hit(p,depth,alpha,beta,chessboard_test);
    //if(value!=-2147483648)
    //return value;
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
          
             val = -Alpha_Beta_Null_Move(depth - 1-2 , -beta, -beta+1, -minimaxplayer, chessboard_test,p);
          
           
             
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
            val = -Alpha_Beta_PVS(depth - 1, -beta, -alpha, -minimaxplayer, chessboard_test,p);
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
      
        int value=Evaluate(chessboard_test,minimaxplayer);
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
            if(alphas[0]!=-2147483646){
            beta=alphas[0];
            }
            pthread_rwlock_unlock(&lock);
            //printf("depth=%d\n",depth);
            
       /*   if(fFoundPv){
              val = -Alpha_Beta_PVS(depth - 1, -alpha-1, -alpha, -minimaxplayer, chessboard_test,p);
              if((val > alpha) && (val < beta)) { 
              val = -Alpha_Beta_PVS(depth - 1, -beta, -alpha,-minimaxplayer,chessboard_test,p);
              }
            }    
           else
            {
            val = -Alpha_Beta_PVS(depth - 1, -beta, -alpha, -minimaxplayer, chessboard_test,p);
            }*/
            val=-Alpha_Beta_Null_Move(depth - 1, -beta, -alpha, -minimaxplayer, chessboard_test,p);
               if(origin==-minimaxplayer)
            {
                if(-minimaxplayer==1)
                chessboard_test.black+=1;
                else
                chessboard_test.white+=1;
            }
           // fvisualize_board(chessboard_test,a,depth,val);
            chessboard_test.chessboard[h->list[a].to.x][h->list[a].to.y] = origin;
            chessboard_test.chessboard[h->list[a].from.x][h->list[a].from.y] = minimaxplayer;
            pthread_rwlock_rdlock(&lock);
            if(alphas[0]!=-2147483646){
            beta=alphas[0];
            }
            pthread_rwlock_unlock(&lock);
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
        update(alpha);

        return alpha;
    
}
int Alpha_Beta_new(int depth, int alpha, int beta, int minimaxplayer,Chessboard chessboard_test,Hash_Move *p)
{

   printf("1\n");
    int hashf=HashAlpha;
    int best_move=0;

    if (depth == 0 || judge(chessboard_test))
    {
        int value=Evaluate(chessboard_test,minimaxplayer);
       
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
      
         //val = -Alpha_Beta_Multi_Thread(depth - 1,  -minimaxplayer,-beta, -alpha,  chessboard_test);
        //  val=-Alpha_Beta_Null_Move(depth-1,-beta,-alpha,-minimaxplayer,chessboard_test,p);
        val=-Alpha_Beta_PVS(depth-1,-beta,-alpha,-minimaxplayer,chessboard_test,p);
          
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
     


        Hash_store(p,hashf,depth,alpha,chessboard_test);
       // printf("best_move=%d\n",best_move);
      printf("alpha=%d\n",alpha);
      printf("best_move=%d\n",best_move);
        return best_move;
    
}
void *Alpha_Beta_pth(void *Arguement)
{

    Para *arg = (Para *)Arguement;
    Hash_Move *p=(Hash_Move *)malloc(Hash_table_length*sizeof(Hash_Move));
    
    Hash_Table_Init(p);
    arg->value = -Alpha_Beta_PVS_Multi_Thread(arg->depth, -2147483646,2147483647, arg->minimaxplayer, arg->chessboard_info,p);
   // printf("pth depth=%d value=%d\n",arg->depth,arg->value);
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
    
  int tids_num=6;
  

        int flag, eval, miniEval = 2147483640, origin;

        Move_List *h = (Move_List *)malloc(sizeof(Move_List));
        h->flag = 0;
        Move_Generate(h, minimaxplayer,Chessboard_test);

        pthread_t tids[tids_num];
        Para arg[h->flag];
        pthread_attr_t attr;
        pthread_attr_init(&attr);
        {
            tid_num=h->flag;
            alphas=(int *)malloc((tid_num+1)*sizeof(int));
            betas=(int *)malloc((tid_num+1)*sizeof(int));
        }
        alphas[0]=-2147483646;
        betas[0]=2147483647;
        pthread_rwlockattr_t lock_attr;
        pthread_rwlockattr_init(&lock_attr);
       pthread_rwlock_init(&lock,&lock_attr);
       int start=0;
        for (int a = start; a < start+h->flag; a++)
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
            origin = arg[a].chessboard_info.chessboard[h->list[a].to.x][h->list[a].to.y];
            arg[a].chessboard_info.chessboard[h->list[a].from.x][h->list[a].from.y] = 0;
            arg[a].chessboard_info.chessboard[h->list[a].to.x][h->list[a].to.y] = minimaxplayer;
                if(origin==-minimaxplayer)
            {
                if(-minimaxplayer==1)
                 arg[a].chessboard_info.black-=1;
                else
                arg[a].chessboard_info.white-=1;
            }
            alphas[a+1]=alpha;
            betas[a+1]=beta;
            arg[a].depth = depth - 1;
            arg[a].minimaxplayer = -minimaxplayer;
            arg[a].tid=a+1;
           
        }
       /*  for (int a = start; a < start+h->flag; a++){
        pthread_create(&tids[a], &attr, Alpha_Beta_pth, &arg[a]);
         }
        for (int a = start; a < start+h->flag; a++)
        {
            pthread_join(tids[a], NULL);
        }
        */
        while(start<h->flag){
        if(h->flag-start>=tids_num){
            if(start!=0){
            for (int a = start; a < start+tids_num; a++){
                 arg[a].alpha=-alphas[0];
             }
            }
         for (int a = start; a < start+tids_num; a++){
        pthread_create(&tids[a%tids_num], &attr, Alpha_Beta_pth, &arg[a]);
         }
        for (int a = start; a < start+tids_num; a++)
        {
            pthread_join(tids[a%tids_num], NULL);
        }

        }
        else{
             for (int a = start; a < h->flag; a++){
                 arg[a].alpha=-alphas[0];
             }
         for (int a = start; a < h->flag; a++){
        pthread_create(&tids[a%tids_num], &attr, Alpha_Beta_pth, &arg[a]);
         }
        for (int a = start; a < start+tids_num; a++)
        {
            pthread_join(tids[a%tids_num], NULL);
        }
        }
        start+=tids_num;
        }
        start=0;
        for(int a = start; a < start+h->flag; a++)
        {  
         //  printf("m depth=%d value=%d\n",depth,arg[a].value);
              
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
    static int count;
    count++;
    Hash_Move *p;
    
      
       int alpha=-2147483640,beta=2147483640;
    if(count>1){       
       p=(Hash_Move *)malloc((Hash_table_length)*sizeof(Hash_Move));
       Hash_Table_Init(p);

        if(count_num()<12)
        {
            k1=2;
            k2=3;
            k3=1;
            k4=1;
        }
        int a;
         if(count_num()<7)
          a=Alpha_Beta_new(depth+2,alpha,beta,who,chessboard,p);
         else
        a=Alpha_Beta_new(depth,alpha,beta,who,chessboard,p);

        Move_List *h = (Move_List *)malloc(sizeof(Move_List));
        h->flag = 0;
      
        visualize_board(chessboard);
        Move_Generate(h, who,chessboard);

   

        if( chessboard.chessboard[h->list[a].to.x][h->list[a].to.y]==-who)
        {
            if(who==1)
            chessboard.white-=1;
            else
            chessboard.black-=1;
            pre_record_competition();
            record_competition(who,h->list[a].from.x,h->list[a].from.y,h->list[a].to.x,h->list[a].to.y,KILL);
        }
        else
        {pre_record_competition();
            record_competition(who,h->list[a].from.x,h->list[a].from.y,h->list[a].to.x,h->list[a].to.y,NOR);
        }
        
        chessboard.chessboard[h->list[a].from.x][h->list[a].from.y]=0;
        chessboard.chessboard[h->list[a].to.x][h->list[a].to.y]=who;
     // printf("from%d %d to%d %d\n",h->list[a].from.x,h->list[a].from.y,h->list[a].to.x,h->list[a].to.y);
    //printf("white=%d,black=%d\n",chessboard.white,chessboard.black);
     
      record(h->list[a].from.x,h->list[a].from.y,h->list[a].to.x,h->list[a].to.y);
    }
    else{
        if(who==1)
        {
            chessboard.chessboard[1][2]=0;
            chessboard.chessboard[2][2]=1;
        }
        else{
             chessboard.chessboard[4][2]=0;
            chessboard.chessboard[3][2]=-1;
        }
    }
}
