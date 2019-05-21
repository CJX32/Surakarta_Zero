#ifndef Initialization_h
#define Initialization_h
#include <stdlib.h>
#include "Move_Generator.h"
#define Orbit_Length 24
void Init_Chessboard(void);
void Add_Node(Orbit *orbit,int node,int node_x,int node_y,int arc,int next,int pre);
void Init_Inside_Orbit(void);
void Init_Outside_Orbit(void);
void Init_Inside_Orbit_Index(void);
void Init_Outside_Orbit_Index(void);
#endif
