#include <iostream>
#include <string>
using namespace std;

// mendefinisikan struct buku
struct Buku {
    string judul_buku[5];
    string pengarang[5];
    string penerbit[5];
    int tebal_halaman[5];
    double harga_buku[5];
};

// main program
int main() {
    // mendeklarasikan struct
    Buku buku;

    // mengisi data buku
    for (int i = 0; i < 5; i++) {
        cout << "Masukkan Informasi Buku ke-" << i+1 << ":" << endl;
        cout << "Judul Buku\t: ";
        cin.ignore(); // membersihkan newline character sebelum menggunakan getline
        getline(cin, buku.judul_buku[i]);
        cout << "Pengarang\t: ";
        getline(cin, buku.pengarang[i]);
        cout << "Penerbit\t: ";
        getline(cin, buku.penerbit[i]);
        cout << "Tebal Halaman\t: ";
        cin >> buku.tebal_halaman[i];
        cout << "Harga Buku\t: ";
        cin >> buku.harga_buku[i];
        cout << endl;
    }

    // menampilkan data buku
    for (int i = 0; i < 5; i++) {
        cout << "Informasi Buku " << i+1 << endl;
        cout << "Judul\t\t: " << buku.judul_buku[i] << endl;
        cout << "Pengarang\t: " << buku.pengarang[i] << endl;
        cout << "Penerbit\t: " << buku.penerbit[i] << endl;
        cout << "Tebal Halaman\t: " << buku.tebal_halaman[i] << endl;
        cout << "Harga Buku\t: " << buku.harga_buku[i] << endl << endl;
    }

    return 0;
}
