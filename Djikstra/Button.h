#pragma once
#include <iostream>
#include "SFML.h"

class Button
{
	public:
		//Deklarasi Fungsi button
		Button(std::string btnText, sf::Vector2f buttonSize, int charSize, sf::Color bgColor, sf::Color textColor);
		//Deklarasi Fungsi untuk mengambil font yang sudah dimasukkan
		void setFont(sf::Font& fonts);
		//Deklarasi fungsi untuk memberikan warna pada button
		void setWarnaBelakang(sf::Color bgcolor);
		//Deklarasi Fungsi untuk memberi warna teks didalam button
		void setWarnaTeks(sf::Color textcolor);
		//Deklarasi Fungsi untuk menentukan posisi dari Button di window yang terbentuk
		void setPosisi(sf::Vector2f point);
		//Deklarasi Fungsi untuk menggambar button
		void drawTo(sf::RenderWindow& window);
		//Deklrasi Fungsi untuk kondisi ketika pointer mouse berada didalam button
		bool MouseDiatasButton(sf::RenderWindow& window);
	private:
		//Pemanggilan kelas untuk membuat persegi
		sf::RectangleShape button;
		//Pemanggilan kelas untuk membuat teks
		sf::Text text;
		//Panjang dan lebar button
		int btnLebar;
		int btnTinggi;
};

