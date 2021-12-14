#include "JarakTerdekat.h"

void JarakTerdekat::Append(std::string sNamaKota, float x, float y)
{
    //Menyimpan nama dan koordinat
    struct tKota d;
    d.TK = 100000000000;
    d.sNamaKota = sNamaKota;
    d.x = x;
    d.y = y;
    lKota.push_back(d);
}

int JarakTerdekat::CariIndeksKota(std::string sNamaKota)
{
    int poskota = -1;
    for (int i = 0; i < lKota.size();i++)
    {
        std::string s = lKota[i].sNamaKota;
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
    //std::cout << kotaasal << kotatujuan;
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
    int n1, n2;
    n1 = CariIndeksKota(DariKota);
    n2 = CariIndeksKota(KeKota);
    bool KotaKetemu = true;
    if ((n1 >= 0) && (n2 >= 0))
    {
        struct tKotaNext d;
        d.KotaLanjutan = KeKota;
        d.jarak = Jarak;
        lKota[n1].lKotaNext.push_back(d);
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

void JarakTerdekat::InitDjikstra()
{
    for (int i = 0;i < lKota.size();i++)
    {
        lKota[i].TK = 1000000000;
    }
}

void JarakTerdekat::djikstra(std::string sKota, float TK)
{
    int n = CariIndeksKota(sKota);

    if (TK > lKota[n].TK)
    {
        return;
    }

    lKota[n].TK = TK;
    for (int i = 0; i < lKota[n].lKotaNext.size();i++)
    {
        std::string snext = lKota[n].lKotaNext[i].KotaLanjutan;
        float jarak = lKota[n].lKotaNext[i].jarak;
        djikstra(snext, TK + jarak);
    }
}

void JarakTerdekat::CariRute(std::string sKota)
{
    kotalewat[kotai] = sKota;
    kotai++;

    int n = CariIndeksKota(sKota);
    float TK = lKota[n].TK;

    if (TK == 0)
    {
        masukteks();
        masukline();
        return;
    }
    for (int i = 0; i < lKota[n].lKotaNext.size();i++)
    {
        std::string snext = lKota[n].lKotaNext[i].KotaLanjutan;
        int Nnext = CariIndeksKota(snext);
        float TKnext = lKota[Nnext].TK;
        int JarakNext = lKota[n].lKotaNext[i].jarak;
        if (JarakNext + TKnext == TK)
        {
            CariRute(snext);
        }
    }
}

void JarakTerdekat::line(float x1, float y1, float x2, float y2)
{
    sf::VertexArray line2(sf::Lines, 2);
    line2[0].position = sf::Vector2f(x1, y1);
    line2[1].position = sf::Vector2f(x2, y2);
    line2[0].color = sf::Color::Green;
    line2[1].color = sf::Color::Green;
    lineterdekat.push_back(line2);
}

void JarakTerdekat::reset()
{
    totaljarak = 0;
    xteks = 800;
    banyakteks = 0;
    kotai = 0;
    lineterdekat.clear();
}

void JarakTerdekat::masukline()
{
    for (size_t i = 0; i < kotai-1; i++)
    {        
       int nline1 = CariIndeksKota(kotalewat[i]);
       int nline2 = CariIndeksKota(kotalewat[i + 1]);
       int njarak = CariIndeksJarak(kotalewat[i], kotalewat[i + 1]);
       line(lKota[nline1].x, lKota[nline1].y, lKota[nline2].x, lKota[nline2].y);
       if (njarak >= 0)
       {
           totaljarak = totaljarak + jarakkota[njarak].jarakasli1;
       }
    }
    masukteksjarak();
}
   

void JarakTerdekat::masukteks()
{
    if (!font.loadFromFile("Assets/Font/arial.ttf"))
    {
        std::cout << "Font tidak ditemukan\n";
    }
    for (size_t teksi = 0; teksi < kotai; teksi++)
    {
        //std::cout <<" "<< kotalewat[teksi] << xteks <<"\n";
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
    totaljarakfix = std::to_string(totaljarak);
    teksjarak.setFont(font);
    teksjarak.setString(totaljarakfix);
    teksjarak.setPosition({ 800, 75 });
    teksjarak.setCharacterSize(20);
    teksjarak.setFillColor(sf::Color::Black);
}

void JarakTerdekat::drawlineterdekat(sf::RenderWindow& window)
{
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