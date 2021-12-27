#include "City.h"
#include "Text.h"

void City::img(std::string teks, std::string ximg, std::string yimg)
{
	if (!fontcity.loadFromFile("Assets/Font/BebasNeue-Regular.otf"))
	{
		std::cout << "Font tidak ditemukan\n";
	}
	//variabel x yang berisi angka random untuk menentukan gambar yang dipakai
	int x = rand() % 6;
	//Posisi dari gambar yang dipakai
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
	//Menentukan kota. Posisi, ukuran, dan gambar yang dipakai
	DCity[NodeC].setTexture(texture[NodeC]);
	DCity[NodeC].setPosition({ ximage-22+250,yimage-25+250 });
	DCity[NodeC].setScale({ 0.050, 0.050 });
	tekskota[NodeC].setFillColor(sf::Color::Black);
	tekskota[NodeC].setFont(fontcity);
	tekskota[NodeC].setCharacterSize(14);
	tekskota[NodeC].setString(teks);
	tekskota[NodeC].setPosition({ ximage + 250 , yimage - 45 + 250 });
	NodeC++;
}

void City::drawToImg(sf::RenderWindow& window)
{
	//Menggambar dengan mengulangi di setiap kota
	for (int i = 0; i < NodeC; i++)
	{
		window.draw(tekskota[i]);
		window.draw(DCity[i]);
	}
}
