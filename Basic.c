#include "Basic.h"
extern Chessboard chessboard;
extern pthread_rwlock_t lock;
extern FILE *fout;
extern int who;
extern int *alphas;
extern int *betas;
void visualize_board(Chessboard chessboard_test){
  for(int  a=0;a<6;a++){
    for(int b=0;b<6;b++){
    if(chessboard_test.chessboard[a][b]==-1)
    printf("2 ");
    else
    printf("%d ",chessboard_test.chessboard[a][b]);
    }
    printf("\n");
    
  }

}
void visualize(Move_List *h){
for(int a=0;a<h->flag;a++){
    printf("from %d,%d to %d,%d\n",h->list[a].from.x,h->list[a].from.y,h->list[a].to.x,h->list[a].to.y);
}
}
int judge(Chessboard chessboard_test){
  if(who==1){
    if(chessboard_test.black==0){
    return 1;
    }
    else if(chessboard_test.white==0){

    return 2;
    }
    else{

    return 0;
    }
   }
   else{
    if(chessboard_test.white==0){

    return 1;
    }
    else if(chessboard_test.black==0){

    return 2;
    }
    else
    return 0;
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
void update(int alpha){
  if(alphas[0]<-alpha){
  pthread_rwlock_wrlock(&lock);
  alphas[0]=alpha;
  pthread_rwlock_unlock(&lock);
  }
}
void fvisualize_board(Chessboard chessboard_test,int tid,int depth,int val){
    char path[50]="/Users/bluesky/Desktop/debug/";
     int n;
    int index=29;
    while(tid>=10){
     n=tid%10;
     tid/=10;
     path[index++]=n+48;
    }
     path[index++]=tid+48;
    path[index++]='.';
    path[index++]='t';
    path[index++]='x';
    path[index++]='t';
    path[index++]='\0';
    fout=fopen(path,"a+");
    fprintf(fout,"depth=%d\n",depth);
    for(int a=0;a<6;a++){
        for(int b=0;b<6;b++){
            if(chessboard_test.chessboard[a][b]==-1)
            fprintf(fout,"2");
            else
            fprintf(fout,"%d",chessboard_test.chessboard[a][b]);
        }
        fprintf(fout,"\n");
    }
    fprintf(fout,"val=%d\n",val);
    fprintf(fout,"\n");
    fclose(fout);
}