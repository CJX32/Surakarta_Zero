#ifndef test_h
#define test_h
#include <stdio.h>
#include "Move_Generator.h"
#include "Search_Engine.h"
#include <stdlib.h>
#define NO_CHESS 0
#define PINK_CHESS 1
#define BLACK_CHESS -1

void test_alpha_beta(FILE *fp);
int * decode(long long board);
void test(FILE *fp);
void new_test(FILE *fp);
#endif 