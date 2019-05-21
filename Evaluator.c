#include "Evaluator.h"
extern int chessboard[6][6];
extern int who;
int Evaluate(){
int count=0;
for(int a=0;a<6;a++){
    for(int b=0;b<6;b++){
        if(chessboard[a][b]==who)
        count++;
       else if(chessboard[a][b]==-who)
       count--;
    }
    
    
}

return count;
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