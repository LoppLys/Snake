#include "Sprite.h"
#include "Snake.h"
#include "System.h"
#include "RedApple.h"

namespace SpriteGame {

Snake::Snake (int x, int y, int w, int h): Sprite(x,y,w,h, IMG_Load("./resources/images/left_snake.png")){ 

}

void Snake::keyUp(){
	if(direction != 1){
		direction = 0;
		setSurface(IMG_Load("./resources/images/up_snake.png"));
		setTexture(getSurface());
	}
	
	
}

void Snake::keyDown(){
	if(direction != 0){
	direction = 1;
	setSurface(IMG_Load("./resources/images/down_snake.png"));
	setTexture(getSurface());
	}
	
	
	
}
void Snake::keyLeft(){
	if(direction != 3){
	direction = 2;
	setSurface(IMG_Load("./resources/images/left_snake.png"));
	setTexture(getSurface());
	}
}

void Snake::keyRight(){
	if(direction != 2){
	direction = 3;
	setSurface(IMG_Load("./resources/images/right_snake.png"));
	setTexture(getSurface());
	}
	
}

void Snake::tick(){ 
	Sprite::draw();
	for(std::size_t i = 0; i != body.size();i++){
			body[i]->follow(getRect().x,getRect().y,i, direction);
			
		}
		
	switch (direction){
			case 0: 
			getRect().y-=speed; 
		 	break;
			case 1: 
			getRect().y+=speed;
		 	break;
			case 2: 
			getRect().x-=speed;
			break;
			case 3: 
			getRect().x+=speed; 
			break;
		}
		
}


void Snake::addBodyPart(){
	
	SnakeBody * b = new SnakeBody(getRect().x,getRect().y,12,12);
	body.push_back(b);
	
	
}

int Snake::collide(Sprite* s){
  
    if(dynamic_cast<Powerup*>(s)){
        s->impact(this);
        if(dynamic_cast<RedApple*>(s)){
        return 1;
        }
    }
    return 0;
}

void Snake::removeOneBodyPart(){
	if(!body.empty()){
		body.pop_back();
	}
}


}