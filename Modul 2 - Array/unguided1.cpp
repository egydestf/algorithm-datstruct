#include <iostream>
#include <vector>
using namespace std;

// main program
int main() {
    // deklarasi variabel ukuran maksimun dan array
    const int maxSize = 100;
    int arr[maxSize];
    int size;

    // meminta user untuk input ukuran array
    cout << "Masukkan ukuran array (maksimal " << maxSize << "): ";
    cin >> size;

    // memastikan ukuran yang dimasukkan oleh user tidak melebihi batas maksimum
    if (size > maxSize) {
        cout << "Ukuran array melebihi batas maksimum. Silakan coba lagi." << endl;
        return 1;
    }

    // meminta user untuk input nilai-nilai ke dalam array
    cout << "Masukkan " << size << " buah nilai array!" << endl;
    for (int i = 0; i < size; ++i) {
        cout << "Nilai array ke-" << i+1 << ": ";
        cin >> arr[i];
    }

    // menampilkan nilai-nilai yang dimasukkan oleh pengguna
    cout << "Data array\t: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // memisahkan nilai ganjil dan genap
    vector<int> ganjil;
    vector<int> genap;
    for (int i = 0; i < size; ++i) {
        if (arr[i] % 2 == 0) {
            genap.push_back(arr[i]);
        } else {
            ganjil.push_back(arr[i]);
        }
    }

    // menampilkan nilai genap
    cout << "Nomor genap\t: ";
    for (int i = 0; i < genap.size(); ++i) {
        cout << genap[i] << " ";
    }
    cout << endl;

    // menampilkan nilai ganjil
    cout << "Nomor ganjil\t: ";
    for (int i = 0; i < ganjil.size(); ++i) {
        cout << ganjil[i] << " ";
    }
    cout << endl;

    return 0;
}
