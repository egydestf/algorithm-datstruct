#include <iostream>
using namespace std;

int main() {
    // deklarasi array
    int maks, a, i = 1, lokasi;

    // input panjang array
    cout << "Masukkan panjang array: ";
    cin >> a;

    // untuk mengindikasi error
    if (a <= 0) {
        cout << "Panjang array harus lebih dari 0!" << endl;
        return 1; // return 1 untuk mengindikasi error
    }

    // input nilai tiap indeks array
    int array[a];
    cout << "Masukkan " << a << " angka\n";

    // perulangan untuk tiap indeks array
    for (int i = 0; i < a; i++) {
        cout << "Array ke-" << (i + 1) << ": ";
        cin >> array[i];
    }

    // variabel untuk menyimpan nilai array maksimun 
    maks = array[0];
    lokasi = 0; // untuk letak nilai array maksimun

    // perulangan untuk menemukan letak nilai maksimun 
    for (int i = 1; i < a; i++) {
        if (array[i] > maks) {
            maks = array[i];
            lokasi = i;
        }
    }

    // output hasil program
    cout << "Nilai maksimum adalah " << maks << " berada di Array ke-" << (lokasi + 1) << endl;

    return 0; // return 0 untuk mengindikasi program berhasil
}
