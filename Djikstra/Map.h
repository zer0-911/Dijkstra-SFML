#pragma once

#include "SFML.h"

class Map
{
private:
	sf::Texture texture[100];
	sf::Sprite DCity[100];
public:
	void img();
	void drawMap(sf::RenderWindow& window);
};

