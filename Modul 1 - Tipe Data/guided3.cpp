#include <iostream>
using namespace std;

// main program
int main() {
    // deklarasi dan inisialisasi isi array
    int nilai[5]; // set 5 sbg jumlah indeks array
    nilai[0] = 23;
    nilai[1] = 50;
    nilai[2] = 34;
    nilai[3] = 78;
    nilai[4] = 90;

    // cetak isi array
    cout << "Isi array pertama\t: " << nilai[0] << endl;
    cout << "Isi array kedua \t: " << nilai[1] << endl;
    cout << "Isi array ketiga\t: " << nilai[2] << endl;
    cout << "Isi array keempat\t: " << nilai[3] << endl;
    cout << "Isi array kelima\t: " << nilai[4] << endl;
    return 0;
}