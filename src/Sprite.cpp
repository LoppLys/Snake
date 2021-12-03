#include "Sprite.h"
#include <iostream>

using namespace std;

namespace SpriteGame{

Sprite::Sprite(int x, int y, int w, int h): Sprite  (x, y, w, h){}

void Sprite::move(int x, int y){
 cout << "Spritens funktion move" << endl;
}
}