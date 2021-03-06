#include "Text.h"
void Text::input(std::string nama, std::string x, std::string y)
{
	//Memanggil fungsi tabel
	this->tabel();
	//Memasukkan nama dan koordinat di array yang sudah dibuat
	dKotaUtama.kota[Node].nama = nama;
	dKotaUtama.kota[Node].xs = x;
	dKotaUtama.kota[Node].x = std::stof(x);
	dKotaUtama.kota[Node].ys = y;
	dKotaUtama.kota[Node].y = std::stof(y);
	//Memanggil fungsi hubungkan pada class JarakTerdekat
	hubung.MFDjikstra(nama, dKotaUtama.kota[Node].x+250, dKotaUtama.kota[Node].y+250);
	//Menmasukkan apa saja yang ada di teks
	text[Node].setString(dKotaUtama.kota[Node].nama);
	text[Node].setPosition({ xsize,ysize });
	text[Node].setFillColor(sf::Color::Black);
	text2[Node].setString(dKotaUtama.kota[Node].xs);
	text2[Node].setPosition({ xsize+50,ysize });
	text2[Node].setFillColor(sf::Color::Black);
	text3[Node].setString(dKotaUtama.kota[Node].ys);
	text3[Node].setPosition({ xsize+100,ysize });
	text3[Node].setFillColor(sf::Color::Black);
	ysize += 20;
	Node = Node + 1;
}

void Text::drawToTx(sf::RenderWindow& window)
{
	//Menggambar fungsi yang ada dikelas JarakTerdekat
	hubung.drawline(window);
	//Menggambar tabel, garis, dan teks
	window.draw(tabel0);
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
	//Mendeklarisikan isi dari teks didalam Tabel
	tabel0.setString("Tabel Daftar Kota");
	tabel0.setPosition({ 30,170 });
	tabel0.setFillColor(sf::Color::Black);

	tabel1.setString("Kota");
	tabel1.setPosition({ 25,190 });
	tabel1.setFillColor(sf::Color::Black);

	tabel2.setString("X");
	tabel2.setPosition({ 78,190 });
	tabel2.setFillColor(sf::Color::Black);

	tabel3.setString("Y");
	tabel3.setPosition({ 128,190 });
	tabel3.setFillColor(sf::Color::Black);
	//Menggambar garis-garis pada tabel
	lineatas.setSize(sf::Vector2f(135, 1));
	lineatas.setPosition({ 20,188 });
	lineatas.setFillColor(sf::Color::Black);
	linebawah.setSize(sf::Vector2f(135, 1));
	linebawah.setPosition({ 20,208 });
	linebawah.setFillColor(sf::Color::Black);
	linekiri[Node].setSize(sf::Vector2f(xline, 1));
	linekiri[Node].setPosition({ 20,188 });
	linekiri[Node].rotate(90);
	linekiri[Node].setFillColor(sf::Color::Black);
	linekanan[Node].setSize(sf::Vector2f(xline, 1));
	linekanan[Node].setPosition({ 155,188 });
	linekanan[Node].rotate(90);
	linekanan[Node].setFillColor(sf::Color::Black);
	line[Node].setSize(sf::Vector2f(135, 1));
	line[Node].setPosition({ 20,yline });
	line[Node].setFillColor(sf::Color::Black);
	yline += 20;
	xline += 20;
}
void Text::caritujuan(std::string namaasal, std::string namatujuan)
{
	int posD, posK;
	//Mencari posisi kota yang dihubungkan
	posD = cari(namaasal);
	posK = cari(namatujuan);
	//Permisalan jika posisi TRUE
	if ((posD >= 0) && (posK >= 0))
	{
		hubung.Hubungkan(dKotaUtama.kota[posD].x+250, dKotaUtama.kota[posD].y+250, dKotaUtama.kota[posK].x + 250, dKotaUtama.kota[posK].y + 250, namaasal, namatujuan, Node);
	}
}
int Text::cari(std::string carikota)
{
	//posisi awal dari variabel pos yang berarti
	//tidak ditemukan
	int pos = -1;
	//pengulangan untuk mencari sampai menemukan
	//variabel string yang sama
	for (int i = 0;i <= Node;i++)
	{
		if (dKotaUtama.kota[i].nama == carikota)
		{
			//mengubah variabel pos menjadi sama dengan 
			//indeks
			pos = i;
			break;
		}
	}
	//mengembalikan variabel pos
	return pos;
}
void Text::jarakTerdekat(std::string AsalK, std::string TujuanK)
{
	hubung.DjikstraOn(AsalK, TujuanK);
}
void Text::setFontTx(sf::Font& fonts)
{
	tabel0.setFont(fonts);
	tabel1.setFont(fonts);
	tabel2.setFont(fonts);
	tabel3.setFont(fonts);
	tabel0.setCharacterSize(14);
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

