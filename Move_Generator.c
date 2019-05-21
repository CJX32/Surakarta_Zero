#include "Move_Generator.h"
extern int chessboard[6][6];
extern Orbit *Inside_Orbit;
extern Orbit *Outside_Orbit;
extern Orbit_Index  Inside_Orbit_Index[6][6];
extern Orbit_Index  Outside_Orbit_Index[6][6];
void Move_Generate(Move_List *h, int who)
{
    int flag = 0;

    Generate_Move_Attack(h,who);


    for (int a=0;a<6; a++){
       for (int b=0;b<6;b++){
            if (chessboard[a][b] == who){
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
                        if (chessboard[c][d] == 0){
                            Add_Move(h, a, b, c, d);
                          
                        }
                    }
                    //flag=Generate_Attack_Move(h,a,b,flag,who);
                }
            }
        }
    
    
   /* for(int a=0;a<6;a++){
        for(int b=0;b<6;b++){
         if(chessboard[a][b]==who){
             flag=Generate_Attack_Move(h,a,b,flag,who);
             
         }
        }
    }*/

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
/*int Generate_Attack_Move(Move *h,int from_x,int from_y,int flag,int who){
     flag=Generate_Attack_Move_Orbit(h,Inside_Orbit,Inside_Orbit_Index,from_x,from_y,flag,who);
     flag=Generate_Attack_Move_Orbit(h,Outside_Orbit,Outside_Orbit_Index,from_x,from_y,flag,who);
     return flag;
}
int Generate_Attack_Move_Orbit(Move *h,Orbit *orbit,Orbit_Index orbit_index[][6],int from_x,int from_y,int flag,int who){

     if(orbit_index[from_x][from_y].amount==0)
     {
         return flag;
     }
     else if(orbit_index[from_x][from_y].amount==1){
         flag=Generate_Attack_Move_Orbit_Nonode_Direction(h,orbit,orbit_index,from_x,from_y,flag,who,pre_direction);
         flag=Generate_Attack_Move_Orbit_Nonode_Direction(h,orbit,orbit_index,from_x,from_y,flag,who,next_direction);
         return flag;
     }
     else{

         flag=Generate_Attack_Move_Orbit_Node_Direction(h,orbit,orbit_index,from_x,from_y,flag,who,pre_direction);
         flag=Generate_Attack_Move_Orbit_Node_Direction(h,orbit,orbit_index,from_x,from_y,flag,who,next_direction);

        return flag;
     }
}*/
/*int Generate_Attack_Move_Orbit_Nonode_Direction(Move *h,Orbit *orbit,Orbit_Index orbit_index[][6],int from_x,int from_y,int flag,int who,int direction){
    
      int index,arc=0,anti_side_side=0;
      if(direction==1)
      {
          index=orbit_index[from_x][from_y].node_1;
         chessboard[orbit[index].node.x][orbit[index].node.y]=0;//记得还原
         do{
             if(orbit[index].arc==1)
             arc++;
             index=orbit[index].pre;
             anti_side_side++;
             if(chessboard[orbit[index].node.x][orbit[index].node.y]==who)
             {
                  chessboard[from_x][from_y]=who;
                   return flag; 
             }
         }while(chessboard[orbit[index].node.x][orbit[index].node.y]!=-who);
        if(orbit[index].arc==1)
           arc++;
        if(arc>=2&&((anti_side_side!=5)||whether_side_side(from_x,from_y,orbit[index].node.x,orbit[index].node.y))){

     
        Add_Move(h,from_x,from_y,orbit[index].node.x,orbit[index].node.y,flag);
        flag++;
        chessboard[from_x][from_y]=who;
        return flag;
        }
        else{
          
        chessboard[from_x][from_y]=who;
        return flag; 
        }
      }
      else
      {
          index=orbit_index[from_x][from_y].node_1;
         chessboard[orbit[index].node.x][orbit[index].node.y]=0;//记得还原
         do{
             if(orbit[index].arc==1)
             arc++;
             index=orbit[index].next;
              anti_side_side++;
             if(chessboard[orbit[index].node.x][orbit[index].node.y]==who)
             {
                  chessboard[from_x][from_y]=who;
                   return flag; 
             }
             else if(chessboard[orbit[index].node.x][orbit[index].node.y]==2){
             
chessboard[from_x][from_y]=who;
                   return flag; 
             }
         }while(chessboard[orbit[index].node.x][orbit[index].node.y]!=-who);
        if(orbit[index].arc==1)
           arc++;
        if(arc>=2&&((anti_side_side!=5)||whether_side_side(from_x,from_y,orbit[index].node.x,orbit[index].node.y))){
          

        Add_Move(h,from_x,from_y,orbit[index].node.x,orbit[index].node.y,flag);
       
        flag++;
          
        chessboard[from_x][from_y]=who;
        return flag;
        }
        else{
      
        chessboard[from_x][from_y]=who;
        return flag; 
        }
      }
}*/
int whether_side_side(int from_x,int from_y,int to_x,int to_y){
    if(from_x==0&&to_x==5)
      return 0;
    if(from_x==5&&to_x==0)
      return 0;
    if(from_y==0&&to_y==5)
      return 0;
    if(from_y==5&&to_y==0)
      return 0;
    else
      return 1;
}
/*int Generate_Attack_Move_Orbit_Node_Direction(Move *h,Orbit *orbit,Orbit_Index orbit_index[][6],int from_x,int from_y,int flag,int who,int direction){
     int index,arc=0,anti_side_side=0;
      if(direction==1)
      {
          index=orbit_index[from_x][from_y].node_1;
         chessboard[orbit[index].node.x][orbit[index].node.y]=0;//记得还原
         do{
             if(orbit[index].arc==1)
             arc++;
             index=orbit[index].pre;
             anti_side_side++;
             if(chessboard[orbit[index].node.x][orbit[index].node.y]==who)
             {
                
                   arc=0;
                   break;
             }
         }while(chessboard[orbit[index].node.x][orbit[index].node.y]!=-who);
        if(orbit[index].arc==1)
           arc++;
        if(arc>=2){
  
        Add_Move(h,from_x,from_y,orbit[index].node.x,orbit[index].node.y,flag);
        flag++;
        }
        arc=0;
        index=orbit_index[from_x][from_y].node_2;
         chessboard[orbit[index].node.x][orbit[index].node.y]=0;//记得还原
         do{
             if(orbit[index].arc==1)
             arc++;
             index=orbit[index].pre;
             anti_side_side++;
             if(chessboard[orbit[index].node.x][orbit[index].node.y]==who)
             {
                  chessboard[from_x][from_y]=who;
                   return flag; 
             }
         }while(chessboard[orbit[index].node.x][orbit[index].node.y]!=-who);
        if(orbit[index].arc==1)
           arc++;
        if(arc>=2){
      
        Add_Move(h,from_x,from_y,orbit[index].node.x,orbit[index].node.y,flag);
        flag++;
        chessboard[from_x][from_y]=who;
        return flag;
        }
        else{
        chessboard[from_x][from_y]=who;
        return flag; 
        }
}
      else
      {
          index=orbit_index[from_x][from_y].node_1;
         chessboard[orbit[index].node.x][orbit[index].node.y]=0;//记得还原
         do{
             if(orbit[index].arc==1)
             arc++;
             index=orbit[index].next;
             anti_side_side++;
             if(chessboard[orbit[index].node.x][orbit[index].node.y]==who)
             {
                
                   arc=0;
                   break;
             }
         }while(chessboard[orbit[index].node.x][orbit[index].node.y]!=-who);
        if(orbit[index].arc==1)
           arc++;
        if(arc>=2){
  
        Add_Move(h,from_x,from_y,orbit[index].node.x,orbit[index].node.y,flag);
        flag++;
        }
        arc=0;
        index=orbit_index[from_x][from_y].node_2;
         chessboard[orbit[index].node.x][orbit[index].node.y]=0;
         do{
             if(orbit[index].arc==1)
             arc++;
             index=orbit[index].next;
             anti_side_side++;
             if(chessboard[orbit[index].node.x][orbit[index].node.y]==who)
             {
                  chessboard[from_x][from_y]=who;
                   return flag; 
             }
         }while(chessboard[orbit[index].node.x][orbit[index].node.y]!=-who);
        if(orbit[index].arc==1)
           arc++;
        if(arc>=2){
      
        Add_Move(h,from_x,from_y,orbit[index].node.x,orbit[index].node.y,flag);
        flag++;
        chessboard[from_x][from_y]=who;
        return flag;
        }
        else{
        chessboard[from_x][from_y]=who;
        return flag; 
        }


      }
}*/
void Generate_Move_Attack(Move_List *h,int who){
    Rool rool[4][6];
    int  flag_index[4];
    flag_index[0]=extract_outside_rool_1(rool[0]);
    flag_index[1]=extract_outside_rool_2(rool[1]);
    flag_index[2]=extract_outside_rool_3(rool[2]);
    flag_index[3]=extract_outside_rool_4(rool[3]);

Attack_Orbit(h,rool,flag_index,who);

    flag_index[0]=extract_inside_rool_1(rool[0]);
    flag_index[1]=extract_inside_rool_2(rool[1]);
    flag_index[2]=extract_inside_rool_3(rool[2]);
    flag_index[3]=extract_inside_rool_4(rool[3]);

Attack_Orbit(h,rool,flag_index,who);

    



}
void Attack_Orbit(Move_List *h,Rool rool[][6],int *flag_index,int who){
     for(int a=0;a<4;a++){
     if(flag_index[a]!=0){
         if(chessboard[rool[a][flag_index[a]-1].from.x][rool[a][flag_index[a]-1].from.y]==who){
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
         /*else{
             index++;
             if(index>=4)
              index=0;
             while(flag_index[index]<1){
             index++;
             if(index>=4)
             index=0;
         }
           if(rool[index][0].chess==-who){
             Add_Move(h,rool[find_unnull][0].from.x,rool[find_unnull][0].from.y,rool[index][0].from.x,rool[index][0].from.y,flag);
             flag++;
           }
         }*/
         index=a;
         if(flag_index[a]>=2)
         {
             if(rool[a][flag_index[a]-2].chess==-who)
             {
                 Add_Move_Attack(h,rool[a][flag_index[a]-1].from.x,rool[a][flag_index[a]-1].from.y,rool[a][flag_index[a]-2].from.x,rool[a][flag_index[a]-2].from.y);
   
             }
            /* else{
               index--;
              if(index<0)
              index=3;
              while(flag_index[index]<1){
             index--;
              if(index<0)
              index=3;
         }
         if(rool[index][flag_index[index-1]].chess==-who){
            Add_Move(h,rool[a][flag_index[a]-1].from.x,rool[a][flag_index[a]-1].from.y,rool[index][flag_index[index-1]].from.x,rool[index][flag_index[index-1]].from.y,flag);
            flag++;
             }

         }*/

         }



         }
         
}
      
      else{
       /* printf("a=%d flag_index[a]-1=%d find_null=%d\n",a,flag_index[a]-1,find_unnull);
       printf("I have judged %d %d\n",rool[a][flag_index[a]-1].chess,rool[find_unnull][0].chess);*/

       Add_Move_Attack(h,rool[a][flag_index[a]-1].from.x,rool[a][flag_index[a]-1].from.y,rool[find_unnull][0].from.x,rool[find_unnull][0].from.y);

      }
     }
if(chessboard[rool[a][0].from.x][rool[a][0].from.y]==who)
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





int extract_outside_rool_1(Rool *rool_1){
   
    int index=0;
   for(int a=5;a>=0;a--){
    if(chessboard[2][a]!=0){
    rool_1[index].chess=chessboard[2][a];
    rool_1[index].from.x=2;
     rool_1[index].from.y=a;
    index++;
    }
   }
   return index;
}
int extract_outside_rool_2(Rool *rool){
    
    int index=0;
   for(int a=0;a<6;a++){
    if(chessboard[a][2]!=0){
    rool[index].chess=chessboard[a][2];
    rool[index].from.x=a;
     rool[index].from.y=2;
    index++;
    }
   }
   return index;
}
int extract_outside_rool_3(Rool *rool){
  
    int index=0;
   for(int a=0;a<6;a++){
    if(chessboard[3][a]!=0){
    rool[index].chess=chessboard[3][a];
    rool[index].from.x=3;
     rool[index].from.y=a;
    index++;
    }
   }
   return index;
}
int extract_outside_rool_4(Rool *rool_4){

    int index=0;
   for(int a=5;a>=0;a--){
    if(chessboard[a][3]!=0){
    rool_4[index].chess=chessboard[a][3];
    rool_4[index].from.x=a;
     rool_4[index].from.y=3;
    index++;
    }
   }
   return index;
}
int extract_inside_rool_1(Rool *rool_1){
   
    int index=0;
   for(int a=5;a>=0;a--){
    if(chessboard[1][a]!=0){
    rool_1[index].chess=chessboard[1][a];
    rool_1[index].from.x=1;
     rool_1[index].from.y=a;
    index++;
    }
   }
   return index;
}
int extract_inside_rool_2(Rool *rool){
    
    int index=0;
   for(int a=0;a<6;a++){
    if(chessboard[a][1]!=0){
    rool[index].chess=chessboard[a][1];
    rool[index].from.x=a;
     rool[index].from.y=1;
    index++;
    }
   }
   return index;
}
int extract_inside_rool_3(Rool *rool){
  
    int index=0;
   for(int a=0;a<6;a++){
    if(chessboard[4][a]!=0){
    rool[index].chess=chessboard[4][a];
    rool[index].from.x=4;
     rool[index].from.y=a;
    index++;
    }
   }
   return index;
}
int extract_inside_rool_4(Rool *rool_4){

    int index=0;
   for(int a=5;a>=0;a--){
    if(chessboard[a][4]!=0){
    rool_4[index].chess=chessboard[a][4];
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
Move_List *del_duplicate(Move_List *h){
    Move_List *p;
    int index;
    p=(Move_List *)malloc(52*sizeof(Move_List));
    p->flag=0;
    
    for(int a=0;a<h->flag;a++){
        index=0;
        for(int b=a+1;b<h->flag;b++){
            if(h->list[a].from.x==h->list[b].from.x&&h->list[a].from.y==h->list[b].from.y&&h->list[a].to.x==h->list[b].to.x&&h->list[a].to.y==h->list[b].to.y){
            index=1;
            break;
            }
        }
        if(!index)
        {
            p->list[p->flag].from.x=h->list[a].from.x;
            p->list[p->flag].from.y=h->list[a].from.y;
            p->list[p->flag].to.x=h->list[a].to.x;
            p->list[p->flag].to.y=h->list[a].to.y;
            p->flag++;
           
        }
    }
    return p;
}
void visualize(Move_List *h){
for(int a=0;a<h->flag;a++){
    printf("from %d,%d to %d,%d\n",h->list[a].from.x,h->list[a].from.y,h->list[a].to.x,h->list[a].to.y);
}
}