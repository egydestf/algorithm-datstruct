# <h1 align="center">Laporan Praktikum Modul Sorting</h1>

<p align="center">Egy Destiar Firmandani</p>
<p align="center">2311110061</p>

## Dasar Teori

Sorting atau pengurutan adalah proses menyusun elemen – elemen dari masukan awal acak menjadi keluaran akhir tertata dengan urutan tertentu[1]. Proses tersebut diimplementasikan dalam bermacam aplikasi. Contoh penerapan sorting antara lain rincian transaksi sesuai urutan tanggal dan jam pada perbankan, daftar hadir yang diurutkan berdasarkan nomor induk dan daftar pustaka yang diurutkan sesuai abjad pengarang ataupun katalog buku di perpustakaan[2].

Ada banyak metode pengurutan yaitu seperti: bubble sort, bi-directional bubble sort, selection sort, shaker sort, insertion sort, inplace merge sort, double storage merge sort, comb sort 11, shell sort, heap sort, exchange sort, merge sort, quick sort, quick sort with bubble sort, enhange quick sort, fast quick sort, radix sort algorithm, swap sort, dan lain sebagainya[3].

Namun pada Modul 3 Sorting ini, mahasiswa mempelajari tiga metode pengurutan atau sorting pada C++ yaitu Insertion Sort, Bubble Sort, dan Selection. Adapun uraiannya antara lain sebagai berikut.

### 1. Insertion Sort

Salah satu algoritma sorting yang sederhana adalah Insertion Sort. Metode ini, didasarkan pada sebuah kunci yang diambil pada elemen ke-2 pada sebuah larik, lalu menyisipkan elemen tersebut jika kondisi percabangan terpenuhi. Metode penyisipan (Insertion) bertujuan untuk menjadikan bagian sisi kiri larik terurutkan sampai dengan seluruh larik berhasil diurutkan[2].

Contoh program fungsi Insertion Sort dalam C++.
```C++
void insertion_sort(int arr[], int length) {
    int i, j, tmp;

    for (i = 1; i < length; i++) {
        j = i;

        while (j > 0 && arr[j - 1] > arr[j]) {
            tmp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = tmp;
            j--;
        }
    }
}
```

### 2. Bubble Sort

Algoritma Bubble Sort adalah sebuah algoritma pengurutan yang paling sederhana. Dalam algoritma Bubble Sort, setiap elemen dalam list dibandingkan dengan elemennya yang adjacent. Jika elemen pertama lebih besar dari elemen berikutnya, maka elemen tersebut akan diganti dengan elemen berikutnya. Ini dilakukan selama setiap iterasi hingga elemen terbesar berada pada posisi yang tepat dalam list.

Contoh program fungsi Bubble Sort dalam C++.
```C++
void bubble_sort(int arr[], int length) {
    bool not_sorted = true;
    int j=0;
    double tmp;

    while (not_sorted) {
        not_sorted = false;
        j++;

        for (int i = 0; i < length - j; i++) {
            if (arr[i] > arr[i + 1]) {
                tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                not_sorted = true;
            }
        }
    }
}
```

### 3. Selection Sort

Algoritma Selection Sort adalah sebuah algoritma pengurutan yang bekerja dengan cara memilih elemen dengan nilai paling kecil dari sebuah array dan menukarnya dengan elemen pertama. Algoritma ini bekerja dengan iterasi melalui setiap elemen dalam array. Algoritma Selection Sort adalah algoritma pengurutan yang mudah dipahami, tetapi kurang efisien untuk data yang besar. Namun, algoritma Selection Sort masih digunakan untuk memperkenalkan konsep pengurutan dalam pemrograman.

Contoh program fungsi Selection Sort dalam C++.
```C++
void selectSort(int arr[], int length) {
    int pos_min, temp;

    for (int i=0; i < length-1; i++) {
        pos_min = i;

        for (int j=i+1; j < length; j++) {
            if (arr[j] < arr[pos_min])
            pos_min=j;
        }

        if (pos_min != i) {
            temp = arr[i];
            arr[i] = arr[pos_min];
            arr[pos_min] = temp;
        }
    }
}
```

## Guided 

### 1. Guided 1
<b>Mengurutkan secara ascending untuk data numerik bertipe double menggunakan Algoritma Bubble Sort.</b>

