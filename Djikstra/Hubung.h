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
public:
	void Hubungkan(float x1, float y1, float x2, float y2);
	void drawline(sf::RenderWindow& window);
};

