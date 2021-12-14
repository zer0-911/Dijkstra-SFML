#pragma once
#include "SFML.h"
#include <iostream>
#include <string>
class City 
{
private:
	//Memanggil class texture untuk membuat Gambar hidup di kartu grafis yang dapat digunakan untuk menggambar
	sf::Texture texture[100];
	//Memanggil class sprite untuk pembuatan gambar
	sf::Sprite DCity[100];
	sf::Text tekskota[100];
	sf::Font fontcity;
	size_t NodeC = 0;
	//Posisi gambar
	float ximage, yimage;
public:
	//Deklarasi Fungsi untuk memanggil gambar
	void img(std::string teks, std::string ximg, std::string yimg);
	//Deklarasi Fungsi untuk menggambar di window
	void drawToImg(sf::RenderWindow& window);
};

