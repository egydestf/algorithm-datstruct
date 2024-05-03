# <h1 align="center">Laporan Praktikum Modul Struct</h1>

<p align="center">Egy Destiar Firmandani</p>
<p align="center">2311110061</p>

## Dasar Teori

### Struktur (Struct)

Struktur (struct) adalah pengelompokan variabel-variabel yang bernaung dalam satu nama yang sama. Berbeda dengan array yang berisi kumpulan variabel-variabel yang bertipe sama dalam satu nama, maka suatu struktur dapat terdiri atas variabel-variabel yang berbeda tipenya dalam satu nama struktur. Struktur biasa dipakai untuk mengelompokkan beberapa informasi yang berkaitan menjadi sebuah kesatuan. Variabel-variabel yang membentuk suatu struktur, selanjutnya disebut sebagai elemen dari struktur atau field. Dengan demikian, dimungkinkan suatu struktur dapat berisi elemen-elemen data berbeda tipe seperti char, int, float, double, dan lain-lain[1].

Struktur data memiliki format khusus yang berfungsi untuk mengatur, memproses, mengambil, dan menyimpan data[2]. Dalam pemrograman C++, struktur dapat berisi dua jenis anggota: anggota data dan fungsi anggota. Anggota data adalah variabel C++ normal, sedangkan fungsi anggota adalah fungsi C++ normal. Struktur dapat dibuat dengan variabel dari jenis data yang berbeda di C++.

Struktur dapat dideklarasikan dengan menggunakan kata kunci struct diikuti dengan nama struktur. Contoh:
```C++
struct tgl {
    int hari;
    int bulan;
    int tahun;
};
```
Dengan demikian, didefinisikan sebuah struktur bernama tgl yang memiliki tiga member bertipe `int` yaitu `hari`, `bulan`, dan `tahun`.

## Guided 

### 1. Guided 1
<b>Buatlah sebuah struktur dengan nama buku yang berisi judul_buku, pengarang, penerbit, tebal_halaman, harga_buku. Isi dengan nilai kemudian tampilkan!</b>

