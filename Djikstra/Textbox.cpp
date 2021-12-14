#include "Textbox.h"

Textbox::Textbox(int size, sf::Color color, bool sel)
{
	//Menentukan ukuran teks, warna teks, dan teks yang aktif
	textbox.setCharacterSize(size);
	textbox.setFillColor(color);
	isSelected = sel;
	if (isSelected)
		textbox.setString("_");
	else
		textbox.setString("");
}

void Textbox::setFont(sf::Font& fonts)
{
	//Menentukan font yang dipakai
	textbox.setFont(fonts);
}

void Textbox::setPosition(sf::Vector2f point)
{
	//Mentukan posisi dari teksbox
	textbox.setPosition(point);
}

void Textbox::setLimit(bool ToF)
{
	//kondisi ketika true
	hasLimit = ToF;
}

void Textbox::setLimit(bool ToF, int lim)
{
	//kondisi ketika memiliki limit
	hasLimit = ToF;
	limit = lim - 1;
}

void Textbox::setSelected(bool sel)
{
	isSelected = sel;
	// Jika tidak dipilih, hapus '_' di akhir
	if (!sel) {
		std::string t = text.str();
		std::string newT = "";
		for (int i = 0; i < t.length(); i++) {
			newT += t[i];
		}
		textbox.setString(newT);
	}
}

std::string Textbox::getText()
{
	//Mengembalikan atau menyimpan kata kata yang diinputkan
	return text.str();
}

void Textbox::drawTo(sf::RenderWindow& window)
{
	//Menggambar teksbox
	window.draw(textbox);
}

void Textbox::typedOn(sf::Event input)
{
	//Ketika teksbox posisi select TRUE
	if (isSelected) {
		int charTyped = input.text.unicode;

		// Hanya izinkan input normal yaitu sampai 128
		if (charTyped < 128) {
			if (hasLimit) {
				// Jika kondisia ada batas, tidak bisa melewatinya
				if (text.str().length() <= limit) {
					inputLogic(charTyped);
				}
				// kondisi ketika mengizinkan penghapusan karakter
				else if (text.str().length() > limit && charTyped == DELETE_KEY) {
					deleteLastChar();
				}
			}
			// Jika tidak ada batasan, jalankan saja fungsinya
			else {
				inputLogic(charTyped);
			}
		}
	}
}

void Textbox::deleteLastChar()
{
	//Menghapus karakter
	std::string t = text.str();
	std::string newT = "";
	for (int i = 0; i < t.length() - 1; i++) {
		newT += t[i];
	}
	text.str("");
	text << newT;
	textbox.setString(text.str() + "_");
}

void Textbox::inputLogic(int charTyped)
{
	// Jika tombol yang ditekan tidak tombol hapus, atau dua tombol lain tambahkan teks dengan karakter
	if (charTyped != DELETE_KEY && charTyped != ENTER_KEY && charTyped != ESCAPE_KEY) {
		text << static_cast<char>(charTyped);
	}
	// Jika ditekan tombol hapus, maka char akan dihapus
	else if (charTyped == DELETE_KEY) {
		if (text.str().length() > 0) {
			deleteLastChar();
		}
	}
	// Setel teks kotak teks
	textbox.setString(text.str() + "_");
}
