#include <iostream>
using namespace std;

// Fungsi hitung mundur dari angka yang diinputkan
void countdown(int n) {
    if (n == 0) {
        return;
    }
    cout << n << " ";
    countdown(n - 1);
}

// main program
int main() {
    cout << "Rekursif Langsung: ";
    countdown(5); // 5 merupakan input
    cout << endl;
    return 0;
}