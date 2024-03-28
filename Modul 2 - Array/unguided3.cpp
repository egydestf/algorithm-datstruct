#include <iostream>
using namespace std;

// fungsi untuk mencari nilai maksimum
int findMax(const int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// fungsi untuk mencari nilai minimum
int findMin(const int arr[], int size) {
    int min = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

// fungsi untuk menghitung nilai rata-rata
double findAverage(const int arr[], int size) {
    double sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return sum / size;
}

// main program
int main() {
    // deklarasi variabel input ukuran
    int size;

    // input ukuran array
    cout << "Masukkan ukuran array: ";
    cin >> size;

    // deklarasi array dengan input
    int arr[size];

    // input nilai tiap indeks array
    cout << "Masukkan elemen-elemen array:\n";
    for (int i = 0; i < size; ++i) {
        cout << "Elemen ke-" << i + 1 << ": ";
        cin >> arr[i];
    }

    // cetak array hasil input
    cout << "Data array anda: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // deklarasi variabel input switch case
    int choice;

    // output menu
    cout << "Pilih operasi yang ingin dilakukan:\n";
    cout << "1. Cari nilai maksimum\n";
    cout << "2. Cari nilai minimum\n";
    cout << "3. Cari nilai rata-rata\n";
    cout << "Masukkan pilihan\t: ";
    cin >> choice; // input pilihan

    // switch case menu
    switch (choice) {
        case 1: // untuk nilai maksimun
            cout << "Nilai maksimum\t: " << findMax(arr, size) << endl;
            break;
        case 2: // untuk nilai minimun
            cout << "Nilai minimum\t: " << findMin(arr, size) << endl;
            break;
        case 3: // untuk nilai rata-rata
            cout << "Nilai rata-rata\t: " << findAverage(arr, size) << endl;
            break;
        default: // jika tidak memenuhi ketiga pilihan diatas
            cout << "Pilihan tidak valid." << endl;
    }

    return 0;
}