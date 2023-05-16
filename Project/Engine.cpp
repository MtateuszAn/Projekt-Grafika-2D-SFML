#include "Engine.h"


// funkcje prywatne
void Engine::initVariables()
{
	this->window = nullptr;
}

void Engine::initWindow()
{
	this->videoMode.height = windowHeight;
	this->videoMode.width = windowWidth;
	this->window = new sf::RenderWindow(this->videoMode, "Game", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(frameRateLimit);
}



//Konstruktor /Destruktor
Engine::Engine()
{
	this->initVariables();
	this->initWindow();
	this->loadTextures();
}

Engine::~Engine()
{
	delete this->window;
}

const bool Engine::running() const
{
	return this->window->isOpen();
}

//funkcje publiczne

void Engine::pollEvents()
{
	while (this->window->pollEvent(this->event))
	{
		switch (this->event.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->event.key.code == sf::Keyboard::Escape)
				this->window->close();
			if (this->event.key.code == sf::Keyboard::W) { player1.up(); }
			if (this->event.key.code == sf::Keyboard::S) { player1.down(); }
			if (this->event.key.code == sf::Keyboard::A) { player1.left(); }
			if (this->event.key.code == sf::Keyboard::D) { player1.right(); }
				

			break;
		}
	}
}

void Engine::loadTextures()
{
	bitmapHandler.loadBitmap("playerD1", "player/d1.png");
	bitmapHandler.loadBitmap("playerD2", "player/d2.png");
	bitmapHandler.loadBitmap("playerD3", "player/d3.png");
	bitmapHandler.loadBitmap("playerD4", "player/d4.png");
	bitmapHandler.loadBitmap("playerD5", "player/d5.png");

	bitmapHandler.loadBitmap("playerL1", "player/l1.png");
	bitmapHandler.loadBitmap("playerL2", "player/l2.png");
	bitmapHandler.loadBitmap("playerL3", "player/l3.png");
	bitmapHandler.loadBitmap("playerL4", "player/l4.png");
	bitmapHandler.loadBitmap("playerL5", "player/l5.png");

	bitmapHandler.loadBitmap("playerP1", "player/p1.png");
	bitmapHandler.loadBitmap("playerP2", "player/p2.png");
	bitmapHandler.loadBitmap("playerP3", "player/p3.png");
	bitmapHandler.loadBitmap("playerP4", "player/p4.png");
	bitmapHandler.loadBitmap("playerP5", "player/p5.png");

	bitmapHandler.loadBitmap("playerG1", "player/g1.png");
	bitmapHandler.loadBitmap("playerG2", "player/g2.png");
	bitmapHandler.loadBitmap("playerG3", "player/g3.png");
	bitmapHandler.loadBitmap("playerG4", "player/g4.png");
	bitmapHandler.loadBitmap("playerG5", "player/g5.png");

}

void Engine::update()
{
	this->pollEvents();

	//Obliczanie FPS
	float currentTime = this->clock.restart().asSeconds();
	float fps = 1.0f / (currentTime);
	//std::cout << "fps: " << fps << std::endl;
	

	//pozycja myszy wzgledem okienka
	if (sf::Mouse::getPosition(*this->window).x>=0 && sf::Mouse::getPosition(*this->window).y >=0 && sf::Mouse::getPosition(*this->window).x <= this->windowWidth && sf::Mouse::getPosition(*this->window).y <= this->windowHeight)
	{
		xMousePosition = sf::Mouse::getPosition(*this->window).x;
		yMousePosition = sf::Mouse::getPosition(*this->window).y;
		//std::cout << "Pozycja myszy: " << xMousePosition << " " << yMousePosition << "\n";
	}



	primitive.makeLineAlgPrzyrost(100, 100, 200, 300);

	primitive.makeCircle(300,300,50);
	//primitive.MakeElipse(300, 300, 50, 25);

	pointArray[0].SetCords(200, 200);
	pointArray[1].SetCords(320, 200);
	pointArray[2].SetCords(210, 250);
	pointArray[3].SetCords(320, 320);
	pointArray[4].SetCords(200, 320);

	primitive.makeLineFromPoints(pointArray,5);

	pointArray[0].SetCords(400, 200);
	pointArray[1].SetCords(520, 200);
	pointArray[2].SetCords(410, 250);
	pointArray[3].SetCords(520, 320);
	pointArray[4].SetCords(400, 320);

	primitive.makeShape(pointArray,5);

	lineS1.SetBegPoint(100,100);
	lineS1.SetEndPoint(300, 300);

	Point2D cen(300,300);

	primitive.floodfill(cen,sf::Color::Red);
	cen.SetCords(270,300);
	primitive.boundryfill(cen,sf::Color::Blue,sf::Color::White);
	player1.update();
	primitive.makeRectangle(Point2D(50,50),Point2D(150,150),sf::Color::Magenta);

}	

void Engine::render()
{
	this->window->clear(sf::Color::Blue);


	sf::Texture texture;
	texture.loadFromImage(primitive.image);
	sf::Sprite sprite;
	sprite.setTexture(texture, true);
	this->window->draw(sprite);
	player1.draw(this->window);
	primitive.clearImage();
	this->window->display();
}

