#include "Interact.h"
extern Chessboard chessboard;
extern int who;
int Place_Move(int *game,SDL_Rect position[6][6]){
SDL_Event e;
int x,y,mouse_x,mouse_y;
 while(SDL_PollEvent(&e)){
            switch (e.type){
                case SDL_QUIT:
                    *game=0;
                    break;
                case SDL_KEYDOWN:
                 
                   /*  switch(e.key.keysym.sym){
                        case SDLK_b:
                         
                            retract(step_h, chessboard);
                            break;
                        case SDLK_RETURN:
                            who=who_turn(step_h);
                           
                            break;
                    }
                    */
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    mouse_x = e.button.x;
                    mouse_y = e.button.y;
                    x=Locate_x(mouse_y,position);
                    y=Locate_y(mouse_x,position);
                    if(Play_H(x, y))
                        return 1;
            }
            
            }
return 0;
}
int Play_H(int x,int y){//用于人类回合下子
    static int a=-1,b=-1;
    int origin=who,target;

    if(chessboard.chessboard[x][y]==-who){
        a=x;b=y;
    }
    else {
        if(a!=-1&&b!=-1){
            //if(judge_legal(a,b,x,y,chessboard,inside_orbit_1,inside_orbit_2,outside_orbit_1,outside_orbit_2))
            {   target=chessboard.chessboard[x][y];
                chessboard.chessboard[a][b]=0;
                if(chessboard.chessboard[x][y]==who)
                {
                    if(who==1)
                    chessboard.black-=1;
                   else
                   chessboard.white-=1;
                   
                }
                chessboard.chessboard[x][y]=-who;
                
               // Add_step(h, a, b, origin, x, y, target);
                a=-1;b=-1;
                return 1;
            }
            
        }
    }
    return 0;
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