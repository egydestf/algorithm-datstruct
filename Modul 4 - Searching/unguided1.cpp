#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Fungsi Binary Search
bool findChar(string kalimat, char huruf) {
    int n = kalimat.length();
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (kalimat[mid] == huruf) {
            return true;
        } else if (kalimat[mid] < huruf) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return false;
}

// main program
int main() {
    // Inisialisasi
    string kalimat;
    char huruf;

    // Input kalimat dan huruf yang ingin dicari
    cout << "Masukkan kalimat: ";
    getline(cin, kalimat);
    cout << "Masukkan huruf yang ingin dicari: ";
    cin >> huruf;

    // Panggil fungsi untuk mencari huruf pada kalimat
    if (findChar(kalimat, huruf)) {
        cout << "Huruf '" << huruf << "' ditemukan pada kalimat." << endl;
    } else {
        cout << "Huruf '" << huruf << "' tidak ditemukan pada kalimat." << endl;
    }

    return 0;
}
