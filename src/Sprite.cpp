#include "Sprite.h"
#include <iostream>


namespace SpriteGame{

    Sprite::Sprite(int x, int y, int w, int h) :rect{x, y, w, h}{}

    Sprite::~Sprite(){}

}