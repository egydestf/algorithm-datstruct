#include <iostream>
#include <string>
using namespace std;

// fungsi cek palindrom
bool isPolindrom(string str) {
    int start = 0;
    int end = str.length() - 1;

    while (start < end) {
        if (str[start] != str[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

// main program
int main() {
    string input;
    cout << "Masukkan Kalimat : ";
    getline(cin, input);
    if (isPolindrom(input)) {
        cout << "Kalimat tersebut adalah Palindrom." << endl;
    } else {
        cout << "Kalimat tersebut bukan Palindrom." << endl;
    }
    return 0;
}
