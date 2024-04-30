# <h1 align="center">Laporan Praktikum Modul Searching</h1>

<p align="center">Egy Destiar Firmandani</p>
<p align="center">2311110061</p>

## Dasar Teori

Algoritma pencarian (searching) adalah prosedur langkah demi langkah pada sebuah program yang digunakan untuk menemukan data tertentu dalam kumpulan data[1]. Algoritma ini bekerja untuk mengambil informasi yang disimpan dalam struktur data tertentu, atau dihitung dalam ruang pencarian domain masalah, baik dengan nilai diskrit atau kontinu. Algoritma pencarian dapat dianggap sebagai metode mendasar dalam operasi komputasi. Ketika sebuah sistem mencari data, perbedaan antara aplikasi yang cepat dan yang lebih lambat seringkali terletak pada penggunaan algoritma pencarian yang tepat[2]. Terdapat dua jenis algoritma pencarian yang umum digunakan, yaitu Sequential (Linear) Search dan Binary Search.

### 1. Sequential Search

Algoritma Sequential atau Linear Searching ini memeriksa setiap elemen dari daftar array data satu per satu hingga ditemukan kecocokan. Sequential cocok untuk mencari data dalam daftar yang tidak berurutan. Namun, untuk data yang didistribusikan secara acak, rata-rata kasus memerlukan pembandingan sebanyak N/2. Algoritma ini cocok untuk array kecil atau data yang tidak terurut.

Contoh program fungsi Sequential Search dalam C++.
```C++
int sequentialSearch(int array[], int arraySize, int element) {
    for (int i = 0; i < arraySize; i++) {
        if (array[i] == element) {
            return i;
        }
    }
    return -1;
}
```

### 2. Binary Search

Algoritma Binary bekerja dengan cara membagi interval pencarian menjadi dua bagian. Jika nilai kunci pencarian lebih kecil dari nilai tengah interval, pencarian dilanjutkan ke bagian kanan; jika lebih besar, ke bagian kiri. Binary Search efisien untuk data yang terurut dan memiliki kompleksitas waktu O(log n), membuatnya lebih cepat daripada Sequential Search untuk dataset besar.

Contoh program fungsi Binary Search dalam C++.
```C++
int binarySearch(int array[], int arraySize, int element) {
    int start = 0;
    int end = arraySize - 1;
    int middle;

    while (start <= end) {
        middle = (start + end) / 2;
        if (array[middle] == element) {
            return middle;
        } else if (array[middle] < element) {
            start = middle + 1;
        } else {
            end = middle - 1;
        }
    }
    return -1;
}
```

## Guided 

### 1. Guided 1
<b>Buatlah sebuah project dengan menggunakan sequential search sederhana untuk melakukan pencarian data!</b>

```C++
#include <iostream>
using namespace std;

//main program
int main(){
    int n = 10; // corrected the value of n to 11 to match the number of elements in the data array
    int data[n] = {9, 4, 1, 7, 5, 12, 4, 13, 4, 10}; // added the last occurence of the number 10
    int cari = 10;
    bool ketemu = false;
    int i;

    // Algoritma Sequential Search
    for (i = 0; i < n; i++){
        if (data[i] == cari){
            ketemu = true;
            break;
        }
    }

    cout << "\t Program Sequential Search Sederhana\n" << endl;
    cout << "data : {9, 4, 1, 7, 5, 12, 4, 13, 4, 10}" << endl;

    if (ketemu){
        cout << "\n angka " << cari << " ditemukan pada indeks ke-" << i << endl;
    } else{
        cout << cari << " tidak dapat ditemukan pada data" << endl;
    }

    return 0;
}
```
Program di atas adalah program untuk melakukan pencarian data dengan sequential search.

Pada main program, program ini menginisialisasi nilai `n` dengan nilai 10, yang menunjukkan jumlah elemen dalam array data. Kemudian, array `data` diinisialisasi dengan nilai-nilai berikut: {9, 4, 1, 7, 5, 12, 4, 13, 4, 10}. Program ini juga menginisialisasi variabel `cari` dengan nilai 10, yang menunjukkan nilai yang akan dicari dalam array `data`. Selain itu, program ini menginisialisasi flag `ketemu` dengan nilai `false`, yang digunakan untuk menandakan apakah nilai `cari` ditemukan dalam array `data` atau tidak.

Program ini menggunakan algoritma Sequential Search untuk mencari nilai `cari` dalam array `data`. Algoritma ini bekerja dengan cara mengulangi proses berikut:
1. Mulai dari indeks pertama dari array `data`, yaitu indeks 0.
2. Periksa apakah nilai pada indeks tersebut sama dengan nilai `cari`.
3. Jika nilai pada indeks tersebut sama dengan nilai `cari`, maka program akan mengubah nilai flag `ketemu` menjadi `true` dan menghentikan proses pencarian.
4. Jika nilai pada indeks tersebut tidak sama dengan nilai `cari`, maka program akan melanjutkan proses pencarian ke indeks berikutnya.

