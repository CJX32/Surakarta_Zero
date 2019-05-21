#include "Basic.h"
extern int chessboard[6][6];
int count_chess(int who)
{int count=0;
    for(int a=0;a<6;a++){
      for(int b=0;b<6;b++){
      if(chessboard[a][b]==who)
       count++;
      }
    }
    return count;
}
void visualize_board(){
  for(int  a=0;a<6;a++){
    for(int b=0;b<6;b++)
    printf("%d ",chessboard[a][b]);
    printf("\n");
  }
  printf("\n");
}