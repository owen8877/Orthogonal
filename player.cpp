#include "player.h"
#include "renderer.h"
#include <SDL2/SDL.h>

Player::Player(){
    x = z = 0.5;
    y = w = 15;
    vx = vy = vz = vw = 0;
    boxy = 0;
    boxx = -12.0/16/2;
    height = 12.0/16;
    width = 12.0/16;
    speed = 8.0;
    spritenum1 = 0;spritenum2 = 4;

    //things about jumping
    hasgravity = true;
    jumpheight = 3.2;
    jumptime = 0.6;
    jumpdistance = 5;
    multg = 5;
    ground1 = ground2 = false;
    jumpflag1 = jumpflag2 = false;

    g = 8 * jumpheight / jumptime / jumptime;
    jumpspeed = 4 * jumpheight / jumptime;
    speed = jumpdistance / jumptime;

}

void Player::render(Renderer * ren){
    ren->playertex->draw(ren->lfieldrect, x + boxx, y + boxy, width, height, spritenum1);
    ren->playertex->draw(ren->rfieldrect, z + boxx, w + boxy, width, height, spritenum2);
}