Setelah proses pencarian selesai, program akan menampilkan hasil sebagai berikut:
- Jika nilai `cari` ditemukan dalam array `data`, maka program akan menampilkan pesan "angka `cari` ditemukan pada indeks ke-`i`", di mana `i` adalah indeks terakhir di mana nilai `cari` ditemukan.
- Jika nilai `cari` tidak ditemukan dalam array `data`, maka program akan menampilkan pesan "cari tidak dapat ditemukan pada data".

Dalam contoh latihan program ini, nilai `cari` adalah 10, yang ditemukan pada indeks ke-9 dalam array `data`. Oleh karena itu, program akan menampilkan pesan "angka 10 ditemukan pada indeks ke-9".

### 2. Guided 2
<b>Buatlah sebuah project untuk melakukan pencarian data dengan menggunakan Binary Search!</b>

```C++
#include <iostream>
#include <iomanip>

using namespace std;

int bil_data[7] = {1, 8, 2, 5, 4, 9, 7};
int cari;

void selection_sort() {
    int temp, min, i, j;
    for(i = 0; i < 7; i++) {
        min = i;
        for(j = i + 1; j < 7; j++) {
            if(bil_data[j] < bil_data[min]) {
                min = j;
            }
        }
        temp = bil_data[i];
        bil_data[i] = bil_data[min];
        bil_data[min] = temp;
    }
}

void binary_search() {
    int awal, akhir, tengah, b_flag = 0;
    awal = 0;
    akhir = 6;
    while (b_flag == 0 && awal <= akhir) {
        tengah = (awal + akhir) / 2;
        if(bil_data[tengah] == cari) {
            b_flag = 1;
            break;
        } else if(bil_data[tengah] < cari) {
            awal = tengah + 1;
        } else {
            akhir = tengah - 1;
        }
    }
    if(b_flag == 1) {
        cout << "\n Data ditemukan pada index ke-" << tengah << endl;
    } else {
        cout << "\n Data tidak ditemukan\n";
    }
}

// main program
int main() {
    cout << "\t BINARY SEARCH\n";
    cout << "\n Data : ";
    
    // tampilkan data awal
    for(int x = 0; x < 7; x++) {
        cout << setw(3) << bil_data[x];
    }

    cout << endl;
    cout << "\n Masukkan data yang ingin Anda cari : ";
    cin >> cari;
    cout << "\n Data diurutkan : ";

    // urutkan data dengan selection sort
    selection_sort();

    // tampilkan data setelah diurutkan
    for(int x = 0; x < 7; x++) {
        cout << setw(3) << bil_data[x];
    }
    
    cout << endl;
    binary_search();
    return 0;
}
```
Program C++ di atas adalah implementasi dari algoritma Binary Search dan Selection Sort untuk mengurutkan dan mencari data dalam sebuah array.

Fungsi `selection_sort` digunakan untuk mengurutkan data dalam array secara ascending. Cara kerjanya adalah sebagai berikut:
1. Memilih elemen pertama dalam array sebagai elemen terkecil.
2. Membandingkan elemen pertama dengan elemen lainnya dalam array. Jika ada elemen lain yang lebih kecil, maka akan diganti elemen pertama dengan elemen tersebut.
3. Mengulangi langkah 2 untuk semua elemen dalam array.
4. Setelah proses selesai, array akan terurut secara ascending.

Fungsi `binary_search` digunakan untuk mencari data yang sudah diurutkan dalam array. Cara kerjanya adalah sebagai berikut:
1. Menentukan awal dan akhir dari rentang pencarian.
2. Menghitung tengah dari rentang tersebut.
3. Membandingkan data di tengah dengan data yang ingin dicari. Jika data di tengah lebih kecil, maka program melanjutkan pencarian di bagian kanan. Jika data di tengah lebih besar, maka program melanjutkan pencarian di bagian kiri.
4. Ulangi langkah 2 dan 3 hingga data ditemukan atau rentang pencarian kosong.
5. Jika data ditemukan, maka tampilkan index ke-nya. Jika tidak ditemukan, maka tampilkan pesan "Data tidak ditemukan".

Program utama melakukan berikut:
1. Menampilkan data awal dalam array.
2. Menginputkan data yang ingin dicari.
3. Mengurutkan data dalam array menggunakan algoritma Selection Sort.
4. Menampilkan data setelah diurutkan.
5. Mencari data yang ingin dicari menggunakan algoritma Binary Search dan menampilkan hasilnya.

