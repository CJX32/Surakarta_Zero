#include "Move_Generator.h"
extern int chessboard[6][6];
extern Orbit *Inside_Orbit;
extern Orbit *Outside_Orbit;
extern Orbit_Index  Inside_Orbit_Index[6][6];
extern Orbit_Index  Outside_Orbit_Index[6][6];
void Move_Generate(Move_List *h, int who,int chessboard_test[][6])
{
    Generate_Move_Attack(h,who,chessboard_test);
      for (int a=0;a<6; a++){
       for (int b=0;b<6;b++){
            if (chessboard_test[a][b] == who){
                for (int c = a - 1; c <= a + 1; c++)
                    for (int d = b - 1; d <= b + 1; d++){
                        if (c< 0)
                            break;
                        if (d < 0)
                            d = 0;
                        if (c > 5)
                            break;
                        if (d > 5)
                            break;
                        if (chessboard_test[c][d] == 0){
                            Add_Move(h, a, b, c, d);
                          
                        }
                    }
                   
                }
            }
        }
      
}
void Add_Move(Move_List *h, int from_x, int from_y, int to_x, int to_y)
{   int flag=h->flag;
    h->list[flag].from.x = from_x;
    h->list[flag].from.y = from_y;
     h->list[flag].to.x  = to_x;
      h->list[flag].to.y= to_y;
     h->flag++;
}
void  Add_Move_Attack(Move_List *h,int from_x,int from_y,int to_x,int to_y){
    int index=0;
    for(int a=0;a<h->flag;a++){

        if(from_x==h->list[a].from.x&&from_y==h->list[a].from.y&&to_x==h->list[a].to.x&&to_y==h->list[a].to.y)
        {
            index=1;
            break;
        }
    }
    if(!index){
    int flag=h->flag;
    h->list[flag].from.x = from_x;
    h->list[flag].from.y = from_y;
     h->list[flag].to.x  = to_x;
    h->list[flag].to.y= to_y;
    h->flag++;
    }

}


void Generate_Move_Attack(Move_List *h,int who,int chessboard_test[][6]){
    Rool rool[4][6];
    int  flag_index[4];
    flag_index[0]=extract_outside_rool_1(rool[0],chessboard_test);
    flag_index[1]=extract_outside_rool_2(rool[1],chessboard_test);
    flag_index[2]=extract_outside_rool_3(rool[2],chessboard_test);
    flag_index[3]=extract_outside_rool_4(rool[3],chessboard_test);

Attack_Orbit(h,rool,flag_index,who,chessboard_test);

    flag_index[0]=extract_inside_rool_1(rool[0],chessboard_test);
    flag_index[1]=extract_inside_rool_2(rool[1],chessboard_test);
    flag_index[2]=extract_inside_rool_3(rool[2],chessboard_test);
    flag_index[3]=extract_inside_rool_4(rool[3],chessboard_test);

Attack_Orbit(h,rool,flag_index,who,chessboard_test);

    



}
void Attack_Orbit(Move_List *h,Rool rool[][6],int *flag_index,int who,int chessboard_test[][6]){
     for(int a=0;a<4;a++){
     if(flag_index[a]!=0){
         if(chessboard_test[rool[a][flag_index[a]-1].from.x][rool[a][flag_index[a]-1].from.y]==who){
        int find_unnull=a+1;
        if(find_unnull>=4)
         find_unnull=0;
       while(!flag_index[find_unnull]){
         find_unnull++;
         if(find_unnull>=4)
         find_unnull=0;
       }
       if(rool[a][flag_index[a]-1].chess==rool[find_unnull][0].chess)
      {
          if(rool[a][flag_index[a]-1].from.x==rool[find_unnull][0].from.x&&rool[a][flag_index[a]-1].from.y==rool[find_unnull][0].from.y)
         {
            int index=find_unnull;
            if(flag_index[find_unnull]>=2)
              {
               if(rool[find_unnull][1].chess==-who){
               Add_Move_Attack(h,rool[find_unnull][0].from.x,rool[find_unnull][0].from.y,rool[find_unnull][1].from.x,rool[find_unnull][1].from.y);

              }
              }
         
         index=a;
         if(flag_index[a]>=2)
         {
             if(rool[a][flag_index[a]-2].chess==-who)
             {
                 Add_Move_Attack(h,rool[a][flag_index[a]-1].from.x,rool[a][flag_index[a]-1].from.y,rool[a][flag_index[a]-2].from.x,rool[a][flag_index[a]-2].from.y);
             }
         }
     }
         
}
      
      else
       Add_Move_Attack(h,rool[a][flag_index[a]-1].from.x,rool[a][flag_index[a]-1].from.y,rool[find_unnull][0].from.x,rool[find_unnull][0].from.y);


     }
if(chessboard_test[rool[a][0].from.x][rool[a][0].from.y]==who)
{
 int find_unnull=a-1;
        if(find_unnull<0)
         find_unnull=3;
       while(!flag_index[find_unnull]){
         find_unnull--;
         if(find_unnull<0)
         find_unnull=3;
       }
       if(rool[a][0].chess==rool[find_unnull][flag_index[find_unnull]-1].chess)
      {
         }
      
      else{
      
       Add_Move_Attack(h,rool[a][0].from.x,rool[a][0].from.y,rool[find_unnull][flag_index[find_unnull]-1].from.x,rool[find_unnull][flag_index[find_unnull]-1].from.y);
 
      }
}
}
     }


}





