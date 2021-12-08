#pragma once
#include "SFML.h"
#include<iostream>
#include<vector>
#include<string>

class JarakTerdekat
{
private:
    struct tKotaNext
    {
        std::string sKotaNext;
        float jarak;
    };
    struct tKota
    {
        float TK;
        float x;
        float y;
        std::string sNamaKota;
        std::vector<struct tKotaNext> lKotaNext;
    };
    struct TKotaJarak
    {
        std::string nama1;
        std::string nama2;
        float jarakasli1;
    };
    TKotaJarak jarakkota[99];
    std::vector<tKota> lKota;
    std::vector<sf::VertexArray> lineterdekat;
    std::string kotalewat[99];
    int kotai = 0;
    int banyakteks = 0;
    int jaraknya = 0;
    float totaljarak = 0;
    std::string totaljarakfix;
    sf::Text teks[99], teksjarak;
    sf::Font font;
    float xteks = 900;
public:
    void Append(std::string sNamaKota, float x, float y);
    int CariIndeksKota(std::string sNamaKota);
    int CariIndekJarak(std::string kotaasal, std::string kotatujuan);
    bool Hubung(std::string sDari, std::string sKe, float Jarak, float jarakasli);
    void InitDjikstra();
    void djikstra(std::string sKota, float TK);
    void CariRute(std::string sKota);
    void line(float x1, float y1, float x2, float y2);
    void reset();
    void masukline();
    void masukteks();
    void masukteksjarak();
	void drawlineterdekat(sf::RenderWindow& window);
};

