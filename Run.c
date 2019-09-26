#include "Run.h"
extern int k1,k2,k3,k4;
extern Chessboard chessboard;
extern int who;
void run(void){

    FILE *record=fopen("/Users/bluesky/Desktop/Surakarta_Zero/record.txt","r");
    if(record==NULL){
    printf("File open error\n");
    exit(0);
    }
    int evalue[2][4],choice;
    fscanf(record,"%d%d%d%d",&evalue[0][0],&evalue[0][1],&evalue[0][2],&evalue[0][3]);
    evalue[1][0]=1;
    evalue[1][1]=0;
    evalue[1][2]=0;
    evalue[1][3]=0;

    while(!judge(chessboard)){
 
    who=1;
    k1=evalue[0][0];k2=evalue[0][1];k3=evalue[0][2];k4=evalue[0][3];
    AI(7);
    if(!judge(chessboard)){
    who=-1;
    k1=evalue[1][0];k2=evalue[1][1];k3=evalue[1][2];k4=evalue[1][3];
    AI(7);
    }
    }

    if(judge(chessboard)==1)
     choice=1;
    else if(judge(chessboard)==2)
     choice=0;
     fclose(record);
     printf("final_choice=%d\n",choice);
    record=fopen("/Users/bluesky/Desktop/Surakarta_Zero/record.txt","w");
    if(record==NULL){
    printf("File open error\n");
    exit(0);
    }
 


    printf("\n%d %d %d %d\n",evalue[choice][0],evalue[choice][1],evalue[choice][2],evalue[choice][3]);
    fprintf(record,"%d %d %d %d\n",evalue[choice][0],evalue[choice][1],evalue[choice][2],evalue[choice][3]);
    fclose(record);
}