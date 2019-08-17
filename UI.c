#include "UI.h"
extern int chessboard[6][6];
extern SDL_Renderer *ren;
extern SDL_Texture *Chess;
extern SDL_Texture *WhiteChess;
extern SDL_Rect position[6][6];
extern SDL_Rect display_position[6][6];
extern SDL_Texture *Blackmax;
extern SDL_Texture *Blackmini;
extern SDL_Texture *Whitemax;
extern SDL_Texture *Whitemini;
extern SDL_Texture *Computermax;
extern SDL_Texture *Computermini;
extern SDL_Texture *Humanmax;
extern SDL_Texture *Humanmini;
extern SDL_Texture *dback;
extern SDL_Texture *tishi;
extern SDL_Texture *tishi_1;
SDL_Texture *renderText(char *s, char *e, SDL_Color color,int fontSize)
{
    TTF_Font *font = TTF_OpenFont(e, fontSize);
    if (font == NULL)
    {
        printf("TTF_OpenFont");
        return NULL;
    }
    SDL_Surface *surf = TTF_RenderText_Blended(font, s, color);
    if (surf == NULL)
    {
        TTF_CloseFont(font);
        printf("TTF_RenderText");
        return NULL;
    }
    SDL_Texture *texture = SDL_CreateTextureFromSurface(ren, surf);
    if (texture == NULL)
    {
        printf("TTF_CreateTexture");
    }
    SDL_FreeSurface(surf);
    TTF_CloseFont(font);
    return texture;
}
choice begin(void){
    int flag_1=1,flag_2=1;
    SDL_Rect whitemax,whitemini,blackmax,blackmini,ti,humanmini,humanmax,computermax,computermini,ti_1;
    whitemax.x=380;whitemax.y=220;
    SDL_QueryTexture(Whitemax, NULL, 0, &whitemax.w, &whitemax.h);
    whitemini.x=435;whitemini.y=220;
    SDL_QueryTexture(Whitemini, NULL, 0, &whitemini.w, &whitemini.h);
    blackmax.x=150;blackmax.y=220;
    SDL_QueryTexture(Blackmax, NULL, 0, &blackmax.w, &blackmax.h);
    blackmini.x=150;blackmini.y=220;
    SDL_QueryTexture(Blackmini, NULL, 0, &blackmini.w, &blackmini.h);
    ti.x=165;ti.y=160;
    SDL_QueryTexture(tishi, NULL, 0, &ti.w, &ti.h);

    humanmax.x=405; humanmax.y=350;
    SDL_QueryTexture(Humanmax, NULL, 0, & humanmax.w, & humanmax.h);
    humanmini.x=425;humanmini.y=350;
    SDL_QueryTexture(Humanmini, NULL, 0, &humanmini.w, &humanmini.h);
    computermax.x=160;computermax.y=350;
    SDL_QueryTexture(Computermax, NULL, 0, &computermax.w, &computermax.h);
    computermini.x=170;computermini.y=350;
    SDL_QueryTexture(Computermini, NULL, 0, &computermini.w, &computermini.h);
    ti_1.x=180;ti_1.y=300;
    SDL_QueryTexture(tishi_1, NULL, 0, &ti_1.w, &ti_1.h);
    
    choice Choice;
    Choice.choice_1=1;
    Choice.choice_2=1;
    SDL_RenderCopy(ren, dback, NULL, NULL);
    SDL_Rect blanket;
    blanket.x=140;blanket.y=150;blanket.w=525;blanket.h=300;
    SDL_SetRenderDrawColor(ren, 47, 54, 56, 255);
    SDL_RenderFillRects(ren, &blanket, 1);

    SDL_Event e;
    while(SDL_PollEvent(&e)!=3){
        SDL_RenderClear(ren);
        SDL_RenderCopy(ren, dback, NULL, NULL);
        SDL_RenderDrawRect(ren, &blanket);
        SDL_RenderFillRects(ren, &blanket, 1);
        SDL_RenderCopy(ren, tishi, NULL, &ti);
         SDL_RenderCopy(ren, tishi_1, NULL, &ti_1);
     if(flag_1)
{
  if(e.type==SDL_KEYDOWN){
   if(e.key.keysym.sym==SDLK_RIGHT)
    Choice.choice_1=1;
    else if(e.key.keysym.sym==SDLK_LEFT)
     Choice.choice_1=-1;
    else if(e.key.keysym.sym==SDLK_RETURN)
    {flag_1=0;
    SDL_Delay(1000);
    }
  }
  }
else if(flag_2){
  if(e.type==SDL_KEYDOWN){
   if(e.key.keysym.sym==SDLK_RIGHT)
    Choice.choice_2=1;
    else if(e.key.keysym.sym==SDLK_LEFT)
     Choice.choice_2=-1;
    else if(e.key.keysym.sym==SDLK_RETURN)
    flag_2=0;
  }
}
else{
  return Choice;
}
if(Choice.choice_1==1)
{
    SDL_RenderCopy(ren, Blackmini, NULL, &blackmini);
    SDL_RenderCopy(ren, Whitemax, NULL, &whitemax);
}
else if(Choice.choice_1==-1)
{
    SDL_RenderCopy(ren, Blackmax, NULL, &blackmax);
    SDL_RenderCopy(ren, Whitemini, NULL, &whitemini);
}
if(Choice.choice_2==1)
{
 SDL_RenderCopy(ren, Humanmax, NULL, &humanmax);
 SDL_RenderCopy(ren, Computermini, NULL, &computermini);
}
else if(Choice.choice_2==-1)
{
SDL_RenderCopy(ren, Humanmini, NULL, &humanmini);
SDL_RenderCopy(ren, Computermax, NULL, &computermax);
}

SDL_RenderPresent(ren);
    }
    return Choice;
}
void Init_Position(){
    for(int a=0;a<6;a++){
        for(int b=0;b<6;b++){
            position[a][b].x=250+b*60;
            position[a][b].y=150+a*60;
        }
    }
}
void Init_Display_Position(){
    for(int a=0;a<6;a++){
        for(int b=0;b<6;b++){
            display_position[a][b].x=250+b*60-20;
            display_position[a][b].y=150+a*60-20;
            display_position[a][b].w=40;
            display_position[a][b].h=40;
        }
    }
}
void Display(void){//用于打印所有的棋子

    SDL_Rect chessw,chessb;
    chessw.x=0;chessw.y=0;
    chessw.w=225;chessw.h=225;
    chessb.x=42;chessb.y=553;
    chessb.w=428;chessb.h=428;
    for(int a=0;a<6;a++){
        for(int b=0;b<6;b++){
            if(chessboard[a][b]==1){
            if(Chess==NULL)
            printf("3\n");
          SDL_RenderCopy(ren, Chess, &chessb, &display_position[a][b]);
            }
            else if(chessboard[a][b]==-1){
                if(WhiteChess==NULL)
            printf("4\n");
             SDL_RenderCopy(ren, WhiteChess, &chessw, &display_position[a][b]);
            }
        }
    }
   
}

