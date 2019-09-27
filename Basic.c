#include "Basic.h"
extern Chessboard chessboard;
extern int who;
void visualize_board(Chessboard chessboard){
  static int count;
  count++;
  for(int  a=0;a<6;a++){
    for(int b=0;b<6;b++)
    if(chessboard.chessboard[a][b]==-1)
    printf("2 ");
    else
    printf("%d ",chessboard.chessboard[a][b]);
    printf("\n");
  }
  printf("\n");
}
void visualize(Move_List *h){
for(int a=0;a<h->flag;a++){
    printf("from %d,%d to %d,%d\n",h->list[a].from.x,h->list[a].from.y,h->list[a].to.x,h->list[a].to.y);
}
}
int judge(Chessboard chessboard_test){
  if(who==1){
    if(chessboard_test.black==0)
    return 1;
    else if(chessboard_test.white==0)
    return 2;
    else
    return 0;
   }
   else{
    if(chessboard_test.white==0)
    return 1;
    else if(chessboard_test.black==0)
    return 2;
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