```C++
#include <iostream>
using namespace std;

// fungsi bubble sorting
void bubble_sort(double arr[], int length) {
    bool not_sorted = true;
    int j=0;
    double tmp;

    while (not_sorted) {
        not_sorted = false;
        j++;
        for (int i = 0; i < length - j; i++) {
            if (arr[i] > arr[i + 1]) {
                tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                not_sorted = true;
            }// end of if
        }// end of for loop
    }// end of while loop
}// end of bubble_sort

// fungsi print array
void print_array(double a[], int length) {
    for(int i=0; i<length; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
}

// main program
int main() {
    int length = 5;
    double a[] = {22.1, 15.3, 8.2, 33.21, 99.99};

    cout << "Urutan bilangan sebelum sorting: " << endl;
    print_array(a, length);

    bubble_sort(a, length);

    cout << "\nUrutan bilangan setelah sorting: " << endl;
    print_array(a, length);
}
```
Program di atas adalah program untuk mengurutkan data double secara ascending menggunakan Bubble Sort.

Fungsi `bubbleSort` menerima sebuah array double `arr` dan ukuran array `length` sebagai parameter. Fungsi ini menggunakan sebuah variabel boolean `not_sorted` untuk menyimpan status pengurutan array. Sedangkan variabel `j` yang digunakan untuk menyimpan indeks iterasi.

Dalam loop utama, terdapat sebuah for loop untuk iterasi melalui setiap elemen dalam array. Setiap iterasi akan mengecek apakah elemen di indeks `i` lebih besar dari elemen di indeks `i + 1`. Jika iya, program akan mengganti elemen tersebut dengan elemen di indeks `i + 1`. Program juga mengubah nilai `not_sorted` menjadi `true` ketika ada perubahan.

Setelah loop utama selesai, program akan mengecek apakah `not_sorted` masih bernilai `true`?. Jika iya, program menetapkan `not_sorted` menjadi `false` dan menambahkan indeks iterasi `j`.

### 2. Guided 2
<b>Mengurutkan karakter secara descending (dari terbesar hingga terkecil) menggunakan Algoritma Insertion Sort.</b>

```C++
#include <iostream>
using namespace std;

// fungsi insertion sorting
void insertion_sort(char arr[], int length) {
    int i, j;
    char tmp;

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

// fungsi print array
void print_array(char a[], int length) {
    for(int i=0; i<length; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
}

// main program
int main() {
    int length = 6;
    char a[length] = {'c', 'f', 'a', 'z', 'd', 'p'};

    cout << "Urutan karakter sebelum sorting: " << endl;
    print_array(a, length);

    insertion_sort(a, length);

    cout << "\nUrutan karakter setelah sorting: " << endl;
    print_array(a, length);
}
```
Program di atas adalah program untuk mengurutkan data bertipe character secara descending menggunakan Insertion Sort.

Fungsi `insertion_sort` menerima sebuah array character `arr` dan ukuran array `length` sebagai parameter. Fungsi ini menggunakan sebuah for loop untuk iterasi melalui setiap elemen dalam array. Setiap iterasi, program akan mengecek apakah elemen di indeks `i` lebih besar dari elemen di indeks `i - 1`. Jika iya, elemen tersebut diganti dengan elemen di indeks `i - 1`. Program juga akan mengubah nilai `not_sorted` menjadi `true` ketika ada perubahan.

## Unguided

### 1. Unguided 1
<b>Kelas S1 IF 2016 G memiliki 5 mahasiswa. Pada akhir semester mereka menerima lembar Indeks Prestasi Semester (IPS), masing-masing mahasiswa tersebut memiliki IPS sebagai berikut: {3.8, 2.9, 3.3, 4.0, 2.4}. Buatlah program untuk mengurutkan IPS mahasiswa tersebut dari yang terbesar hingga terkecil dengan menggunakan algoritma Selection Sort!</b>

