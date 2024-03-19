# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>

<p align="center">Egy Destiar Firmandani (2311110061)</p>

## Dasar Teori

Tipe data merupakan bagian penting dari sebuah pemrogaman yang akan mempengaruhi jalannya suatu pemrogaman. Tipe data sendiri adalah pengklasifikasian data berdasarkan jenis dari data tersebut. Tipe data dibutuhkan agar kompiler dapat mengetahui bagaimana sebuah data akan digunakan. Tipe data menjadi blok pembangun untuk data terstruktur pada C++[1]. Dalam C++ sendiri, terdapat beberapa jenis tipe data anatara lain sebagai berikut.

### 1. Tipe Data Primitif

Tipe data primitif dalam C++ adalah jenis tipe data dasar yang langsung didukung oleh bahasa pemrogaman. Contoh tipe data primitif dalam C++ yaitu sebagai berikut.

- Integer, yaitu tipe data untuk menyimpan bilangan bulat.
- Float, yaitu tipe data untuk menyimpan bilangan desimal.
- Char, yaitu tipe data untuk menyimpan data berupa sebuah huruf.
- Bool, yaitu tipe data untuk menyimpan nilai boolean berupa true ataupun false.

### 2. Tipe Data Abstrak

Tipe data abstrak dalam C++ adalah jenis tipe data yang didefinisikan oleh pengguna dengan menggunakan kelas. Tipe data abstrak memiliki beberapa karakteristik yang memungkinkan pengguna untuk menggunakannya dengan mudah tanpa perlu mengetahui bagaimana tipe data tersebut dibangun[2]. Pada tipe data abstrak bisa berisi banyak tipe data, jadi nilainya bisa lebih dari satu dan beragam tipe data.  Fitur Class adalah fitur Object Oriented Program(OPP) pada bahasa C++ yang mirip dengan fitur data structures Struct pada bahasa C. Keduanya berfungsi untuk membungkus tipe data di dalamnya sebagai anggota.

### 3. Tipe Data Koleksi

Tipe data koleksi dalam C++ adalah tipe data yang digunakan untuk menyimpan dan mengelola koleksi atau sekumpulan data. Tipe data koleksi berguna untuk menyimpan, mengelola, dan mengakses sejumlah besar data dengan cara yang terstruktur. Beberapa tipe data koleksi dalam C++ antara lain sebagai berikut.

- `Array`, yaitu tipe data koleksi yang didefinisikan oleh pengguna dengan menggunakan kurung siku. Setiap elemen dalam array harus memiliki tipe data yang sama.
- `Vector`, yaitu berisi elemen dengan tipe data yang berbeda dan dapat menjadi lebih dinamis dibandingkan array. Kemampuan vector bukan hanya pada jumlah elemen yang dinamis, vector pada C/C++ juga dilengkapi dengan fitur-fitur pelengkap seperti element access, iterators, capacity, modifiers.
- `Map`, yaitu tipe data koleksi yang didefinisikan oleh pengguna dengan menggunakan tipe data `std::map`. Map dapat digunakan untuk menyimpan kumpulan data yang dapat diakses menggunakan tipe data `std::string` sebagai key. Map terasa mirip dengan array namun dengan index yang memungkinkan untuk berupa tipe data selain integer.

## Guided 

### 1. Guided 1: Tipe Data Primitif

