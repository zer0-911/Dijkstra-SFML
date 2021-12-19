#include "Button.h"

Button::Button::Button(std::string btnText, sf::Vector2f buttonSize, int charSize, sf::Color bgColor, sf::Color textColor)
{
	//Memberikan ukuran, warna, dan karakter
	button.setSize(buttonSize);
	button.setFillColor(bgColor);
	btnLebar = buttonSize.x;
	btnTinggi = buttonSize.y;
	text.setString(btnText);
	text.setCharacterSize(charSize);
	text.setFillColor(textColor);
}

void Button::Button::setFont(sf::Font& fonts)
{
	//Menentukan font
	text.setFont(fonts);
}

void Button::Button::setWarnaBelakang(sf::Color bgcolor)
{
	//Menentukan warna
	button.setFillColor(bgcolor);
}

void Button::Button::setWarnaTeks(sf::Color textcolor)
{
	//Menentukan warna teks
	text.setFillColor(textcolor);
}

void Button::Button::setPosisi(sf::Vector2f point)
{
	//Menentukan posisi 
	button.setPosition(point);

	// Menentukan poisisi teks ke tengah
	float xPos = (point.x + btnLebar / 2) - (text.getLocalBounds().width / 2);
	float yPos = (point.y + btnTinggi / 2.2) - (text.getLocalBounds().height / 2);
	text.setPosition(xPos, yPos);
}

void Button::Button::drawTo(sf::RenderWindow& window)
{
	//Menggambar button dan teks
	window.draw(button);
	window.draw(text);
}

bool Button::Button::MouseDiatasButton(sf::RenderWindow& window)
{
	//Mencari posisi mouse dan menentukan kondisi ketika posisi mouse tepat di kotak
	int mouseX = sf::Mouse::getPosition(window).x;
	int mouseY = sf::Mouse::getPosition(window).y;

	int btnPosX = button.getPosition().x;
	int btnPosY = button.getPosition().y;

	int btnxPosWidth = button.getPosition().x + btnLebar;
	int btnyPosHeight = button.getPosition().y + btnTinggi;

	if ((mouseX < btnxPosWidth) && (mouseX > btnPosX) && (mouseY < btnyPosHeight) && (mouseY > btnPosY)) {
		return true;
	}
	return false;
}
