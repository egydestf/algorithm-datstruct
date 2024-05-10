#include <iostream>
#include <string>
using namespace std;

// mendefinisikan struct buku
struct Buku {
    string judul_buku;
    string pengarang;
    string penerbit;
    int tebal_buku;
    double harga_buku;
}; Buku buku1; Buku buku2;

// main program
int main() {
    // mengisi data buku 1
    buku1.judul_buku = "Algoritma Pemrograman";
    buku1.pengarang = "Raden Wardana";
    buku1.penerbit = "Gramedia Pustaka";
    buku1.tebal_buku = 300;
    buku1.harga_buku = 120000;

    // mengisi data buku 2
    buku2.judul_buku = "Kalkulus 2";
    buku2.pengarang = "Ajeng Kusuma Ayu";
    buku2.penerbit = "Erlangga";
    buku2.tebal_buku = 400;
    buku2.harga_buku = 150000;

    // menampilkan data buku 1
    cout << "Informasi Buku 1" << endl;
    cout << "Judul\t\t: " << buku1.judul_buku << endl;
    cout << "Pengarang\t: " << buku1.pengarang << endl;
    cout << "Penerbit\t: " << buku1.penerbit << endl;
    cout << "Tebal Halaman\t: " << buku1.tebal_buku << endl;
    cout << "Harga Buku\t: " << buku1.harga_buku << endl << endl;

    // menampilkan data buku 2
    cout << "Informasi Buku 2" << endl;
    cout << "Judul\t\t: " << buku2.judul_buku << endl;
    cout << "Pengarang\t: " << buku2.pengarang << endl;
    cout << "Penerbit\t: " << buku2.penerbit << endl;
    cout << "Tebal Halaman\t: " << buku2.tebal_buku << endl;
    cout << "Harga Buku\t: " << buku2.harga_buku << endl;

    return 0;
}
