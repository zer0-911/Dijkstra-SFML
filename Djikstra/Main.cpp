#include <iostream>
#include <string>
#include "SFML.h"
#include "Textbox.h"
#include "Button.h"
#include "Text.h"
#include "City.h"
#include "JarakTerdekat.h"

int main()
{
	sf::Image icon;
	if (!icon.loadFromFile("Assets\\Icon\\decor_4.png"))
	{
		std::cout << "Gambar tidak ditemukan\n";
	}
	//sf::RenderWindow digunakan untuk kelas modul grafis. lebih banyak fitur yang terkait dengan gambar 2D dengan modul grafis ini
	sf::RenderWindow window;
	// Digunakan untuk menentukan ukuran dan tempat muncul window
	sf::Vector2i centerWindow((sf::VideoMode::getDesktopMode().width / 2) - 845, (sf::VideoMode::getDesktopMode().height / 2) - 480);
	//membuat window dan posisi window
	window.create(sf::VideoMode(1600, 900), "Djikstra-App", sf::Style::Titlebar | sf::Style::Close);
	window.setPosition(centerWindow);
	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
	window.setKeyRepeatEnabled(true);
	//mendeklarasikan font yang digunakan
	sf::Font font;
	if (!font.loadFromFile("Assets/Font/BebasNeue-Regular.otf"))
	{
		std::cout << "Font tidak ditemukan\n";
	}
	sf::Texture BackgroundTexture;
	sf::Sprite background;
	sf::Vector2u TextureSize;  //Deklarasi penyimpanan ukuran texture
	sf::Vector2u WindowSize;   //Deklarasi penyimpanan ukuran window

	if (!BackgroundTexture.loadFromFile("Assets\\Background\\bg.png"))
	{
		std::cout << "Gambar tidak ditemukan\n";
	}
	else
	{
		TextureSize = BackgroundTexture.getSize(); //Ukuran dari texture
		WindowSize = window.getSize();             //Ukuran dari window

		float ScaleX = (float)WindowSize.x / TextureSize.x;
		float ScaleY = (float)WindowSize.y / TextureSize.y;     //Kalkulasi ukuran

		background.setTexture(BackgroundTexture);
		background.setScale(ScaleX, ScaleY);      //Menetapkan ukuran. 
	}


		
	//Memanggil class dan menamai class Textbox yang digunakan untuk input dari keyboard
	Textbox text1(20, sf::Color::Black, false), text2(20, sf::Color::Black, false), text3(20, sf::Color::Black, false), text4(20, sf::Color::Black, false), text5(20, sf::Color::Black, false);
	Textbox text6(20, sf::Color::Black, false), text7(20, sf::Color::Black, false);
	//Memanggil beberapa fungsi yang terdapat di class Textbox
	text1.setPosition({ 15, 25 });
	text1.setLimit(true, 6);
	text1.setFont(font);

	text2.setPosition({ 15, 75 });
	text2.setLimit(true, 4);
	text2.setFont(font);

	text3.setPosition({ 15, 125 });
	text3.setLimit(true, 4);
	text3.setFont(font);

	text4.setPosition({ 305, 25 });
	text4.setLimit(true, 6);
	text4.setFont(font);

	text5.setPosition({ 305, 75 });
	text5.setLimit(true, 6);
	text5.setFont(font);

	text6.setPosition({ 605, 25 });
	text6.setLimit(true, 6);
	text6.setFont(font);

	text7.setPosition({ 605, 75 });
	text7.setLimit(true, 6);
	text7.setFont(font);
	//Memanggil class dan menamai class Button yang digunakan untuk tempat klik dari mouse
	//Memnaggil beberapa fungsi yang ada di class button
	Button btn1("Cetak", { 60, 30 }, 14, sf::Color::White, sf::Color::Black);
	btn1.setFont(font);
	btn1.setPosition({ 125, 125 });
	size_t x = 0;

	Button btn2("Hubung", { 60, 30 }, 14, sf::Color::White, sf::Color::Black);
	btn2.setFont(font);
	btn2.setPosition({ 400, 125 });

	Button btn3("\tJarak \n Terdekat", { 80, 40 }, 14, sf::Color::White, sf::Color::Black);
	btn3.setFont(font);
	btn3.setPosition({ 700, 115 });
	//Memanggil kelas Text dan menamainya, kelas ini berfungsi untuk menyimpan dan melakukan berbagai proses
	//Mulai dari menyimpan, menghubungkan, menghitung jarak, dll.
	Text tx1;
	tx1.setFontTx(font);
	//Membuat teks dari sf::Text
	sf::Text help1, help2, help3, help4, help5, help6, help7, help8, help9;
	help1.setString("Nama Kota");
	help1.setFillColor(sf::Color::Black);
	help1.setCharacterSize(14);
	help1.setPosition({ 10, 8 });
	help1.setFont(font);
	help2.setString("Koordinat X");
	help2.setFillColor(sf::Color::Black);
	help2.setCharacterSize(14);
	help2.setPosition({ 10, 58 });
	help2.setFont(font);
	help3.setString("Koordinat Y");
	help3.setFillColor(sf::Color::Black);
	help3.setCharacterSize(14);
	help3.setPosition({ 10, 108 });
	help3.setFont(font);
	help4.setString("Kota Asal");
	help4.setFillColor(sf::Color::Black);
	help4.setCharacterSize(14);
	help4.setPosition({ 300, 8 });
	help4.setFont(font);
	help5.setString("Kota Tujuan");
	help5.setFillColor(sf::Color::Black);
	help5.setCharacterSize(14);
	help5.setPosition({ 300, 58 });
	help5.setFont(font);
	help6.setString("Kota Asal");
	help6.setFillColor(sf::Color::Black);
	help6.setCharacterSize(14);
	help6.setPosition({ 600, 8 });
	help6.setFont(font);
	help7.setString("Kota Tujuan");
	help7.setFillColor(sf::Color::Black);
	help7.setCharacterSize(14);
	help7.setPosition({ 600, 58 });
	help7.setFont(font);
	help8.setString("Kota Yang Dilewati");
	help8.setFillColor(sf::Color::Black);
	help8.setCharacterSize(14);
	help8.setPosition({ 800, 8 });
	help8.setFont(font);
	help9.setString("Total Jarak Yang Ditempuh");
	help9.setFillColor(sf::Color::Black);
	help9.setCharacterSize(14);
	help9.setPosition({ 800, 58 });
	help9.setFont(font);
	//Memanggil kelas City untuk menggambar sprite yang berbentuk kota
	City city;
	//Looping
	while (window.isOpen()) {

		sf::Event Event;
		//Kondisi ketika keyboard ditekan, jika tertulis true berarti akan mengaktifkan textbox tersebut
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
			text1.setSelected(true);
			text2.setSelected(false);
			text3.setSelected(false);
			text4.setSelected(false);
			text5.setSelected(false);
			text6.setSelected(false);
			text7.setSelected(false);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			text1.setSelected(false);
			text2.setSelected(true);
			text3.setSelected(false);
			text4.setSelected(false);
			text5.setSelected(false);
			text6.setSelected(false);
			text7.setSelected(false);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
		{
			text1.setSelected(false);
			text2.setSelected(false);
			text3.setSelected(true);
			text4.setSelected(false);
			text5.setSelected(false);
			text6.setSelected(false);
			text7.setSelected(false);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F1))
		{
			text1.setSelected(false);
			text2.setSelected(false);
			text3.setSelected(false);
			text4.setSelected(true);
			text5.setSelected(false);
			text6.setSelected(false);
			text7.setSelected(false);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F2))
		{
			text1.setSelected(false);
			text2.setSelected(false);
			text3.setSelected(false);
			text4.setSelected(false);
			text5.setSelected(true);
			text6.setSelected(false);
			text7.setSelected(false);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F3))
		{
			text1.setSelected(false);
			text2.setSelected(false);
			text3.setSelected(false);
			text4.setSelected(false);
			text5.setSelected(false);
			text6.setSelected(true);
			text7.setSelected(false);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F4))
		{
			text1.setSelected(false);
			text2.setSelected(false);
			text3.setSelected(false);
			text4.setSelected(false);
			text5.setSelected(false);
			text6.setSelected(false);
			text7.setSelected(true);
		}

		//Event Loop
		while (window.pollEvent(Event)) {
			switch (Event.type) {

			case sf::Event::Closed:
				window.close();
				//ketika diketikan
			case sf::Event::TextEntered:
				text1.typedOn(Event);
				text2.typedOn(Event);
				text3.typedOn(Event);
				text4.typedOn(Event);
				text5.typedOn(Event);
				text6.typedOn(Event);
				text7.typedOn(Event);
				//Event gerakan dari pointer mouse
			case sf::Event::MouseMoved:
				//Fungsi kondisi ketika pointer mouse berada di titik yang ditentukan maka akan berubah warna
				if (btn1.isMouseOver(window)) {
					btn1.setBackColor(sf::Color::Red);
				}
				else {
					btn1.setBackColor(sf::Color::White);
				}
				if (btn2.isMouseOver(window)) {
					btn2.setBackColor(sf::Color::Red);
				}
				else {
					btn2.setBackColor(sf::Color::White);
				}
				if (btn3.isMouseOver(window)) {
					btn3.setBackColor(sf::Color::Red);
				}
				else {
					btn3.setBackColor(sf::Color::White);
				}
				break;
				//Fungsi ketika mouse diklik kiri dan berada di tempat yang sudah ditentukan
			case sf::Event::MouseButtonPressed:
				if (btn1.isMouseOver(window)) {
					std::string z = text1.getText();
					std::string x = text2.getText();
					std::string y = text3.getText();
					float batasx = std::stof(x);
					float batasy = std::stof(y);
					if((batasx > 300) && (batasy > 300))
					{
						tx1.input(z, x, y);
						city.img(z,x, y);

					}
					else
					{
						std::cout << "Koordinat X dan/atau Koordinat Y terlalu kecil, buat lebih dari x = 300 dan y = 300 \n";
					}
					
				}
				else if (btn2.isMouseOver(window)) {
					std::string namaasal = text4.getText();
					std::string namatujuan = text5.getText();
					tx1.caritujuan(namaasal, namatujuan);

				}
				else if (btn3.isMouseOver(window)) {
					std::string namaasaldj = text6.getText();
					std::string namatujuandj = text7.getText();
					tx1.jarakTerdekat(namaasaldj, namatujuandj);
				}
			}
		}
		//Membersihkan window
		window.clear();
		//Menggambar masing masing kelas yang sudah dideklarasi
		window.draw(background);
		window.draw(help1);
		window.draw(help2);
		window.draw(help3);
		window.draw(help4);
		window.draw(help5);
		window.draw(help6);
		window.draw(help7);
		window.draw(help8);
		window.draw(help9);
		text1.drawTo(window);
		text2.drawTo(window);
		text3.drawTo(window);
		text4.drawTo(window);
		text5.drawTo(window);
		text6.drawTo(window);
		text7.drawTo(window);
		tx1.drawToTx(window);
		city.drawToImg(window);
		btn1.drawTo(window);
		btn2.drawTo(window);
		btn3.drawTo(window);
		window.display();
	}
	return 0;
}