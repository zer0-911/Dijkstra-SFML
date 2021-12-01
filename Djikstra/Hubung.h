#pragma once
#include "SFML.h"
#include <SFML/Graphics/Vertex.hpp>
#include <vector>
#include <iostream>

class Hubung
{
private:
	int jumlah;
	std::vector<sf::VertexArray> m_vertices;
	float x = 300, y = 100;
public:
	void Hubungkan();
	void drawline(sf::RenderWindow& window);
};

