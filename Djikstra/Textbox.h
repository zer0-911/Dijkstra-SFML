#pragma once
#include <iostream>
#include <sstream>
#include "SFML.h"

// Deklarasi memberi nama pada nilai yang sudah ditentukan
#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27

class Textbox
{
public:
	//Deklarasi fungsi untuk pemanggilan fungsi lain
	Textbox(int size, sf::Color color, bool sel);
	//Deklarasi fungsi untuk menentukan font yang dipakai
	void setFont(sf::Font& fonts);
	//Deklarasi fungsi untuk menentukan tempat teksbox
	void setPosition(sf::Vector2f point);
	//Deklarasi fungsi untuk menentukan terdapat limit atau tidak
	void setLimit(bool ToF);
	//Deklarasi fungsi untuk menentukan limit dari teksbox
	void setLimit(bool ToF, int lim);
	//Deklarasi fungsi untuk mengaktifkan textbox
	void setSelected(bool sel);
	//Untuk menyimpan teks yang sudah diinputkan
	std::string getText();
	//Deklarasi fungsi untuk menggambar teks ketikan
	void drawTo(sf::RenderWindow& window);
	//Deklarasi fungsi untuk mengetik
	void typedOn(sf::Event input);

private: 
	sf::Text textbox;
	std::ostringstream text;
	bool isSelected = false;
	bool hasLimit = false;
	int limit = 0;
	//Deklarasi fungsi untuk menghapus
	void deleteLastChar();
	//Deklarasi fungsi untuk kondisi ketika mengetik
	void inputLogic(int charTyped);
};

