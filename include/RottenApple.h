#include "Powerup.h"

namespace SpriteGame{

class RottenApple : public Powerup{
public:
    RottenApple(int x, int y, int w, int h, int popup_time) : Powerup(x, y, w, h, popup_time){}

    //Impact on snake: Decrease body by 1 unit
};

}