#### Program: 
```C++
#include <iostream>
using namespace std;

// fungsi descending selection sorting
void selectSortDesc(float arr[], int n) {
    int pos_max; // elemen perulangan
    float temp; // temporary float data

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
    int n = 5; // panjang array
    float a[n] = {3.8, 2.9, 3.3, 4.0, 2.4}; // IPS mahasiswa

    cout << "Nilai IPS mahasiswa sebelum descending selection sorting: " << endl;
    print_array(a, n); // cetak array sebelum dilakukan sorting

    selectSortDesc(a, n); // pemanggilan fungsi selection sort dalam array

    cout << "\nNilai IPS mahasiswa setelah descending selection sorting: " << endl;
    print_array(a, n); // cetak array setelah dilakukan sorting

    return 0;
}
```
#### Output:
![Screenshot 2024-04-12 222725](https://github.com/egydestf/datstruct-practicum/assets/152776726/adef278c-83a8-46aa-a4da-4c97ceabfa01)

Program C++ di atas menunjukkan algoritma pengurutan descending (urutan terbalik) menggunakan algoritma Selection Sort. Algoritma ini bekerja dengan cara menemukan elemen dengan nilai paling besar dalam sebuah array dan menukarnya dengan elemen pertama. Algoritma ini bekerja dengan iterasi melalui setiap elemen dalam array. Program ini menggunakan tipe data float dan menghubungkan nilai float dengan fungsi `selectSortDesc`. Ini akan membuat algoritma pengurutan yang berfungsi untuk mengurutkan elemen dalam array dalam urutan terbalik.

Function `selectSortDesc` menerima sebuah array `arr` dan ukuran array `n`. Function ini melakukan perulangan menggunakan dua for loop. Loop pertama berjalan dari indeks 0 hingga indeks `n - 1`, sementara loop kedua berjalan dari indeks `i + 1` hingga indeks `n`. Dalam loop kedua, setiap elemen yang lebih besar dari elemen yang dijumpai akan diperbarui sebagai elemen maximum. Jika elemen di `j` lebih besar dari elemen di `pos_max`, maka `pos_max` diperbarui. Setelah menemukan elemen maximum dalam array, program akan menukarnya dengan elemen di indeks `i`.

Fungsi `print_array` digunakan untuk menampilkan isi sebuah array dalam bentuk tabel, yang menggambarkan nilai dari setiap elemen dalam array. Fungsi ini dapat digunakan untuk mengubah tampilan array menjadi lebih rapi dan mudah dibaca. Dalam fungsi `print_array`, digunakan sebuah for loop untuk melakukan iterasi melalui setiap elemen dalam array. Setiap iterasi akan ditampilkan nilai elemen dalam bentuk tabel tanpa garis dengan menggunakan operasi `cout`. Setelah selesai melakukan iterasi, program akan menambahkan satu baris kosong untuk membuat tabel terlihat rapi.

### 2. Unguided 2
<b>Pak RT memiliki 10 warga dengan nama: Siti, Situ, Sana, Ana, Ani, Caca, Cici, Dida, Dodo, dan Dadi. Supaya mudah dalam melakukan pencarian, Pak RT akan mengurutkan nama-nama tersebut sesuai dengan alfabet. Buatlah program untuk membantu Pak RT dengan  menggunakan algoritma Bubble Sort!</b>

#### Program: 
```C++
#include <iostream>
#include <string>
using namespace std;

// fungsi bubble sorting
void bubbleSort(string arr[], int n) {
    bool not_sorted = true; // status pengurutan array
    int j=0; // indeks perulangan
    string tmp; // temporary string data

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
    int n = 10; // panjang array
    string a[n] = {"Siti", "Situ", "Sana", "Ana", "Ani",
    "Caca", "Cici", "Dida", "Dodo", "Dadi"}; // 10 warga Pak RT

    cout << "Nama 10 warga Pak RT sebelum diurutkan: " << endl;
    print_array(a, n); // cetak array sebelum dilakukan sorting

    bubbleSort(a, n); // pemanggilan fungsi bubble sort dalam array

    cout << "\nNama 10 warga Pak RT setelah diurutkan: " << endl;
    print_array(a, n); // cetak array setelah dilakukan sorting

    return 0;
}
```
#### Output:
![Screenshot 2024-04-12 222804](https://github.com/egydestf/datstruct-practicum/assets/152776726/51f98d1f-c6ef-41da-b3c1-5aa419ce1698)

Program di atas adalah program untuk mengurutkan data tipe string secara ascending menggunakan Bubble Sort.

Fungsi `bubbleSort` menerima sebuah array string `arr` dan ukuran array `n` sebagai parameter. Fungsi ini menggunakan sebuah variabel boolean `not_sorted` untuk menyimpan status pengurutan array. Sedangkan variabel `j` yang digunakan untuk menyimpan indeks iterasi.

Dalam loop utama, terdapat sebuah for loop untuk iterasi melalui setiap elemen dalam array. Setiap iterasi akan mengecek apakah elemen di indeks `i` lebih besar dari elemen di indeks `i + 1`. Jika iya, program akan mengganti elemen tersebut dengan elemen di indeks `i + 1`. Program juga mengubah nilai `not_sorted` menjadi `true` ketika ada perubahan.

Setelah loop utama selesai, program akan mengecek apakah `not_sorted` masih bernilai `true`?. Jika iya, program menetapkan `not_sorted` menjadi `false` dan menambahkan indeks iterasi `j`.

### 3. Unguided 3
<b>Buatlah program yang meminta user menginputkan suatu bilangan n dan meminta user untuk menginputkan sejumlah n karakter. Kemudian program akan melakukan sorting secara menaik (ascending) dan menurun (descending)!</b>

#### Program: 
```C++
#include <iostream>
using namespace std;

// fungsi insertion sort ascending
void insertionSortAsc(char arr[], int n) {
    int i, j; // indeks untuk perulangan
    char tmp; // temporary char data

    for (i = 1; i < n; i++) {
        j = i;

        while (j > 0 && arr[j - 1] > arr[j]) { // pengurutan ascending terjadi
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

        while (j > 0 && arr[j - 1] < arr[j]) { // pengurutan descending terjadi
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
    int n; // panjang array
    cout << "Input (n) = ";
    cin >> n; // input panjang array

    char a[n]; // inisialisasi array tipe char

    for  (int i = 0; i < n; ++i) {
        cout << "Karakter ke-" << i+1 << ": ";
        cin >> a[i]; // input tiap indeks sesuai n
    }

    cout << "\nUrutan karakter sebelum sorting:" << endl;
    print_array(a, n); // cetak array sebelum dilakukan sorting

    insertionSortAsc(a, n); // pemanggilan fungsi ascending insertion sort dalam array
    cout << "\nUrutan karakter setelah ascending sort:" << endl;
    print_array(a, n); // cetak array setelah dilakukan ascending sorting

    insertionSortDesc(a, n); // pemanggilan fungsi descending insertion sort dalam array
    cout << "\nUrutan karakter setelah descending sort:" << endl;
    print_array(a, n); // cetak array setelah dilakukan descending sorting
}
```
#### Output:
![Screenshot 2024-04-12 222839](https://github.com/egydestf/datstruct-practicum/assets/152776726/0dcdedd8-5959-490d-8de1-bcf5ed8d0d33)

Program ini menggunakan algoritma insertion sort untuk mengurutkan elemen dalam array character dalam urutan ascending dan descending.

Program C++ di atas mencakup dua fungsi yang menggunakan algoritma insertion sort untuk mengurutkan sebuah array character dalam urutan ascending dan descending. Algoritma insertion sort adalah sebuah algoritma pengurutan yang bekerja dengan cara menyisipkan setiap elemen dari bagian unsorted ke bagian sorted.

Fungsi `insertionSortAsc` menerima sebuah array character `arr` dan ukuran array `n` sebagai parameter. Fungsi ini menggunakan sebuah for loop untuk iterasi melalui setiap elemen dalam array. Setiap iterasi, program akan mengecek apakah elemen di indeks `i` lebih kecil dari elemen di indeks `i - 1`. Jika iya, elemen tersebut diganti dengan elemen di indeks `i - 1`. Program juga akan mengubah nilai `not_sorted` menjadi `true` ketika ada perubahan.

Fungsi `insertionSortDesc` menerima sebuah array character `arr` dan ukuran array `n` sebagai parameter. Fungsi ini menggunakan sebuah for loop untuk iterasi melalui setiap elemen dalam array. Setiap iterasi, program akan mengecek apakah elemen di indeks `i` lebih besar dari elemen di indeks `i - 1`. Jika iya, elemen tersebut diganti dengan elemen di indeks `i - 1`. Program juga akan mengubah nilai `not_sorted` menjadi `true` ketika ada perubahan.

## Kesimpulan

Praktikum Modul 3 Sorting ini membahas pengenalan dari metode sorting atau pengurutan pada C++ seperti Insertion Sort, Bubble Sort, dan Selection Sort. Masing-masing dari ketiga metode sorting tersebut memiliki cara kerja yang berbeda-beda. Insertion Sort didasarkan pada sebuah key yang diambil pada elemen ke-2 pada sebuah array, lalu menyisipkan elemen tersebut jika kondisi percabangan terpenuhi. Insertion bertujuan untuk menjadikan bagian sisi kiri array terurutkan sampai dengan seluruh larik berhasil diurutkan. Bubble Sort didasarkan pada elemen dalam list dibandingkan yang dengan elemennya yang adjacent. Jika elemen pertama lebih besar dari elemen berikutnya, maka elemen tersebut akan diganti dengan elemen berikutnya. Terakhir Selection Sort yang bekerja dengan cara memilih elemen dengan nilai paling kecil dari sebuah array dan menukarnya dengan elemen pertama. Algoritma ini bekerja dengan iterasi melalui setiap elemen dalam array.

## Referensi
[1] Anonim. Srand. diakses dari http://www.cplusplus.com/reference/clibrary/cstdlib/srand/

[2] Saptadi, A. H. dan Sari, D. W. 2012. Analisis Algoritma Insertion Sort, Merge Sort dan Implementasinya dalam Bahasa Pemrogaman C++. Jurnal Infotel. Purwokerto.

[3] Atrinawati, L. H. Analisis Kompleksitas Algoritma untuk Berbagai Macam Metode Pencarian Nilai (Searching) dan Pengurutan Nilai (Sorting) pada Tabel. Program Studi Teknik Informatika. ITB. Bandung.
