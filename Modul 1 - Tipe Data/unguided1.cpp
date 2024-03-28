#include <iostream> // standard c++ library
using namespace std; // agar tdk perlu 'std::' di setiap cout atau cin

// fungsi untuk luas lingkaran
double luasLingkaran(double phi, int r) {
    return phi * (r*r); // rumus hitung luas lingkaran
}

// fungsi untuk keliling lingkaran
double kelilingLingkaran(double phi, int r) {
    return phi * (r*2); // rumus hitung keliling lingkaran
}

// main program
int main() {
    // inisialisasi
    const double phi = 3.14; // nilai phi konstan tdk bisa diubah
    int r; // jari-jari lingkaran
    
    // input jari-jari lingkaran (cm)
    cout << "Masukkan jari-jari lingkaran: ";
    cin >> r; // pengguna diminta input jari-jari lingkaran

    // variabel untuk memanggil fungsi lingkaran & menyimpan hasil
    double luas = luasLingkaran(phi, r);
    double keliling = kelilingLingkaran(phi, r);

    // output cetak variabel hasil
    cout << "Luas Lingkaran   \t: " << luas << " cm" << endl;
    cout << "Keliling Lingkaran\t: " << keliling << " cm" << endl;

    return 0;
}
