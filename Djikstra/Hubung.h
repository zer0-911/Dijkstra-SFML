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
	//Membuat vectior dari vertex array untuk digunakan pada pembuatan garis
	std::vector<sf::VertexArray> m_garis;
	std::vector<sf::VertexArray> m_garistanda;
	sf::Text teksjarak[100];
	sf::Font font;
	//Pemanggilan class jarak terdekat dan penamaannya
	JarakTerdekat djikstra;
public:
	//Deklarasi fungsi untuk menghubungkan antar kota
	void Hubungkan(float x1, float y1, float x2, float y2, std::string kotaasal, std::string kotatujuan, int Node);
	//Deklarasi fungsi untuk memasukkann kota ke struct yang ada didalam class jarakTerdekat
	void MFDjikstra(std::string sNamaKota, float x, float y);
	//Deklarasi fungsi untuk mencari jarak terdekat
	void DjikstraOn(std::string Asal, std::string Tujuan);
	//Deklarasi fungsi untuk menggambar
	void drawline(sf::RenderWindow& window);
};

