#include <iostream>
using namespace std;

// fungsi descending selection sorting
void selectSortDesc(float arr[], int n) {
    int pos_max;
    float temp;

    for (int i = 0; i < n - 1; i++) {
        pos_max = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[pos_max]) // pengurutan descending terjadi
                pos_max = j;
        }

        if (pos_max != i) {
            temp = arr[i];
            arr[i] = arr[pos_max];
            arr[pos_max] = temp;
        }
    }
}

// fungsi cetak array
void print_array(float a[], int n) {
    for(int i=0; i<n; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
}

// main program
int main() {
    int n = 5;
    float a[n] = {3.8, 2.9, 3.3, 4.0, 2.4};

    cout << "Nilai IPS mahasiswa sebelum descending selection sorting: " << endl;
    print_array(a, n);

    selectSortDesc(a, n);

    cout << "\nNilai IPS mahasiswa setelah descending selection sorting: " << endl;
    print_array(a, n);

    return 0;
}
