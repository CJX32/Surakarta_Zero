#ifndef Move_Generator_h
#define Move_Generator_h
#define pre_direction 1
#define next_direction 2
#include <stdio.h>
#include <stdlib.h>
#include "Basic.h"
void Add_Move(Move_List *h, int from_x, int from_y, int to_x, int to_y);
void Move_Generate(Move_List *h,int who,int chessboard_test[][6]);
void Move_Generate_reverse(Move_List *h, int who,int chessboard_test[][6]);
int Generate_Attack_Move(Move *h,int from_x,int from_y,int index,int who,int chessboard_test[][6]);
void Add_Move_Attack(Move_List *h,int from_x,int from_y,int to_x,int to_y);
int whether_side_side(int from_x,int from_y,int to_x,int to_y);
void Generate_Move_Attack(Move_List *h,int who,int chessboard_test[][6]);
void Attack_Orbit(Move_List *h,Rool rool[][6],int *flag_index,int who,int chessboard_test[][6]);
int extract_outside_rool_1(Rool *rool_1,int chessboard_test[][6]);
int extract_outside_rool_2(Rool *rool_2,int chessboard_test[][6]);
int extract_outside_rool_3(Rool *rool_3,int chessboard_test[][6]);
int extract_outside_rool_4(Rool *rool_4,int chessboard_test[][6]);
int extract_inside_rool_1(Rool *rool_1,int chessboard_test[][6]);
int extract_inside_rool_2(Rool *rool_2,int chessboard_test[][6]);
int extract_inside_rool_3(Rool *rool_3,int chessboard_test[][6]);
int extract_inside_rool_4(Rool *rool_4,int chessboard_test[][6]);
int Sort_Move(Move *h,int flag);
#endif