#pragma once
#include "SFML/Graphics.hpp"
#include <map>
using namespace sf;
/**
 * @brief Klasa repozytorium bitmap
 */
class BitmapHandler
{
	std::map<std::string, Texture*> textureRepo/*!<Mapa z repozytorium>*/;
public:
	/**
	 * @brief Konstruktor
	 *
	 */
	BitmapHandler();
	/**
	 * @brief Destruktor
	 *
	 */
	~BitmapHandler();

	/**
	 * @brief Usuwa bitmape
	 *
	 * \param name Nazwa bitmapy
	 */
	void deleteBitmap(std::string name);
	/**
	 * @brief Za³adowanie bitmapy
	 *
	 * \param name Nazwa bitmapy
	 * \param src Scie¿ka do bitmapy
	 */
	void loadBitmap(std::string name, std::string src);
	/**
	 * @brief Zapis bitmapy na dysku
	 *
	 * \param name Nazwa bitmapy
	 * \param src Scie¿ka do zapisu bitmapy
	 */
	void saveBitmap(std::string name, std::string src);
	/**
	 * @brief Dodanie bitmapy
	 *
	 * \param name Nazwa bitmapy
	 * \param texture Bitmapa
	 */
	void addBitmap(std::string name, Texture texture);
	/**
	 * @brief Getter tekstury
	 *
	 * \param name Nazwa bitmapy
	 * \return Teksture
	 */
	Texture* getTexture(std::string name);

};

