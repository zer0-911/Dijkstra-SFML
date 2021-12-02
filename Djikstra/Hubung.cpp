#include "Hubung.h"

void Hubung::Hubungkan(float x1, float y1, float x2, float y2, std::string kotaasal, std::string kotatujuan)
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
    A = 0;
    B = 0;
    xtengah = 0;
    ytengah = 0;
    A = (x2 - x1) * (x2 - x1);
    B = (y2 - y1) * (y2 - y1);
    hasil = sqrt(A + B);
    jarak[banyak] = std::to_string(hasil);
    xtengah = (x1 + x2) / 2;
    ytengah = (y1 + y2) / 2;
    std::cout << jarak[3] << "\n";
    std::cout << banyak << "\n";
    teksjarak[banyak].setString(jarak[banyak]);
    teksjarak[banyak].setFont(font);
    teksjarak[banyak].setCharacterSize(14);
    teksjarak[banyak].setPosition({xtengah, ytengah});
    teksjarak[banyak].setFillColor(sf::Color::Blue);
    banyak = banyak + 1;
}

void Hubung::drawline(sf::RenderWindow& window)
{
    for (size_t i = 0; i < m_vertices.size(); i++)
    {
        window.draw(m_vertices[i]);
        window.draw(teksjarak[i]);
    }
}
