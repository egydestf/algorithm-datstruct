#include <iostream>
using namespace std;

// fungsi insertion sort ascending
void insertionSortAsc(char arr[], int n) {
    int i, j;
    char tmp;

    for (i = 1; i < n; i++) {
        j = i;

        while (j > 0 && arr[j - 1] > arr[j]) {
            tmp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = tmp;
            j--;
        }
    }
}

// fungsi insertion sort descending
void insertionSortDesc(char arr[], int n) {
    int i, j;
    char tmp;

    for (i = 1; i < n; i++) {
        j = i;

        while (j > 0 && arr[j - 1] < arr[j]) {
            tmp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = tmp;
            j--;
        }
    }
}

// fungsi cetak array
void print_array(char a[], int n) {
    for(int i=0; i<n; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
}

// main program
int main() {
    int n;
    cout << "Input (n) = ";
    cin >> n;

    char a[n];

    for  (int i = 0; i < n; ++i) {
        cout << "Karakter ke-" << i+1 << ": ";
        cin >> a[i];
    }

    cout << "\nUrutan karakter sebelum sorting:" << endl;
    print_array(a, n);

    insertionSortAsc(a, n);
    cout << "\nUrutan karakter setelah ascending sort:" << endl;
    print_array(a, n);

    insertionSortDesc(a, n);
    cout << "\nUrutan karakter setelah descending sort:" << endl;
    print_array(a, n);
}
