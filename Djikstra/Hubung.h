#pragma once
#include "SFML.h"
#include <SFML/Graphics/Vertex.hpp>
#include <vector>
#include <iostream>
#include <string>
#include <iomanip>

class Hubung
{
private:
	float A, B, hasil; //Mencari jarak
	float xtengah, ytengah; //Mencari titik tengah
	int banyak = 0;
	std::string jarak[100];
	std::vector<sf::VertexArray> m_vertices;
	sf::Text teksjarak[100];
	sf::Font font;

public:
	void Hubungkan(float x1, float y1, float x2, float y2, std::string kotaasal, std::string kotatujuan);
	
	void drawline(sf::RenderWindow& window);
};

