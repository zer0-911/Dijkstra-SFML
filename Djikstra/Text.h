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
	//Struct untuk menyimpan kota
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
	//Deklarasi fungsi input 
	void input(std::string nama, std::string x, std::string y);
	//Deklarasi fungsi untuk menggambar teks 
	void drawToTx(sf::RenderWindow& window);
	//Deklarasi fungsi untuk set font yang dipakai
	void setFontTx(sf::Font& fonts);
	//Deklarasi fungsi untuk membuat tabel
	void tabel();
	//Deklarasi fungsi untuk menghubungkan satu kota ke kota lain
	void caritujuan(std::string namaasal, std::string namatujuan);
	//Deklarasi fungsi untuk mencari kota
	int cari(std::string carikota);
	//Deklarasi untuk mencari jarak terdekat 
	void jarakTerdekat(std::string AsalK, std::string TujuanK);
private:
	//Memanggil class Hubung dan menamainya
	Hubung hubung;
	float xsize = 25, ysize =210;
	float yline = 228;
	float xline = 40;
	//Memanggil class Text
	sf::Text text[100],text2[100], text3[100];
	sf::Text tabel0,tabel1, tabel2, tabel3;
	//Memanggil class Rextangle unuk membuat garis persegi panjang
	sf::RectangleShape line[100], lineatas, linebawah, linekiri[100], linekanan[100];
};

