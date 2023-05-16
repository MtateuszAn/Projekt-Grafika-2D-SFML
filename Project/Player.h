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
	BitmapHandler* bitmapHandler/*!<Wska�nik do repozytorium tekstur aplikacji>*/;
	/**
	 * @brief Konstruktor gracza
	 * 
	 * \param position Pozycja gracza
	 * \param bitmapHandler Wska�nik do repozytorium tekstur aplikacji
	 */
	Player(Point2D position, BitmapHandler* bitmapHandler);
	/**
	 * @brief Destruktor gracza
	 * 
	 */
	~Player();

	char lastDirection;/*!<Ostatni kierunek ruchu gracza>*/
	/**
	 * @brief Poruszanie si� gracza
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
	 * \param window Wska�nik do okna w kt�rym ma si� pojawi� figura
	 */
	void draw(RenderWindow* window);
	/**
	 * @brief Przemieszcza gracza
	 * 
	 * \param x Wspo�rz�dna na osi X
	 * \param y Wspo�rz�dna na osi X
	 */
	void translate(int x, int y);
	/**
	 * @brief Rotuje gracza
	 * 
	 * \param px Wspo�rz�dna punktu na osi X
	 * \param py Wspo�rz�dna punktu na osi Y
	 * \param angle K�t o jaki ma sie przemie�ci� figura
	 */
	void rotate(int px, int py, int angle);
	/**
	 * @brief Obraca gracza
	 * 
	 * \param angle K�t o jaki ma sie przemie�ci� figura
	 */
	void rotate(int angle);
	/**
	 * @brief Skaluje gracza wzgl�dem podanych punkt�w
	 * 
	 * \param px Wspo�rz�dna punktu na osi X
	 * \param py Wspo�rz�dna punktu na osi Y
	 * \param kx Wsp�czynnik skalowania na osi X
	 * \param ky Wsp�czynnik skalowania na osi Y
	 */
	void scale(int px, int py, float kx, float ky);
	/**
	 * @brief Skaluje gracza wzgl�dem punktu 0,0 
	 * 
	 * \param kx Wsp�czynnik skalowania na osi X
	 * \param ky Wsp�czynnik skalowania na osi Y
	 */
	void scale(float kx, float ky);
	/**
	 * @brief Animacje gracza
	 * 
	 * \param deltaTime Czas pomi�dzy klatkami
	 */
	void animate();
};