Dalam sintaks program, `bil_data` adalah array yang berisi data yang ingin diurutkan dan dicari. `cari` adalah variabel yang berisi data yang ingin dicari. `selection_sort` dan `binary_search` adalah fungsi yang masing-masing melakukan proses pengurutan dan pencarian data.

## Unguided

### 1. Unguided 1
<b>Buatlah sebuah program untuk mencari sebuah huruf pada sebuah kalimat yang sudah di input dengan menggunakan Binary Search!</b>

#### Program: 
```C++
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Fungsi Binary Search
bool findChar(string kalimat, char huruf) {
    int n = kalimat.length();
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (kalimat[mid] == huruf) {
            return true;
        } else if (kalimat[mid] < huruf) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return false;
}

// main program
int main() {
    // Inisialisasi
    string kalimat;
    char huruf;

    // Input kalimat dan huruf yang ingin dicari
    cout << "Masukkan kalimat: ";
    getline(cin, kalimat);
    cout << "Masukkan huruf yang ingin dicari: ";
    cin >> huruf;

    // Panggil fungsi untuk mencari huruf pada kalimat
    if (findChar(kalimat, huruf)) {
        cout << "Huruf '" << huruf << "' ditemukan pada kalimat." << endl;
    } else {
        cout << "Huruf '" << huruf << "' tidak ditemukan pada kalimat." << endl;
    }

    return 0;
}
```
#### Output:
![Screenshot 2024-04-30 183151](https://github.com/egydestf/datstruct-practicum/assets/152776726/7afd4f9d-fa77-4301-ab8f-6d063e9bc350)

Program C++ di atas adalah implementasi fungsi binary search untuk mencari huruf tertentu dalam sebuah kalimat.

Fungsi ini menggunakan algoritma binary search yang efektif untuk mencari huruf yang ingin dicari dalam kalimat. Program ini meminta input dari pengguna untuk kalimat dan huruf yang ingin dicari, lalu menggunakan fungsi `findChar` untuk mencari huruf tersebut dalam kalimat. Jika huruf ditemukan, program akan mencetak pesan "Huruf '" + huruf + "' ditemukan pada kalimat.", jika tidak ditemukan, maka program akan mencetak pesan "Huruf '" + huruf + "' tidak ditemukan pada kalimat.".

Fungsi `findChar` berfungsi untuk mencari huruf tertentu dalam sebuah kalimat. Fungsi ini menggunakan algoritma binary search untuk mencari huruf yang ingin dicari. Fungsi findChar memiliki dua parameter yaitu `kalimat` dengan string yang berisi kalimat yang ingin dicari hurufnya, dan `huruf` dengan huruf yang ingin dicari dalam kalimat.

Dalam sintaks C++, fungsi `findChar` menggunakan operator `<` untuk membandingkan huruf pada indeks `mid` dengan huruf yang ingin dicari. Jika huruf pada indeks `mid` lebih kecil dari huruf yang ingin dicari, maka `low` diubah menjadi `mid + 1`. Jika huruf pada indeks `mid` lebih besar dari huruf yang ingin dicari, maka high diubah menjadi `mid - 1`. Proses ini dilakukan hingga huruf ditemukan atau perulangan selesai.

### 2. Unguided 2
<b>Buatlah sebuah program yang dapat menghitung banyaknya huruf vocal dalam sebuah kalimat!</b>

#### Program: 
```C++
#include <iostream>
#include <string>
using namespace std;

// main program
int main() {
    // inisialisasi
    string kalimat;
    int vokal = 0;

    // input kalimat
    cout << "Masukkan kalimat: ";
    getline(cin, kalimat);

    // hitung jumlah huruf vokal
    for (int i = 0; i < kalimat.length(); i++) {
        if (kalimat[i] == 'a' || kalimat[i] == 'A'
         || kalimat[i] == 'i' || kalimat[i] == 'I' 
         || kalimat[i] == 'u' || kalimat[i] == 'U' 
         || kalimat[i] == 'e' || kalimat[i] == 'E' 
         || kalimat[i] == 'o' || kalimat[i] == 'O') {
            vokal++;
        }
    }

    // tampilkan total huruf vokal
    if (vokal > 0) {
        cout << "Jumlah huruf vokal = " << vokal << endl;
    } else {
        cout << "Huruf vokal tidak ditemukan" << endl;
    }

    return 0;
}
```
#### Output:
![Screenshot 2024-04-30 183207](https://github.com/egydestf/datstruct-practicum/assets/152776726/aa00f01d-e5e9-425b-93ab-3bdf84da8011)

Program C++ di atas berfungsi untuk menghitung jumlah huruf vokal dalam sebuah kalimat yang diinputkan oleh pengguna.

Cara kerja program ini dimulai dengan menginisialisasi variabel `kalimat` sebagai string untuk menampung kalimat yang diinputkan dan `vokal` sebagai integer untuk menampung jumlah huruf vokal. Lalu, program meminta input dari pengguna untuk kalimat yang ingin dihitung jumlah huruf vokalnya. Setelah itu, program menggunakan perulangan untuk menghitung jumlah huruf vokal dalam kalimat. Perulangan ini membandingkan setiap huruf dalam kalimat dengan huruf vokal (a, i, u, e, o, A, I, U, E, O) dan jika huruf tersebut sama, maka variabel `vokal` akan diinkrementasi. Setelah perulangan selesai, program akan menampilkan jumlah huruf vokal jika lebih dari nol, atau pesan "Huruf vokal tidak ditemukan" jika tidak ada huruf vokal dalam kalimat.

### 3. Unguided 3
<b>Diketahui data = 9, 4, 1, 4, 7, 10, 5, 4, 12, 4. Hitunglah berapa banyak angka 4 dengan menggunakan algoritma Sequential Search!</b>

#### Program: 
```C++
#include <iostream>
using namespace std;

int main() {
    int n = 10; // Jumlah elemen dalam data array
    int data[n] = { 9, 4, 1, 4, 7, 10, 5, 4, 12, 4}; // Data array
    int cari = 4; // Nilai yang ingin dicari
    bool ketemu = false;
    int i;
    int count = 0; // Variabel untuk menghitung jumlah kemunculan nilai yang dicari

    // Algoritma Sequential Search
    for (i = 0; i < n; i++) {
        if (data[i] == cari) {
            ketemu = true;
            count++; // Tambahkan penghitungan setiap kali nilai yang dicari ditemukan
        }
    }

    cout << "Program Mencari Nilai 4 Menggunakan Algoritma Sequential Search\n" << endl;
    cout << "Data : { 9, 4, 1, 4, 7, 10, 5, 4, 12, 4}" << endl;

    if (ketemu) {
        cout << "\nAngka " << cari << " ditemukan sebanyak " << count << " kali." << endl;
    } else {
        cout << "Angka " << cari << " tidak dapat ditemukan pada data." << endl;
    }
    return 0;
}
```
#### Output:
![Screenshot 2024-04-30 183223](https://github.com/egydestf/datstruct-practicum/assets/152776726/870cb09e-2fdf-43b4-b704-ac59f3a1edcc)

Program C++ di atas berfungsi untuk mencari nilai tertentu dalam sebuah array menggunakan algoritma sequential search.

Program ini dimulai dengan menginisialisasi variabel `n` sebagai jumlah elemen dalam array, `data` sebagai array yang berisi nilai-nilai, `cari` sebagai nilai yang ingin dicari, `ketemu` sebagai boolean untuk menunjukkan apakah nilai yang dicari ditemukan atau tidak, `i` sebagai variabel loop, dan `count` sebagai variabel untuk menghitung jumlah kemunculan nilai yang dicari. Kemudian, program menggunakan perulangan untuk mengiterasi setiap elemen dalam array dan membandingkan dengan nilai yang ingin dicari. Jika nilai yang dicari ditemukan, maka variabel `ketemu` akan diubah menjadi `true` dan `count` akan diinkrementasi. Setelah perulangan selesai, program akan menampilkan pesan yang menunjukkan apakah nilai yang dicari ditemukan dan jika ditemukan, maka program juga akan menampilkan jumlah kemunculan nilai yang dicari.

## Kesimpulan

Praktikum Modul 4 Searching ini membahas pengenalan dari metode searching atau pencarian pada C++ yaitu Sequential Search dan Binary Search. Masing-masing dari kedua metode searching tersebut memiliki cara kerja yang berbeda-beda. Sequential atau Linear Searching memeriksa setiap elemen dari daftar array data satu per satu hingga ditemukan kecocokan. Sequential cocok untuk mencari data dalam daftar yang tidak berurutan. Seadangkan Binary search bekerja dengan cara membagi interval pencarian menjadi dua bagian. Jika nilai kunci pencarian lebih kecil dari nilai tengah interval, pencarian dilanjutkan ke bagian kanan; jika lebih besar, ke bagian kiri. Binary Search efisien untuk data yang terurut.

## Referensi
[1] Z. W. Geem, "Recent Advances in Harmony Search Algorithm," 2010.

[2] Trivusi. Algoritma Pencarian: Pengertian, Karakteristik, dan Jenis-Jenisnya. diakses dari https://www.trivusi.web.id/2022/11/pengertian-algoritma-pencarian.html?m=1#google_vignette 