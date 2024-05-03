#include <iostream>
using namespace std;

int main() {
    int n = 10; // Jumlah elemen dalam data array
    int data[n] = { 9, 4, 1, 4, 7, 10, 5, 4, 12, 4}; // Data array
    int cari = 4; // Nilai yang ingin dicari
    bool ketemu = false;
    int i;
    int count = 0; // Variabel untuk menghitung jumlah kemunculan nilai yang dicari

    // Algoritma Sequential Search
    for (i = 0; i < n; i++) {
        if (data[i] == cari) {
            ketemu = true;
            count++; // Tambahkan penghitungan setiap kali nilai yang dicari ditemukan
        }
    }

    cout << "Program Mencari Nilai 4 Menggunakan Algoritma Sequential Search\n" << endl;
    cout << "Data : { 9, 4, 1, 4, 7, 10, 5, 4, 12, 4}" << endl;

    if (ketemu) {
        cout << "\nAngka " << cari << " ditemukan sebanyak " << count << " kali." << endl;
    } else {
        cout << "Angka " << cari << " tidak dapat ditemukan pada data." << endl;
    }
    return 0;
}
