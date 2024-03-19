#include <iostream>
using namespace std;

// main program
int main() {
    // deklarasi dan inisialisasi
    char op;
    float num1, num2;
    
    // user diminta memilih operator yg tersedia
    cout << "Masukkan Operator (+, - , *, /) : ";
    cin >> op;

    // user diminta input 2 buah bilangan yg akan dioperasikan
    cout << "\nMasukkan Bilangan ke-1 dan ke-2.\n";
    cin >> num1 >> num2;

    // switch statement
    switch (op)
    {
    case '+': // jika user input '+', maka fungsi penjumlahan berjalan
        cout << "Hasil Penjumlahan Bilangan: ";
        cout << num1 + num2;
        break; // program berhenti
    case '-': // jika user input '-', maka fungsi pengurangan berjalan
        cout << "Hasil Pengurangan Bilangan: ";
        cout << num1 - num2;
        break;
    case '*': // jika user input '*', maka fungsi perkalian berjalan
        cout << "Hasil Perkalian Bilangan: ";
        cout << num1 * num2;
        break;
    case '/': // jika user input '/', maka fungsi pembagian berjalan
        cout << "Hasil Pembagian Bilangan: ";
        cout << num1 / num2;
        break;
    
    /* jika user input selain operator yg tersedia di atas,
    maka akan menampilkan default output di bawah ini */
    default:
        cout << "Error! operator is not correct";
    }

    return 0;
}