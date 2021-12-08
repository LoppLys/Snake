#include "Powerup.h"

namespace SpriteGame{

class RedApple : public Powerup{
public:
    RedApple(int x, int y, int w, int h, int popup_time) : Powerup(x, y, w, h, popup_time){}

    //Impact on snake: Increase body by 1 unit
};

}