#include <iostream>
using namespace std;

// main program
int main() {
    // deklarasi variabel
    int x_size, y_size, z_size;

    // memasukkan jumlah dan ukuran elemen array
    cout << "Masukkan matriks array\t: ";
    cin >> x_size;
    cout << "Masukkan baris array\t: ";
    cin >> y_size;
    cout << "Masukkan kolom array\t: ";
    cin >> z_size;

    // deklarasi Array
    int arr[x_size][y_size][z_size];

    // input elemen
    for (int x=0; x < x_size; x++)
    {
        for (int y=0; y < y_size; y++)
        {
            for (int z=0; z < z_size; z++)
            {
                cout << "Input array[" << x << "] [" << y << "] [" << z <<"] = ";
                cin >> arr[x][y][z];
            }
        }
        cout << endl;
    }

    // output Array
    for (int x = 0; x < x_size; x++)
    {
        for (int y = 0; y < y_size; y++)
        {
            for (int z = 0; z < z_size; z++)
            {
                cout << "Data array[" << x << "] [" << y << "] [" << z << "] = " << arr[x][y][z] << endl;
            }
        }
    }
    cout << endl;

    // tampilan array
    for (int x = 0; x < x_size; x++)
    {
        for (int y = 0; y < y_size; y++)
        {
            for (int z = 0; z < z_size; z++)
            {
                cout << arr[x][y][z] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}