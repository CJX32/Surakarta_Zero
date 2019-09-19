#include "Record.h"
extern FILE *battle;
void record_pre(int index){
int digit=0,c=51,b=index;
char path[70]="/Users/bluesky/Desktop/Surakarta_Zero/Battle/record.txt";
for(int a=0;b!=0;a++){
b/=10;
digit++;
}
for(int a=54;a>=51;a--)
path[a+digit]=path[a];
b=index;
c=51+digit;
while(b!=0){
    path[c]=b%10+48;
    b/=10;
    c--;
}
printf("%s\n",path);
battle=fopen(path,"a+");
fclose(battle);
}