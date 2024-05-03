#include <iostream>
#include <string>
using namespace std;

struct Hewan {
    string Nama_hewan;
    string Jenis_kelamin;
    string cara_berkembangbiak;
    string alat_bernafas ;
    string tempat_hidup;
    bool karnivora;
};

struct Hewan_darat{
    int jumlah_kaki;
    bool apakah_menyusui;
    string suara;
    Hewan info_hewan ;

}; Hewan_darat hewan1;

struct Hewan_laut{
    string Bentuk_sirip;
    string Pertahanan_diri;
    Hewan info_hewan;
}; Hewan_laut hewan2;

// main program
int main(){
    hewan1.info_hewan.Nama_hewan = "Kucing";
    hewan1.info_hewan.Jenis_kelamin = "Betina";
    hewan1.info_hewan.cara_berkembangbiak = "Melahirkan";
    hewan1.info_hewan.alat_bernafas = "Paru-paru";
    hewan1.info_hewan.tempat_hidup = "Daratan";
    hewan1.info_hewan.karnivora = false;
    hewan1.jumlah_kaki = 4;
    hewan1.apakah_menyusui = true;
    hewan1.suara = "Meow";

    hewan2.info_hewan.Nama_hewan = "Penyu";
    hewan2.info_hewan.Jenis_kelamin = "Betina";
    hewan2.info_hewan.cara_berkembangbiak = "Bertelur";
    hewan2.info_hewan.alat_bernafas = "Paru-paru dan insang";
    hewan2.info_hewan.tempat_hidup = "Lautan";
    hewan2.info_hewan.karnivora = false;
    hewan2.Bentuk_sirip = "Sirip dan ekor";
    hewan2.Pertahanan_diri = "Cangkang yang kuat";

    cout << "\t Hewan Darat :" << endl;
    cout << "Nama Hewan : " << hewan1.info_hewan.Nama_hewan << endl;
    cout << "Jenis Kelamin : " << hewan1.info_hewan.Jenis_kelamin << endl;
    cout << "Cara Berkembangbiak : " << hewan1.info_hewan.cara_berkembangbiak << endl;
    cout << "Pernapasan : " << hewan1.info_hewan.alat_bernafas << endl;
    cout << "Tempat Hidup : " << hewan1.info_hewan.tempat_hidup << endl;
    cout << "Apakah Karnivora? : " << hewan1.info_hewan.karnivora << endl;
    cout << "Jumlah Kaki : " << hewan1.jumlah_kaki << endl;
    cout << "Apakah Menyusui? : " << hewan1.apakah_menyusui << endl;
    cout << "Suara : " << hewan1.suara << endl << endl;

    cout << "\t Hewan Laut :" << endl;  
    cout << "Nama Hewan : " << hewan2.info_hewan.Nama_hewan << endl;
    cout << "Jenis Kelamin : " << hewan2.info_hewan.Jenis_kelamin << endl;
    cout << "Cara Berkembangbiak : " << hewan2.info_hewan.cara_berkembangbiak << endl;
    cout << "Pernapasan : " << hewan2.info_hewan.alat_bernafas << endl;
    cout << "Tempat Hidup : " << hewan2.info_hewan.tempat_hidup << endl;
    cout << "Apakah Karnivora? : " << hewan2.info_hewan.karnivora << endl;
    cout << "Bentuk Sirip : " << hewan2.Bentuk_sirip << endl;

    return 0;
}