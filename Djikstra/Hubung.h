#pragma once
#include "SFML.h"
#include <SFML/Graphics/Vertex.hpp>
#include <vector>
#include <iostream>
#include <string>
#include <iomanip>
#include "JarakTerdekat.h"

class Hubung
{
private:
	float A, B, hasil; //Mencari jarak
	int hasil2;
	float xtengah, ytengah; //Mencari titik tengah
	int banyak = 0;
	std::string jarak[100];
	std::vector<sf::VertexArray> m_vertices;
	sf::Text teksjarak[100];
	sf::Font font;
	JarakTerdekat djikstra;
public:
	void Hubungkan(float x1, float y1, float x2, float y2, std::string kotaasal, std::string kotatujuan, int Node);
	void MFDjikstra(std::string sNamaKota, float x, float y);
	void DjikstraOn(std::string Asal, std::string Tujuan);
	void drawline(sf::RenderWindow& window);
};

