#include <iostream>
#include <string>
using namespace std;

// main program
int main() {
    // inisialisasi
    string kalimat;
    int vokal = 0;

    // input kalimat
    cout << "Masukkan kalimat: ";
    getline(cin, kalimat);

    // hitung jumlah huruf vokal
    for (int i = 0; i < kalimat.length(); i++) {
        if (kalimat[i] == 'a' || kalimat[i] == 'A'
         || kalimat[i] == 'i' || kalimat[i] == 'I' 
         || kalimat[i] == 'u' || kalimat[i] == 'U' 
         || kalimat[i] == 'e' || kalimat[i] == 'E' 
         || kalimat[i] == 'o' || kalimat[i] == 'O') {
            vokal++;
        }
    }

    // tampilkan total huruf vokal
    if (vokal > 0) {
        cout << "Jumlah huruf vokal = " << vokal << endl;
    } else {
        cout << "Huruf vokal tidak ditemukan" << endl;
    }

    return 0;
}