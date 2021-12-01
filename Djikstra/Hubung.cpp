#include "Hubung.h"

void Hubung::Hubungkan(float x1, float y1, float x2, float y2)
{
    //std::cout << 
    sf::VertexArray line(sf::Lines, 2);
    line[0].position = sf::Vector2f(x1,y1);
    line[1].position = sf::Vector2f(x2,y2);
    m_vertices.push_back(line);
}

void Hubung::drawline(sf::RenderWindow& window)
{
    for (size_t i = 0; i < m_vertices.size(); i++)
    {
        window.draw(m_vertices[i]);
    }
}
