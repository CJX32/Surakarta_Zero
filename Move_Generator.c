#include "Move_Generator.h"
extern Chessboard chessboard;
void Move_Generate(Move_List *h, int who,Chessboard chessboard_test)
{
    h->flag=0;
    Generate_Move_Attack(h,who,chessboard_test);
      for (int a=0;a<6; a++){
       for (int b=0;b<6;b++){
            if (chessboard_test.chessboard[a][b] == who){
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
                        if (chessboard_test.chessboard[c][d] == 0){
                    
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


void Generate_Move_Attack(Move_List *h,int who,Chessboard chessboard_test){
    
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
void Attack_Orbit(Move_List *h,Rool rool[][6],int *flag_index,int who,Chessboard chessboard_test){
     for(int a=0;a<4;a++){
     if(flag_index[a]!=0){
         if(chessboard_test.chessboard[rool[a][flag_index[a]-1].from.x][rool[a][flag_index[a]-1].from.y]==who){
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
if(chessboard_test.chessboard[rool[a][0].from.x][rool[a][0].from.y]==who)
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
void *Generate_Move_Attack_Multi_Thread_In(void *para){
    Para_1 *info=(Para_1 *)para;
    int who=info->who;
    Move_List *h=info->h;
    pthread_t tids[8];
 
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    Rool rool[4][6];
    int  flag_index[4];
    role flag[8];
    
    flag[0].rool=rool[0]; 
    flag[1].rool=rool[1]; 
    flag[2].rool=rool[2]; 
    flag[3].rool=rool[3];

 
     pthread_create(&tids[0], &attr, extract_inside_rool_1_MT, &flag[0]);
     pthread_create(&tids[1], &attr, extract_inside_rool_2_MT, &flag[1]);
     pthread_create(&tids[2], &attr, extract_inside_rool_3_MT, &flag[2]);
     pthread_create(&tids[3], &attr, extract_inside_rool_4_MT, &flag[3]);
   
    pthread_join(tids[0],NULL);
    pthread_join(tids[1],NULL);
    pthread_join(tids[2],NULL);
    pthread_join(tids[3],NULL);
     flag_index[0]=flag[0].index;
    flag_index[1]=flag[1].index;
    flag_index[2]=flag[2].index;
    flag_index[3]=flag[3].index;
Attack_Orbit(h,rool,flag_index,who,chessboard);
pthread_exit(0);


}
void *Generate_Move_Attack_Multi_Thread_Out(void *para){
        Para_1 *info=(Para_1 *)para;
    int who=info->who;
    Move_List *h=info->h;
      pthread_t tids[8];
 
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    Rool rool[4][6];
    int  flag_index[4];
    role flag[8];
   flag[4].rool=rool[0]; 
    flag[5].rool=rool[1]; 
    flag[6].rool=rool[2]; 
    flag[7].rool=rool[3]; 
     pthread_create(&tids[4], &attr, extract_outside_rool_1_MT, &flag[4]);
     pthread_create(&tids[5], &attr, extract_outside_rool_2_MT, &flag[5]);
     pthread_create(&tids[6], &attr, extract_outside_rool_3_MT, &flag[6]);
     pthread_create(&tids[7], &attr, extract_outside_rool_4_MT, &flag[7]);
  
    pthread_join(tids[4],NULL);
    pthread_join(tids[5],NULL);
    pthread_join(tids[6],NULL);
    pthread_join(tids[7],NULL);
    flag_index[0]=flag[4].index;
    flag_index[1]=flag[5].index;
    flag_index[2]=flag[6].index;
    flag_index[3]=flag[7].index;
Attack_Orbit(h,rool,flag_index,who,chessboard);
pthread_exit(0);
}


int extract_outside_rool_1(Rool *rool_1,Chessboard chessboard_test){
   
    int index=0;
   for(int a=5;a>=0;a--){
    if(chessboard_test.chessboard[2][a]!=0){
    rool_1[index].chess=chessboard_test.chessboard[2][a];
    rool_1[index].from.x=2;
     rool_1[index].from.y=a;
    index++;
    }
   }
   return index;
}
int extract_outside_rool_2(Rool *rool,Chessboard chessboard_test){
    
    int index=0;
   for(int a=0;a<6;a++){
    if(chessboard_test.chessboard[a][2]!=0){
    rool[index].chess=chessboard_test.chessboard[a][2];
    rool[index].from.x=a;
     rool[index].from.y=2;
    index++;
    }
   }
   return index;
}
int extract_outside_rool_3(Rool *rool,Chessboard chessboard_test){
  
    int index=0;
   for(int a=0;a<6;a++){
    if(chessboard_test.chessboard[3][a]!=0){
    rool[index].chess=chessboard_test.chessboard[3][a];
    rool[index].from.x=3;
     rool[index].from.y=a;
    index++;
    }
   }
   return index;
}
int extract_outside_rool_4(Rool *rool_4,Chessboard chessboard_test){

    int index=0;
   for(int a=5;a>=0;a--){
    if(chessboard_test.chessboard[a][3]!=0){
    rool_4[index].chess=chessboard_test.chessboard[a][3];
    rool_4[index].from.x=a;
     rool_4[index].from.y=3;
    index++;
    }
   }
   return index;
}
int extract_inside_rool_1(Rool *rool_1,Chessboard chessboard_test){
   
    int index=0;
   for(int a=5;a>=0;a--){
    if(chessboard_test.chessboard[1][a]!=0){
    rool_1[index].chess=chessboard_test.chessboard[1][a];
    rool_1[index].from.x=1;
     rool_1[index].from.y=a;
    index++;
    }
   }
   return index;
}
int extract_inside_rool_2(Rool *rool,Chessboard chessboard_test){
    
    int index=0;
   for(int a=0;a<6;a++){
    if(chessboard_test.chessboard[a][1]!=0){
    rool[index].chess=chessboard_test.chessboard[a][1];
    rool[index].from.x=a;
     rool[index].from.y=1;
    index++;
    }
   }
   return index;
}
int extract_inside_rool_3(Rool *rool,Chessboard chessboard_test){
  
    int index=0;
   for(int a=0;a<6;a++){
    if(chessboard_test.chessboard[4][a]!=0){
    rool[index].chess=chessboard_test.chessboard[4][a];
    rool[index].from.x=4;
     rool[index].from.y=a;
    index++;
    }
   }
   return index;
}
int extract_inside_rool_4(Rool *rool_4,Chessboard chessboard_test){

    int index=0;
   for(int a=5;a>=0;a--){
    if(chessboard_test.chessboard[a][4]!=0){
    rool_4[index].chess=chessboard_test.chessboard[a][4];
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
void *extract_outside_rool_1_MT(void *Para){
   role *flag=(role *)Para;
    int index=0;
   for(int a=5;a>=0;a--){
    if(chessboard.chessboard[2][a]!=0){
    flag->rool[index].chess=chessboard.chessboard[2][a];
    flag->rool[index].from.x=2;
     flag->rool[index].from.y=a;
    index++;
    }
   }
   flag->index=index;
   pthread_exit(0);
}
void *extract_outside_rool_2_MT(void *Para){
     role *flag=(role *)Para;
    int index=0;
   for(int a=0;a<6;a++){
    if(chessboard.chessboard[a][2]!=0){
    flag->rool[index].chess=chessboard.chessboard[a][2];
    flag->rool[index].from.x=a;
     flag->rool[index].from.y=2;
    index++;
    }
   }
  flag->index=index;
   pthread_exit(0);
}
void *extract_outside_rool_3_MT(void *Para){
   role *flag=(role *)Para;
    int index=0;
   for(int a=0;a<6;a++){
    if(chessboard.chessboard[3][a]!=0){
    flag->rool[index].chess=chessboard.chessboard[3][a];
    flag->rool[index].from.x=3;
    flag-> rool[index].from.y=a;
    index++;
    }
   }
   flag->index=index;
    pthread_exit(0);
}
void *extract_outside_rool_4_MT(void *Para){
 role *flag=(role *)Para;
    int index=0;
   for(int a=5;a>=0;a--){
    if(chessboard.chessboard[a][3]!=0){
    flag->rool[index].chess=chessboard.chessboard[a][3];
    flag->rool[index].from.x=a;
     flag->rool[index].from.y=3;
    index++;
    }
   }
   flag->index=index;
    pthread_exit(0);
}
void *extract_inside_rool_1_MT(void *Para){
    role *flag=(role *)Para;
    int index=0;
   for(int a=5;a>=0;a--){
    if(chessboard.chessboard[1][a]!=0){
    flag->rool[index].chess=chessboard.chessboard[1][a];
    flag->rool[index].from.x=1;
     flag->rool[index].from.y=a;
    index++;
    }
   }
   flag->index=index;
    pthread_exit(0);
}
void *extract_inside_rool_2_MT(void *Para){
    role *flag=(role *)Para; 
    int index=0;
   for(int a=0;a<6;a++){
    if(chessboard.chessboard[a][1]!=0){
    flag->rool[index].chess=chessboard.chessboard[a][1];
    flag->rool[index].from.x=a;
     flag->rool[index].from.y=1;
    index++;
    }
   }
  flag->index=index;
   pthread_exit(0);
}
void *extract_inside_rool_3_MT(void *Para){
   role *flag=(role *)Para;
    int index=0;
   for(int a=0;a<6;a++){
    if(chessboard.chessboard[4][a]!=0){
    flag->rool[index].chess=chessboard.chessboard[4][a];
    flag->rool[index].from.x=4;
     flag->rool[index].from.y=a;
    index++;
    }
   }
   flag->index=index;
    pthread_exit(0);
}
void *extract_inside_rool_4_MT(void *Para){
 role *flag=(role *)Para;
    int index=0;
   for(int a=5;a>=0;a--){
    if(chessboard.chessboard[a][4]!=0){
    flag->rool[index].chess=chessboard.chessboard[a][4];
    flag->rool[index].from.x=a;
    flag->rool[index].from.y=4;
    index++;
    }
   }
   flag->index=index;
    pthread_exit(0);
}
void Move_Generate_MT(Move_List *h, int who,Chessboard chessboard_test)
{
    h->flag=0;
    Para_1 arg[2];
    pthread_t tids[2];
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    arg[0].h=h;
    arg[1].h=h;
    arg[0].who=who;
    arg[1].who=who;
    pthread_create(&tids[0],&attr,Generate_Move_Attack_Multi_Thread_In,&arg[0]);
    pthread_create(&tids[1],&attr,Generate_Move_Attack_Multi_Thread_Out,&arg[1]);
    pthread_join(tids[0],NULL);
    pthread_join(tids[1],NULL);

      for (int a=0;a<6; a++){
       for (int b=0;b<6;b++){
            if (chessboard_test.chessboard[a][b] == who){
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
                        if (chessboard_test.chessboard[c][d] == 0){
                            h->list[0].from.x=1;
                            Add_Move(h, a, b, c, d);
                          
                        }
                    }
                   
                }
            }
        }
      
}

