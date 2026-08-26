#ifndef SDL2_SANDBOX_GAME_H
#define SDL2_SANDBOX_GAME_H
#include <SDL2/SDL.h>
#include <iostream>
using namespace std;

class Game {
public:
    Game();
    ~Game();

    void init(const char* title , int xpos , int ypos , int width , int height ,bool fullscreen);
    void collision();
    void velocity();
    void handleEvents();
    void update();
    void render();
    void clean();

    bool running(){return isRunning;}

private:
    bool isRunning = false;
    bool LmovingUp;
    bool LmovingDown;
    bool RmovingUp;
    bool RmovingDown;
    float ballspeedX = 300.0f;
    float ballX = 390.0f;
    float ballspeedY = 300.0f;
    float ballY = 0.0f;
    Uint32 lastTime = 0;
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Rect Lpaddle={0,250,20,100};
    SDL_Rect Rpaddle={780,250,20,100};;
    SDL_Rect Ball = {390,0,10,10};
    SDL_Event event;

};


#endif //SDL2_SANDBOX_GAME_H
