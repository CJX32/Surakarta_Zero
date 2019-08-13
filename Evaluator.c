#include "Evaluator.h"
extern int chessboard_test[6][6];
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
int k1=1,k2=1,k3=1,k4=1;
int Evaluate(int chessboard_test[][6],int who_test){
int test=Evaluate_test(chessboard_test,who_test);
if(test==9999||test==-9999)
return test;
int value;
int extendVal;
int positionVal;
int dynamicVal;
int potentialVal;

extendVal=count(chessboard_test)*100;
positionVal=position_value(chessboard_test)+arc_count(chessboard_test)*arcPara;
dynamicVal=anotherMark(chessboard_test);
potentialVal=greenpotential(chessboard_test);
value=extendVal*k1+positionVal*k2+dynamicVal*k3+potentialVal*k3;
if(who_test==who)
return value;
else
return -value;

}

int count(int chessboard_test[][6]){

    int count=0;
    for(int a=0;a<6;a++){
        for(int b=0;b<6;b++){
          if(chessboard_test[a][b]==who)
          count++;
          else if(chessboard_test[a][b]==-who)
          count--;
        }
    }
    return count;
}
int position_value(int chessboard_test[][6])
{
    int value = 0;
    for (int a = 0; a < 6; a++)
    {
        for (int b = 0; b < 6; b++)
        {
            if (chessboard_test[a][b] == who)
                value += chessboard_value[a][b];
            else if (chessboard_test[a][b] == -who)
                value -= chessboard_value[a][b];
        }
    }
    return value;
}
int greenpotential(int chessboard_test[][6]){
int value=0;
for(int a=0;a<=15;a+=2){
    if(chessboard_test[look_for_intersection[a/2][0]][look_for_intersection[a/2][1]]==who){
  if(chessboard_test[look_for[a][0]][look_for[a][1]]==0&&chessboard_test[look_for[a+1][0]][look_for[a+1][1]]==0)
  {value+=greenPotential[0];}
  else if(chessboard_test[look_for[a][0]][look_for[a][1]]==-who&&chessboard_test[look_for[a+1][0]][look_for[a+1][1]]==-who)   
  {value+=greenPotential[1];}
  else if((chessboard_test[look_for[a][0]][look_for[a][1]]==who||chessboard_test[look_for[a+1][0]][look_for[a+1][1]]==who)&&(chessboard_test[look_for[a][0]][look_for[a][1]]==0||chessboard_test[look_for[a+1][0]][look_for[a+1][1]]==0))
  {value+=greenPotential[2];}
  else if(chessboard_test[look_for[a][0]][look_for[a][1]]==who&&chessboard_test[look_for[a+1][0]][look_for[a+1][1]]==who)
  {value+=greenPotential[4];}
  }
  else if(chessboard_test[look_for_intersection[a/2][0]][look_for_intersection[a/2][1]]==0)
  {  if(chessboard_test[look_for[a][0]][look_for[a][1]]==who&&chessboard_test[look_for[a+1][0]][look_for[a+1][1]]==who)
     {value+=greenPotential[5];}
     else if(chessboard_test[look_for[a][0]][look_for[a][1]]==-who&&chessboard_test[look_for[a+1][0]][look_for[a+1][1]]==-who)   
     {value+=greenPotential[6];}
     else if((chessboard_test[look_for[a][0]][look_for[a][1]]==who||chessboard_test[look_for[a+1][0]][look_for[a+1][1]]==who)&&(chessboard_test[look_for[a][0]][look_for[a][1]]==0||chessboard_test[look_for[a+1][0]][look_for[a+1][1]]==0))
    { value+=greenPotential[7];}
    else if((chessboard_test[look_for[a][0]][look_for[a][1]]==-who||chessboard_test[look_for[a+1][0]][look_for[a+1][1]]==-who)&&(chessboard_test[look_for[a][0]][look_for[a][1]]==0||chessboard_test[look_for[a+1][0]][look_for[a+1][1]]==0))
     {value+=greenPotential[9];}
}
else if(chessboard_test[look_for_intersection[a/2][0]][look_for_intersection[a/2][1]]==-who){
 if(chessboard_test[look_for[a][0]][look_for[a][1]]==0&&chessboard_test[look_for[a+1][0]][look_for[a+1][1]]==0 )
  {value+=greenPotential[11];}
else if(chessboard_test[look_for[a][0]][look_for[a][1]]==-who&&chessboard_test[look_for[a+1][0]][look_for[a+1][1]]==-who)   
  {value+=greenPotential[12];}
else if(chessboard_test[look_for[a][0]][look_for[a][1]]==who&&chessboard_test[look_for[a+1][0]][look_for[a+1][1]]==who)
  {value+=greenPotential[13];}
else if((chessboard_test[look_for[a][0]][look_for[a][1]]==who||chessboard_test[look_for[a+1][0]][look_for[a+1][1]]==who)&&(chessboard_test[look_for[a][0]][look_for[a][1]]==0||chessboard_test[look_for[a+1][0]][look_for[a+1][1]]==0))
  {value+=greenPotential[14];}
}
}
return value;
}
int arc_count(int chessboard_test[][6]){
  int count=0;
  for(int a=0;a<20;a++)
  {
    if(chessboard_test[look_for_arc[a][0]][look_for_arc[a][1]]==who)
    count++;
    else if(chessboard_test[look_for_arc[a][0]][look_for_arc[a][1]]==-who)
    count--;
  }
  return count;
}
int anotherMark(int chessboard_test[][6]){
int count=0;
for(int a=0;a<=9;a+=3){
if(chessboard_test[look_for_anotherMark[a][0]][look_for_anotherMark[a][1]]==who)
{
  if(chessboard_test[look_for_anotherMark[a+1][0]][look_for_anotherMark[a+1][1]]==-who&&chessboard_test[look_for_anotherMark[a+1][0]][look_for_anotherMark[a+1][1]]==-who)
  count++;
}
else if(chessboard_test[look_for_anotherMark[a][0]][look_for_anotherMark[a][1]]==-who){
  if(chessboard_test[look_for_anotherMark[a+1][0]][look_for_anotherMark[a+1][1]]==who&&chessboard_test[look_for_anotherMark[a+1][0]][look_for_anotherMark[a+1][1]]==who)
  count--;
}
}
return count;
}
int Evaluate_test(int chessboard_test[][6],int who_test){
  int count=0;
  int flag_1=1,flag_2=1;
  for(int a=0;a<6;a++){
    for(int b=0;b<6;b++){
      if(chessboard_test[a][b]==who_test){
      count++;
      flag_1=0;
      }
      else if (chessboard_test[a][b]==-who_test){
      count--;
      flag_2=0;
      }
     }
  }
  if(flag_1)
  return -9999;
  else if(flag_2)
  return 9999;
  return count;
}