#pragma once

#include "Header.h"
#include "PrimitiveRenderer.h"
#include "Point2D.h"
#include "LineSegment.h"
#include "ShapeObject.h"
#include "Player.h"
#include "BitmapHandler.h"

class Engine
{
public:

	//Zmienne
	int windowWidth = 600;
	int windowHeight = 600;
	int frameRateLimit = 60;
	int xMousePosition = 0;
	int yMousePosition = 0;




	//Window
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event event;
	sf::Clock clock;

	sf::Texture texture;
	sf::Sprite sprite;

	

	//PrimitiveRenderer
	BitmapHandler bitmapHandler;
	PrimitiveRenderer primitive;
	Point2D pointArray[100];
	LineSegment lineS1;

	//player
	Player player1 = Player(Point2D(10, 10), &bitmapHandler);
	//funkcje prywate
	void initVariables();
	void initWindow();

	//Konstruktor /Destruktor
	Engine();
	~Engine();


	//
	const bool running() const;


	//Funkcje
	void pollEvents();
	void loadTextures();
	void update();
	void render();
};




