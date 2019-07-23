#include "Evaluator.h"
extern int chessboard[6][6];
extern int who;
int chessboard_value[6][6]={
{5,20,20,20,20,5},
{20,30,50,50,30,20},
{20,50,40,40,50,20},
{20,50,40,40,50,20},
{20,30,50,50,30,20},
{5,20,20,20,20,5}
 };
int greenPotential[16]={84,91,35,35,-20,25,-25,45,-45,-45,-84,20,-91,-35,-35};
int look_for[16][2]={
{0,2},{2,0},{0,3},{2,5},{3,0},{5,2},{5,3},{3,5},
{1,0},{0,1},{0,4},{1,5},{4,0},{5,1},{4,5},{5,4},
};
int look_for_intersection[8][2]={
{2,2},{2,3},{3,2},{3,3},
{1,1},{1,4},{4,1},{4,4},
};
int look_for_arc[20][2]={
  {0,0},{0,1},{0,2},{0,3},{0,4},{0,5},
  {1,5},{2,5},{3,5},{4,5},{5,5},
  {5,4},{5,3},{5,2},{5,1},{5,0},
  {4,0},{3,0},{2,0},{1,0}
};
int look_for_anotherMark[12][2]={
  {2,2},{1,2},{2,1},
  {2,3},{1,3},{2,4},
  {3,2},{3,1},{4,2},
  {3,3},{3,4},{4,3} 
};
int arcPara;
int k1,k2,k3,k4;
int Evaluate(void){
int value;
int extendVal;
int positionVal;
int dynamicVal;
int potentialVal;

extendVal=count()*100;
positionVal=position_value()+arc_count()*arcPara;
dynamicVal=anotherMark();
potentialVal=greenpotential();
value=extendVal*k1+positionVal*k2+dynamicVal*k3+potentialVal*k3;
return value;
}

int count(void){

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
int position_value(void)
{
    int value = 0;
    for (int a = 0; a < 6; a++)
    {
        for (int b = 0; b < 6; b++)
        {
            if (chessboard[a][b] == who)
                value += chessboard_value[a][b];
            else if (chessboard[a][b] == -who)
                value -= chessboard_value[a][b];
        }
    }
    return value;
}
int greenpotential(void){
int value=0;
for(int a=0;a<=15;a+=2){
    if(chessboard[look_for_intersection[a/2][0]][look_for_intersection[a/2][1]]==who){
  if(chessboard[look_for[a][0]][look_for[a][1]]==0&&chessboard[look_for[a+1][0]][look_for[a+1][1]]==0)
  {value+=greenPotential[0];printf("0\n");}
  else if(chessboard[look_for[a][0]][look_for[a][1]]==-who&&chessboard[look_for[a+1][0]][look_for[a+1][1]]==-who)   
  {value+=greenPotential[1];printf("1\n");}
  else if((chessboard[look_for[a][0]][look_for[a][1]]==who||chessboard[look_for[a+1][0]][look_for[a+1][1]]==who)&&(chessboard[look_for[a][0]][look_for[a][1]]==0||chessboard[look_for[a+1][0]][look_for[a+1][1]]==0))
  {value+=greenPotential[2];printf("2\n");}
  else if(chessboard[look_for[a][0]][look_for[a][1]]==who&&chessboard[look_for[a+1][0]][look_for[a+1][1]]==who)
  {value+=greenPotential[4];printf("4\n");}
  }
  else if(chessboard[look_for_intersection[a/2][0]][look_for_intersection[a/2][1]]==0)
  {  if(chessboard[look_for[a][0]][look_for[a][1]]==who&&chessboard[look_for[a+1][0]][look_for[a+1][1]]==who)
     {value+=greenPotential[5];printf("5\n");}
     else if(chessboard[look_for[a][0]][look_for[a][1]]==-who&&chessboard[look_for[a+1][0]][look_for[a+1][1]]==-who)   
     {value+=greenPotential[6];printf("6\n");}
     else if((chessboard[look_for[a][0]][look_for[a][1]]==who||chessboard[look_for[a+1][0]][look_for[a+1][1]]==who)&&(chessboard[look_for[a][0]][look_for[a][1]]==0||chessboard[look_for[a+1][0]][look_for[a+1][1]]==0))
    { value+=greenPotential[7];printf("7\n");}
    else if((chessboard[look_for[a][0]][look_for[a][1]]==-who||chessboard[look_for[a+1][0]][look_for[a+1][1]]==-who)&&(chessboard[look_for[a][0]][look_for[a][1]]==0||chessboard[look_for[a+1][0]][look_for[a+1][1]]==0))
     {value+=greenPotential[9];printf("9\n");}
}
else if(chessboard[look_for_intersection[a/2][0]][look_for_intersection[a/2][1]]==-who){
 if(chessboard[look_for[a][0]][look_for[a][1]]==0&&chessboard[look_for[a+1][0]][look_for[a+1][1]]==0 )
  {value+=greenPotential[11];printf("11\n");}
else if(chessboard[look_for[a][0]][look_for[a][1]]==-who&&chessboard[look_for[a+1][0]][look_for[a+1][1]]==-who)   
  {value+=greenPotential[12];printf("12\n");}
else if(chessboard[look_for[a][0]][look_for[a][1]]==who&&chessboard[look_for[a+1][0]][look_for[a+1][1]]==who)
  {value+=greenPotential[13];printf("13\n");}
else if((chessboard[look_for[a][0]][look_for[a][1]]==who||chessboard[look_for[a+1][0]][look_for[a+1][1]]==who)&&(chessboard[look_for[a][0]][look_for[a][1]]==0||chessboard[look_for[a+1][0]][look_for[a+1][1]]==0))
  {value+=greenPotential[14];printf("14\n");}
}
}
return value;
}
int arc_count(void){
  int count=0;
  for(int a=0;a<20;a++)
  {
    if(chessboard[look_for_arc[a][0]][look_for_arc[a][1]]==who)
    count++;
    else if(chessboard[look_for_arc[a][0]][look_for_arc[a][1]]==-who)
    count--;
  }
  return count;
}
int anotherMark(void){
int count=0;
for(int a=0;a<=9;a+=3){
if(chessboard[look_for_anotherMark[a][0]][look_for_anotherMark[a][1]]==who)
{
  if(chessboard[look_for_anotherMark[a+1][0]][look_for_anotherMark[a+1][1]]==-who&&chessboard[look_for_anotherMark[a+1][0]][look_for_anotherMark[a+1][1]]==-who)
  count++;
}
else if(chessboard[look_for_anotherMark[a][0]][look_for_anotherMark[a][1]]==-who){
  if(chessboard[look_for_anotherMark[a+1][0]][look_for_anotherMark[a+1][1]]==who&&chessboard[look_for_anotherMark[a+1][0]][look_for_anotherMark[a+1][1]]==who)
  count--;
}
}
return count;
}
int Evaluate_test(int chessboard_test[][6]){
  int count=0;
  for(int a=0;a<6;a++){
    for(int b=0;b<6;b++){
      if(chessboard_test[a][b]==who)
      count++;
      else if (chessboard_test[a][b]==-who)
      count--;
     }
  }
  if(judge(chessboard_test)==1)
  return -9999;
  else if(judge(chessboard_test)==2)
  return 9999;
  return count;
}