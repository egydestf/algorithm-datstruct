# <h1 align="center">Laporan Praktikum Modul Array</h1>

<p align="center">Egy Destiar Firmandani (2311110061)</p>

## Dasar Teori

Array atau larik adalah sebuah tipe data bentukan yang terdiri dari sejumlah komponen dengan tipe data yang sama. Array dapat di analogikan sebagai sebuah loker yang memiliki sederetan kotak penyimpanan yang diberi nomor berurutan. Data-data dalam array disebut dengan elemen array [1]. Setiap elemen array tersebut dapat diakses langsung melalui indeksnya.

### 1. Array Satu Dimensi

Array satu dimensi adalah sekumpulan elemen yang identik dan tersusun dalam satu baris. Elemen tersebut memiliki tipe data yang sama, tetapi isi dari elemen tersebut bisa berbeda [2]. Array satu dimensi dapat diakses melalui indeks yang berurutan. Array saty dimensi dapat digunakan untuk menyimpan dan mengelola data yang bertipe sama dan berurutan [3]. Contoh penggunaan array satu dimensi adalah untuk menyimpan deret angka, menyimpan nilai-nilai yang sama, dan menyimpan data yang berurutan [3].

#### Contoh Program:

```C++
#include <iostream>
using namespace std;

int main() {
    // deklarasi array 
    int arr[5] {9, 3, 5, 2, 1};

    // cetak isi array
    cout << arr[1] << endl;
    cout << arr[4];
}
```

### 2. Array Dua Dimensi

Array dua dimensi adalah sekumpulan elemen yang terdiri dari baris dan kolom. Setiap elemen dalam array dua dimensi memiliki tipe data yang sama, tetapi isi dari elemen tersebut bisa berbeda. Array dua dimensi dapat diakses melalui indeks yang berurutan. Array dua dimensi dapat digunakan untuk menyimpan dan mengelola data yang bertipe sama dan berurutan. Contoh penggunaan array dua dimensi adalah untuk menyimpan deret angka, menyimpan nilai-nilai yang sama, dan menyimpan data yang berurutan.

#### Contoh Program:

```C++
#include <iostream>
using namespace std;

int main() {
    int arr[2][2] = {{3, 2}, {2, 5}};
    for (int i=0; i<2; i++) {
        for(int j=0; j<2; j++) {
            cout << arr[i][j] << ends;
        };
        cout << endl;
    };
}
```

### 3. Array Multidimensi

Array multidimensi adalah sekumpulan elemen yang terdiri dari lebih dari satu dimensi. Contohnya adalah array dua dimensi, yang terdiri dari baris dan kolom, atau array tiga dimensi, yang terdiri dari baris, kolom, dan lapisan. Array multidimensi dapat digunakan untuk menyimpan data yang lebih kompleks, seperti tabel dengan data yang berurutan. Array multidimensi dapat digunakan untuk menyimpan dan mengelola data yang bertipe sama dan berurutan. Contoh penggunaan array multidimensi adalah untuk menyimpan deret angka, menyimpan nilai-nilai yang sama, dan menyimpan data yang berurutan.

#### Contoh Program:

```C++
#include <iostream>
using namespace std;

int main() {
    int arr[2][2][3] = {{{2, 8, 7}, {6, 5, 1}},
    {{8, 5, 2}, {9, 2, 7}}};
    for (int i=0; i<2; i++) {
        for(int j=0; j<2; j++) {
            for(int k=0; k<3; k++) {
                cout<< arr[i][j][k] << ends;
            };
            cout<< endl;
        };
        cout<< endl;
    };
}
```

## Guided 

### 1. Guided 1
#### Program Input Array Tiga Dimensi

```C++
#include <iostream>
using namespace std;

int main() {
    // deklarasi array
    int arr[2][3][3];

    // input elemen
    for (int x = 0; x < 2; x++) {
        for (int y = 0; y < 3; y++) {
            for (int z = 0; z < 3; z++) {
                cout << "Input Array[" << x << "][" << y << "][" << z << "] = ";
                cin >> arr[x][y][z];
            }
        }
        cout << endl;
    }

    // output array 
    for (int x = 0; x < 2; x++) {
        for (int y = 0; y < 3; y++) {
            for (int z = 0; z < 3; z++) {
                cout << "Data Array[" << x << "][" << y << "][" << z << "] = " << arr[x][y][z] << endl;
            }
        }
    }
    cout << endl;

    // tampilan array
    for (int x = 0; x < 2; x++) {
        for (int y = 0; y < 3; y++) {
            for (int z = 0; z < 3; z++) {
                cout << arr[x][y][z] << ' ';
            }
            cout << endl;
        }
        cout << endl;
    }
}
```
Program di atas adalah program input array tiga dimensi.