```C++
#include <iostream>
using namespace std;

// main program
int main() {
    // deklarasi dan inisialisasi
    char op;
    float num1, num2;
    
    // user diminta memilih operator yg tersedia
    cout << "Masukkan Operator (+, - , *, /) : ";
    cin >> op;

    // user diminta input 2 buah bilangan yg akan dioperasikan
    cout << "\nMasukkan Bilangan ke-1 dan ke-2.\n";
    cin >> num1 >> num2;

    // switch statement
    switch (op)
    {
    case '+': // jika user input '+', maka fungsi penjumlahan berjalan
        cout << "Hasil Penjumlahan Bilangan: ";
        cout << num1 + num2;
        break; // program berhenti
    case '-': // jika user input '-', maka fungsi pengurangan berjalan
        cout << "Hasil Pengurangan Bilangan: ";
        cout << num1 - num2;
        break;
    case '*': // jika user input '*', maka fungsi perkalian berjalan
        cout << "Hasil Perkalian Bilangan: ";
        cout << num1 * num2;
        break;
    case '/': // jika user input '/', maka fungsi pembagian berjalan
        cout << "Hasil Pembagian Bilangan: ";
        cout << num1 / num2;
        break;
    
    /* jika user input selain operator yg tersedia di atas,
    maka akan menampilkan default output di bawah ini */
    default:
        cout << "Error! operator is not correct";
    }

    return 0;
}
```
Program di atas adalah perintah operasi matematika sederhana 2 bilangan.

Program dimulai dari inisialisasi operator menjadi variabel `op` dengan tipe data `char` dan variabel `num1, num2` dengan tipe `float`. Kedua variabel tersebut masing-masing akan digunakan untuk menyimpan suatu nilai sementara dari program tersebut. Kemudian, program akan meminta input dari user berupa simbol operator matematika yang tersedia (+, - , *, /). Program juga akan meminta input dari user berupa 2 buah bilangan bulat yang akan dioperasikan program. Terakhir, program akan menjalankan switch case agar program hanya menjalankan operator yang telah diinput user sebelumnya. Masing-masing case diberi perintah atau fungsi sesuai dengan operator matematika pada umumnya. Jika user menginput selain operator yang telah disediakan case, maka program akan menampilkan default output yang berisi pengingat bahwa operator yang dimasukkan salah.

### 2. Guided 2: Tipe Data Abstrak

```C++
#include <iostream>

// membuat tempat untuk menyimpan isian struct
struct Mahasiswa
{
    char *name; // untuk isian nama
    char *address; // untuk isian alamat
    int age; // untuk isian usia
};

// main program
int main() {

    // menggunakan fungsi struct dan inisialisasi
    struct Mahasiswa mhs1, mhs2;
    // mengisi nilai struct
    mhs1.name = "Rusdi"; // nama
    mhs1.address = "Ngawi"; // alamat
    mhs1.age = 25; // usia
    mhs2.name = "Ashel";
    mhs2.address = "Jakarta";
    mhs2.age = 19;

    // print isi struct
    /* fungsi printf bawaan dari library iostream
    sehingga tidak perlu cout dari std */
    printf("### Mahasiswa 1 ###\n"); // \n untuk mengakhiri baris
    printf("Nama\t: %s\n", mhs1.name); // \t untuk tab
    printf("Alamat\t: %s\n", mhs1.address); // %s mendefinisikan output sbg string
    printf("Umur\t: %d\n", mhs1.age); // %d mendefinisikan output sbg decimal
    printf("### Mahasiswa 2 ###\n");
    printf("Nama\t: %s\n", mhs2.name);
    printf("Alamat\t: %s\n", mhs2.address);
    printf("Umur\t: %d\n", mhs2.age);

    return 0;
}
```
Program di atas adalah program untuk menampilkan fungsi struct secara sederhana.

Program dimulai dengan membuat variabel bernama `Mahasiswa` untuk menyimpan isian struct. Isian struct juga diisi dengan variabel untuk menampung value dari masing-masing isi struct. Sebagai contoh variabel `name` untuk menampung nama dari mahasiswa. Masuk ke main program dengan menginisialisasi struct untuk digunakan dan membuat variabel untuk menampung hasil isian struct. Kemudian, struct `Mahasiswa` diisi sesuai dengan tempatnya. Setelah semua variabel dalam struct `Mahasiswa` terisi, cetak isi struct dengan mencetak variabel tampungan yang dibuat pada main program dan variabel dalam struct. Contohnya `mhs1.name` ,`mhs1` sebagai variabel tampungan main program dan `name` sebagai variabel dalam struct tersebut.

