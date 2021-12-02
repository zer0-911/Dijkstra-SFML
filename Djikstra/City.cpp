#include "City.h"
#include "Text.h"

void City::img(std::string ximg, std::string yimg)
{
	int x = rand() % 6;
	ximage = std::stof(ximg);
	yimage = std::stof(yimg);
	if (x == 1)
	{
		if (!texture[NodeC].loadFromFile("Assets/Building/building_1.png"))
		{
			printf("error gambar");
		}
	}
	else if (x == 2)
	{
		if (!texture[NodeC].loadFromFile("Assets/Building/building_2.png"))
		{
			printf("error gambar");
		}
	}
	else if (x == 3)
	{
		if (!texture[NodeC].loadFromFile("Assets/Building/building_3.png"))
		{
			printf("error gambar");
		}
	}
	else if (x == 4)
	{
		if (!texture[NodeC].loadFromFile("Assets/Building/building_4.png"))
		{
			printf("error gambar");
		}
	}
	else if (x == 4)
	{
		if (!texture[NodeC].loadFromFile("Assets/Building/building_5.png"))
		{
			printf("error gambar");
		}
	}
	else 
	{
		if (!texture[NodeC].loadFromFile("Assets/Building/building_6.png"))
		{
			printf("error gambar");
		}
	}
	
	DCity[NodeC].setTexture(texture[NodeC]);
	DCity[NodeC].setPosition({ ximage-25,yimage-25 });
	DCity[NodeC].setScale({ 0.075, 0.075 });
	NodeC++;
}

void City::drawToImg(sf::RenderWindow& window)
{
	for (int i = 0; i < NodeC; i++)
	{
		window.draw(DCity[i]);
	}
}
