#ifndef Move_Generator_h
#define Move_Generator_h
#define pre_direction 1
#define next_direction 2
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "Basic.h"
void Add_Move(Move_List *h, int from_x, int from_y, int to_x, int to_y);
void Move_Generate(Move_List *h,int who, Chessboard chessboard_test);
void Move_Generate_reverse(Move_List *h, int who, Chessboard chessboard_test);
int Generate_Attack_Move(Move *h,int from_x,int from_y,int index,int who, Chessboard chessboard_test);
void Add_Move_Attack(Move_List *h,int from_x,int from_y,int to_x,int to_y);
int whether_side_side(int from_x,int from_y,int to_x,int to_y);
void Generate_Move_Attack(Move_List *h,int who, Chessboard chessboard_test);
void Attack_Orbit(Move_List *h,Rool rool[][6],int *flag_index,int who, Chessboard chessboard_test);
int extract_outside_rool_1(Rool *roo,Chessboard chessboard_test);
int extract_outside_rool_2(Rool *rool_2, Chessboard chessboard_test);
int extract_outside_rool_3(Rool *rool_3, Chessboard chessboard_test);
int extract_outside_rool_4(Rool *rool_4, Chessboard chessboard_test);
int extract_inside_rool_1(Rool *rool_1, Chessboard chessboard_test);
int extract_inside_rool_2(Rool *rool_2, Chessboard chessboard_test);
int extract_inside_rool_3(Rool *rool_3, Chessboard chessboard_test);
int extract_inside_rool_4(Rool *rool_4, Chessboard chessboard_test);
void* extract_outside_rool_1_MT(void *Para);
void* extract_outside_rool_2_MT(void *Para);
void* extract_outside_rool_3_MT(void *Para);
void* extract_outside_rool_4_MT(void *Para);
void* extract_inside_rool_1_MT(void *Para);
void* extract_inside_rool_2_MT(void *Para);
void* extract_inside_rool_3_MT(void *Para);
void* extract_inside_rool_4_MT(void *Para);
int Sort_Move(Move *h,int flag);
void Generate_Move_Attack_Multi_Thread(Move_List *h,int who, Chessboard chessboard_test);
void Move_Generate_MT(Move_List *h, int who, Chessboard chessboard_test);
void *Generate_Move_Attack_Multi_Thread_In(void *para);
void *Generate_Move_Attack_Multi_Thread_Out(void *para);
#endif