### 3. Guided 3: Tipe Data Koleksi

```C++
#include <iostream>
using namespace std;

// main program
int main() {
    // deklarasi dan inisialisasi isi array
    int nilai[5]; // set 5 sbg jumlah indeks array
    nilai[0] = 23;
    nilai[1] = 50;
    nilai[2] = 34;
    nilai[3] = 78;
    nilai[4] = 90;

    // cetak isi array
    cout << "Isi array pertama\t: " << nilai[0] << endl;
    cout << "Isi array kedua \t: " << nilai[1] << endl;
    cout << "Isi array ketiga\t: " << nilai[2] << endl;
    cout << "Isi array keempat\t: " << nilai[3] << endl;
    cout << "Isi array kelima\t: " << nilai[4] << endl;

    return 0;
}
```
Program di atas adalah program untuk menampilkan isi array.

Pada main program, program dimulai dengan mendeklarasikan dan menginisialisasi array dengan nama variabel `nilai`. Isi dari array dideklarasikan sebagai data `integer` dengan jumlah 5 indeks dalam array tersebut. Kemudian setiap indeks array tersebut dengan value berupa data `integer` atau bilangan bulat. Terakhir, array dicetak dengan memanggil nama variabel `nilai` dan urutan indeks yang akan dicetak.

## Unguided 

### 1. Buatlah program menggunakan tipe data primitif minimal dua fungsi dan bebas. Menampilkan program, jelaskan program tersebut dan ambil kesimpulan dari materi tipe data primitif!

