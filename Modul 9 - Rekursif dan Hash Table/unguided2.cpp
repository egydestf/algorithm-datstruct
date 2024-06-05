#include <iostream>
using namespace std;

int factorialB(int n);

// Fungsi pertama memulai panggilan rekursi tidak langsung
int factorialA(int n) {
    if (n == 0) {  
        return 1;
    } else {  
        return n * factorialB(n - 1);
    }
}

// Fungsi kedua melanjutkan panggilan rekursi tidak langsung
int factorialB(int n) {
    if (n == 0) {  
        return 1;
    } else {  
        return n * factorialA(n - 1);
    }
}

// main program
int main() {
    int num;
    cout << "Masukkan bilangan bulat positif: ";
    cin >> num;

    if (num >= 0) {
        cout << "Faktorial dari " << num << " adalah: " << factorialA(num) << endl;
    } else {
        cout << "Input harus bilangan bulat positif!"; // error handling
    }

    return 0;
}