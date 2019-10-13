#include "Record.h"
extern FILE *battle;
extern FILE *competition;
extern FILE *board;
extern Move_List battle_record;
extern Chessboard chessboard;
extern char path[70];
extern int who;
void record_pre(int index){
int digit=0,c=51,b=index;
for(int a=0;b!=0;a++){
b/=10;
digit++;
}
for(int a=54;a>=51;a--)
path[a+digit]=path[a];
b=index;
c=50+digit;
while(b!=0){
    path[c]=b%10+48;
    b/=10;
    c--;
}
printf("%s\n",path);
battle=fopen(path,"a+");

}
void record(int from_x,int from_y,int to_x,int to_y){
battle=fopen(path,"a");
static int index;
battle_record.list[index].from.x=from_x;
battle_record.list[index].to.x=to_x;
battle_record.list[index].from.y=from_y;
battle_record.list[index].to.y=to_y;
fprintf(battle,"from %d %d to %d %d\n",from_x,from_y,to_x,to_y);
fclose(battle);
}
void pre_record_competition(){
    competition=fopen("/Users/bluesky/Desktop/Competition_Data/index.txt","r");
    int num,n,index=40;
    fscanf(competition,"%d",&num);
    competition=fopen("/Users/bluesky/Desktop/Competition_Data/index.txt","w");
    fprintf(competition,"%d",num);
    fclose(competition);
    char path[60]="/Users/bluesky/Desktop/Competition_Data/";

     while(num>=10){
     n=num%10;
     num/=10;
     path[index++]=n+48;
    }
     path[index++]=num+48;
    path[index++]='.';
    path[index++]='t';
    path[index++]='x';
    path[index++]='t';
    path[index++]='\0';
    competition=fopen(path,"a+");
}
void record_competition(int who,int from_x,int from_y,int to_x,int to_y,int mode){
if(who==1){
fprintf(competition,"B");
fprintf(competition,"%c",from_x+49);
fprintf(competition,"%c",from_y+65);
if(mode==KILL)
fprintf(competition,"x");
else
fprintf(competition,"-");
fprintf(competition,"%c",to_x+49);
fprintf(competition,"%c",to_y+65);
}
else
{
fprintf(competition,"R");
fprintf(competition,"%c",from_x+49);
fprintf(competition,"%c",from_y+65);
if(mode==KILL)
fprintf(competition,"x");
else
fprintf(competition,"-");
fprintf(competition,"%c",to_x+49);
fprintf(competition,"%c",to_y+65);
}
fprintf(competition,"\n");
fclose(competition);
}
void end_record(){
       competition=fopen("/Users/bluesky/Desktop/Competition_Data/index.txt","r");
    int num,n,index=40;
    fscanf(competition,"%d",&num);
    competition=fopen("/Users/bluesky/Desktop/Competition_Data/index.txt","w");
    fprintf(competition,"%d",num+1);
    fclose(competition);
}
void board_record(){
board=fopen("/Users/bluesky/Desktop/Competition_Data/board.txt","w");
fprintf(board,"1\n");
for(int a=0;a<6;a++){
    for(int b=0;b<6;b++){
        if(chessboard.chessboard[a][b]==-1)
        fprintf(board,"2 ");
        else
    fprintf(board,"%d ",chessboard.chessboard[a][b]);
    }
    fprintf(board,"\n");
}
fprintf(board,"%d %d %d",chessboard.black,chessboard.white,who);
fclose(board);
}
int load(){
board=fopen("/Users/bluesky/Desktop/Competition_Data/board.txt","r");
int index,flag;
fscanf(board,"%d\n",&index);
if(index==1)
{
    for(int a=0;a<6;a++){
        for(int b=0;b<6;b++){
            fscanf(board,"%d ",&flag);
            if(flag==2)
            chessboard.chessboard[a][b]=-1;
            else
             chessboard.chessboard[a][b]=flag;
        }
    }
    fscanf(board,"%d ",&chessboard.black);
    fscanf(board,"%d ",&chessboard.white);
    fscanf(board,"%d ",&who);
    printf("return 1\n");
    return 1;
}

printf("return 0\n");
fclose(board);
return 0;
}
void end_game(void){
board=fopen("/Users/bluesky/Desktop/Competition_Data/board.txt","w");
fprintf(board," ");
fclose(board);
}