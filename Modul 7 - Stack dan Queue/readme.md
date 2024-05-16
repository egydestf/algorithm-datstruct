# <h1 align="center">Laporan Praktikum Modul Stack dan Queue</h1>

<p align="center">Egy Destiar Firmandani</p>
<p align="center">2311110061</p>

## Dasar Teori

### Stack

Stack (atau tumpukan) adalah struktur data yang memungkinkan operasi-operasi seperti push dan pop, dimana data yang ditambahkan terakhir akan dihapus terlebih dahulu[1]. Dalam pemrograman, stack digunakan untuk menampung dan mengatur urutan operasi yang perlu dilakukan, seperti dalam penghitungan prioritas, pengelolaan kiri-kanan, dan pengelolaan kiri-kanan dalam sintaks. Stack juga digunakan dalam implementasi fungsi rekursif, seperti fungsi yang memanggil dirinya sendiri, dan dalam implementasi fungsi yang memerlukan informasi tentang sejarah operasi yang telah dilakukan. Contoh aplikasi stack adalah dalam penggunaan fungsi undo dan redo pada aplikasi pengolah kata, serta dalam penggunaan fungsi call stack pada pemrograman fungsi.

![Screenshot 2024-05-16 225442](https://github.com/egydestf/datstruct-practicum/assets/152776726/e3f8e587-0afa-4fb7-b504-f12571d1bc84)

Elemen dapat ditambahkan ke atas stack menggunakan operasi push, dan elemen dapat dihapus dari stack menggunakan operasi pop. Operasi peek digunakan untuk melihat elemen yang terletak di atas stack tanpa menghapusnya. Stack juga dapat digunakan untuk menampung data yang perlu diakses secara terurut, seperti dalam penghitungan prioritas, sehingga elemen dengan prioritas tertinggi dapat diakses terlebih dahulu[2].

### Queue

Queue (atau antrean) adalah struktur data yang memungkinkan operasi-operasi seperti enqueue dan dequeue, dimana data yang ditambahkan terakhir akan dihapus pertama kali[1]. Dalam pemrograman, queue digunakan untuk menampung dan mengatur urutan operasi yang perlu dilakukan, seperti dalam pengelolaan jaringan, pengelolaan proses, dan pengelolaan antrian. Queue juga digunakan dalam implementasi fungsi yang memerlukan informasi tentang sejarah operasi yang telah dilakukan, seperti dalam penghitungan prioritas, sehingga elemen dengan prioritas tertinggi dapat diakses terlebih dahulu. Contoh aplikasi queue adalah dalam penggunaan sistem print dokumen di komputer, serta dalam penggunaan sistem jaringan internet untuk mengatur urutan pengiriman data.

![Screenshot 2024-05-16 225505](https://github.com/egydestf/datstruct-practicum/assets/152776726/7f866514-41a1-4bf8-a80f-1b235a478e52)

Elemen dapat ditambahkan ke dalam queue menggunakan operasi enqueue, dan elemen dapat dihapus dari queue menggunakan operasi dequeue. Operasi peek digunakan untuk melihat elemen yang terletak di depan queue tanpa menghapusnya. Queue juga dapat digunakan untuk menampung data yang perlu diakses secara terurut, seperti dalam penghitungan prioritas, sehingga elemen dengan prioritas tertinggi dapat diakses terlebih dahulu[2].

## Guided 

### 1. Guided 1
<b>Latihan Stack</b>

#### Program:
```C++
#include <iostream>
using namespace std;

string arrayBuku[5];
int maksimal = 5, top = 0;

bool isFull() {
    return (top == maksimal);
}

bool isEmpty() {
    return (top == 0);
}

void pushArrayBuku(string data) {
    if (isFull()) {
        cout << "Data telah penuh" << endl;
    } else {
        arrayBuku[top] = data;
        top++;
    }
}

void popArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dihapus" << endl;
    } else {
        arrayBuku[top - 1] = "";
        top--;
    }
}

void peekArrayBuku(int posisi) {
    if (isEmpty()) {
        cout << "Tidak ada data yang bisa dilihat" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }
        cout << "Posisi ke " << posisi << " adalah " << arrayBuku[index] << endl;
    }
}

int countStack() {
    return top;
}

void changeArrayBuku(int posisi, string data) {
    if (posisi > top) {
        cout << "Posisi melebihi data yang ada" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }
        arrayBuku[index] = data;
    }
}

void destroyArraybuku() {
    for (int i = top; i >= 0; i--) {
        arrayBuku[i] = "";
    }
    top = 0;
}

void cetakArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dicetak" << endl;
    } else {
        for (int i = top - 1; i >= 0; i--) {
            cout << arrayBuku[i] << endl;
        }
    }
}

int main() {
    pushArrayBuku("Kalkulus");
    pushArrayBuku("Struktur Data");
    pushArrayBuku("Matematika Diskrit");
    pushArrayBuku("Dasar Multimedia");
    pushArrayBuku("Inggris");

    cetakArrayBuku();
    cout << "\n";
    cout << "Apakah data stack penuh? " << isFull() << endl;
    cout << "Apakah data stack kosong? " << isEmpty() << endl;
    peekArrayBuku(2);
    popArrayBuku();
    cout << "Banyaknya data = " << countStack() << endl;
    changeArrayBuku(2, "Bahasa Jerman");
    cout << endl;
    cetakArrayBuku();
    cout << "\n";
    destroyArraybuku();
    cout << "Jumlah data setelah dihapus: " << top << endl;
    cetakArrayBuku();

    return 0;
}
```
#### Output:
![Screenshot 2024-05-16 222435](https://github.com/egydestf/datstruct-practicum/assets/152776726/cd8f9d57-97a5-4afc-9160-5dc530aaad63)

Program C++ di atas adalah implementasi dari struktur data stack (pemrosesan data yang berurutan) dengan fungsi-fungsi dasar seperti push, pop, peek, dan destroy. Stack digunakan untuk menampung data dalam bentuk array yang dapat diperbarui secara dinamis.

Pertama, program ini memasukkan lima buku ke dalam stack menggunakan fungsi `pushArrayBuku`. Kemudian, program mencetak isi stack menggunakan fungsi `cetakArrayBuku` untuk memperlihatkan data yang telah dimasukkan. Selanjutnya, program memeriksa apakah stack penuh dengan fungsi `isFull` dan apakah stack kosong dengan fungsi `isEmpty`. Fungsi `peekArrayBuku` digunakan untuk melihat isi stack pada posisi tertentu, namun jika stack kosong, program akan menampilkan pesan _"Tidak ada data yang bisa dilihat"_.

Program juga memiliki fungsi `popArrayBuku` untuk menghapus data dari stack. Jika stack kosong, program akan menampilkan pesan _"Tidak ada data yang dihapus"_. Fungsi `countStack` digunakan untuk menghitung jumlah data yang tersimpan di dalam stack. Fungsi `changeArrayBuku` digunakan untuk mengubah isi data di dalam stack. Jika posisi yang diinginkan melebihi jumlah data yang tersimpan, program akan menampilkan pesan _"Posisi melebihi data yang ada"_. Setelah beberapa operasi pada stack, program menghapus semua data di dalam stack menggunakan fungsi `destroyArraybuku` dan mencetak jumlah data yang tersimpan setelah dihapus.

### 2. Guided 2
<b>Latihan Queue</b>

#### Program:
```C++
#include <iostream>
using namespace std;

const int maksimalQueue = 5; // Maksimal antrian
int front = 0; // Penanda depan antrian
int back = 0; // Penanda belakang antrian
string queueTeller[5]; // Array untuk menyimpan antrian

bool isFull() { // Pengecekan antrian penuh atau tidak
    if (back == maksimalQueue) {
        return true; // =1
    } else {
        return false;
    }
}

bool isEmpty() { // Antrian kosong atau tidak
    if (back == 0) {
        return true;
    } else {
        return false;
    }
}

void enqueueAntrian(string data) { // Menambahkan antrian
    if (isFull()) {
        cout << "Antrian penuh" << endl;
    } else {
        if (isEmpty()) { // Jika antrian kosong
            queueTeller[0] = data;
            front++;
            back++;
        } else { // Jika antrian ada isi
            queueTeller[back] = data;
            back++;
        }
    }
}

void dequeueAntrian() { // Mengurangi antrian
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = queueTeller[i + 1];
        }
        back--;
    }
}

int countQueue() { // Menghitung jumlah antrian
    return back;
}

void clearQueue() { // Menghapus semua antrian
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = "";
        }
        back = 0;
        front = 0;
    }
}

void viewQueue() { // Melihat isi antrian
    cout << "Data antrian teller:" << endl;
    for (int i = 0; i < maksimalQueue; i++) {
        if (queueTeller[i] != "") {
            cout << i + 1 << ". " << queueTeller[i] << endl;
        } else {
            cout << i + 1 << ". (kosong)" << endl;
        }
    }
}

int main() {
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    return 0;
}
```
#### Output:
![Screenshot 2024-05-16 222450](https://github.com/egydestf/datstruct-practicum/assets/152776726/e699c4e6-3a9f-4d96-bd72-47ad87b01f7a)

Program C++ di atas adalah implementasi dari struktur data queue (antrian) yang digunakan untuk menampung data dalam bentuk array yang dapat diperbarui secara dinamis. Queue digunakan untuk mengatur urutan proses yang harus dilakukan, seperti dalam kasus antrian di bank atau kantor pos.

Program ini memiliki fungsi-fungsi dasar seperti enqueue, dequeue, dan view untuk mengatur dan melihat isi antrian. Fungsi `enqueueAntrian` digunakan untuk menambahkan data ke dalam antrian. Jika antrian penuh, program akan menampilkan pesan _"Antrian penuh"_. Jika antrian kosong, program akan menambahkan data ke dalam antrian dan mengupdate penanda depan dan belakang antrian.

Fungsi `dequeueAntrian` digunakan untuk mengurangi data dari antrian. Jika antrian kosong, program akan menampilkan pesan _"Antrian kosong"_. Jika antrian ada isi, program akan menghapus data dari antrian dan mengupdate penanda depan dan belakang antrian.

Fungsi `countQueue` digunakan untuk menghitung jumlah data yang tersimpan di dalam antrian. Fungsi `clearQueue` digunakan untuk menghapus semua data di dalam antrian dan mengupdate penanda depan dan belakang antrian.

Fungsi `viewQueue` digunakan untuk melihat isi antrian. Program ini menampilkan isi antrian dengan nomor urut dan data yang tersimpan. Jika data tidak ada, program akan menampilkan pesan _"(kosong)"_.

Dalam program ini, `enqueueAntrian` digunakan untuk menambahkan dua data, Andi dan Maya, ke dalam antrian. Kemudian, program mencetak isi antrian menggunakan fungsi `viewQueue` dan menghitung jumlah antrian menggunakan fungsi `countQueue`. Selanjutnya, program menghapus data dari antrian menggunakan fungsi `dequeueAntrian` dan mencetak isi antrian lagi. Akhirnya, program menghapus semua data di dalam antrian menggunakan fungsi `clearQueue` dan mencetak isi antrian yang kosong.

## Unguided

### 1. Unguided 1
<b>Buatlah program untuk menentukan apakah kalimat tersebut yang diinputkan dalam program stack adalah palindrom/tidak. Palindrom kalimat yang dibaca dari depan dan belakang sama. Jelaskan bagaimana cara kerja programnya!</b>

#### Program: 
```C++
#include <iostream>
#include <string>
using namespace std;

// fungsi cek palindrom
bool isPolindrom(string str) {
    int start = 0;
    int end = str.length() - 1;

    while (start < end) {
        if (str[start] != str[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

// main program
int main() {
    string input;
    cout << "Masukkan Kalimat : ";
    getline(cin, input);
    if (isPolindrom(input)) {
        cout << "Kalimat tersebut adalah Palindrom." << endl;
    } else {
        cout << "Kalimat tersebut bukan Palindrom." << endl;
    }
    return 0;
}
```

#### Output:
![Screenshot 2024-05-16 223604](https://github.com/egydestf/datstruct-practicum/assets/152776726/9d262388-fe80-4c68-81f7-78fab5749483)

Program di atas adalah program C++ yang berfungsi untuk mengecek apakah sebuah kalimat adalah palindrom atau tidak. Palindrom adalah sebuah kalimat yang ketika dibaca dari awal hingga akhir dan dari akhir hingga awal, maka hasilnya sama.

Program ini dimulai dengan meminta pengguna untuk memasukkan sebuah kalimat melalui input. Kemudian, program akan memanggil fungsi `isPolindrom` dengan parameter kalimat yang dimasukkan pengguna. Fungsi ini akan membandingkan huruf pertama dan terakhir kalimat, kemudian huruf kedua dan terakhir, dan seterusnya hingga tidak ada huruf yang tidak sama. Jika tidak ditemukan huruf yang tidak sama, maka kalimat tersebut adalah palindrom dan program akan mencetak _"Kalimat tersebut adalah Palindrom."_. Jika ditemukan huruf yang tidak sama, maka kalimat tersebut bukan palindrom dan program akan mencetak _"Kalimat tersebut bukan Palindrom."_.

### 2. Unguided 2
<b>Ubah guided queue di atas agar menjadi program inputan user dan program menu!</b>

#### Program:
```C++
#include <iostream>
using namespace std;

const int maksimalQueue = 10; // maks antrian
int front = 0; // penanda depan antrian
int back = 0; // penanda belakang antrian
string queueTeller[5]; // array untuk menyimpan antrian

// fungsi cek antrian (penuh/tidak)
bool isFull() {
    if (back == maksimalQueue) {
        return true; // =1
    } else {
        return false;
    }
}

// fungsi cek antrian (kosong/tidak)
bool isEmpty() {
    if (back == 0) {
        return true;
    } else {
        return false;
    }
}

// fungsi tambah antrian
void enqueueAntrian(string data) {
    if (isFull()) {
        cout << "Antrian penuh" << endl;
    } else {
        if (isEmpty()) { // jika antrian kosong
            queueTeller[0] = data;
            front++;
            back++;
        } else { // jika antrian terisi
            queueTeller[back] = data;
            back++;
        }
    }
}

// fungsi kurangi antrian
void dequeueAntrian() {
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = queueTeller[i + 1];
        }
        back--;
    }
}

// hitung jumlah antrian
int countQueue() {
    return back;
}

// fungsi hapus semua antrian
void clearQueue() {
    if (isEmpty()) {
        cout << "Antrian kosong." << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = "";
        }
        back = 0;
        front = 0;
    }
}

// fungsi lihat isi antrian
void viewQueue() {
    cout << "Data antrian teller:" << endl;
    for (int i = 0; i < maksimalQueue; i++) {
        if (queueTeller[i] != "") {
            cout << i + 1 << ". " << queueTeller[i] << endl;
        } else {
            cout << i + 1 << ". (kosong)" << endl;
        }
    }
}

// fungsi menu
void showMenu() {
    cout << "Pilihan Menu:" << endl;
    cout << "1. Tambah Antrian" << endl;
    cout << "2. Kurangi Antrian" << endl;
    cout << "3. Lihat Antrian" << endl;
    cout << "4. Jumlah Antrian" << endl;
    cout << "5. Hapus Semua Antrian" << endl;
    cout << "6. Keluar" << endl;
}

// main program
int main() {
    int choice; // menyimpan pilihan menu user
    string data; // menyimpan nama

    do {
        showMenu();
        cout << "Masukkan menu pilihan: ";
        cin >> choice; // input pilihan menu user

        // switch case menu
        switch (choice) {
            case 1:
                cout << "Masukkan nama: ";
                cin >> data;
                enqueueAntrian(data);
                break;
            case 2:
                dequeueAntrian();
                break;
            case 3:
                viewQueue();
                break;
            case 4:
                cout << "Jumlah antrian : " << countQueue() << " antrian.\n";
                break;
            case 5:
                clearQueue();
                break;
            case 6:
                cout << "Anda keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan pilih menu dengan benar.\n";
        }
    } while (choice != 6);

    return 0;
}
```

#### Output:

##### Tambah antrian
![Screenshot 2024-05-16 224639](https://github.com/egydestf/datstruct-practicum/assets/152776726/6bcf677b-a541-4232-993f-eb1f3cee7e7f)
![Screenshot 2024-05-16 224710](https://github.com/egydestf/datstruct-practicum/assets/152776726/1092659b-0b22-4a1c-8085-60808035d587)

##### Kurangi antrian
![Screenshot 2024-05-16 224958](https://github.com/egydestf/datstruct-practicum/assets/152776726/0fe74e54-7520-4d54-a8af-c509b6692211)

##### Lihat antrian
![Screenshot 2024-05-16 225128](https://github.com/egydestf/datstruct-practicum/assets/152776726/aa6a09c3-d82a-4f30-8bd1-079a5fd4a268)

##### Jumlah antrian
![Screenshot 2024-05-16 225221](https://github.com/egydestf/datstruct-practicum/assets/152776726/822b507b-1e07-4f02-822f-aa161de11ecf)

##### Hapus semua antrian
![Screenshot 2024-05-16 225329](https://github.com/egydestf/datstruct-practicum/assets/152776726/d6ed89ef-7178-4eb2-b698-ae1eac83e57b)

Program C++ di atas adalah implementasi dari sebuah sistem antrian untuk manajemen teller.

Program tersebut memungkinkan pengguna untuk menambahkan, mengurangi, melihat isi, menghitung jumlah, dan menghapus semua antrian. Berikut adalah fungsi-fungsi yang tersedia dalam program ini:
- Fungsi `isFull()` memeriksa apakah antrian telah penuh. Jika `back` (penanda belakang antrian) telah mencapai `maksimalQueue`, maka antrian dikatakan penuh dan fungsi ini mengembalikan nilai `true`.
- Fungsi `isEmpty()` memeriksa apakah antrian kosong. Jika `back` adalah `0`, maka antrian dikatakan kosong dan fungsi ini mengembalikan nilai `true`.
- Fungsi `enqueueAntrian()`menambahkan data ke dalam antrian. Jika antrian penuh, fungsi ini akan menampilkan pesan _"Antrian penuh"_. Jika antrian kosong, fungsi ini akan menambahkan data ke dalam antrian dan meningkatkan `front` dan `back`. Jika antrian terisi, fungsi ini akan menambahkan data ke dalam antrian dan meningkatkan `back`.
- Fungsi `dequeueAntrian()` mengurangi antrian. Jika antrian kosong, fungsi ini akan menampilkan pesan _"Antrian kosong"_. Jika antrian tidak kosong, fungsi ini akan mengurangi `back` dan memindahkan data dari posisi berikutnya ke posisi yang sedang dihapus.
- Fungsi `countQueue()` menghitung jumlah antrian. Fungsi ini mengembalikan nilai `back`, yang mewakili jumlah antrian.
- Fungsi `clearQueue()` menghapus semua antrian. Jika antrian kosong, fungsi ini akan menampilkan pesan _"Antrian kosong"_. Jika antrian tidak kosong, fungsi ini akan menghapus semua data dalam antrian dan mengembalikan `front` dan `back` ke nilai awal atau 0.
- Fungsi `viewQueue()` menampilkan isi antrian. Fungsi ini akan menampilkan nama-nama yang terdaftar dalam antrian, serta menampilkan _"kosong"_ jika posisi antrian tidak terisi.
- Fungsi `showMenu()` menampilkan menu pilihan untuk pengguna. Menu ini terdiri dari enam pilihan yaitu menambahkan antrian, mengurangi antrian, melihat isi antrian, menghitung jumlah antrian, menghapus semua antrian, dan keluar dari program.

## Kesimpulan

Praktikum Modul 7 Stack dan Queue ini membahas pengenalan dari konsep Stack atau Queue pada C++. Stack adalah struktur data linier yang mengikuti prinsip Last-In-First-Out (LIFO). Ini berarti elemen yang terakhir dimasukkan ke dalam stack akan menjadi elemen pertama yang keluar. Sedangkan Queue adalah struktur data linier di mana elemen yang pertama dimasukkan akan menjadi elemen yang pertama keluar (prinsip First-In-First-Out (FIFO)). Stack memiliki dua operasi utama yaitu push (menambahkan elemen ke atas tumpukan) dan pop (menghapus elemen dari atas tumpukan). Queue memiliki dua operasi utama yaitu enqueue (menambahkan elemen ke ujung belakang antrian) dan dequeue (menghapus elemen dari ujung depan antrian). Perbedaan utama antara stack dan queue adalah prinsip urutan elemen yang dimasukkan dan dihapus. Stack lebih sederhana, sedangkan queue lebih kompleks dalam penerapannya.

## Referensi
[1] E. Sari, "Visualisasi tipe data abstrak stack dan queue," SKRIPSI-2011, 2017.

[2] I. A. Pratiwi and A. Setiawan, "STANQUE: Android-based stack and queue learning media for vocational students," in AIP Conference Proceedings, vol. 2727, no. 1, June 2023.

[3] GeeksForGeeks. Difference between Stack and Queue Data Structures. diakses dari https://www.geeksforgeeks.org/difference-between-stack-and-queue-data-structures/
