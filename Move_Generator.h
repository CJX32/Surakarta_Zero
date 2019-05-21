#ifndef Move_Generator_h
#define Move_Generator_h
#define pre_direction 1
#define next_direction 2
#include <stdio.h>
#include <stdlib.h>
typedef struct position{
    int x;
    int y;
}Position;
typedef struct move{
Position from;
Position to;
}Move;
typedef struct orbit{
Position node;
int arc;
int next;
int pre;
}Orbit;
typedef  struct orbit_index{
int amount;
int node_1;
int node_2;
}Orbit_Index;
typedef struct rool{
int chess;
Position from;
}Rool;
typedef struct move_list{
    Move list[100];
    int  flag;
}Move_List;
void Add_Move(Move_List *h, int from_x, int from_y, int to_x, int to_y);
void Move_Generate(Move_List *h,int who);
int Generate_Attack_Move(Move *h,int from_x,int from_y,int index,int who);
void  Add_Move_Attack(Move_List *h,int from_x,int from_y,int to_x,int to_y);
/*int Generate_Attack_Move_Orbit(Move *h,Orbit *orbit,Orbit_Index orbit_index[][6],int from_x,int from_y,int flag,int who);
int Generate_Attack_Move_Orbit_Nonode_Direction(Move *h,Orbit *orbit,Orbit_Index orbit_index[][6],int from_x,int from_y,int flag,int who,int direction);
int Generate_Attack_Move_Orbit_Node_Direction(Move *h,Orbit *orbit,Orbit_Index orbit_index[][6],int from_x,int from_y,int flag,int who,int direction);*/
int whether_side_side(int from_x,int from_y,int to_x,int to_y);
void Generate_Move_Attack(Move_List *h,int who);
void Attack_Orbit(Move_List *h,Rool rool[][6],int *flag_index,int who);
int extract_outside_rool_1(Rool *rool_1);
int extract_outside_rool_2(Rool *rool_2);
int extract_outside_rool_3(Rool *rool_3);
int extract_outside_rool_4(Rool *rool_4);
int extract_inside_rool_1(Rool *rool_1);
int extract_inside_rool_2(Rool *rool_2);
int extract_inside_rool_3(Rool *rool_3);
int extract_inside_rool_4(Rool *rool_4);
int Sort_Move(Move *h,int flag);
Move_List *del_duplicate(Move_List *h);
void visualize(Move_List *h);
#endif