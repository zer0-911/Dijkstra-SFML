#include "Hubung.h"

void Hubung::Hubungkan(float x1, float y1, float x2, float y2, std::string kotaasal, std::string kotatujuan, int Node)
{
    //Memanggil font
    if (!font.loadFromFile("Assets/Font/BebasNeue-Regular.otf"))
    {
        std::cout << "Font tidak ditemukan\n";
    }
    //Membuat garis dengan Vertex Array
    sf::VertexArray line(sf::Lines, 2);
    line[0].position = sf::Vector2f(x1,y1);
    line[1].position = sf::Vector2f(x2,y2);
    m_garis.push_back(line);
    hasil = 0;
    hasil2 = 0;
    A = 0;
    B = 0;
    xtengah = 0;
    ytengah = 0;
    //Menghitung jarak
    A = (x2 - x1) * (x2 - x1);
    B = (y2 - y1) * (y2 - y1);
    hasil = sqrt(A + B);
    hasil2 = std::round(hasil * 100);
    std::cout << kotaasal << " " << kotatujuan << " " << hasil << "\n";
    //Memanggil fungsi yang ada di kelas JarakTerdekat
    bool b;
    b = djikstra.Hubung(kotaasal, kotatujuan, hasil2, hasil);
    b = djikstra.Hubung(kotatujuan, kotaasal, hasil2, hasil);
    //Memaasukkan teks ke jarak[banyak]
    jarak[banyak] = std::to_string(hasil);
    //Menentukan posisi dari teks yang berisi jarak
    xtengah = (x1 + x2) / 2;
    ytengah = (y1 + y2) / 2;
    //Membuat teks jarak
    teksjarak[banyak].setString(jarak[banyak]);
    teksjarak[banyak].setFont(font);
    teksjarak[banyak].setCharacterSize(14);
    teksjarak[banyak].setPosition({xtengah, ytengah});
    teksjarak[banyak].setFillColor(sf::Color::Black);
    banyak = banyak + 1;
}

void Hubung::MFDjikstra(std::string sNamaKota, float x, float y)
{
    //Memanggil fungsi di kelas JarakTerdekat
    djikstra.Append(sNamaKota, x, y);
}

void Hubung::DjikstraOn(std::string Asal, std::string Tujuan)
{
    //Memanggil fungsi di kelas JarakTerdekat
    djikstra.reset();
    djikstra.InitDjikstra();
    djikstra.djikstra(Tujuan, 0);
    djikstra.CariRute(Asal);
}

void Hubung::drawline(sf::RenderWindow& window)
{
    //Menggambar dengan mengulangi per garis, dan teks
    for (size_t i = 0; i < m_garis.size(); i++)
    {
        window.draw(m_garis[i]);
        window.draw(teksjarak[i]);
    }
    djikstra.drawlineterdekat(window);
}

