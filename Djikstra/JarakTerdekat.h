#pragma once
#include "SFML.h"
#include<iostream>
#include<vector>
#include<string>
#include <math.h>
#include <sstream>

class JarakTerdekat
{
private:
    //Struct untuk menyimpan kota
    struct tKota
    {
        float TitikKota;
        float x;
        float y;
        std::string sNamaKota;
        std::string kotaLanjutannyal;
    };
    struct tKota Kota[99];
    //Struct untuk menyimpan jarak kota
    struct TKotaJarak
    {
        std::string nama1;
        std::string nama2;
        float jarak;
        float jarakasli1;
    };
    TKotaJarak jarakkota[99];
    std::vector<sf::VertexArray> lineterdekat;
    std::string kotalewat[99];
    int kotai = 0;
    int banyakteks = 0;
    int jaraknya = 0;
    float totaljarak = 0;
    std::string totaljarakfix; // Total jarak kota terdekat
    sf::Text teks[99], teksjarak;
    sf::Font font;
    int indekskota = -1;
    float xteks = 800;
public:
    //Deklarasi fungsi untuk memasukkan kota
    void DataMasuk(std::string NamaKota, float x, float y);
    //Deklarasi  fungsi untuk mencari indeks  kota
    int CariIndeksKota(std::string NamaKotaL);
    //Deklarasi fungsi untuk mencari indeks jarak antar kota
    int CariIndeksJarak(std::string kotaasal, std::string kotatujuan);
    //Deklarasi fungsi untuk menghubungkan
    void Hubung(std::string sDari, std::string sKe, float Jarak, float jarakasli);
    //Deklarasi fungsi untuk mengisi TK 
    void InitFungsiDjikstra();
    //Deklarasi fungsi untuk mencari kota tujuan
    void djikstra(std::string kotaSel, float kedekatan, std::string awal, std::string tuju);
    //Deklarasi fungsi untuk memisahkan string yang tergabung
    void pencarianJalur(int Tujuan);
    //Deklarasi fungsi untuk membuat garis hubung jarak terdekat
    void line(float x1, float y1, float x2, float y2);
    //Deklarasi fungsi untuk mengembalikan nilai awal
    void reset();
    //Deklarasi fungsi untuk mencari nilai garis yang akan dihubungkan
    void masukline();
    //Deklarasi fungsi untuk mencetak teks kota terlewati
    void masukteks();
    //Deklarasi fungsi untuk mencetak totaljarak
    void masukteksjarak();
    //Deklarasi fungsi untuk menggambar
	void drawlineterdekat(sf::RenderWindow& window);
};

