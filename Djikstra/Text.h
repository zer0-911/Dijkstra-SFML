#pragma once

#include <iostream>
#include "SFML.h"
#include <Window.hpp>
#include <string>
#include "Hubung.h"
#define Maksimum 100
class Text 
{
public:
	struct KotaUtama
	{
		std::string nama;
		std::string xs;
		std::string ys;
		float x;
		float y;
		std::string Next[100];
		int next;
	};
	struct data
	{
		//banyak variabel struct kota utama
		struct KotaUtama kota[Maksimum];
	};
	struct data dKotaUtama;
	size_t cek = 0;
	size_t Node = 0;
	std::string Next[100];
	void input(std::string nama, std::string x, std::string y);
	void drawToTx(sf::RenderWindow& window);
	void setFontTx(sf::Font& fonts);
	void tabel();
	void caritujuan(std::string namaasal, std::string namatujuan);
	int cari(std::string carikota);
	void jarakTerdekat(std::string AsalK, std::string TujuanK);
private:
	Hubung hubung;
	float xsize = 25, ysize =210;
	float yline = 228;
	float xline = 40;
	sf::Text text[100],text2[100], text3[100];
	sf::Text tabel0,tabel1, tabel2, tabel3;
	sf::RectangleShape line[100], lineatas, linebawah, linekiri[100], linekanan[100];
};