Program dimulai dengan mendeklarasikan array dengan jumlah bilangan tertentu agar menjadi array tiga dimensi. Bilangan pertama / `2` menunjukkan jumlah matriks, bilangan kedua / `3` menunjukkan jumlah baris, dan bilangan terakhir / `3` menunjukkan jumlah kolom. Lalu program meminta user untuk memasukkan jumlah elemen pada tiap indeks yang diminta program dan akan dilakukan perulangan for loop. Terakhir array akan menampilkan output sesuai dengan susunan elemen yang diinput user pada baris sebelumnya dan akan terus berulang sampai indeks bilangan terakhir.

### 2. Guided 2
#### Program Mencari Nilai Maksimal pada Array

```C++
#include <iostream>
using namespace std;

int main() {
    // deklarasi array dan membuat variabel
    int maks, a, i = 1, lokasi;

    // input panjang array
    cout << "Masukkan panjang array: ";
    cin >> a;

    // untuk mengindikasi error
    if (a <= 0) {
        cout << "Panjang array harus lebih dari 0!" << endl;
        return 1; // return 1 untuk mengindikasi error
    }

    // input nilai tiap indeks array
    int array[a]; // inisialisasi array
    cout << "Masukkan " << a << " angka\n";

    // perulangan untuk tiap indeks array
    for (int i = 0; i < a; i++) {
        cout << "Array ke-" << (i + 1) << ": ";
        cin >> array[i];
    }

    // variabel untuk menyimpan nilai array maksimun 
    maks = array[0];
    lokasi = 0; // untuk letak nilai array maksimun

    // perulangan untuk menemukan letak nilai maksimun 
    for (int i = 1; i < a; i++) {
        if (array[i] > maks) {
            maks = array[i];
            lokasi = i;
        }
    }

    // output hasil program
    cout << "Nilai maksimum adalah " << maks << " berada di Array ke-" << (lokasi + 1) << endl;

    return 0; // return 0 untuk mengindikasi program berhasil
}
```
Program di atas adalah program untuk mencari nilai maksimal pada array.

Program dimulai dengan mendeklarasikan array dan membuat variabel. Array dideklarasikan dengan variabel `a` untuk panjang array dan `i = 1` untuk isi array nantinya. Kemudian user diminta untuk menginput panjang array melalui inputan variabel `a`. Untuk mengindikasi error saat input panjang array kurang dari sama dengan 0, maka dibuatlah if statement pada variabel `a`. Lalu, program akan meminta input pada tiap indeks array sesuai dengan panjang array. Fungsi for looping akan mengulangi inputan indeks pada tiap array dan akan disimpan pada variabel `i`. Variabel `maks` untuk menyimpan nilai array maksimun dan variabel `lokasi` untuk letak nilai array maksimun pada indeks array. Terakhir program akan melakukan perulangan kembali dengan for loop untuk menemukan letak nilai maksimun pada array.

## Unguided 

### 1. Buatlah program untuk menampilkan Output seperti berikut dengan data yang diinputkan oleh user!

