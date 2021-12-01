#include "Hubung.h"

void Hubung::Hubungkan()
{
    //std::cout << 
    sf::VertexArray line(sf::Lines, 2);
    line[0].position = sf::Vector2f(x,300);
    line[1].position = sf::Vector2f(200,y);
    m_vertices.push_back(line);
    x += 50;
    y += 50;
}

void Hubung::drawline(sf::RenderWindow& window)
{
    for (size_t i = 0; i < m_vertices.size(); i++)
    {
        window.draw(m_vertices[i]);
    }
}
