#ifndef Interact_h
#define Interact_h
#include <SDL2/SDL.h>
void Place_Move(int *who_test,int *game,SDL_Rect position[6][6]);
int Play_H(int who,int chessboard[][6],int x,int y);
int Locate_x(int mouse_y,SDL_Rect position[][6]);
int Locate_y(int mouse_x,SDL_Rect position[][6]);
#endif