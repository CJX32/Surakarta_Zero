#include "test.h"
extern int chessboard[6][6];
void test(FILE *fp){
int count=0,ta;

int index_1,index_2,index_3,index_4;
 while(count<=5715){

     count++;
     
     Move_List *h;
     
     h=(Move_List *)malloc(sizeof(Move_List));
  

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

 Move_Generate(h,-1,chessboard);
 if(h->flag!=index_3){

 printf("chess=-1 \n%d %d\n",h->flag,index_3);
 for(int a=0;a<6;a++){
      for(int b=0;b<6;b++){
          printf("%d ",chessboard[a][b]);
      }
      printf("\n");
  }
 visualize(h);

 }
  Move_Generate(h,1,chessboard);
 if(h->flag!=index_4){

 printf("chess=-1 \n%d %d\n",h->flag,index_4);
 for(int a=0;a<6;a++){
      for(int b=0;b<6;b++){
          printf("%d ",chessboard[a][b]);
      }
      printf("\n");
  }
 visualize(h);

 }


count++;

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
       int haha;
       int alpha=-2147483646,beta=2147483647;
       Hash_Move *p;
       p=(Hash_Move *)malloc((Hash_table_length)*sizeof(Hash_Move));
       Hash_Table_Init(p);
       for(int a=1;a<=7;a++){
           //data[a-1]=Alpha_Beta_Multi_Thread(a, 1,alpha,beta);
          int vl=Alpha_Beta(a,alpha,beta,1,chessboard,p);
          //int vl=Alpha_Beta_Multi_Thread(a,1,alpha,beta);
           if(a%2)
           data[a-1]=-vl;
           else
            data[a-1]=vl;
           
        /*    haha=data[a-1];
           alpha=haha-1;
           beta=haha+1;*/
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
              printf("depth=%d index=%d my=%d\n",d+1,index[d],data[d]);
               }
               break;
          }
       }
    }
    printf("Error_number=%d\n",count);
}
