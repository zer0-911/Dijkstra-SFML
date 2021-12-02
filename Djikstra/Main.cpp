#include <iostream>
#include <string>
#include "SFML.h"
#include "Textbox.h"
#include "Button.h"
#include "Text.h"
#include "City.h"

int main()
{
	sf::RenderWindow window;

	sf::Vector2i centerWindow((sf::VideoMode::getDesktopMode().width / 2) - 845, (sf::VideoMode::getDesktopMode().height / 2) - 480);
	

	window.create(sf::VideoMode(1600, 900), "Djikstra", sf::Style::Titlebar | sf::Style::Close);
	window.setPosition(centerWindow);

	window.setKeyRepeatEnabled(true);

	sf::Font font;
	if (!font.loadFromFile("Assets/Font/arial.ttf"))
	{
		std::cout << "Font tidak ditemukan\n";
	}
		

	Textbox text1(20, sf::Color::White, false), text2(20, sf::Color::White, false), text3(20, sf::Color::White, false), text4(20, sf::Color::White, false), text5(20, sf::Color::White, false);
	text1.setPosition({ 10, 25 });
	text1.setLimit(true, 6);
	text1.setFont(font);

	text2.setPosition({ 10, 75 });
	text2.setLimit(true, 3);
	text2.setFont(font);

	text3.setPosition({ 10, 125 });
	text3.setLimit(true, 3);
	text3.setFont(font);

	text4.setPosition({ 300, 25 });
	text4.setLimit(true, 6);
	text4.setFont(font);

	text5.setPosition({ 300, 75 });
	text5.setLimit(true, 6);
	text5.setFont(font);

	Button btn1("Masuk", { 60, 20 }, 14, sf::Color::Green, sf::Color::Black);
	btn1.setFont(font);
	btn1.setPosition({ 100, 125 });
	size_t x = 0;

	Button btn2("Hubung", { 60, 20 }, 14, sf::Color::Green, sf::Color::Black);
	btn2.setFont(font);
	btn2.setPosition({ 400, 125 });

	Button btn3("Jarak \n Terdekat", { 70, 40 }, 14, sf::Color::Green, sf::Color::Black);
	btn3.setFont(font);
	btn3.setPosition({ 700, 125 });

	Text tx1;
	tx1.setFontTx(font);

	sf::Text help1, help2, help3, help4, help5, help6, help7;
	help1.setString("Nama Kota");
	help1.setCharacterSize(14);
	help1.setPosition({ 10, 10 });
	help1.setFont(font);
	help2.setString("Koordinat X");
	help2.setCharacterSize(14);
	help2.setPosition({ 10, 60 });
	help2.setFont(font);
	help3.setString("Koordinat Y");
	help3.setCharacterSize(14);
	help3.setPosition({ 10, 110 });
	help3.setFont(font);
	help4.setString("Kota Asal");
	help4.setCharacterSize(14);
	help4.setPosition({ 300, 10 });
	help4.setFont(font);
	help5.setString("Kota Tujuan");
	help5.setCharacterSize(14);
	help5.setPosition({ 300, 60 });
	help5.setFont(font);
	help6.setString("Kota Asal");
	help6.setCharacterSize(14);
	help6.setPosition({ 600, 10 });
	help6.setFont(font);
	help7.setString("Kota Tujuan");
	help7.setCharacterSize(14);
	help7.setPosition({ 600, 60 });
	help7.setFont(font);
	City city;


	while (window.isOpen()) {

		sf::Event Event;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
			text1.setSelected(true);
			text2.setSelected(false);
			text3.setSelected(false);
			text4.setSelected(false);
			text5.setSelected(false);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			text1.setSelected(false);
			text2.setSelected(true);
			text3.setSelected(false);
			text4.setSelected(false);
			text5.setSelected(false);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
		{
			text1.setSelected(false);
			text2.setSelected(false);
			text3.setSelected(true);
			text4.setSelected(false);
			text5.setSelected(false);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F1))
		{
			text1.setSelected(false);
			text2.setSelected(false);
			text3.setSelected(false);
			text4.setSelected(true);
			text5.setSelected(false);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F2))
		{
			text1.setSelected(false);
			text2.setSelected(false);
			text3.setSelected(false);
			text4.setSelected(false);
			text5.setSelected(true);
		}

		//Event Loop:
		while (window.pollEvent(Event)) {
			switch (Event.type) {

			case sf::Event::Closed:
				window.close();
			case sf::Event::TextEntered:
				text1.typedOn(Event);
				text2.typedOn(Event);
				text3.typedOn(Event);
				text4.typedOn(Event);
				text5.typedOn(Event);
			case sf::Event::MouseMoved:
				if (btn1.isMouseOver(window)) {
					btn1.setBackColor(sf::Color::Magenta);
				}
				else {
					btn1.setBackColor(sf::Color::Green);
				}
				if (btn2.isMouseOver(window)) {
					btn2.setBackColor(sf::Color::Magenta);
				}
				else {
					btn2.setBackColor(sf::Color::Green);
				}
				if (btn3.isMouseOver(window)) {
					btn3.setBackColor(sf::Color::Magenta);
				}
				else {
					btn3.setBackColor(sf::Color::Green);
				}
				break;
				
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
						city.img(x, y);
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
			}
		}
		window.clear();
		window.draw(help1);
		window.draw(help2);
		window.draw(help3);
		window.draw(help4);
		window.draw(help5);
		window.draw(help6);
		window.draw(help7);
		text1.drawTo(window);
		text2.drawTo(window);
		text3.drawTo(window);
		text4.drawTo(window);
		text5.drawTo(window);
		tx1.drawToTx(window);
		city.drawToImg(window);
		btn1.drawTo(window);
		btn2.drawTo(window);
		btn3.drawTo(window);
		window.display();
	}
	return 0;
}