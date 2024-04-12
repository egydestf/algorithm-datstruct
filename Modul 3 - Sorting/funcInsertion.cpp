#include <iostream>
using namespace std;

void insertion_sort(int arr[], int length) {
    int i, j, tmp;

    for (i = 1; i < length; i++) {
        j = i;

        while (j > 0 && arr[j - 1] > arr[j]) {
            tmp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = tmp;
            j--;
        }// end of while loop
    }// end of for loop
}

void print_array(int a[], int length) {
    for(int i=0; i<length; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
}

// main program
int main() {
    int length = 6;
    int a[length] = {22, 10, 15, 3, 8, 2};

    insertion_sort(a, length);
    print_array(a, length);
}