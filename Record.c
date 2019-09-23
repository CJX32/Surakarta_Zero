#include "Record.h"
extern FILE *battle;
extern Move_List battle_record;
extern char path[70];
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