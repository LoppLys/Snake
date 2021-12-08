#include "Powerup.h"

namespace SpriteGame{

class Bomb : public Powerup{
public:
    Bomb(int x, int y, int w, int h, int popup_time) : Powerup(x, y, w, h, popup_time){}

    //Impact on snake: Decrease body by half
};

}