#ifndef Evaluator_h
#define Evaluator_h
#include <stdio.h>
#include "Basic.h"
int Evaluate(int chessboard_test[][6]);
int count(int chessboard_test[][6]);
int position_value(int chessboard_test[][6]);
int greenpotential(int chessboard_test[][6]);
int arc_count(int chessboard_test[][6]);
int anotherMark(int chessboard_test[][6]);
int Evaluate_test(int chessboard_test[][6],int who_test);
#endif