#### Program: 
```C++
#include <iostream>
#include <vector>
using namespace std;

// main program
int main() {
    // deklarasi variabel ukuran maksimun dan array
    const int maxSize = 100; // maks panjang array 100
    int arr[maxSize];
    int size;

    // meminta user untuk input ukuran array
    cout << "Masukkan ukuran array (maksimal " << maxSize << "): ";
    cin >> size;

    // memastikan ukuran yang dimasukkan oleh user tidak melebihi batas maksimum
    if (size > maxSize) {
        cout << "Ukuran array melebihi batas maksimum. Silakan coba lagi." << endl;
        return 1;
    }

    // meminta user untuk input nilai-nilai ke dalam array
    cout << "Masukkan " << size << " buah nilai array!" << endl;
    for (int i = 0; i < size; ++i) {
        cout << "Nilai array ke-" << i+1 << ": ";
        cin >> arr[i];
    }

    // menampilkan nilai-nilai yang dimasukkan oleh pengguna
    cout << "Data array\t: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // memisahkan nilai ganjil dan genap
    vector<int> ganjil;
    vector<int> genap;
    for (int i = 0; i < size; ++i) {
        if (arr[i] % 2 == 0) {
            genap.push_back(arr[i]);
        } else {
            ganjil.push_back(arr[i]);
        }
    }

    // menampilkan nilai genap
    cout << "Nomor genap\t: ";
    for (int i = 0; i < genap.size(); ++i) {
        cout << genap[i] << " ";
    }
    cout << endl;

    // menampilkan nilai ganjil
    cout << "Nomor ganjil\t: ";
    for (int i = 0; i < ganjil.size(); ++i) {
        cout << ganjil[i] << " ";
    }
    cout << endl;

    return 0;
}
```
#### Output:
![Screenshot 2024-03-28 212144](https://github.com/egydestf/algorithm-datstruct/assets/152776726/5ca09a5f-010d-42f9-9422-a69eb720b8ad)

Program dimulai dengan mendeklarasikan variabel ukuran dan variabel untuk menampung array. Variabel ukuran atau `maxSize` adalah variabel untuk membatasi user dalam menginput ukuran panjang array. Kemudian program meminta input dari user untuk ukuran array. Untuk memastikan bahwa ukuran panjang array yang dimasukkan user tidak melebihi 100, program menampilkan if statement dan akan return 1 jika if tersebut bernilai `True`. Lalu program akan menampilkan data array yang sudah diinput user.

Selanjutnya program akan melakukan pemisahan antara nilai bilangan genap dan nilai bilangan ganjil dalam array tersebut. Array dipisahkan menggunakan variabel `genap` dan variabel `ganjil` yang dideklarasikan melalui fungsi `<vector>`. Fungsi `<vector>` sendiri diperoleh dari pemanggilan library `#include <vector>`. Kemudian fungsi `push_back` akan melakukan if statement untuk memisahkan nilai bilangan genap dan nilai bilangan ganjil dalam array. Terakhir program akan menampilkan data array yang telah dipisahkan antara bilangan genap dan bilangan ganjil dalam array tersebut.

#### Full Code Screenshot
![Screenshot 2024-03-28 220454](https://github.com/egydestf/algorithm-datstruct/assets/152776726/cb2f4a3c-bfa9-4e27-bae9-f46cfc46cbeb)

### 2. Buatlah program Input array tiga dimensi (seperti pada guided) tetapi jumlah atau ukuran elemennya diinputkan oleh user!

#### Program: 
```C++
#include <iostream>
using namespace std;

// main program
int main() {
    // Deklarasi variabel
    int x_size, y_size, z_size;

    // Memasukkan jumlah dan ukuran elemen array
    cout << "Masukkan matriks array\t: ";
    cin >> x_size;
    cout << "Masukkan baris array\t: ";
    cin >> y_size;
    cout << "Masukkan kolom array\t: ";
    cin >> z_size;

    // Deklarasi Array
    int arr[x_size][y_size][z_size];

    // Input elemen
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

    // Output Array
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

    //Tampilan array
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
```
#### Output:
![Screenshot 2024-03-28 212518](https://github.com/egydestf/algorithm-datstruct/assets/152776726/1fc181b5-76a1-4b7e-b3ef-9c3378461ac4)
![Screenshot 2024-03-28 212538](https://github.com/egydestf/algorithm-datstruct/assets/152776726/77a265da-ea30-478b-94f2-20534ac6823b)

Program di atas adalah program input array tiga dimensi dengan ukuran elemen yang diinputkan oleh user.

Program dimulai dengan mendeklarasikan variabel untuk menampung input dari user. Variabel `x_size` untuk menampung ukuran matriks array, variabel `y_size` untuk menampung ukuran baris array, dan variabel `z_size` untuk menampung ukuran kolom array. Kemudian program meminta user untuk menginput bilangan `integer` untuk isian pada variabel yang dideklarasikan sebelumnya. Setelah variabel semua variabel tersebut terisi, barulah array bisa dideklarasikan.

Selanjutnya program meminta user untuk memasukkan jumlah elemen pada tiap indeks yang diminta program dan akan dilakukan perulangan for loop. Terakhir array akan menampilkan output sesuai dengan susunan elemen yang diinput user pada baris sebelumnya dan akan terus berulang sampai indeks bilangan terakhir.

#### Full Code Screenshot:
![Screenshot 2024-03-28 220609](https://github.com/egydestf/algorithm-datstruct/assets/152776726/c4dd5ed0-40f8-4da6-953c-6bf44a4b7aba)

### 3. Buatlah program menu untuk mencari nilai Maksimum, Minimum dan Nilai rata – rata dari suatu array dengan input yang dimasukan oleh user!

#### Program: 
```C++
#include <iostream>
using namespace std;

// fungsi untuk mencari nilai maksimum
int findMax(const int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// fungsi untuk mencari nilai minimum
int findMin(const int arr[], int size) {
    int min = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

// fungsi untuk menghitung nilai rata-rata
double findAverage(const int arr[], int size) {
    double sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return sum / size;
}

// main program
int main() {
    // deklarasi variabel input ukuran
    int size;

    // input ukuran array
    cout << "Masukkan ukuran array: ";
    cin >> size;

    // deklarasi array dengan input
    int arr[size];

    // input nilai tiap indeks array
    cout << "Masukkan elemen-elemen array:\n";
    for (int i = 0; i < size; ++i) {
        cout << "Elemen ke-" << i + 1 << ": ";
        cin >> arr[i];
    }

    // cetak array hasil input
    cout << "Data array anda: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // deklarasi variabel input switch case
    int choice;

    // output menu
    cout << "Pilih operasi yang ingin dilakukan:\n";
    cout << "1. Cari nilai maksimum\n";
    cout << "2. Cari nilai minimum\n";
    cout << "3. Cari nilai rata-rata\n";
    cout << "Masukkan pilihan\t: ";
    cin >> choice; // input pilihan

    // switch case menu
    switch (choice) {
        case 1: // untuk nilai maksimun
            cout << "Nilai maksimum\t: " << findMax(arr, size) << endl;
            break;
        case 2: // untuk nilai minimun
            cout << "Nilai minimum\t: " << findMin(arr, size) << endl;
            break;
        case 3: // untuk nilai rata-rata
            cout << "Nilai rata-rata\t: " << findAverage(arr, size) << endl;
            break;
        default: // jika tidak memenuhi ketiga pilihan diatas
            cout << "Pilihan tidak valid." << endl;
    }

    return 0;
}
```
#### Output:
![Screenshot 2024-03-28 213033](https://github.com/egydestf/algorithm-datstruct/assets/152776726/1de5688f-bdda-41fa-95f6-423cfa86e8a9)
![Screenshot 2024-03-28 213054](https://github.com/egydestf/algorithm-datstruct/assets/152776726/7b8c03b2-a391-4dd5-ac12-936b8cac191d)
![Screenshot 2024-03-28 213130](https://github.com/egydestf/algorithm-datstruct/assets/152776726/e8011cef-5031-4fd9-9f9f-02f8f95e8c4a)

Program di atas adalah program menu untuk mencari nilai Maksimum, Minimum dan Nilai rata – rata dari suatu array dengan input user.

Program dimulai dengan membuat fungsi untuk mencari nilai Maksimum, Minimum dan Nilai rata – rata. Fungsi `findMax` untuk mencari nilai maksimun array, fungsi `findMin` untuk mencari nilai minimum array, dan fungsi `findAverage` untuk mencari nilai rata-rata array. 

Pada main program, variabel `size` dideklarasikan untuk menampung input ukuran array. Lalu program akan meminta input ukuran array dalam variabel `size`. Sebelum input nilai pada tiap indeks array, array dideklarasikan dengan memasukkan variabel `size`. Barulah program akan meminta input user untuk memasukkan nilai pada tiap indeks array sesuai panjang ukuran array. Setelah nilai tiap indeks terinput, program akan mencetak data array yang telah diinput user.

Masuk ke switch case menu, variabel `choice` dideklarasikan sebagai input pilihan menu user. Case `1` berisi fungsi `findMax` yang akan mencari nilai maksimun array, case `2` berisi fungsi `findMin` yang akan mencari nilai minimum array, dan case `3` berisi fungsi `findAverage` yang akan mencari nilai rata-rata array. Tiap case akan terpilih jika input pada variabel `choice` memenuhi case yang ditentukan. Apabila tidak memenuhi case yang ditentukan, case akan menjadi default case. 

#### Full Code Screenshot:
![Screenshot 2024-03-28 220731](https://github.com/egydestf/algorithm-datstruct/assets/152776726/159a14d7-9be3-43aa-a58c-65dfc5949494)

## Kesimpulan

Praktikum Modul 2 Array ini membahas pengenalan array yang ada pada program C++ meliputi array satu dimensi, array dua dimensi, dan array multidimensi. Array satu dimensi adalah sekumpulan elemen yang identik dan tersusun dalam satu baris. Array dua dimensi adalah sekumpulan elemen yang terdiri dari baris dan kolom. Sedangkan array multidimensi adalah sekumpulan elemen yang terdiri dari lebih dari satu dimensi.

## Referensi
[1] A. Arraffi, "Tipe Data Larik (Array)," OSF Preprints, 2019.

[2] M. Nasrul Choirudin. Array 1 dan 2 Dimensi. diakses dari https://laskar21.blogspot.com/2016/09/pengertian-array-1-dimensi-dan-2-dimensi.html?m=1

[3] Polinema Programming. Array 1 Dasar Pemrograman. diakses dari https://polinema-programming.github.io/11/jobsheet11.html 
