#include "Button.h"

Button::Button::Button(std::string btnText, sf::Vector2f buttonSize, int charSize, sf::Color bgColor, sf::Color textColor)
{
	//Memberikan ukuran, warna, dan karakter
	button.setSize(buttonSize);
	button.setFillColor(bgColor);
	btnWidth = buttonSize.x;
	btnHeight = buttonSize.y;
	text.setString(btnText);
	text.setCharacterSize(charSize);
	text.setFillColor(textColor);
}

void Button::Button::setFont(sf::Font& fonts)
{
	//Menentukan font
	text.setFont(fonts);
}

void Button::Button::setBackColor(sf::Color bgcolor)
{
	//Menentukan warna
	button.setFillColor(bgcolor);
}

void Button::Button::setTextColor(sf::Color textcolor)
{
	//Menentukan warna teks
	text.setFillColor(textcolor);
}

void Button::Button::setPosition(sf::Vector2f point)
{
	//Menentukan posisi 
	button.setPosition(point);

	// Menentukan poisisi teks ke tengah
	float xPos = (point.x + btnWidth / 2) - (text.getLocalBounds().width / 2);
	float yPos = (point.y + btnHeight / 2.2) - (text.getLocalBounds().height / 2);
	text.setPosition(xPos, yPos);
}

void Button::Button::drawTo(sf::RenderWindow& window)
{
	//Menggambar button dan teks
	window.draw(button);
	window.draw(text);
}

bool Button::Button::isMouseOver(sf::RenderWindow& window)
{
	//Mencari posisi mouse dan menentukan kondisi ketika posisi mouse tepat di kotak
	int mouseX = sf::Mouse::getPosition(window).x;
	int mouseY = sf::Mouse::getPosition(window).y;

	int btnPosX = button.getPosition().x;
	int btnPosY = button.getPosition().y;

	int btnxPosWidth = button.getPosition().x + btnWidth;
	int btnyPosHeight = button.getPosition().y + btnHeight;

	if ((mouseX < btnxPosWidth) && (mouseX > btnPosX) && (mouseY < btnyPosHeight) && (mouseY > btnPosY)) {
		return true;
	}
	return false;
}
