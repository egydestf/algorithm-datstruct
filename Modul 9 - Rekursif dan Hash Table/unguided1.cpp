#include <iostream>
using namespace std;

// Fungsi faktorial
int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

// main program
int main() {
    int num;
    cout << "Masukkan bilangan bulat positif: ";
    cin >> num;

    if (num < 0) {
        cout << "Input harus bilangan bulat positif!"; // error handling
    } else {
        cout << "Faktorial dari " << num << " adalah: " << factorial(num) << endl;
    }

    return 0;
}