#ifndef UI_h
#define UI_h
#include<stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
SDL_Texture *renderText(char *s, char *e, SDL_Color color,int fontSize, SDL_Renderer *ren);
int begin(SDL_Renderer *ren,SDL_Texture *Blackmax,SDL_Texture *Blackmini,SDL_Texture *Whitemax,SDL_Texture *Whitemini,SDL_Texture *dback,SDL_Texture *tishi);
void Init_Position(SDL_Rect position[][6]);
void Init_Display_Position(SDL_Rect display_position[][6]);
void Display(SDL_Renderer *ren,SDL_Texture *blackchess,SDL_Texture *whitechess,int chessboard[][6],SDL_Rect position[][6]);
int Locate_x(int mouse_y,SDL_Rect position[][6]);
int Locate_y(int mouse_x,SDL_Rect position[][6]);
int Play_H(int who,int chessboard[][6],int x,int y);
#endif
