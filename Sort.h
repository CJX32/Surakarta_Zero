#ifndef Sort_h
#define Sort_h
#include <stdlib.h>
#include "Basic.h"
void merge_sort(Move *list,int length);
void merge(Move *list,Move *right,Move *left,int length);
void switch_move(Move_List *h,int a);
#endif