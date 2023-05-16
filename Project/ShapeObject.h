#pragma once
#include "DrawableObject.h"
#include "TransformableObject.h"
#include "Point2D.h"

/**
* @brief Klasa, po kt�rej dziedzicz� primitywy
*/
class ShapeObject : public DrawableObject, TransformableObject
{
public:
	/**
	* @brief Rysowanie obiektu
	*
	* \param window Wska�nik do okna w kt�rym ma si� pojawi� figura
	*/
	virtual void draw() = 0;
	/**
	 * @brief Przesuni�cie obiektu
	 *
	 * \param x Referencje do zmiennej zawieraj�cej warto�� pocz�tkow� punktu oraz miejsce w kt�rym zostana zapisane wyniki dzia�ania metody na osi X
	 * \param y Referencje do zmiennej zawieraj�cej warto�� pocz�tkow� punktu oraz miejsce w kt�rym zostana zapisane wyniki dzia�ania metody na osi Y
	 */
	virtual void translate(int x, int y) = 0;
	/**
	 * @brief Obr�cenie obiektu wzgl�dem punkt�w
	 *
	 * \param px Wspo�rz�dna punktu na osi X
	 * \param py Wspo�rz�dna punktu na osi Y
	 * \param angle K�t o jaki ma si� rotowa� obiekt
	 */
	virtual void rotate(int xo, int yo, int al) = 0;
	/**
	 * @brief Skalowanie obiektu wzgl�dem podanych punkt�w
	 *
	 * \param px Wspo�rz�dna punktu na osi X
	 * \param py Wspo�rz�dna punktu na osi Y
	 * \param kx Wsp�czynnik skalowania na osi X
	 * \param ky Wsp�czynnik skalowania na osi Y
	 */
	virtual void scale(int xo, int yo, int k) = 0;

};

