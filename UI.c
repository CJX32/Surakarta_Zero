#include "UI.h"
SDL_Texture *renderText(char *s, char *e, SDL_Color color,int fontSize, SDL_Renderer *ren)
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
int begin(SDL_Renderer *ren,SDL_Texture *Blackmax,SDL_Texture *Blackmini,SDL_Texture *Whitemax,SDL_Texture *Whitemini,SDL_Texture *dback,SDL_Texture *tishi){
    SDL_Rect whitemax,whitemini,blackmax,blackmini,ti;
    whitemax.x=380;whitemax.y=400;
    SDL_QueryTexture(Whitemax, NULL, 0, &whitemax.w, &whitemax.h);
    whitemini.x=430;whitemini.y=400;
    SDL_QueryTexture(Whitemini, NULL, 0, &whitemini.w, &whitemini.h);
    blackmax.x=160;blackmax.y=400;
    SDL_QueryTexture(Blackmax, NULL, 0, &blackmax.w, &blackmax.h);
    blackmini.x=170;blackmini.y=400;
    SDL_QueryTexture(Blackmini, NULL, 0, &blackmini.w, &blackmini.h);
    SDL_QueryTexture(tishi, NULL, 0, &ti.w, &ti.h);
    ti.x=180;ti.y=300;
    int choice=-1;
    SDL_RenderCopy(ren, dback, NULL, NULL);
    SDL_Rect blanket;
    blanket.x=160;blanket.y=300;blanket.w=500;blanket.h=200;
    SDL_SetRenderDrawColor(ren, 47, 54, 56, 255);
    SDL_RenderFillRects(ren, &blanket, 1);
    SDL_Event e;
    while(SDL_PollEvent(&e)!=3){
        SDL_RenderClear(ren);
        SDL_RenderCopy(ren, dback, NULL, NULL);
        SDL_RenderDrawRect(ren, &blanket);
        SDL_RenderFillRects(ren, &blanket, 1);
        SDL_RenderCopy(ren, tishi, NULL, &ti);
        if(e.type==SDL_KEYDOWN){
            if(e.key.keysym.sym==SDLK_RIGHT)
                choice=-1;
            else if(e.key.keysym.sym==SDLK_LEFT)
                choice=1;
            else if(e.key.keysym.sym==SDLK_RETURN)
                return choice;
        }
        if(choice==-1){
            SDL_RenderCopy(ren, Blackmini, NULL, &blackmini);
            SDL_RenderCopy(ren, Whitemax, NULL, &whitemax);
        }
        else if(choice==1){
            SDL_RenderCopy(ren, Blackmax, NULL, &blackmax);
            SDL_RenderCopy(ren, Whitemini, NULL, &whitemini);
        }
        SDL_RenderPresent(ren);
    }
    return choice;
}
void Init_Position(SDL_Rect position[][6]){
    for(int a=0;a<6;a++){
        for(int b=0;b<6;b++){
            position[a][b].x=250+b*60;
            position[a][b].y=150+a*60;
        }
    }
}
void Init_Display_Position(SDL_Rect display_position[][6]){
    for(int a=0;a<6;a++){
        for(int b=0;b<6;b++){
            display_position[a][b].x=250+b*60-20;
            display_position[a][b].y=150+a*60-20;
            display_position[a][b].w=40;
            display_position[a][b].h=40;
        }
    }
}
void Display(SDL_Renderer *ren,SDL_Texture *blackchess,SDL_Texture *whitechess,int chessboard[][6],SDL_Rect position[][6]){//用于打印所有的棋子

    SDL_Rect chessw,chessb;
    chessw.x=0;chessw.y=0;
    chessw.w=225;chessw.h=225;
    chessb.x=42;chessb.y=553;
    chessb.w=428;chessb.h=428;
    for(int a=0;a<6;a++){
        for(int b=0;b<6;b++){
            if(chessboard[a][b]==1){
          SDL_RenderCopy(ren, blackchess, &chessb, &position[a][b]);
            }
            else if(chessboard[a][b]==-1)
                SDL_RenderCopy(ren, whitechess, &chessw, &position[a][b]);
        }
    }
   
}
int Locate_x(int mouse_y,SDL_Rect position[][6]){//用于根据鼠标的点击坐标确定二维数组的x
    int result=0,flag=600;
    for(int a=0;a<6;a++){
        if(abs(mouse_y-position[a][0].y)<flag){
            flag=abs(mouse_y-position[a][0].y);
            result=a;
        }
    }
    return result;
}
int Locate_y(int mouse_x,SDL_Rect position[][6]){//用于根据鼠标的点击坐标确定二维数组的y
    int result=0,flag=800;
    for(int a=0;a<6;a++){
        if(abs(mouse_x-position[0][a].x)<flag){
            flag=abs(mouse_x-position[0][a].x);
            result=a;
        }
    }
    return result;
}
int Play_H(int who,int chessboard[][6],int x,int y){//用于人类回合下子
    static int a=-1,b=-1;
    int origin=who,target;
    if(chessboard[x][y]==who){
        a=x;b=y;
    }
    else {
        if(a!=-1&&b!=-1){
            //if(judge_legal(a,b,x,y,chessboard,inside_orbit_1,inside_orbit_2,outside_orbit_1,outside_orbit_2))
            {   target=chessboard[x][y];
                chessboard[a][b]=0;
                chessboard[x][y]=who;
               // Add_step(h, a, b, origin, x, y, target);
                a=-1;b=-1;
                return 1;
            }
            
        }
    }
    return 0;
}