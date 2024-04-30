#include <iostream>
#include <string>
using namespace std;

// fungsi bubble sorting
void bubbleSort(string arr[], int n) {
    bool not_sorted = true;
    int j=0;
    string tmp;

    while (not_sorted) {
        not_sorted = false;
        j++;

        for (int i = 0; i < n - j; i++) {
            if (arr[i] > arr[i + 1]) {
                tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                not_sorted = true;
            }
        }
    }
}

// fungsi cetak array
void print_array(string a[], int n) {
    for(int i=0; i<n; i++) {
        cout << a[i] << "   ";
    }
    cout << endl;
}

// main program
int main() {
    int n = 10;
    string a[n] = {"Siti", "Situ", "Sana", "Ana", "Ani",
    "Caca", "Cici", "Dida", "Dodo", "Dadi"};

    cout << "Nama 10 warga Pak RT sebelum diurutkan: " << endl;
    print_array(a, n);

    bubbleSort(a, n);

    cout << "\nNama 10 warga Pak RT setelah diurutkan: " << endl;
    print_array(a, n);

    return 0;
}
