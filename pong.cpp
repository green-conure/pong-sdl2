#include "pong.h"

Game::Game() {

}

Game::~Game() {

}

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen) {

    int flags = 0;
    if (fullscreen){flags = SDL_WINDOW_FULLSCREEN;}

    //SDL Initialization
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        cout << "SDL Initialized" << endl;

        //window creation
        window = SDL_CreateWindow(title,xpos,ypos,width,height,0);
        if (window) {
            cout << "Window created"<< endl;
        }else {
            cout << SDL_GetError();
        }

        //renderer creation
        renderer = SDL_CreateRenderer(window,-1,0);
        if (renderer) {
            cout << "renderer created"<< endl;
        }else {
            cout << SDL_GetError();
        }

        lastTime = SDL_GetTicks();

        //running true if sdl init successful
        isRunning = true;
    }else {
        //running false if sdl init failed
        isRunning = false;
    }
}

void Game::handleEvents() {
    while (SDL_PollEvent(&event)){
        switch (event.type) {
            case SDL_KEYDOWN:
                if (event.key.repeat != 0) break;
                if (event.key.keysym.sym == SDLK_w) LmovingUp = true;
                if (event.key.keysym.sym == SDLK_s) LmovingDown = true;
                if (event.key.keysym.sym == SDLK_UP) RmovingUp = true;
                if (event.key.keysym.sym == SDLK_DOWN) RmovingDown = true;
                break;

            case SDL_KEYUP:
                if (event.key.keysym.sym == SDLK_w) LmovingUp = false;
                if (event.key.keysym.sym == SDLK_s) LmovingDown = false;
                if (event.key.keysym.sym == SDLK_UP) RmovingUp = false;
                if (event.key.keysym.sym == SDLK_DOWN) RmovingDown = false;
                break;
            case SDL_QUIT:
                isRunning = false;
                break;
            default:
                break;
        }
    }
}

void Game::collision() {
    if (Ball.x < Lpaddle.x + Lpaddle.w && Ball.x + Ball.w > Lpaddle.x &&
        Ball.y < Lpaddle.y + Lpaddle.h && Ball.y + Ball.h > Lpaddle.y) {
        ballspeedX *= -1;
        ballX = Lpaddle.x + Lpaddle.w;
        Ball.x = (int)ballX;
    }
    if (Ball.x < Rpaddle.x + Rpaddle.w && Ball.x + Ball.w > Rpaddle.x &&
        Ball.y < Rpaddle.y + Rpaddle.h && Ball.y + Ball.h > Rpaddle.y) {
        ballspeedX *= -1;
        ballX = Rpaddle.x - Ball.w;
        Ball.x = (int)ballX;
    }
    if (Ball.x+ Ball.w > 800 || Ball.x < 0) {
        ballX = 390.0f;
        ballY = 0.0f;
        Ball.x = 390;
        Ball.y = 0;
    }
    if (Ball.y+ Ball.h >= 600) {
        ballY = 589;
        Ball.y = (int)ballY;
        ballspeedY *= -1;
    }else if (Ball.y <= 0) {
        ballY = 1;
        Ball.y = (int)ballY;
        ballspeedY *= -1;
    }
}

void Game::velocity() {
    Uint32 currentTime = SDL_GetTicks();
    float deltaTime = (currentTime - lastTime) / 1000.0f;
    lastTime = currentTime;
    ballX += ballspeedX * deltaTime;
    Ball.x = (int)ballX;
    ballY += ballspeedY * deltaTime;
    Ball.y = (int)ballY;
}

void Game::update() {
    if (LmovingDown) {
        if (Lpaddle.y +Lpaddle.h > 600) {
        }else {
            Lpaddle.y +=1;
        }
    }
    if (LmovingUp) {
        if (Lpaddle.y < 0) {
        }else {
            Lpaddle.y -=1;
        }
    }
    if (RmovingDown) {
        if (Rpaddle.y +Rpaddle.h > 600) {
        }else {
            Rpaddle.y +=1;
        }
    }
    if (RmovingUp) {
        if (Rpaddle.y < 0) {
        }else {
            Rpaddle.y -=1;
        }
    }
    velocity();
    collision();
}


void Game::render() {
    SDL_SetRenderDrawColor(renderer,0,0,0,0);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer,255,255,255,255);
    SDL_RenderFillRect(renderer,&Lpaddle);
    SDL_RenderFillRect(renderer,&Rpaddle);
    SDL_RenderFillRect(renderer,&Ball);
    //stuff to render
    SDL_RenderPresent(renderer);
}

void Game::clean() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    cout << "game cleaned";
}


