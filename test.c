#include "test.h"
extern int chessboard[6][6];
int cntBlack;
int cntPink;




int * decode(long long board){
    //get the board from a long long type number
    cntBlack=0;
    cntPink=0;
    int* result = (int*)malloc(36*sizeof(char));
    for(int i=0;i<36;i++){
        if(board&1){
            board>>=1;
            if(board&1){
                cntBlack++;
                chessboard[i/6][i-6*(i/6)]=BLACK_CHESS;
            }
            else{
                cntPink++;
                chessboard[i/6][i-6*(i/6)]=PINK_CHESS;
            }
            board>>=1;
        }
        else{
            board>>=1;
            chessboard[i/6][i-6*(i/6)]=NO_CHESS;
        }
    }
    return result;
}
void test(FILE *fp){
int count=0,ta;

int index_1,index_2,index_3,index_4;
 while(count<=5715){
     // printf("%d\n",count);
     count++;
     
     Move_List *h;
     
     h=(Move_List *)malloc(100*sizeof(Move_List));
     h->flag=0;

for(int a=0;a<6;a++){
      for(int b=0;b<6;b++){
        fscanf(fp,"%d",&ta);
        if(ta==2)
        chessboard[a][b]=-1;
        else
        chessboard[a][b]=ta;
      }
}

 fscanf(fp,"%d %d %d %d",&index_1,&index_2,&index_3,&index_4);

 Move_Generate(h,-1);
 if(h->flag!=index_3){
  printf("count=%d\n",count);
 printf("chess=-1 \n%d %d\n",h->flag,index_3);
 for(int a=0;a<6;a++){
      for(int b=0;b<6;b++){
          printf("%d ",chessboard[a][b]);
      }
      printf("\n");
  }
 visualize(h);

 }


count++;
     
    
    
     h=(Move_List *)malloc(100*sizeof(Move_List));
      h->flag=0;
      for(int a=0;a<6;a++){
      for(int b=0;b<6;b++){
        fscanf(fp,"%d",&ta);
        if(ta==2)
        chessboard[a][b]=-1;
        else
        chessboard[a][b]=ta;
      }
}

 fscanf(fp," %d %d %d %d",&index_1,&index_2,&index_3,&index_4);

 Move_Generate(h,1);
 if(h->flag!=index_4){
 printf("count=%d\n",count);
 printf("chess=1  \n%d %d\n",h->flag,index_4);
 for(int a=0;a<6;a++){
      for(int b=0;b<6;b++){
          printf("%d ",chessboard[a][b]);
      }
      printf("\n");
  }
 visualize(h);

 }
}
}
void test_alpha_beta(FILE *fp){
    int count=0;
    for(int a=0;a<100;a++){
        int flag;
       for(int b=0;b<6;b++){
           for(int c=0;c<6;c++){
               fscanf(fp,"%d ",&flag);
              if(flag==2)
              chessboard[b][c]=-1;
              else
              chessboard[b][c]=flag;
              
           }
       }
       int index[7];
       int data[7];
       for(int a=0;a<7;a++){
           fscanf(fp,"%d",&index[a]);
       }
       for(int a=1;a<=7;a++){
           data[a-1]=Alpha_Beta(a,-2147483648, 2147483647, 1);
         
       }
       for(int e=0;e<7;e++){
           if(data[e]!=index[e]){
               count++;
               for(int c=0;c<6;c++){
                 for(int b=0;b<6;b++){
                     if(chessboard[c][b]==-1)
                     printf("2 ");
                     else
                 printf("%d ",chessboard[c][b]);
                 }
                 printf("\n");
               }
               for(int d=0;d<7;d++){
                   printf("index=%d data=%d\n",index[d],data[d]);
               }
              /*Move *h;
              h=(Move *)malloc(52*sizeof(Move));
              int haha=Generate_Move_Attack(h,1,0);
               visualize(h,haha);*/
             
               break;
           }
 
       }
    }
    printf("Error_number=%d\n",count);
}
