#pragma once
#include "SFML.h"
#include <vector>
class JarakTerdekat
{
private:
	struct kotaU
	{
		std::string kota1;
		std::string kota2;
		float jarak;
		float x1, y1, x2, y2;
	};
	std::vector <kotaU> kota;
	std::vector<sf::VertexArray> linebaru;
public:
	void init(float x1, float y1, float x2, float y2, std::string kotaasal, std::string kotatujuan, float jarak);
	void jarakterdekat(std::string kota1, std::string kota2);
	void line(float x1, float y1, float x2, float y2);
	void reset();
	void drawlineterdekat(sf::RenderWindow& window);
};

