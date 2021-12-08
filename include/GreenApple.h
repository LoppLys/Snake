#include "Powerup.h"

namespace SpriteGame{

class GreenApple : public Powerup{
public:
    GreenApple(int x, int y, int w, int h, int popup_time) : Powerup(x, y, w, h, popup_time){}

    //Impact on snake: Increase speed - for a short period of time
};

}