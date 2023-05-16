#pragma once
#include "DrawableObject.h"
#include "TransformableObject.h"
#include "Point2D.h"

/**
* @brief Klasa, po której dziedzicz¹ primitywy
*/
class ShapeObject : public DrawableObject, TransformableObject
{
public:
	/**
	* @brief Rysowanie obiektu
	*
	* \param window WskaŸnik do okna w którym ma siê pojawiæ figura
	*/
	virtual void draw() = 0;
	/**
	 * @brief Przesuniêcie obiektu
	 *
	 * \param x Referencje do zmiennej zawieraj¹cej wartoœæ pocz¹tkow¹ punktu oraz miejsce w którym zostana zapisane wyniki dzia³ania metody na osi X
	 * \param y Referencje do zmiennej zawieraj¹cej wartoœæ pocz¹tkow¹ punktu oraz miejsce w którym zostana zapisane wyniki dzia³ania metody na osi Y
	 */
	virtual void translate(int x, int y) = 0;
	/**
	 * @brief Obrócenie obiektu wzglêdem punktów
	 *
	 * \param px Wspo³rzêdna punktu na osi X
	 * \param py Wspo³rzêdna punktu na osi Y
	 * \param angle K¹t o jaki ma siê rotowaæ obiekt
	 */
	virtual void rotate(int xo, int yo, int al) = 0;
	/**
	 * @brief Skalowanie obiektu wzglêdem podanych punktów
	 *
	 * \param px Wspo³rzêdna punktu na osi X
	 * \param py Wspo³rzêdna punktu na osi Y
	 * \param kx Wspó³czynnik skalowania na osi X
	 * \param ky Wspó³czynnik skalowania na osi Y
	 */
	virtual void scale(int xo, int yo, int k) = 0;

};

