#include "Basic.h"
extern int chessboard[6][6];
extern int who;
void visualize_board(){
  for(int  a=0;a<6;a++){
    for(int b=0;b<6;b++)
    printf("%d ",chessboard[a][b]);
    printf("\n");
  }
  printf("\n");
}
void visualize(Move_List *h){
for(int a=0;a<h->flag;a++){
    printf("from %d,%d to %d,%d\n",h->list[a].from.x,h->list[a].from.y,h->list[a].to.x,h->list[a].to.y);
}
}
int judge(){
    int count_1=0,count_2=0;
    for(int a=0;a<6;a++){
        for(int b=0;b<6;b++){
      if(chessboard[a][b]==who)
      count_1++;
      else if(chessboard[a][b]==-who)
      count_2++;
        }
    }
    if(count_1==0)
    return 1;
    else if(count_2==0)
    return 2;
    else
    return 0;
}