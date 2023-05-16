#include "Player.h"



Player::Player(Point2D position,BitmapHandler* bitmapHandler)
{
    this->position = position;
    this->bitmapHandler = bitmapHandler;
    lastDirection = 'S';
    if (!tmpText.loadFromFile("image.png"))
    {
        perror("player texture");
    }
}

Player::~Player()
{
}


void Player::up()
{
    this->position.ycord--;
    this->position.ycord--;
    lastDirection = 'W';
}

void Player::down()
{
    this->position.ycord++;
    this->position.ycord++;
    lastDirection = 'S';
}

void Player::left()
{
    this->position.xcord--;
    this->position.xcord--;
    lastDirection = 'A';
}

void Player::right()
{
    this->position.xcord++;
    this->position.xcord++;
    lastDirection = 'D';
}

void Player::update()
{

	if (framedelay < 10)
	{
		framedelay++;

	}
	else {
		if (frameNum > 5)
			frameNum = 1;
		switch (lastDirection)
		{
		case 'A':
			sprite.setTexture(*bitmapHandler->getTexture("playerL" + std::to_string(frameNum)));
			frameNum++;
			framedelay = 0;
			break;
		case 'S':
			sprite.setTexture(*bitmapHandler->getTexture("playerD" + std::to_string(frameNum)));
			frameNum++;
			framedelay = 0;
			break;
		case 'D':
			sprite.setTexture(*bitmapHandler->getTexture("playerP" + std::to_string(frameNum)));
			frameNum++;
			framedelay = 0;
			break;
		case 'W':
			sprite.setTexture(*bitmapHandler->getTexture("playerG" + std::to_string(frameNum)));
			frameNum++;
			framedelay = 0;
			break;

		default:
			break;
		}
	}
}

void Player::draw(RenderWindow* window)
{
    sprite.setPosition(sf::Vector2f(this->position.ReadXCords(),this->position.ReadYCords()));
    //std::cout << "Pozycja myszy: " << this->position.ReadXCords() << " " << this->position.ReadYCords() << "\n";
    window->draw(sprite);
}

void Player::translate(int x, int y)
{
    position.SetCords(x, y);
}

void Player::rotate(int px, int py, int angle)
{
    
}

void Player::rotate(int angle)
{
   
}

void Player::scale(int px, int py, float kx, float ky)
{
    
}

void Player::scale(float kx, float ky)
{
    
}

void Player::animate()
{
    
}


