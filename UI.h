#ifndef UI_h
#define UI_h
#include<stdio.h>
//#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "Basic.h"
SDL_Texture *renderText(char *s, char *e, SDL_Color color,int fontSize);
choice begin(void);
void Init_Position(void);
void Init_Display_Position(void);
void Display(void);

#endif
