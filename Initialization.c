#include "Initialization.h"
extern int chessboard[6][6];
extern Orbit *Inside_Orbit;
extern Orbit *Outside_Orbit;
extern Orbit_Index Inside_Orbit_Index[6][6];
extern Orbit_Index Outside_Orbit_Index[6][6];
void Init_Chessboard(){
    for(int a=0;a<6;a++){
        for(int b=0;b<6;b++){
            if(a<2)
                chessboard[a][b]=1;
            else if(a>=4)
                chessboard[a][b]=-1;
            else
                chessboard[a][b]=0;
        }
    }
}
void Add_Node(Orbit *orbit,int node,int node_x,int node_y,int arc,int next,int pre){
orbit[node].node.x=node_x;
orbit[node].node.y=node_y;
orbit[node].arc=arc;
orbit[node].next=next;
orbit[node].pre=pre;
}
void Init_Inside_Orbit(){
    Inside_Orbit=(Orbit *)malloc(Orbit_Length*sizeof(Orbit));
    Add_Node(Inside_Orbit, 0, 1, 1, 0, 1, 23);
    Add_Node(Inside_Orbit, 1, 0, 1, 1, 2, 0);
    Add_Node(Inside_Orbit, 2, 1, 0, 1, 3, 1);
    Add_Node(Inside_Orbit, 3, 1, 1, 0, 4, 2);
    Add_Node(Inside_Orbit, 4, 1, 2, 0, 5, 3);
    Add_Node(Inside_Orbit, 5, 1, 3, 0, 6, 4);
    Add_Node(Inside_Orbit, 6, 1, 4, 0, 7, 5);
    Add_Node(Inside_Orbit, 7, 1, 5, 1, 8, 6);
    Add_Node(Inside_Orbit, 8, 0, 4, 1, 9, 7);
    Add_Node(Inside_Orbit, 9, 1, 4, 0, 10, 8);
    Add_Node(Inside_Orbit, 10, 2, 4, 0, 11, 9);
    Add_Node(Inside_Orbit, 11, 3, 4, 0, 12, 10);
    Add_Node(Inside_Orbit, 12, 4, 4, 0, 13, 11);
    Add_Node(Inside_Orbit, 13, 5, 4, 1, 14, 12);
    Add_Node(Inside_Orbit, 14, 4, 5, 1, 15, 13);
    Add_Node(Inside_Orbit, 15, 4, 4, 0, 16, 14);
    Add_Node(Inside_Orbit, 16, 4, 3, 0, 17, 15);
    Add_Node(Inside_Orbit, 17, 4, 2, 0, 18, 16);
    Add_Node(Inside_Orbit, 18, 4, 1, 0, 19, 17);
    Add_Node(Inside_Orbit, 19, 4, 0, 1, 20, 18);
    Add_Node(Inside_Orbit, 20, 5, 1, 1, 21, 19);
    Add_Node(Inside_Orbit, 21, 4, 1, 0, 22, 20);
    Add_Node(Inside_Orbit, 22, 3, 1, 0, 23, 21);
    Add_Node(Inside_Orbit, 23, 2, 1, 0, 0, 22);
}
void Init_Outside_Orbit(){
    Outside_Orbit=(Orbit *)malloc(Orbit_Length*sizeof(Orbit));
    Add_Node(Outside_Orbit, 0, 2, 2, 0, 1, 23);
    Add_Node(Outside_Orbit, 1, 1, 2, 0, 2, 0);
    Add_Node(Outside_Orbit, 2, 0, 2, 1, 3, 1);
    Add_Node(Outside_Orbit, 3, 2, 0, 1, 4, 2);
    Add_Node(Outside_Orbit, 4, 2, 1, 0, 5, 3);
    Add_Node(Outside_Orbit, 5, 2, 2, 0, 6, 4);
    Add_Node(Outside_Orbit, 6, 2, 3, 0, 7, 5);
    Add_Node(Outside_Orbit, 7, 2, 4, 0, 8, 6);
    Add_Node(Outside_Orbit, 8, 2, 5, 1, 9, 7);
    Add_Node(Outside_Orbit, 9, 0, 3, 1, 10, 8);
    Add_Node(Outside_Orbit, 10, 1, 3, 0, 11, 9);
    Add_Node(Outside_Orbit, 11, 2, 3, 0, 12, 10);
    Add_Node(Outside_Orbit, 12, 3, 3, 0, 13, 11);
    Add_Node(Outside_Orbit, 13, 4, 3, 0, 14, 12);
    Add_Node(Outside_Orbit, 14, 5, 3, 1, 15, 13);
    Add_Node(Outside_Orbit, 15, 3, 5, 1, 16, 14);
    Add_Node(Outside_Orbit, 16, 3, 4, 0, 17, 15);
    Add_Node(Outside_Orbit, 17, 3, 3, 0, 18, 16);
    Add_Node(Outside_Orbit, 18, 3, 2, 0, 19, 17);
    Add_Node(Outside_Orbit, 19, 3, 1, 0, 20, 18);
    Add_Node(Outside_Orbit, 20, 3, 0, 1, 21, 19);
    Add_Node(Outside_Orbit, 21, 5, 2, 1, 22, 20);
    Add_Node(Outside_Orbit, 22, 4, 2, 0, 23, 21);
    Add_Node(Outside_Orbit, 23, 3, 2, 0, 0, 22);
}
void Init_Inside_Orbit_Index(){
   int index_x,index_y;
   for(int a=0;a<6;a++){
       for(int b=0;b<6;b++){
         Inside_Orbit_Index[a][b].amount=0;
   }
   }
   for(int a=0;a<24;a++){
       index_x=Inside_Orbit[a].node.x;index_y=Inside_Orbit[a].node.y;
       if(Inside_Orbit_Index[index_x][index_y].amount==0){
          Inside_Orbit_Index[index_x][index_y].node_1=a;
          Inside_Orbit_Index[index_x][index_y].amount=1;
       }
       else{
        Inside_Orbit_Index[index_x][index_y].node_2=a;
          Inside_Orbit_Index[index_x][index_y].amount=2;
       }
   }
}
void Init_Outside_Orbit_Index(){
int index_x,index_y;
   for(int a=0;a<6;a++){
       for(int b=0;b<6;b++){
         Outside_Orbit_Index[a][b].amount=0;
   }
   }
   for(int a=0;a<24;a++){
       index_x=Outside_Orbit[a].node.x;index_y=Outside_Orbit[a].node.y;
       if(Outside_Orbit_Index[index_x][index_y].amount==0){
          Outside_Orbit_Index[index_x][index_y].node_1=a;
          Outside_Orbit_Index[index_x][index_y].amount=1;
       }
       else{
          Outside_Orbit_Index[index_x][index_y].node_2=a;
          Outside_Orbit_Index[index_x][index_y].amount=2;
       }
   }
}