int extract_outside_rool_1(Rool *rool_1,int chessboard_test[][6]){
   
    int index=0;
   for(int a=5;a>=0;a--){
    if(chessboard_test[2][a]!=0){
    rool_1[index].chess=chessboard_test[2][a];
    rool_1[index].from.x=2;
     rool_1[index].from.y=a;
    index++;
    }
   }
   return index;
}
int extract_outside_rool_2(Rool *rool,int chessboard_test[][6]){
    
    int index=0;
   for(int a=0;a<6;a++){
    if(chessboard_test[a][2]!=0){
    rool[index].chess=chessboard_test[a][2];
    rool[index].from.x=a;
     rool[index].from.y=2;
    index++;
    }
   }
   return index;
}
int extract_outside_rool_3(Rool *rool,int chessboard_test[][6]){
  
    int index=0;
   for(int a=0;a<6;a++){
    if(chessboard_test[3][a]!=0){
    rool[index].chess=chessboard_test[3][a];
    rool[index].from.x=3;
     rool[index].from.y=a;
    index++;
    }
   }
   return index;
}
int extract_outside_rool_4(Rool *rool_4,int chessboard_test[][6]){

    int index=0;
   for(int a=5;a>=0;a--){
    if(chessboard_test[a][3]!=0){
    rool_4[index].chess=chessboard_test[a][3];
    rool_4[index].from.x=a;
     rool_4[index].from.y=3;
    index++;
    }
   }
   return index;
}
int extract_inside_rool_1(Rool *rool_1,int chessboard_test[][6]){
   
    int index=0;
   for(int a=5;a>=0;a--){
    if(chessboard_test[1][a]!=0){
    rool_1[index].chess=chessboard_test[1][a];
    rool_1[index].from.x=1;
     rool_1[index].from.y=a;
    index++;
    }
   }
   return index;
}
int extract_inside_rool_2(Rool *rool,int chessboard_test[][6]){
    
    int index=0;
   for(int a=0;a<6;a++){
    if(chessboard_test[a][1]!=0){
    rool[index].chess=chessboard_test[a][1];
    rool[index].from.x=a;
     rool[index].from.y=1;
    index++;
    }
   }
   return index;
}
int extract_inside_rool_3(Rool *rool,int chessboard_test[][6]){
  
    int index=0;
   for(int a=0;a<6;a++){
    if(chessboard_test[4][a]!=0){
    rool[index].chess=chessboard_test[4][a];
    rool[index].from.x=4;
     rool[index].from.y=a;
    index++;
    }
   }
   return index;
}
int extract_inside_rool_4(Rool *rool_4,int chessboard_test[][6]){

    int index=0;
   for(int a=5;a>=0;a--){
    if(chessboard_test[a][4]!=0){
    rool_4[index].chess=chessboard_test[a][4];
    rool_4[index].from.x=a;
     rool_4[index].from.y=4;
    index++;
    }
   }
   return index;
}
int Sort_Move(Move *h,int flag){
  Move *p;
  int index,count=0;
  p=(Move *)malloc(24*sizeof(Move));
  for(int i=0;i<flag;i++)
  {index=0;
     for(int o=i+1;o<flag;o++){
         if(h[i].from.x==h[o].from.x&&h[i].from.y==h[o].from.y&&h[i].to.x==h[o].to.x&&h[i].to.y==h[o].to.y)
         {
             index=1;
             flag--;
             break;
         }
     }
     if(!index)
     {
     p[count]=h[count];
     count++;
     }
  }
  h=p;
return flag;
}

