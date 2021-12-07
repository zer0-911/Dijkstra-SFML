#pragma once
#include "SFML.h"
#include<iostream>
#include<vector>

class JarakTerdekat
{
private:
    struct tKotaNext
    {
        std::string sKotaNext;
        float jarak;
        float jarakasli;
    };
    struct tKota
    {
        float TK;
        float x;
        float y;
        std::string sNamaKota;
        std::vector<struct tKotaNext> lKotaNext;
    };
    std::vector<tKota> lKota;
    std::vector<sf::VertexArray> lineterdekat;
    std::string kotalewat[99];
    int kotai = 0;
public:
    void Append(std::string sNamaKota, float x, float y);
    int CariIndeksKota(std::string sNamaKota);
    bool Hubung(std::string sDari, std::string sKe, float Jarak);
    void InitDjikstra();
    void djikstra(std::string sKota, float TK);
    void CariRute(std::string sKota);
    void line(float x1, float y1, float x2, float y2);
    void reset();
    void masukline();
	void drawlineterdekat(sf::RenderWindow& window);
};

