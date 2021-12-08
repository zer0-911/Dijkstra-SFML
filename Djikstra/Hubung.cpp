#include "Hubung.h"

void Hubung::Hubungkan(float x1, float y1, float x2, float y2, std::string kotaasal, std::string kotatujuan, int Node)
{
    //std::cout << 
    if (!font.loadFromFile("Assets/Font/arial.ttf"))
    {
        std::cout << "Font tidak ditemukan\n";
    }
    sf::VertexArray line(sf::Lines, 2);
    line[0].position = sf::Vector2f(x1,y1);
    line[1].position = sf::Vector2f(x2,y2);
    m_vertices.push_back(line);
    hasil = 0;
    hasil2 = 0;
    A = 0;
    B = 0;
    xtengah = 0;
    ytengah = 0;
    A = (x2 - x1) * (x2 - x1);
    B = (y2 - y1) * (y2 - y1);
    hasil = sqrt(A + B);
    hasil2 = std::round(hasil * 100);
    std::cout << kotaasal << " " << kotatujuan << " " << hasil << "\n";
    bool b;
    b = djikstra.Hubung(kotaasal, kotatujuan, hasil2, hasil);
    b = djikstra.Hubung(kotatujuan, kotaasal, hasil2, hasil);
    jarak[banyak] = std::to_string(hasil);
    xtengah = (x1 + x2) / 2;
    ytengah = (y1 + y2) / 2;
    teksjarak[banyak].setString(jarak[banyak]);
    teksjarak[banyak].setFont(font);
    teksjarak[banyak].setCharacterSize(14);
    teksjarak[banyak].setPosition({xtengah, ytengah});
    teksjarak[banyak].setFillColor(sf::Color::Blue);
    banyak = banyak + 1;
}

void Hubung::MFDjikstra(std::string sNamaKota, float x, float y)
{
    djikstra.Append(sNamaKota, x, y);
}

void Hubung::DjikstraOn(std::string Asal, std::string Tujuan)
{
    djikstra.reset();
    djikstra.InitDjikstra();
    djikstra.djikstra(Tujuan, 0);
    djikstra.CariRute(Asal);
}

void Hubung::drawline(sf::RenderWindow& window)
{
    
    for (size_t i = 0; i < m_vertices.size(); i++)
    {
        window.draw(m_vertices[i]);
        window.draw(teksjarak[i]);
    }
    djikstra.drawlineterdekat(window);
}

