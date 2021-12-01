#pragma once
#include "SFML.h"
#include <iostream>
#include <string>
class City 
{
private:
	sf::Texture texture[100];
	sf::Sprite DCity[100];
	size_t NodeC = 0;
	float ximage, yimage;
public:
	void img(std::string ximg, std::string yimg);
	void drawToImg(sf::RenderWindow& window);
};

