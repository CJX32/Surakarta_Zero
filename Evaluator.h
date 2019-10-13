#ifndef Evaluator_h
#define Evaluator_h
#include <stdio.h>
#include "Basic.h"
int Evaluate(Chessboard chessboard_test,int who_test);
int count(Chessboard chessboard_test);
int position_value(Chessboard chessboard_test);
int greenpotential(Chessboard chessboard_test);
int arc_count(Chessboard chessboard_test);
int anotherMark(Chessboard chessboard_test);
int Evaluate_test(Chessboard chessboard_test,int who_test);
int count_num(void);
#endif