#### Program:
```C++
#include <iostream>
#include <string>
using namespace std;

// mendefinisikan struct buku
struct Buku {
    string judul_buku;
    string pengarang;
    string penerbit;
    int tebal_buku;
    double harga_buku;
}; Buku buku1; Buku buku2;

// main program
int main() {
    // mengisi data buku 1
    buku1.judul_buku = "Algoritma Pemrograman";
    buku1.pengarang = "Raden Wardana";
    buku1.penerbit = "Gramedia Pustaka";
    buku1.tebal_buku = 300;
    buku1.harga_buku = 120000;

    // mengisi data buku 2
    buku2.judul_buku = "Kalkulus 2";
    buku2.pengarang = "Ajeng Kusuma Ayu";
    buku2.penerbit = "Erlangga";
    buku2.tebal_buku = 400;
    buku2.harga_buku = 150000;

    // menampilkan data buku 1
    cout << "Informasi Buku 1" << endl;
    cout << "Judul\t\t: " << buku1.judul_buku << endl;
    cout << "Pengarang\t: " << buku1.pengarang << endl;
    cout << "Penerbit\t: " << buku1.penerbit << endl;
    cout << "Tebal Halaman\t: " << buku1.tebal_buku << endl;
    cout << "Harga Buku\t: " << buku1.harga_buku << endl << endl;

    // menampilkan data buku 2
    cout << "Informasi Buku 2" << endl;
    cout << "Judul\t\t: " << buku2.judul_buku << endl;
    cout << "Pengarang\t: " << buku2.pengarang << endl;
    cout << "Penerbit\t: " << buku2.penerbit << endl;
    cout << "Tebal Halaman\t: " << buku2.tebal_buku << endl;
    cout << "Harga Buku\t: " << buku2.harga_buku << endl;

    return 0;
}
```
#### Output:
![Screenshot 2024-05-03 100608](https://github.com/egydestf/datstruct-practicum/assets/152776726/d4b3e61e-aa79-49a3-a3bc-0b8640c9fd7d)

Program di atas adalah program untuk menampilkan sebuah struktur dengan nama buku yang berisi judul_buku, pengarang, penerbit, tebal_halaman, harga_buku.

Program C++ di atas berisi definisi struktur `Buku` yang berisi atribut judul buku, pengarang, penerbit, tebal buku, dan harga buku. Kemudian, program ini diisi data dua buku, yaitu `buku1` dan `buku2`, dengan informasi yang berbeda-beda. Setelah itu, program ini menampilkan informasi kedua buku tersebut ke layar menggunakan fungsi `cout`.

Alur program dapat dijabarkan sebagai berikut: program pertama-tama mendefinisikan struktur `Buku`, lalu data buku 1 dan buku 2 diisi dengan informasi yang berbeda-beda. Setelah itu, program menampilkan informasi buku 1 dan buku 2 ke layar menggunakan fungsi `cout`. Program ini berjalan secara berurutan, mulai dari definisi struktur `Buku`, pengisian data buku 1 dan buku 2, hingga menampilkan informasi buku 1 dan buku 2 ke layar.

### 2. Guided 2
<b>Buatlah sebuah struktur dengan skema seperti dibawah, isi dengan nilai kemudian jalankan!</b>

![Screenshot 2024-05-03 100912](https://github.com/egydestf/datstruct-practicum/assets/152776726/d460678b-c135-40f6-8560-ff78e98b7eb1)

#### Program:
```C++
#include <iostream>
#include <string>
using namespace std;

struct Hewan {
    string Nama_hewan;
    string Jenis_kelamin;
    string cara_berkembangbiak;
    string alat_bernafas ;
    string tempat_hidup;
    bool karnivora;
};

struct Hewan_darat{
    int jumlah_kaki;
    bool apakah_menyusui;
    string suara;
    Hewan info_hewan ;

}; Hewan_darat hewan1;

struct Hewan_laut{
    string Bentuk_sirip;
    string Pertahanan_diri;
    Hewan info_hewan;
}; Hewan_laut hewan2;

// main program
int main(){
    hewan1.info_hewan.Nama_hewan = "Kucing";
    hewan1.info_hewan.Jenis_kelamin = "Betina";
    hewan1.info_hewan.cara_berkembangbiak = "Melahirkan";
    hewan1.info_hewan.alat_bernafas = "Paru-paru";
    hewan1.info_hewan.tempat_hidup = "Daratan";
    hewan1.info_hewan.karnivora = false;
    hewan1.jumlah_kaki = 4;
    hewan1.apakah_menyusui = true;
    hewan1.suara = "Meow";

    hewan2.info_hewan.Nama_hewan = "Penyu";
    hewan2.info_hewan.Jenis_kelamin = "Betina";
    hewan2.info_hewan.cara_berkembangbiak = "Bertelur";
    hewan2.info_hewan.alat_bernafas = "Paru-paru dan insang";
    hewan2.info_hewan.tempat_hidup = "Lautan";
    hewan2.info_hewan.karnivora = false;
    hewan2.Bentuk_sirip = "Sirip dan ekor";
    hewan2.Pertahanan_diri = "Cangkang yang kuat";

    cout << "\t Hewan Darat :" << endl;
    cout << "Nama Hewan : " << hewan1.info_hewan.Nama_hewan << endl;
    cout << "Jenis Kelamin : " << hewan1.info_hewan.Jenis_kelamin << endl;
    cout << "Cara Berkembangbiak : " << hewan1.info_hewan.cara_berkembangbiak << endl;
    cout << "Pernapasan : " << hewan1.info_hewan.alat_bernafas << endl;
    cout << "Tempat Hidup : " << hewan1.info_hewan.tempat_hidup << endl;
    cout << "Apakah Karnivora? : " << hewan1.info_hewan.karnivora << endl;
    cout << "Jumlah Kaki : " << hewan1.jumlah_kaki << endl;
    cout << "Apakah Menyusui? : " << hewan1.apakah_menyusui << endl;
    cout << "Suara : " << hewan1.suara << endl << endl;

    cout << "\t Hewan Laut :" << endl;  
    cout << "Nama Hewan : " << hewan2.info_hewan.Nama_hewan << endl;
    cout << "Jenis Kelamin : " << hewan2.info_hewan.Jenis_kelamin << endl;
    cout << "Cara Berkembangbiak : " << hewan2.info_hewan.cara_berkembangbiak << endl;
    cout << "Pernapasan : " << hewan2.info_hewan.alat_bernafas << endl;
    cout << "Tempat Hidup : " << hewan2.info_hewan.tempat_hidup << endl;
    cout << "Apakah Karnivora? : " << hewan2.info_hewan.karnivora << endl;
    cout << "Bentuk Sirip : " << hewan2.Bentuk_sirip << endl;

    return 0;
}
```
#### Output:
![Screenshot 2024-05-03 100628](https://github.com/egydestf/datstruct-practicum/assets/152776726/5e12e72c-02d4-4aec-98b6-0aba632f4e9c)

Program C++ di atas berisi definisi struktur `Hewan` yang berisi atribut nama hewan, jenis kelamin, cara berkembangbiak, alat pernafasan, tempat hidup, dan apakah hewan karnivora atau tidak. Kemudian, program ini juga mendefinisikan struktur `Hewan_darat` dan `Hewan_laut` yang masing-masing memiliki atribut yang spesifik untuk hewan darat dan laut. Program ini diisi data dua hewan, yaitu `hewan1` dan `hewan2`, dengan informasi yang berbeda-beda. Setelah itu, program ini menampilkan informasi kedua hewan tersebut ke layar menggunakan fungsi `cout`.

Alur program dapat dijabarkan sebagai berikut: program pertama-tama mendefinisikan struktur `Hewan`, `Hewan_darat`, dan `Hewan_laut`, lalu data hewan 1 dan hewan 2 diisi dengan informasi yang berbeda-beda. Setelah itu, program menampilkan informasi hewan 1 dan hewan 2 ke layar menggunakan fungsi `cout`. Program ini berjalan secara berurutan, mulai dari definisi struktur `Hewan`, pengisian data hewan 1 dan hewan 2, hingga menampilkan informasi hewan 1 dan hewan 2 ke layar.

## Unguided

### 1. Unguided 1
<b>Modifikasi tugas guided pertama, sehingga setiap item yang terdapat pada struct buku berupa array yang berukuran 5, isi dengan data kemudian tampilkan!</b>

#### Program: 
```C++
#include <iostream>
#include <string>
using namespace std;

// mendefinisikan struct buku
struct Buku {
    string judul_buku[5];
    string pengarang[5];
    string penerbit[5];
    int tebal_halaman[5];
    double harga_buku[5];
};

// main program
int main() {
    // mendeklarasikan struct
    Buku buku;

    // mengisi data buku
    for (int i = 0; i < 5; i++) {
        cout << "Masukkan Informasi Buku ke-" << i+1 << ":" << endl;
        cout << "Judul Buku\t: ";
        cin.ignore(); // membersihkan newline character sebelum menggunakan getline
        getline(cin, buku.judul_buku[i]);
        cout << "Pengarang\t: ";
        getline(cin, buku.pengarang[i]);
        cout << "Penerbit\t: ";
        getline(cin, buku.penerbit[i]);
        cout << "Tebal Halaman\t: ";
        cin >> buku.tebal_halaman[i];
        cout << "Harga Buku\t: ";
        cin >> buku.harga_buku[i];
        cout << endl;
    }

    // menampilkan data buku
    for (int i = 0; i < 5; i++) {
        cout << "Informasi Buku " << i+1 << endl;
        cout << "Judul\t\t: " << buku.judul_buku[i] << endl;
        cout << "Pengarang\t: " << buku.pengarang[i] << endl;
        cout << "Penerbit\t: " << buku.penerbit[i] << endl;
        cout << "Tebal Halaman\t: " << buku.tebal_halaman[i] << endl;
        cout << "Harga Buku\t: " << buku.harga_buku[i] << endl << endl;
    }

    return 0;
}
```
#### Input:
![Screenshot 2024-05-03 095629](https://github.com/egydestf/datstruct-practicum/assets/152776726/0a4cd72a-2691-487b-92f7-8149b0b8dfa3)

#### Output:
![Screenshot 2024-05-03 095651](https://github.com/egydestf/datstruct-practicum/assets/152776726/14d4b213-e2d9-4d6d-9486-6839116eb126)


Program C++ di atas berisi definisi struktur `Buku` yang berisi atribut `judul_buku`, `pengarang`, `penerbit`, `tebal_halaman`, dan `harga_buku`. Struktur ini dapat menampung informasi lima buah buku. Program ini kemudian diisi data lima buku dengan meminta input dari pengguna melalui console. Setelah itu, program menampilkan informasi lima buku yang telah diinput ke layar menggunakan fungsi `cout`.

Alur program dapat dijabarkan sebagai berikut: program pertama-tama mendefinisikan struktur `Buku`, lalu mengisi data lima buku dengan meminta input dari pengguna. Setelah itu, program menampilkan informasi lima buku yang telah diinput ke layar. Program ini berjalan secara berurutan, mulai dari definisi struktur `Buku`, pengisian data buku, hingga menampilkan informasi buku ke layar.

### 2. Unguided 2
<b>Apa yang terjadi jika deklarasi variabel struct yang dibuat pada tugas guided I, berjenis Array. Bagaimana cara mengisi data dan menampilkannya ?</b>

Jika deklarasi variabel struct yang dibuat pada program berjenis Array, maka program akan mendefinisikan sebuah array yang terdiri dari beberapa elemen yang masing-masing adalah sebuah struktur data Buku. Contohnya, jika ingin mendefinisikan array Buku dengan nama buku yang memiliki 3 elemen, maka deklarasi tersebut akan seperti berikut:
```C++
Buku buku[3];
```

Untuk mengisi data pada array Buku, digunakan indeks array untuk mengakses setiap elemen dan kemudian diisi data dengan cara yang sama seperti mengisi data pada variabel struct individual. Contohnya, untuk mengisi data pada elemen pertama array Buku, dapat menggunakan sintaks berikut:
```C++
buku[0].judul_buku = "Algoritma Pemrograman";
buku[0].pengarang = "Raden Wardana";
buku[0].penerbit = "Gramedia Pustaka";
buku[0].tebal_buku = 300;
buku[0].harga_buku = 120000;
```

Untuk menampilkan data pada array Buku, digunakan perulangan untuk mengakses setiap elemen dan kemudian ditampilkan data dengan cara yang sama seperti menampilkan data pada variabel struct individual. Contohnya, untuk menampilkan data pada array Buku, dapat menggunakan sintaks berikut:
```C++
for(int i = 0; i < 3; i++) {
    cout << "Informasi Buku " << i+1 << endl;
    cout << "Judul\t\t: " << buku[i].judul_buku << endl;
    cout << "Pengarang\t: " << buku[i].pengarang << endl;
    cout << "Penerbit\t: " << buku[i].penerbit << endl;
    cout << "Tebal Halaman\t: " << buku[i].tebal_buku << endl;
    cout << "Harga Buku\t: " << buku[i].harga_buku << endl << endl;
}
```
Dalam sintaks di atas, perulangan `for` digunakan untuk mengakses setiap elemen dalam array Buku dengan menggunakan indeks `i`. Kemudian, data pada setiap elemen diakses menggunakan sintaks `buku[i].judul_buku` dan kemudian ditampilkan ke layar menggunakan fungsi `cout`.

## Kesimpulan

Praktikum Modul 5 Struct ini membahas pengenalan dari konsep struct atau struktur pada C++. Struktur (struct) adalah pengelompokan variabel-variabel yang bernaung dalam satu nama yang sama. Struktur biasa dipakai untuk mengelompokkan beberapa informasi yang berkaitan menjadi sebuah kesatuan. Struktur data menjadi salah satu bagian penting yang wajib dipahami oleh para programmer, karena memudahkan pengguna mengakses data yang dibutuhkan secara cepat dan tepat. Struktur data memiliki format khusus yang berfungsi untuk mengatur, memproses, mengambil, dan menyimpan data. Dalam pemrograman C++, struktur dapat berisi dua jenis anggota: anggota data dan fungsi anggota. Struktur dapat dibuat dengan variabel dari jenis data yang berbeda di C++.

## Referensi
[1] M. T. D. Putra, Munawir, A. R. Yuniarti, and E. Damayanti, "BELAJAR PEMROGRAMAN LANJUT DENGAN C++," CV WIDINA MEDIA UTAMA, 2023.

[2] Andriana Sari. Apa Itu Struktur Data dan Kegunaannya dalam Pemrograman?. diakses dari https://www.niagahoster.co.id/blog/apa-itu-struktur-data/ 