#### Program: 
```C++
#include <iostream> // standard c++ library
using namespace std; // agar tdk perlu 'std::' di setiap cout atau cin

// fungsi untuk luas lingkaran
double luasLingkaran(double phi, int r) {
    return phi * (r*r); // rumus hitung luas lingkaran
}

// fungsi untuk keliling lingkaran
double kelilingLingkaran(double phi, int r) {
    return phi * (r*2); // rumus hitung keliling lingkaran
}

// main program
int main() {
    // inisialisasi
    const double phi = 3.14; // nilai phi konstan tdk bisa diubah
    int r; // jari-jari lingkaran
    
    // input jari-jari lingkaran (cm)
    cout << "Masukkan jari-jari lingkaran: ";
    cin >> r; // pengguna diminta input jari-jari lingkaran

    // variabel untuk memanggil fungsi lingkaran & menyimpan hasil
    double luas = luasLingkaran(phi, r);
    double keliling = kelilingLingkaran(phi, r);

    // output cetak variabel hasil
    cout << "Luas Lingkaran   \t: " << luas << " cm" << endl;
    cout << "Keliling Lingkaran\t: " << keliling << " cm" << endl;

    return 0;
}
```
#### Output:
![Screenshot (189)](https://github.com/egydestf/algorithm-datstruct/assets/152776726/43732d0f-ab88-4332-b1b1-8ac0d5af2b0f)

Program di atas adalah program sederhana untuk menghitung luas dan keliling lingkaran.

Program dimulai dengan membuat fungsi untuk menghitung luas dan keliling lingkaran. Untuk fungsi luas lingkaran diberi nama `luasLingkaran` dengan tipe data `double` sebagai tampungan hasil perhitungannya nanti. Sedangkan untuk fungsi keliling lingkaran diberi nama `kelilingLingkaran` dengan tipe data `double` sebagai tampungan hasil perhitungan. Dalam masing-masing fungsi tersebut terdapat pula variabel dengan nama `r` bertipe `int` untuk menyimpan input jari-jari lingkaran dan variabel `phi` bertipe `double`. Nilai return pada masing-masing fungsi tersebut nantinya akan memproses operasi matematika dari perhitungan luas dan keliling lingkaran sesuai kerja rumusnya.

Masuk ke main program, masing-masing variabel dalam fungsi diinisialisasi dengan set variabel `phi` sebesar 3.14 dan bernilai konstan. `const` dipakai untuk menginisialisasi bahwa variabel `phi` bernilai konstan dan tidak bisa diubah. Kemudian variabel `r` untuk menampung input jari-jari juga diinisialisasi. Setelah variabel `r` diinisialisasi, program akan meminta user untuk menginput jari-jari lingkaran yang diinginkan melalui `cin >> r;`. Untuk memproses dan mencetak nilai jari-jari yang sudah diinput user, variabel fungsi harus ditampung terlebih dahulu pada variabel baru dengan nama `luas` dan `keliling`. Pada kedua variabel baru tersebut masing-masing harus diisi dengan variabel fungsi lingkaran yang sudah dibuat pada awal program tadi. Terakhir, barulah program dapat mencetak dan menampilkan hasilnya melalui `cout` dari variabel baru tersebut.

### 2. Jelaskan fungsi dari class dan struct secara detail dan berikan contoh programnya

Class adalah cetak biru atau blueprint yang digunakan untuk membuat kerangka dasar untuk objek. Class mendefinisikan atribut (properti) dan method (fungsi) yang akan dijadikan bagian dari objek. Class hanya digunakan untuk membuat kerangka dasar, dan objek yang dihasilkan dari class akan mengadopsi semua karakteristik dan perilaku yang telah ditetapkan dalam class.

Struct atau structure adalah kumpulan dari beberapa variabel dengan beragam tipe data yang dibungkus dalam satu varabel. Struct juga dikenal dengan records dalam bahasa pemrograman lain seperti Pascal. Struct digunakan untuk mengelompokkan variabel dengan tipe data yang terkait.

Class dan struct digunakan untuk membuat objek yang memiliki karakteristik dan perilaku yang terkait. Class digunakan untuk membuat kerangka dasar, dan objek yang dihasilkan dari class akan mengadopsi semua karakteristik dan perilaku yang telah ditetapkan dalam class. Struct digunakan untuk mengelompokkan variabel dengan tipe data yang terkait.

#### Program: 
```C++
#include <iostream>
using namespace std;

/* membuat isian struct
-- struct desc untuk isian deskripsi album -- */
struct desc {
    string albumName; // nama album
    string bandName; // nama band
    int releasedYear; // tahun rilis
};

/* membuat isian class yg bersifat publik
-- class detail untuk detail album -- */
class detail {
    public:
    string genre; // genre album
    string studio; // alamat studio
    string label; // label album
    string producer; // produser album
};

// main program
int main() {
    // inisialisasi struct dan membuat variabel untuk menampung isian struct
    struct desc var1;

    /* mengisi struct sesuai dengan masing-masing isian
     -- ini akan mengisi struct pada var1 -- */
    var1.albumName = "Dookie";
    var1.bandName = "Green Day";
    var1.releasedYear = 1994;

    // cetak output struct dari variabel var1
    cout << "========= ALBUM DESCRIPTION (struct) ===" << endl;
    cout << "Name\t: " << var1.albumName << endl;
    cout << "By\t: " << var1.bandName << endl;
    cout << "Year\t: " << var1.releasedYear << endl;

    // inisialisasi class dan membuat variabel untuk menampung isian class
    detail var2;

    /* mengisi class sesuai dengan masing-masing isian
     -- ini akan mengisi class pada var2 -- */
    var2.genre = "Pop Punk,Punk Rock,Skate Punk";
    var2.studio = "Fantasy, Berkeley, California";
    var2.label = "Reprise";
    var2.producer = "Rob Cavallo and Green Day";

    // cetak output class dari variabel var2
    cout << "========= ALBUM DETAIL (class) =========" << endl;
    cout << "Genre\t: " << var2.genre << endl;
    cout << "Studio\t: " << var2.studio << endl;
    cout << "Label\t: " << var2.label << endl;
    cout << "Prod\t: " << var2.producer << endl;
    cout << "========================================" << endl;

    return 0;
}
```
#### Output:
![Screenshot (190)](https://github.com/egydestf/algorithm-datstruct/assets/152776726/a070df26-fc16-4ebe-b95b-37b9023a82b6)

Program di atas adalah program untuk menampilkan isi struct dan class dari album band Green Day.

Variabel struct bernama `desc` dibuat untuk menyimpan isian struct. Isian struct diisi dengan variabel untuk menampung value dari masing-masing isi struct. Sebagai contoh variabel `albumName` bertipe `string` untuk menampung nama album, `bandName` bertipe `string` untuk nama band, dan `releasedYear` bertipe `int` untuk tahun rilis.

Variabel class bernama `detail` dibuat untuk detail singkat album. Class `detail` didefinisikan sebagai `public` agar dapat diakses dari manapun di dalam program. Ini berarti bahwa anggota dengan hak akses public dapat diakses oleh fungsi lain, termasuk fungsi lain dalam class yang berbeda. Sebagai contoh variabel `genre` bertipe `string` untuk menampung genre dari album.

Masuk ke main program dengan menginisialisasi struct untuk digunakan dan membuat variabel `var1` untuk menampung hasil isian struct. Kemudian, struct `desc` diisi sesuai dengan tempatnya. Setelah semua variabel dalam struct `desc` terisi, cetak isi struct dengan mencetak variabel tampungan `var1` yang dibuat pada main program dan variabel dalam struct. Contohnya `var1.albumName` ,`var1` sebagai variabel tampungan yang dibuat di main program dan `name` sebagai variabel dalam struct tersebut.

Selanjutnya, dilakukan juga inisialisasi pada class `detail` dan menambahkan variabel `var2` untuk menampung hasil isian class. Kemudian, class `detail` diisi sesuai dengan tempatnya. Setelah semua variabel dalam class `detail` terisi, cetak isi class dengan mencetak variabel tampungan `var2` yang dibuat pada main program dan variabel dalam struct. Contohnya `var2.genre`,`var2` sebagai variabel tampungan yang dibuat pada main program dan `genre` sebagai variabel dalam struct tersebut.

### 3. Buat dan jelaskan program menggunakan fungsi map dan jelaskan perbedaan dari array dengan map.

##### Array
- Array adalah struktur data yang menyimpan elemen-elemen dengan tipe data yang sama secara berurutan dalam memori.
- Ukuran array harus ditentukan pada saat deklarasi dan tidak dapat diubah setelahnya.
- Akses ke elemen array dilakukan dengan menggunakan indeks numerik.
- Array cocok digunakan ketika jumlah elemen yang tetap diketahui sebelumnya dan akses langsung ke elemen berdasarkan indeks diperlukan.

##### Map
- Map adalah struktur data yang memetakan kunci (key) ke nilai (value) yang terkait.
- Map memungkinkan penggunaan kunci dengan tipe data yang berbeda, tidak terbatas pada tipe data numerik seperti pada array.
- Ukuran map dapat dinamis, dan elemen dapat ditambah atau dihapus saat program berjalan.
- Akses ke elemen map dilakukan dengan menggunakan kunci, bukan indeks numerik.
- Map sangat berguna ketika hubungan antara kunci dan nilai perlu dipertahankan, seperti dalam kasus kamus atau database.

Dengan demikian, perbedaan utama antara array dan map adalah dalam cara mereka menyimpan dan mengakses data. Array cocok untuk koleksi elemen dengan tipe data yang sama dan akses langsung melalui indeks numerik, sementara map lebih fleksibel dalam hal tipe data kunci dan nilai serta memungkinkan akses berdasarkan kunci yang terkait.

#### Program: 
```C++
#include <iostream>
#include <map> // library untuk map
using namespace std;

// main program
int main() {
    /* inisialisasi map dengan nama "dookie"
     -- int untuk key map dan string untuk value map -- */
    map <int, string> dookie;

    /* setiap key diisi dengan value berupa string data
     -- isian key bisa dimulai dari key indeks 0 -- */
    dookie[0] = "Burnout";
    dookie[1] = "Having a Blast";
    dookie[2] = "Chump";
    dookie[3] = "Longview";
    dookie[4] = "Welcome to Paradise";
    dookie[5] = "Pulling Teeth";
    dookie[6] = "Basket Case";
    dookie[7] = "She";
    dookie[8] = "Sassafras Roots";
    dookie[9] = "When I Come Around";
    dookie[10] = "Coming Clean";
    dookie[11] = "Emenius Sleepus";
    dookie[12] = "In The End";
    dookie[13] = "F.O.D.";
    dookie[14] = "All by Myself";

    // cetak map dari masing-masing key map
    cout << "===== DOOKIE TRACK LIST =====" << endl;
    cout << "Track-01: " << dookie[0] << endl;
    cout << "Track-02: " << dookie[1] << endl;
    cout << "Track-03: " << dookie[2] << endl;
    cout << "Track-04: " << dookie[3] << endl;
    cout << "Track-05: " << dookie[4] << endl;
    cout << "Track-06: " << dookie[5] << endl;
    cout << "Track-07: " << dookie[6] << endl;
    cout << "Track-08: " << dookie[7] << endl;
    cout << "Track-09: " << dookie[8] << endl;
    cout << "Track-10: " << dookie[9] << endl;
    cout << "Track-11: " << dookie[10] << endl;
    cout << "Track-12: " << dookie[11] << endl;
    cout << "Track-13: " << dookie[12] << endl;
    cout << "Track-14: " << dookie[13] << endl;
    cout << "Track-15: " << dookie[14] << endl;
    cout << "=============================" << endl;
    // output akan berupa value dari masing-masing key tsb.

    return 0;
}
```
#### Output:
![Screenshot (191)](https://github.com/egydestf/algorithm-datstruct/assets/152776726/ff2b5696-1d3d-4f32-874f-c86803230790)

Program di atas adalah program untuk menampilkan map dari list lagu dalam album dookie.

Program dimulai dengan inisialisasi map dengan nama `dookie` dengan tipe key `int` dan value `string`. Kemudian setiap key diisi dengan value berupa data `string`. Pengisian key map bisa dimulai dari indeks 0. Map diisi dengan cara menambahkan value pada key map. Sebagai contoh map `dookie[0]` dengan value `"Burnout"`, artinya pada map `dookie` indeks 0 berisi kata `"Burnout"` berupa `string`. Terakhir, map dicetak dengan mengakses nama map dan masing-masing key nya. Output yang tercetak akan berupa value dari masing-masing key tersebut.

## Kesimpulan

Praktikum Modul 1 Tipe Data ini membahas pengenalan dari tipe data yang ada pada program C++ seperti primitif, abstrak, dan koleksi. Tipe data primitif adalah tipe data dasar yang langsung didukung oleh bahasa pemrogaman. Tipe data abstrak adalah tipe data yang didefinisikan oleh user dengan menggunakan kelas (class). Tipe data koleksi adalah tipe data yang digunakan untuk menyimpan dan mengelola koleksi atau sekumpulan data. Masing-masing dari tipe data tersebut mempunyai fungsi yang berbeda sesuai dengan penggunaannya.

## Referensi
[1] R.H. Sianipar, "Pemrograman C++ Untuk Pemula," Penerbit INFORMATIKA, Vol.1, 2014.

[2] Geeksforgeeks. Abstract Data Types (C++ and Java). diakses dari https://www.geeksforgeeks.org/abstract-data-types/

[3] Geeksforgeeks. Map of Arrays in C++. diakses dari https://www.geeksforgeeks.org/map-of-arrays-in-cpp/
