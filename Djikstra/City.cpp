#include "City.h"
#include "Text.h"

void City::img(std::string ximg, std::string yimg)
{
	std::cout << Cek;
	ximage = std::stof(ximg);
	yimage = std::stof(yimg);
	if (!texture.loadFromFile("building_1.png"))
	{
		printf("error gambar");
	}
	DCity[NodeC].setTexture(texture);
	DCity[NodeC].setPosition({ ximage,yimage });
	DCity[NodeC].setScale({ 0.1, 0.1 });
	NodeC++;
}

void City::drawToImg(sf::RenderWindow& window)
{
	for (int i = 0; i < NodeC; i++)
	{
		window.draw(DCity[i]);
	}
}
