#include <SDL2/SDL.h>
#include "Sprite.h"

namespace SpriteGame{
class Powerup : public Sprite{
public:
    Powerup(int x, int y, int w, int h, int p_time) : Sprite(x, y, w, h), popup_time(p_time){}
    virtual void add();
    virtual void remove();
    virtual void impact();

private:
    int popup_time;
};
}