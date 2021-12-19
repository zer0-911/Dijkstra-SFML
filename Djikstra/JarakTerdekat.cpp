#include "JarakTerdekat.h"

void JarakTerdekat::DataMasuk(std::string NamaKota, float x, float y)
{
    //Menyimpan nama dan koordinat
    struct tKota masuk;
    masuk.TitikKota = 100000000000;
    masuk.sNamaKota = NamaKota;
    masuk.x = x;
    masuk.y = y;
    DjikstraKota.push_back(masuk);
}

int JarakTerdekat::CariIndeksKota(std::string sNamaKota)
{
    //Mencari indeks kota
    int poskota = -1;
    for (int i = 0; i < DjikstraKota.size();i++)
    {
        std::string s = DjikstraKota[i].sNamaKota;
        //Jika ketemu maka nilai pos kota berubah
        if (sNamaKota.compare(s) == 0)
        {
            poskota = i;
            break;
        }

    }
    return poskota;
}

int JarakTerdekat::CariIndeksJarak(std::string kotaasal, std::string kotatujuan)
{
    int jkotaKetemu = -1;
    for (int i = 0; i <= jaraknya;i++)
    {
        std::cout << jarakkota[i].nama1 << jarakkota[i].nama1;
        if ((jarakkota[i].nama1 == kotaasal) && (jarakkota[i].nama2 == kotatujuan))
        {
            jkotaKetemu = i;
            break;
        }

    }
    return jkotaKetemu;
}

bool JarakTerdekat::Hubung(std::string DariKota, std::string KeKota, float Jarak, float jarakasli)
{
    int Kota1, Kota2;
    Kota1 = CariIndeksKota(DariKota);
    Kota2 = CariIndeksKota(KeKota);
    bool KotaKetemu = true;
    //Menghubungkan kota agar masuk ke vector 
    if ((Kota1 >= 0) && (Kota2 >= 0))
    {
        struct tKotaNext d;
        d.KotaLanjutan = KeKota;
        d.jarak = Jarak;
        DjikstraKota[Kota1].Kota2Lanjut.push_back(d);
        jarakkota[jaraknya].nama1 = DariKota;
        jarakkota[jaraknya].nama2 = KeKota;
        jarakkota[jaraknya].jarakasli1 = jarakasli;
        jaraknya++;
    }
    else
    {
        KotaKetemu = false;
    }
    return KotaKetemu;
}

void JarakTerdekat::InitFungsiDjikstra()
{
    //Memasukkan nilai di array tersebut
    for (int i = 0;i < DjikstraKota.size();i++)
    {
        DjikstraKota[i].TitikKota = 1000000000;
    }
}

void JarakTerdekat::djikstra(std::string sKota, float titikKota)
{
    int n = CariIndeksKota(sKota);
    //Kondisi ketika titikKota sudah lebih dari nilai struct titikKota
    if (titikKota > DjikstraKota[n].TitikKota)
    {
        return;
    }
    //Penggunaan algoritma djikstra
    DjikstraKota[n].TitikKota = titikKota;
    for (int i = 0; i < DjikstraKota[n].Kota2Lanjut.size();i++)
    {
        std::string LanjutK = DjikstraKota[n].Kota2Lanjut[i].KotaLanjutan;
        float jarak = DjikstraKota[n].Kota2Lanjut[i].jarak;
        djikstra(LanjutK, titikKota + jarak);
    }
}

void JarakTerdekat::CariRute(std::string DjKota)
{
    //Memasukkan nilai dari DjKota ke array kotalewat
    kotalewat[kotai] = DjKota;
    kotai++;

    int n = CariIndeksKota(DjKota);
    float TitikK = DjikstraKota[n].TitikKota;
    //Kondisi ketika titikK memiliki nilai 0 
    if (TitikK == 0)
    {
        masukteks();
        masukline();
        return;
    }
    //Perulangan untuk mencari kota terdekat
    for (int i = 0; i < DjikstraKota[n].Kota2Lanjut.size();i++)
    {
        std::string snext = DjikstraKota[n].Kota2Lanjut[i].KotaLanjutan;
        int Nnext = CariIndeksKota(snext);
        float TKnext = DjikstraKota[Nnext].TitikKota;
        int JarakNext = DjikstraKota[n].Kota2Lanjut[i].jarak;
        if (JarakNext + TKnext == TitikK)
        {
            CariRute(snext);
        }
    }
}

void JarakTerdekat::line(float x1, float y1, float x2, float y2)
{
    //Membuat garis sesuai dengan koordinat dari kota yang dihubungkan terdekat
    sf::VertexArray line2(sf::Lines, 2);
    line2[0].position = sf::Vector2f(x1, y1);
    line2[1].position = sf::Vector2f(x2, y2);
    line2[0].color = sf::Color::Green;
    line2[1].color = sf::Color::Green;
    lineterdekat.push_back(line2);
}

void JarakTerdekat::reset()
{
    //Mereset variabel ke 0
    totaljarak = 0;
    xteks = 800;
    banyakteks = 0;
    kotai = 0;
    lineterdekat.clear();
}

void JarakTerdekat::masukline()
{
    //Mengulang hingga indeks kotai - 1
    for (size_t i = 0; i < kotai-1; i++)
    {       
        //Mencari indeks kota dan  indeks jarak sesuai dengan kota terdekat yang sudah dihasilkan
        int nline1 = CariIndeksKota(kotalewat[i]);
        int nline2 = CariIndeksKota(kotalewat[i + 1]);
        int njarak = CariIndeksJarak(kotalewat[i], kotalewat[i + 1]);
        line(DjikstraKota[nline1].x, DjikstraKota[nline1].y, DjikstraKota[nline2].x, DjikstraKota[nline2].y);
        if (njarak >= 0)
        {
            totaljarak = totaljarak + jarakkota[njarak].jarakasli1;
        }
    }
    masukteksjarak();
}
   

void JarakTerdekat::masukteks()
{
    //Memanggil font yang digunakan
    if (!font.loadFromFile("Assets/Font/arial.ttf"))
    {
        std::cout << "Font tidak ditemukan\n";
    }
    for (size_t teksi = 0; teksi < kotai; teksi++)
    {
        //Membuat teks kota lewat
        teks[banyakteks].setFont(font);
        teks[banyakteks].setString(kotalewat[teksi]);
        teks[banyakteks].setPosition({ xteks, 25 });
        teks[banyakteks].setCharacterSize(20);
        teks[banyakteks].setFillColor(sf::Color::Black);
        xteks=xteks+40;
        banyakteks++;
    }
}

void JarakTerdekat::masukteksjarak()
{
    //Mengubah tipe data float totaljarak ke string
    totaljarakfix = std::to_string(totaljarak);
    //Membuat teksjarak yang berisi string totaljarak
    teksjarak.setFont(font);
    teksjarak.setString(totaljarakfix);
    teksjarak.setPosition({ 800, 75 });
    teksjarak.setCharacterSize(20);
    teksjarak.setFillColor(sf::Color::Black);
}

void JarakTerdekat::drawlineterdekat(sf::RenderWindow& window)
{
    //Menggambar teks dan garis dari hasil algoritma djikstra
    window.draw(teksjarak);
    for (size_t i = 0; i < banyakteks; i++)
    {
        window.draw(teks[i]);
    }
    for (size_t i = 0; i < lineterdekat.size(); i++)
    {
        window.draw(lineterdekat[i]);
    }
}