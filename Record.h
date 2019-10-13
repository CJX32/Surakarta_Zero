#ifndef Record_h
#define Record_h
#include <stdio.h>
#include "Basic.h"
#define KILL 1
#define NOR 2
void record_pre(int index);
void record(int from_x,int from_y,int to_x,int to_y);
void pre_record_competition();
void record_competition();
void end_record();
void board_record();
int load();
void end_game(void);
#endif