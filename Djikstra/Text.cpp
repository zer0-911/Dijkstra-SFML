#include "Text.h"

void Text::input(std::string nama, std::string x, std::string y)
{
	//std::cout << Node;
	this->tabel();
	dKotaUtama.kota[Node].nama = nama;
	dKotaUtama.kota[Node].xs = x;
	dKotaUtama.kota[Node].x = std::stof(x);
	dKotaUtama.kota[Node].ys = y;
	dKotaUtama.kota[Node].y = std::stof(y);
	//std::cout << dKotaUtama.kota[Node].x;
	text[Node].setString(dKotaUtama.kota[Node].nama);
	text[Node].setPosition({ xsize,ysize });
	text2[Node].setString(dKotaUtama.kota[Node].xs);
	text2[Node].setPosition({ xsize+50,ysize });
	text3[Node].setString(dKotaUtama.kota[Node].ys);
	text3[Node].setPosition({ xsize+100,ysize });
	ysize += 20;
	Node = Node + 1;
}

void Text::drawToTx(sf::RenderWindow& window)
{
	window.draw(tabel1);
	window.draw(tabel2);
	window.draw(tabel3);
	window.draw(lineatas);
	window.draw(linebawah);
	
	for (int i = 0; i < Node; i++)
	{
		window.draw(linekiri[i]);
		window.draw(linekanan[i]);
		window.draw(line[i]);
		window.draw(text[i]);
		window.draw(text2[i]);
		window.draw(text3[i]);
	}
}
void Text::tabel()
{
	tabel1.setString("Kota");
	tabel1.setPosition({ 25,180 });

	tabel2.setString("X");
	tabel2.setPosition({ 78,180 });

	tabel3.setString("Y");
	tabel3.setPosition({ 128,180 });
	lineatas.setSize(sf::Vector2f(135, 1));
	lineatas.setPosition({ 20,178 });
	linebawah.setSize(sf::Vector2f(135, 1));
	linebawah.setPosition({ 20,198 });
	linekiri[Node].setSize(sf::Vector2f(xline, 1));
	linekiri[Node].setPosition({ 20,178 });
	linekiri[Node].rotate(90);
	linekanan[Node].setSize(sf::Vector2f(xline, 1));
	linekanan[Node].setPosition({ 155,178 });
	linekanan[Node].rotate(90);
	line[Node].setSize(sf::Vector2f(135, 1));
	line[Node].setPosition({ 20,yline });
	yline += 20;
	xline += 20;
}
void Text::setFontTx(sf::Font& fonts)
{
	tabel1.setFont(fonts);
	tabel2.setFont(fonts);
	tabel3.setFont(fonts);
	tabel1.setCharacterSize(14);
	tabel2.setCharacterSize(14);
	tabel3.setCharacterSize(14);
	for (int i = 0; i < 100; i++)
	{
		text[i].setFont(fonts);
		text2[i].setFont(fonts);
		text3[i].setFont(fonts);
		text[i].setCharacterSize(14);
		text2[i].setCharacterSize(14);
		text3[i].setCharacterSize(14);
	}
}
