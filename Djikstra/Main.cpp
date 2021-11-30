#include <iostream>
#include <SFML/Graphics.hpp>
#include "Textbox.h"
#include "Button.h"
#include "Text.h"
#include "City.h"


int main()
{
	sf::RenderWindow window;

	sf::Vector2i centerWindow((sf::VideoMode::getDesktopMode().width / 2) - 445, (sf::VideoMode::getDesktopMode().height / 2) - 480);

	window.create(sf::VideoMode(1600, 900), "SFML Textbox", sf::Style::Titlebar | sf::Style::Close);
	window.setPosition(centerWindow);

	window.setKeyRepeatEnabled(true);

	sf::Font font;
	if (!font.loadFromFile("arial.ttf"))
		std::cout << "Font not found!\n";

	Textbox text1(20, sf::Color::White, false), text2(20, sf::Color::White, false), text3(20, sf::Color::White, false);
	text1.setPosition({ 10, 25 });
	text1.setLimit(true, 6);
	text1.setFont(font);	

	text2.setPosition({ 10, 75 });
	text2.setLimit(true, 3);
	text2.setFont(font);

	text3.setPosition({ 10, 125 });
	text3.setLimit(true, 3);
	text3.setFont(font);

	Button btn1("Enter", { 50, 30 }, 18, sf::Color::Green, sf::Color::Black);
	btn1.setFont(font);
	btn1.setPosition({ 100, 110 });
	size_t x = 0;

	Text tx1;
	tx1.setFontTx(font);

	sf::Text help1, help2, help3;
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
	City city;

	while (window.isOpen()) {

		sf::Event Event;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
			text1.setSelected(true);
			text2.setSelected(false);
			text3.setSelected(false);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			text1.setSelected(false);
			text2.setSelected(true);
			text3.setSelected(false);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
		{
			text1.setSelected(false);
			text2.setSelected(false);
			text3.setSelected(true);
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
			case sf::Event::MouseMoved:
				if (btn1.isMouseOver(window)) {
					btn1.setBackColor(sf::Color::Magenta);
				}
				else {
					btn1.setBackColor(sf::Color::Green);
				}
				break;
			case sf::Event::MouseButtonPressed:
				if (btn1.isMouseOver(window)) {
					std::string z = text1.getText();
					std::string x = text2.getText();
					std::string y = text3.getText();
					tx1.input(z,x,y);
					city.img(x, y);
				}
			}
		}
		window.clear();
		window.draw(help1);
		window.draw(help2);
		window.draw(help3);
		text1.drawTo(window);
		text2.drawTo(window);
		text3.drawTo(window);
		tx1.drawToTx(window);
		city.drawToImg(window);
		btn1.drawTo(window);
		window.display();
	}
	return 0;
}