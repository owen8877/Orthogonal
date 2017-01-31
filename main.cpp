#include "main.h"
#include "map.h"
#include "player.h"
#include "cursor.h"
#include "renderer.h"

char msg[ERRBUFSIZE];

const int MainApp::mapSize = 16;

MainApp mainApp;

MainApp::MainApp(){
    state = S_STOP;

    dt = 18/1000.0;
    g = 1.0;

    mapname = "assets/test.map";

    map = new Map(mapSize);
    player = new Player();
    cursor = new Cursor();

    cursor->active1 = cursor->active2 = 0;
    cursor->focus = Cursor::C_None;
}

MainApp::~MainApp(){
    delete map;
    delete player;
    delete cursor;
}

int MainApp::OnExecute() {
    try{
        if (OnInit() == false){
            return -1;
        }

        SDL_Event event;
        while (state != S_STOP){
            while (SDL_PollEvent(&event)){
                OnEvent(&event);
            }
            OnLoop();
            OnRender();
            OnDelay();
        }
    }
    catch (SDL_Exception & e){
        printf("%s", e.what());
    }
    catch (std::exception & e){
        printf("%s", e.what());
    }

    OnCleanup();

    return 0;
}


int main(int argc, char* argv[]) {
    return mainApp.OnExecute();
}

bool MainApp::OnInit(){
    //initializing window and render environment
    renderer = new Renderer(mapSize);

    //loading map
    try{
        map->load(mapname);
    }
    catch (std::exception & e){
        SDL_Log(e.what());
        errno = 0;
        SDL_Log("Starting with empty map");
        map->clear();
    }
    
    //done initilizing
    state = S_RUNNING;

    return true;
}

void MainApp::OnRender(){
    renderer->clear();

    renderer->bgtex->draw(NULL);
    renderer->fieldtex->draw(&renderer->lfieldrect);
    renderer->fieldtex->draw(&renderer->rfieldrect);

    map->render(player, renderer);
    cursor->render(renderer);
    player->render(renderer);

    renderer->present();
}

void MainApp::OnDelay(){
    //SDL_Delay(18);
}

void MainApp::OnCleanup(){
    if (renderer) delete renderer;
}

