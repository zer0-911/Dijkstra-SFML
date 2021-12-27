#include "JarakTerdekat.h"

void JarakTerdekat::DataMasuk(std::string NamaKota, float x, float y)
{
    //Menyimpan nama dan koordinat
    indekskota++;
    Kota[indekskota].sNamaKota = NamaKota;
    Kota[indekskota].x = x;
    Kota[indekskota].y = y;
}

int JarakTerdekat::CariIndeksKota(std::string sNamaKota)
{
    //Mencari indeks kota
    int poskota = -1;
    for (int i = 0; i <= indekskota;i++)
    {
        //Jika ketemu maka nilai pos kota berubah
        if (Kota[i].sNamaKota == sNamaKota)
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
        //Kondisi ketika terdapat kesamaan isi dari variabel array masing masing
        if ((jarakkota[i].nama1 == kotaasal) && (jarakkota[i].nama2 == kotatujuan))
        {
            jkotaKetemu = i;
            break;
        }

    }
    return jkotaKetemu;
}

void JarakTerdekat::Hubung(std::string DariKota, std::string KeKota, float Jarak, float jarakasli)
{
    int Kota1, Kota2;
    Kota1 = CariIndeksKota(DariKota);
    Kota2 = CariIndeksKota(KeKota);
    //Menghubungkan kota agar masuk ke array struct jarakkota
    if ((Kota1 >= 0) && (Kota2 >= 0))
    {
        jarakkota[jaraknya].nama1 = DariKota;
        jarakkota[jaraknya].nama2 = KeKota;
        jarakkota[jaraknya].jarakasli1 = jarakasli;
        jarakkota[jaraknya].jarak = Jarak;
        jaraknya++;
    }
}

void JarakTerdekat::InitFungsiDjikstra()
{
    //Memasukkan nilai di array tersebut
    for (int i = 0;i <= indekskota ;i++)
    {
        Kota[i].TitikKota = 1000000000;
        Kota[i].kotaLanjutannyal.clear();
    }
}

void JarakTerdekat::djikstra(std::string kotaSel, float kedekatan, std::string awal, std::string tuju)
{
    std::string KotaTe;
    //Mangisi variabel n dan p dengan hasil pencarian awal dan tujuan dengan isi array struct yang ada
    int n = CariIndeksKota(awal);
    int p = CariIndeksKota(tuju);
    //Kondisi ketika titikKota sudah lebih dari nilai struct titikKota
    if (kedekatan >= Kota[n].TitikKota)
    {
        return;
    }

    Kota[n].TitikKota = kedekatan;
    Kota[n].kotaLanjutannyal = kotaSel;
    //Perulangan dimana saat kota == variabel awal maka akan kota nama2 akan disimpan di KotaTe
    for (int i = 0; i <= jaraknya;i++)
    {
        if (jarakkota[i].nama1 == awal) {
            KotaTe = jarakkota[i].nama2;
            float jarak = jarakkota[i].jarak;
            djikstra(KotaTe + " " + kotaSel, kedekatan + jarak, KotaTe, tuju);
        }
    }
}

void JarakTerdekat::pencarianJalur(int Tujuan)
{
    std::string str = Kota[Tujuan].kotaLanjutannyal;
    std::istringstream ss(str);

    std::string katakata; // untuk memasukkan setiap kata

    while (ss >> katakata)
    {
        // memasukkan kata
        kotalewat[kotai] = katakata;
        kotai++;
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
        int njarak = CariIndeksJarak(kotalewat[i+1], kotalewat[i]);
        line(Kota[nline1].x, Kota[nline1].y, Kota[nline2].x, Kota[nline2].y);
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
    //Membalik 
    for (int teksi = kotai-1; teksi >= 0; teksi--)
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