//
//  Game_AI.c
//  Surakarta
//
//  Created by Blue Sky on 3/15/19.
//  Copyright © 2019 Blue Sky. All rights reserved.
//

#include "Game_AI.h"
extern int chessboard[6][6];


void game_AI(int depth){
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        printf("SDL Init");
        SDL_Quit();
        return ;
    }
    if (TTF_Init() != 0)
    {
        printf("Font Load");
        SDL_Quit();
        return ;
    }
    SDL_Window *win = SDL_CreateWindow("Suratarka", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    if (win == NULL)
    {
        printf("Create Window");
        SDL_Quit();
        return ;
    }
    SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (ren == NULL)
    {
        printf("Create Render");
        SDL_DestroyWindow(win);
        SDL_Quit();
    }
    SDL_Texture *back= IMG_LoadTexture(ren, "/Users/bluesky/Documents/Surakarta/board.jpg");
    if(back==NULL){
        printf("Load background3");
        SDL_DestroyWindow(win);
        SDL_DestroyRenderer(ren);
        SDL_Quit();
        return ;
    }
    SDL_Texture *dback= IMG_LoadTexture(ren, "/Users/bluesky/Documents/Surakarta/dboard.jpeg");
    if(dback==NULL){
        printf("Load dbackground");
        SDL_DestroyWindow(win);
        SDL_DestroyRenderer(ren);
        SDL_Quit();
        return ;
    }
    SDL_Surface *chess= IMG_Load("/Users/bluesky/Documents/Surakarta/Chess.jpg");
    if(chess==NULL){
        printf("Load background1");
        SDL_DestroyWindow(win);
        SDL_DestroyRenderer(ren);
        SDL_Quit();
        return ;
    }
    SDL_Surface *whitechess= IMG_Load("/Users/bluesky/Documents/Surakarta/WhiteChess.png");
    if(whitechess==NULL){
        printf("Load background2");
        SDL_DestroyWindow(win);
        SDL_DestroyRenderer(ren);
        SDL_Quit();
        return ;
    }
    SDL_Color color = {0, 0, 0, 0};
    SDL_Color color1={191,191,191,191};
    SDL_Color color2 = {255,255,255,255};
    Uint32 color3 = SDL_MapRGB(chess->format, 255, 255, 255);
    SDL_SetColorKey(chess, SDL_TRUE, color3);
    Uint32 color4 = SDL_MapRGB(whitechess->format, 0, 0, 0);
    SDL_SetColorKey(whitechess, SDL_TRUE, color4);
    SDL_Texture *Chess=SDL_CreateTextureFromSurface(ren, chess);
    SDL_Texture *WhiteChess=SDL_CreateTextureFromSurface(ren, whitechess);
    SDL_Texture *Blackmini = renderText("Black Chess", "/Users/bluesky/Documents/Renzhe/Font.ttf", color, 40, ren);
    SDL_Texture *Blackmax = renderText("Black Chess", "/Users/bluesky/Documents/Renzhe/Font.ttf", color, 55, ren);
    SDL_Texture *Whitemini = renderText("White Chess", "/Users/bluesky/Documents/Renzhe/Font.ttf", color2, 40, ren);
    SDL_Texture *Whitemax = renderText("White Chess", "/Users/bluesky/Documents/Renzhe/Font.ttf", color2, 55, ren);
    SDL_Texture *tishi = renderText("Choose the Color of chess", "/Users/bluesky/Documents/Renzhe/Font.ttf", color1, 40, ren);
    SDL_Texture *win1 = renderText("Black Chess WIN!", "/Users/bluesky/Documents/Renzhe/Font.ttf", color2, 40, ren);
    SDL_Texture *win2 = renderText("White Chess WIN!", "/Users/bluesky/Documents/Renzhe/Font.ttf", color2, 40, ren);
    int who=begin(ren,Blackmax,Blackmini,Whitemax,Whitemini,dback,tishi);
    int *who_test=&who;
    Chessboard_Init(chessboard);
    SDL_Rect position[6][6];
    Init_Position(position);
    SDL_Rect display_position[6][6];
    Init_Display_Position(display_position);
    SDL_Event e;
    
    
    

    
    
    


    FILE *index=fopen("/Users/bluesky/Documents/Surakarta/Index.txt", "r");
  if(index==NULL)
    printf("\n\n\nError occurd when open file\n");
    
  
 
    FILE *fp;
    fp=fopen("/Users/bluesky/Documents/Surakarta/Transposition Table.txt", "r");
    if(fp==NULL)
    printf("\n\n\nError occurd when open file\n");
   

    fp=fopen("/Users/bluesky/Documents/Surakarta/Transposition Table.txt", "w");
    if(fp==NULL)
        printf("\n\n\nError occurd when open file\n");
    int game=1,x,y,mouse_x,mouse_y;
    int *game_test=&game;
    do{ if(who==1){
        
        Place_Move(who_test,game_test,position);
            }
    else{
        AI(7);
        who=-who;
       
    }
        SDL_RenderClear(ren);
        SDL_RenderCopy(ren, back, NULL, NULL);
        Display(ren,Chess,WhiteChess,chessboard,display_position);
        SDL_RenderPresent(ren);
        game=judge(chessboard);
        
    }while(game!=1&&game!=2);

   
}

