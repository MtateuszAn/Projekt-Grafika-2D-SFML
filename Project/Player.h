#pragma once
#include "UpdatableObject.h"
#include "TransformableObject.h"
#include <SFML/Graphics.hpp>
#include "AnimatedObject.h"
#include "BitmapObject.h"
#include "Point2D.h"
#include "BitmapHandler.h"
#include "SpriteObject.h"
using namespace sf;
/**
 * @brief Klasa gracza
 */
class Player: public SpriteObject
{
public:
	int frameNum=1;
	int framedelay=0;
	Point2D position;
	sf::Sprite sprite;
	Texture tmpText/*!<Tekstura>*/;
	BitmapHandler* bitmapHandler/*!<WskaŸnik do repozytorium tekstur aplikacji>*/;
	/**
	 * @brief Konstruktor gracza
	 * 
	 * \param position Pozycja gracza
	 * \param bitmapHandler WskaŸnik do repozytorium tekstur aplikacji
	 */
	Player(Point2D position, BitmapHandler* bitmapHandler);
	/**
	 * @brief Destruktor gracza
	 * 
	 */
	~Player();

	char lastDirection;/*!<Ostatni kierunek ruchu gracza>*/
	/**
	 * @brief Poruszanie siê gracza
	 *
	 */

	void up();
	void down();
	void left();
	void right();
	/**
	 * @brief Aktualizuje gracza 
	 * 
	 */
	void update();
	/**
	 * @brief Rysuje gracza 
	 * 
	 * \param window WskaŸnik do okna w którym ma siê pojawiæ figura
	 */
	void draw(RenderWindow* window);
	/**
	 * @brief Przemieszcza gracza
	 * 
	 * \param x Wspo³rzêdna na osi X
	 * \param y Wspo³rzêdna na osi X
	 */
	void translate(int x, int y);
	/**
	 * @brief Rotuje gracza
	 * 
	 * \param px Wspo³rzêdna punktu na osi X
	 * \param py Wspo³rzêdna punktu na osi Y
	 * \param angle K¹t o jaki ma sie przemieœciæ figura
	 */
	void rotate(int px, int py, int angle);
	/**
	 * @brief Obraca gracza
	 * 
	 * \param angle K¹t o jaki ma sie przemieœciæ figura
	 */
	void rotate(int angle);
	/**
	 * @brief Skaluje gracza wzglêdem podanych punktów
	 * 
	 * \param px Wspo³rzêdna punktu na osi X
	 * \param py Wspo³rzêdna punktu na osi Y
	 * \param kx Wspó³czynnik skalowania na osi X
	 * \param ky Wspó³czynnik skalowania na osi Y
	 */
	void scale(int px, int py, float kx, float ky);
	/**
	 * @brief Skaluje gracza wzglêdem punktu 0,0 
	 * 
	 * \param kx Wspó³czynnik skalowania na osi X
	 * \param ky Wspó³czynnik skalowania na osi Y
	 */
	void scale(float kx, float ky);
	/**
	 * @brief Animacje gracza
	 * 
	 * \param deltaTime Czas pomiêdzy klatkami
	 */
	void animate();
};