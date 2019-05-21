#ifndef Search_Engine_h
#define Search_Engine_h
#include <stdlib.h>
#include "Evaluator.h"
#include "Move_Generator.h"
#include "Basic.h"
int Alpha_Beta(int depth,int alpha,int beta,int minimaxplayer);

int max(int a,int b);
int mini(int a,int b);

int count(void);
#endif