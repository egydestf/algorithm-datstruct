# <h1 align="center">Laporan Praktikum Modul Linked List</h1>

<p align="center">Egy Destiar Firmandani</p>
<p align="center">2311110061</p>

## Dasar Teori

Linked List adalah struktur data yang terdiri dari elemen-elemen yang disambungkan secara langsung menggunakan pointer[1]. Setiap elemen dalam linked list disebut sebagai "node" dan memiliki dua bagian utama yaitu data dan pointer. Data adalah nilai yang disimpan dalam node, sedangkan pointer mengarahkan ke node lain yang berada di dalam linked list.

Linked list dapat dibuat dengan cara membuat node pertama dan kemudian menambahkan node lain secara berurutan. Setiap node yang ditambahkan memiliki pointer yang mengarahkan ke node berikutnya, sehingga linked list dapat dibuat secara dinamis[2]. Linked list ini sangat berguna ketika pengguna perlu menambahkan atau menghapus elemen secara dinamis dalam suatu program.

Dalam linked list, operasi yang paling umum adalah traversal, yaitu proses mengunjungi setiap node dalam linked list secara berurutan. Traversal dapat dilakukan dengan cara mengikuti pointer dari node ke node lainnya. Selain itu, linked list juga dapat digunakan untuk melakukan operasi lain seperti mencari nilai tertentu, menambahkan atau menghapus node, dan lain-lain[1].

### 1. Single Linked List

Single Linked List (SLL) adalah jenis linked list yang paling sederhana, di mana setiap node memiliki pointer yang mengarahkan ke node berikutnya. Dalam SLL, setiap node memiliki dua bagian utama yaitu data dan pointer. Data adalah nilai yang disimpan dalam node, sedangkan pointer mengarahkan ke node berikutnya dalam linked list. SLL dapat dibuat dengan cara membuat node pertama dan kemudian menambahkan node lain secara berurutan. Setiap node yang ditambahkan memiliki pointer yang mengarahkan ke node berikutnya, sehingga SLL dapat dibuat secara dinamis. SLL sangat berguna ketika pengguna perlu menambahkan atau menghapus elemen secara dinamis dalam suatu program, serta dalam aplikasi yang memerlukan akses data secara berurutan.

### 2. Double Linked List

Double Linked List (DLL) adalah jenis linked list yang lebih kompleks dibandingkan dengan Single Linked List (SLL), di mana setiap node memiliki dua pointer yaitu pointer "next" yang mengarahkan ke node berikutnya dan pointer "prev" yang mengarahkan ke node sebelumnya. Dengan demikian, DLL memungkinkan akses ke node secara berurutan dalam dua arah, baik dari awal maupun dari akhir linked list. DLL sangat berguna ketika pengguna perlu melakukan operasi yang memerlukan akses ke node secara berurutan dalam dua arah, seperti mencari nilai tertentu, menambahkan atau menghapus node, serta dalam aplikasi yang memerlukan akses data secara berurutan dalam dua arah. Oleh karena itu, DLL sering digunakan dalam aplikasi yang memerlukan kinerja yang lebih baik dan fleksibilitas dalam mengakses data.

## Guided 

### 1. Guided 1
<b>Latihan Single Linked List</b>

#### Program:
```C++
#include <iostream>
using namespace std;

///PROGRAM SINGLE LINKED LIST NON-CIRCULAR
//Deklarasi Struct Node
struct Node {
    //komponen/member
    int data;
    Node *next;
};
    Node *head;
    Node *tail;

//Inisialisasi Node
void init() {
    head = NULL;
    tail = NULL;
}

// Pengecekan
bool isEmpty() {
    if (head == NULL)
    return true;
    else
    return false;
}

//Tambah Depan
void insertDepan(int nilai) {
    //Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true){
        head = tail = baru;
        tail->next = NULL;
    }
    else{
        baru->next = head;
        head = baru;
    }
}

//Tambah Belakang
void insertBelakang(int nilai) {
    //Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true){
        head = tail = baru;
        tail->next = NULL;
    }
    else{
    tail->next = baru;
    tail = baru;
    }
}

//Hitung Jumlah List
int hitungList(){
    Node *hitung;
    hitung = head;
    int jumlah = 0;
    while( hitung != NULL ){
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}

//Tambah Tengah
void insertTengah(int data, int posisi) {
    if( posisi < 1 || posisi > hitungList() ){
        cout << "Posisi diluar jangkauan" << endl;
    }
    else if( posisi == 1){
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else{
        Node *baru, *bantu;
        baru = new Node();
        baru->data = data;
        // tranversing
            bantu = head;
            int nomor = 1;
        while( nomor < posisi - 1 ){
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

//Hapus Depan
void hapusDepan() {
    Node *hapus;
    if (isEmpty() == false){
        if (head->next != NULL){
            hapus = head;
            head = head->next;
            delete hapus;
        }
        else{
            head = tail = NULL;
        }
    }
    else{
        cout << "List kosong!" << endl;
    }
}

//Hapus Belakang
void hapusBelakang() {
    Node *hapus;
    Node *bantu;
    if (isEmpty() == false){
        if (head != tail){
            hapus = tail;
            bantu = head;
            while (bantu->next != tail){
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
        delete hapus;
        }
        else{
            head = tail = NULL;
        }
    }
    else{
        cout << "List kosong!" << endl;
    }
}

//Hapus Tengah
void hapusTengah(int posisi) {
    Node *hapus, *bantu, *bantu2;
    if( posisi < 1 || posisi > hitungList() ){
        cout << "Posisi di luar jangkauan" << endl;
    }
    else if( posisi == 1){
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else{
        int nomor = 1;
        bantu = head;
        while( nomor <= posisi ){
            if( nomor == posisi-1 ){
                bantu2 = bantu;
            }
            if( nomor == posisi ){
                hapus = bantu;
            }
            bantu = bantu->next;
            nomor++;
        }
        bantu2->next = bantu;
    delete hapus;
    }
}

//Ubah Depan
void ubahDepan(int data) {
    if (isEmpty() == false){
        head->data = data;
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}

//Ubah Tengah
void ubahTengah(int data, int posisi) {
    Node *bantu;
    if (isEmpty() == false){
        if( posisi < 1 || posisi > hitungList() ){
            cout << "Posisi di luar jangkauan" << endl;
        }
        else if( posisi == 1){
            cout << "Posisi bukan posisi tengah" << endl;
        }
        else{
            bantu = head;
            int nomor = 1;
            while (nomor < posisi){
                bantu = bantu->next;nomor++;
            }
            bantu->data = data;
        }
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}

//Ubah Belakang
void ubahBelakang(int data) {
    if (isEmpty() == false){
        tail->data = data;
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}

//Hapus List
void clearList() {
    Node *bantu, *hapus;
    bantu = head;
    while (bantu != NULL){
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}

//Tampilkan List
void tampil() {
    Node *bantu;
    bantu = head;
    if (isEmpty() == false){
        while (bantu != NULL){
            cout << bantu->data << ends;
            bantu = bantu->next;
        }
        cout << endl;
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}

// main program
int main() {
    init();
    insertDepan(3);
    tampil();
    insertBelakang(5);
    tampil();
    insertDepan(2);
    tampil();
    insertDepan(1);
    tampil();
    hapusDepan();
    tampil();
    hapusBelakang();
    tampil();
    insertTengah(7,2);
    tampil();
    hapusTengah(2);
    tampil();
    ubahDepan(1);
    tampil();
    ubahBelakang(8);
    tampil();
    ubahTengah(11, 2);
    tampil();

    insertTengah(7,1);
    tampil();
    return 0;
}
```
Program di atas adalah contoh implementasi dari Single Linked List pada C++.

#### Penjelasan fungsi:
- Fungsi `init()` digunakan untuk menginisialisasi sebuah linked list. Dalam program ini, fungsi ini memastikan bahwa `head` dan `tail` dari linked list menjadi `NULL`, sehingga linked list dalam keadaan kosong dan siap digunakan untuk operasi lainnya.
- Fungsi `isEmpty()` digunakan untuk memeriksa apakah linked list masih kosong atau tidak. Fungsi ini mengembalikan nilai `true` jika `head` dari linked list adalah `NULL`, yang berarti linked list masih kosong. Jika `head` tidak `NULL`, maka fungsi ini mengembalikan nilai `false`, yang berarti linked list tidak kosong.
- Fungsi `insertDepan()` digunakan untuk menambahkan elemen ke depan linked list. Fungsi ini membuat sebuah node baru dengan nilai yang diberikan dan menghubungkan node baru dengan node yang sebelumnya menjadi `head` dari linked list. Jika linked list masih kosong, maka node baru menjadi `head` dan `tail` dari linked list.
- Fungsi `insertBelakang()` digunakan untuk menambahkan elemen ke belakang linked list. Fungsi ini membuat sebuah node baru dengan nilai yang diberikan dan menghubungkan node baru dengan node yang sebelumnya menjadi `tail` dari linked list. Jika linked list masih kosong, maka node baru menjadi `head` dan `tail` dari linked list.
- Fungsi `hitungList()` digunakan untuk menghitung jumlah elemen dalam linked list. Fungsi ini mengembalikan jumlah elemen yang terdapat dalam linked list dengan cara menghitung jumlah node yang terhubung dari `head` hingga `tail`.
- Fungsi `insertTengah()` digunakan untuk menambahkan elemen ke tengah linked list. Fungsi ini membuat sebuah node baru dengan nilai yang diberikan dan menghubungkan node baru dengan node yang sebelumnya menjadi node yang berada di posisi tengah linked list. Jika posisi yang diberikan tidak valid, maka fungsi ini tidak melakukan operasi apapun.
- Fungsi `hapusDepan()` digunakan untuk menghapus elemen dari depan linked list. Fungsi ini menghapus node yang menjadi `head` dari linked list dan menggantikan dengan node yang berikutnya. Jika linked list masih kosong, maka fungsi ini tidak melakukan operasi apapun.
- Fungsi `hapusBelakang()` digunakan untuk menghapus elemen dari belakang linked list. Fungsi ini menghapus node yang menjadi `tail` dari linked list dan menggantikan dengan node yang sebelumnya. Jika linked list masih kosong atau hanya memiliki satu node, maka fungsi ini menghapus semua node dan mengembalikan linked list menjadi kosong.
- Fungsi `hapusTengah()` digunakan untuk menghapus elemen dari tengah linked list. Fungsi ini menghapus node yang berada di posisi yang diberikan dan menggantikan dengan node yang sebelumnya. Jika posisi yang diberikan tidak valid, maka fungsi ini tidak melakukan operasi apapun.
- Fungsi `ubahDepan()` digunakan untuk mengubah nilai elemen yang berada di depan linked list. Fungsi ini mengubah nilai `head` dari linked list menjadi nilai yang diberikan. Jika linked list masih kosong, maka fungsi ini tidak melakukan operasi apapun.
- Fungsi `ubahBelakang()` digunakan untuk mengubah nilai elemen yang berada di belakang linked list. Fungsi ini mengubah nilai `tail` dari linked list menjadi nilai yang diberikan. Jika linked list masih kosong, maka fungsi ini tidak melakukan operasi apapun.
- Fungsi `ubahTengah()` digunakan untuk mengubah nilai elemen yang berada di tengah linked list. Fungsi ini mengubah nilai node yang berada di posisi yang diberikan menjadi nilai yang diberikan. Jika posisi yang diberikan tidak valid, maka fungsi ini tidak melakukan operasi apapun.
- Fungsi `clearList()` digunakan untuk menghapus semua elemen dalam linked list. Fungsi ini menghapus semua node yang terhubung dari `head` hingga `tail` dan mengembalikan linked list menjadi kosong.
- Fungsi `tampil()` digunakan untuk menampilkan isi linked list. Fungsi ini mengembalikan isi linked list dengan cara menghitung dari `head` hingga `tail` dan menampilkan nilai setiap node. Jika linked list masih kosong, maka fungsi ini menampilkan pesan bahwa linked list masih kosong.

### 2. Guided 2
<b>Latihan Double Linked List</b>

```C++
#include <iostream>
using namespace std;

class Node {
    public:int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
        public:
        Node* head;
        Node* tail;
        DoublyLinkedList() {
            head = nullptr;
            tail = nullptr;
    }
    void push(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->prev = nullptr;
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        } 
        else {
            tail = newNode;
        }
        head = newNode;
    }
    void pop() {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } 
        else {
            tail = nullptr;
        }
        delete temp;
    }
    bool update(int oldData, int newData) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == oldData) {
                current->data = newData;
                return true;
            }
            current = current->next;
        }
        return false;
    }
    void deleteAll() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }
    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

// main program
int main() {
    DoublyLinkedList list;
    while (true) {
        cout << "1. Add data" << endl;
        cout << "2. Delete data" << endl;
        cout << "3. Update data" << endl;
        cout << "4. Clear data" << endl;
        cout << "5. Display data" << endl;
        cout << "6. Exit" << endl;int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                int data;
                cout << "Enter data to add: ";
                cin >> data;
                list.push(data);
                break;
            }
            case 2: {
                list.pop();
                break;
            }
            case 3: {
                int oldData, newData;
                cout << "Enter old data: ";
                cin >> oldData;
                cout << "Enter new data: ";
                cin >> newData;
                bool updated = list.update(oldData, newData);
                if (!updated) {
                    cout << "Data not found" << endl;
                }
                break;
            }
            case 4: {
                list.deleteAll();
                break;
            }
            case 5: {
                list.display();
                break;
            }
            case 6: {
                return 0;
            }
            default: {
                cout << "Invalid choice" << endl;
                break;
            }
        }
    }
    return 0;
}
```
Program C++ di atas adalah implementasi dari Double Linked List yang dapat menambahkan, menghapus, mengupdate, dan menghapus semua data yang tersimpan.

Program ini memiliki menu yang memungkinkan pengguna untuk memilih operasi yang ingin dilakukan terhadap data. Program tersebut menampilkan menu yang berisi enam pilihan yaitu menambahkan data, menghapus data, mengupdate data, menghapus semua data, menampilkan data, dan keluar. Pengguna diminta memilih pilihan yang diinginkan dengan memasukkan nomor pilihan. Setiap nomor pilihan tersebut berada di dalam proses switch case dan memiliki fungsi yang berbeda sesuai dengan pilihan menu.

Berikut adalah beberapa kemungkinan yang terjadi pada switch case, jika pengguna memasukkan nomor pilihan pada menu.
- Jika pengguna memilih opsi 1, program akan meminta pengguna untuk memasukkan data yang ingin ditambahkan. Data tersebut kemudian ditambahkan ke dalam linked list menggunakan fungsi `push()`.
- Jika pengguna memilih opsi 2, program akan menghapus data yang terakhir ditambahkan menggunakan fungsi `pop()`.
- Jika pengguna memilih opsi 3, program akan meminta pengguna untuk memasukkan data lama dan baru yang ingin diupdate. Fungsi `update()` kemudian digunakan untuk mencari data lama dan menggantinya dengan data baru. Jika data tidak ditemukan, program akan menampilkan pesan "Data not found".
- Jika pengguna memilih opsi 4, program akan menghapus semua data yang tersimpan menggunakan fungsi `deleteAll()`.
- Jika pengguna memilih opsi 5, program akan menampilkan semua data yang tersimpan menggunakan fungsi `display()`.
- Jika pengguna memilih opsi 6, program akan berhenti dan keluar.
- Jika pengguna memilih opsi selain keenam opsi di atas, program akan menampilkan pesan "Invalid choice".

## Unguided

### 1. Unguided 1
<b>Buatlah program menu Single Linked List Non-Circular untuk menyimpan Nama dan usia mahasiswa, dengan menggunakan inputan dari user. Lakukan operasi berikut:</b>

![Screenshot 2024-05-10 102131](https://github.com/egydestf/datstruct-practicum/assets/152776726/86161e12-b1b1-4d00-8fef-a0ad7ac19285)

#### Program: 
```C++
#include <iostream>
#include <string>
using namespace std;

// Struktur node untuk menyimpan data mahasiswa
struct Mahasiswa {
    string nama;
    int usia;
    Mahasiswa* next;
};

// Class untuk Linked List
class LinkedList {
private:
    Mahasiswa* head;

public:
    // Konstruktor
    LinkedList() {
        head = nullptr;
    }

    // Destruktor
    ~LinkedList() {
        Mahasiswa* current = head;
        Mahasiswa* next;
        while (current != nullptr) {
            next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }

    // Method untuk menambahkan data mahasiswa di depan linked list
    void tambahDataDepan(string nama, int usia) {
        Mahasiswa* newNode = new Mahasiswa;
        newNode->nama = nama;
        newNode->usia = usia;
        newNode->next = head;
        head = newNode;
        cout << "Data mahasiswa berhasil ditambahkan di depan." << endl;
    }

    // Method untuk menambahkan data mahasiswa di belakang linked list
    void tambahDataBelakang(string nama, int usia) {
        Mahasiswa* newNode = new Mahasiswa;
        newNode->nama = nama;
        newNode->usia = usia;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Mahasiswa* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Method untuk menambahkan data mahasiswa di tengah linked list
    void tambahDataTengah(string nama, int usia, int posisi) {
        if (posisi <= 0) {
            cout << "Posisi harus lebih dari 0." << endl;
            return;
        }

        Mahasiswa* newNode = new Mahasiswa;
        newNode->nama = nama;
        newNode->usia = usia;

        if (posisi == 1) {
            newNode->next = head;
            head = newNode;
            cout << "Data mahasiswa berhasil ditambahkan di posisi " << posisi << "." << endl;
            return;
        }

        Mahasiswa* current = head;
        int counter = 1;
        while (current != nullptr && counter < posisi - 1) {
            current = current->next;
            counter++;
        }

        if (current == nullptr) {
            cout << "Posisi melebihi jumlah elemen yang ada." << endl;
            return;
        }

        newNode->next = current->next;
        current->next = newNode;
        cout << "Data mahasiswa berhasil ditambahkan di posisi " << posisi << "." << endl;
    }

    // Method untuk mengubah data mahasiswa
    void ubahData(string namaLama, string namaBaru, int usiaBaru) {
        Mahasiswa* current = head;
        bool found = false;
        while (current != nullptr) {
            if (current->nama == namaLama) {
                current->nama = namaBaru;
                current->usia = usiaBaru;
                found = true;
                break;
            }
            current = current->next;
        }
        if (found) {
            cout << "Data mahasiswa berhasil diubah." << endl;
        } else {
            cout << "Data mahasiswa tidak ditemukan." << endl;
        }
    }

    // Method untuk menghapus data mahasiswa
    void hapusData(string nama) {
        if (head == nullptr) {
            cout << "Linked list kosong." << endl;
            return;
        }

        Mahasiswa* current = head;
        Mahasiswa* prev = nullptr;
        bool found = false;

        // Cari node yang akan dihapus dan prev node sebelumnya
        while (current != nullptr) {
            if (current->nama == nama) {
                found = true;
                break;
            }
            prev = current;
            current = current->next;
        }

        // Jika data ditemukan, hapus node
        if (found) {
            if (prev == nullptr) { // Jika node yang akan dihapus adalah head
                head = current->next;
            } else {
                prev->next = current->next;
            }
            delete current;
            cout << "Data mahasiswa berhasil dihapus." << endl;
        } else {
            cout << "Data mahasiswa tidak ditemukan." << endl;
        }
    }

    // Method untuk menampilkan semua data mahasiswa
    void tampilkanData() {
        if (head == nullptr) {
            cout << "Linked list kosong." << endl;
            return;
        }
        Mahasiswa* current = head;
        cout << "====================" << endl;
        cout << "Nama\t\tUsia" << endl;
        cout << "====================" << endl;
        while (current != nullptr) {
            cout  << current->nama << "\t\t" << current->usia << endl;
            current = current->next;
        }
    }
};

int main() {
    LinkedList linkedList;
    int choice;
    string nama, namaBaru;
    int usia, usiaBaru, posisi;

    // Menambahkan nama mahasiswa dan usia
    linkedList.tambahDataBelakang("John", 19);
    linkedList.tambahDataBelakang("Jane", 20);
    linkedList.tambahDataBelakang("Michael", 18);
    linkedList.tambahDataBelakang("Yusuke", 19);
    linkedList.tambahDataBelakang("Akechi", 20);
    linkedList.tambahDataBelakang("Hoshino", 18);
    linkedList.tambahDataBelakang("Karin", 18);

    // Menampilkan nama dan usia
    linkedList.tampilkanData();
    cout << "====================" << endl;
    
    do {
        cout << "\n====================================" << endl;
        cout << "Menu:" << endl;
        cout << "1. Tambah Data Mahasiswa di Depan" << endl;
        cout << "2. Tambah Data Mahasiswa di Belakang" << endl;
        cout << "3. Tambah Data Mahasiswa di Tengah" << endl;
        cout << "4. Ubah Data Mahasiswa" << endl;
        cout << "5. Hapus Data Mahasiswa" << endl;
        cout << "6. Tampilkan Data Mahasiswa" << endl;
        cout << "7. Keluar" << endl;
        cout << "====================================" << endl;
        cout << "Pilihan Menu: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Masukkan Nama Mahasiswa: ";
                cin >> nama;
                cout << "Masukkan Usia Mahasiswa: ";
                cin >> usia;
                linkedList.tambahDataDepan(nama, usia);
                break;
            case 2:
                cout << "Masukkan Nama Mahasiswa: ";
                cin >> nama;
                cout << "Masukkan Usia Mahasiswa: ";
                cin >> usia;
                linkedList.tambahDataBelakang(nama, usia);
                break;
            case 3:
                cout << "Masukkan Nama Mahasiswa: ";
                cin >> nama;
                cout << "Masukkan Usia Mahasiswa: ";
                cin >> usia;
                cout << "Masukkan Posisi untuk Menambahkan Data: ";
                cin >> posisi;
                linkedList.tambahDataTengah(nama, usia, posisi);
                break;
            case 4:
                cout << "Masukkan Nama Mahasiswa yang Ingin Diubah: ";
                cin >> nama;
                cout << "Masukkan Nama Mahasiswa Baru: ";
                cin >> namaBaru;
                cout << "Masukkan Usia Mahasiswa Baru: ";
                cin >> usiaBaru;
                linkedList.ubahData(nama, namaBaru, usiaBaru);
                break;
            case 5:
                cout << "Masukkan Nama Mahasiswa yang Ingin Dihapus: ";
                cin >> nama;
                linkedList.hapusData(nama);
                break;
            case 6:
                linkedList.tampilkanData();
                break;
            case 7:
                cout << "Program selesai.";
                break;
            default:
                cout << "Pilihan tidak valid.";
                break;
        }
    } while (choice != 7);

    return 0;
}
```
#### Output:
##### Tampilan awal
![Screenshot 2024-05-10 093616](https://github.com/egydestf/datstruct-practicum/assets/152776726/5d1b39a3-2858-4f48-ba4f-e9c445b9f8a1)
##### Menambahkan nama dan usia user
![Screenshot 2024-05-10 093649](https://github.com/egydestf/datstruct-practicum/assets/152776726/f60f78cc-49cd-40b2-a3e3-85c0e86c2878)
##### Menghapus data Akechi
![Screenshot 2024-05-10 093706](https://github.com/egydestf/datstruct-practicum/assets/152776726/0525558b-ef93-4012-8746-487b14505d79)
##### Menambahkan nama Futaba 18 di antara John dan Jane
![Screenshot 2024-05-10 093727](https://github.com/egydestf/datstruct-practicum/assets/152776726/dd75b879-3bc1-4b5b-8bc5-847487be45c6)
##### Menambahkan nama Igor 20 di awal
![Screenshot 2024-05-10 093753](https://github.com/egydestf/datstruct-practicum/assets/152776726/aed02ec3-3010-4463-a945-e6a85b647c83)
##### Mengubah nama Michael menjadi Reyn 18
![Screenshot 2024-05-10 093811](https://github.com/egydestf/datstruct-practicum/assets/152776726/ba593e44-5fab-4a93-b42e-4a4cc4cbde2f)
##### Menampilkan seluruh data setelah diubah
![Screenshot 2024-05-10 093831](https://github.com/egydestf/datstruct-practicum/assets/152776726/3fd23973-b935-43e6-98cf-62e7e2a3e22c)
##### Keluar program
![Screenshot 2024-05-10 093844](https://github.com/egydestf/datstruct-practicum/assets/152776726/10d6a290-16dd-4a34-a66b-9369b3c724f0)

#### Penjelasan fungsi:
- Fungsi `tambahDataDepan` digunakan untuk menambahkan data mahasiswa di depan Linked List. Ketika fungsi ini dipanggil, sebuah node baru akan dibuat, kemudian node tersebut akan disisipkan di depan Linked List, dan head dari Linked List akan diperbarui untuk menunjuk ke node baru tersebut.
- Fungsi `tambahDataBelakang` bertujuan untuk menambahkan data mahasiswa di belakang Linked List. Jika Linked List masih kosong, node baru akan menjadi head. Jika tidak, maka fungsi akan mencari node terakhir dari Linked List dan menambahkan node baru setelahnya.
- Fungsi `tambahDataTengah` memungkinkan penambahan data mahasiswa di posisi tertentu dalam Linked List. Pengguna harus memberikan posisi di mana data akan dimasukkan. Fungsi ini kemudian menemukan node sebelum posisi yang ditentukan, menyisipkan node baru di antara dua node terkait.
- Fungsi `ubahData` digunakan untuk mengubah data mahasiswa. Pengguna harus memberikan nama mahasiswa yang ingin diubah beserta data baru yang ingin dimasukkan. Fungsi ini akan mencari node dengan nama yang sesuai, jika ditemukan, data di dalamnya akan diperbarui.
- Fungsi `hapusData` bertugas untuk menghapus data mahasiswa dari Linked List. Pengguna harus memberikan nama mahasiswa yang ingin dihapus. Fungsi akan mencari node dengan nama tersebut dan menghapusnya dari Linked List.
- Fungsi `tampilkanData` digunakan untuk menampilkan seluruh data mahasiswa yang tersimpan dalam Linked List. Fungsi ini akan mengunjungi setiap node dalam Linked List dan menampilkan nama dan usia mahasiswa. Jika Linked List kosong, pesan akan ditampilkan untuk mengindikasikan hal tersebut.

### 2. Unguided 2
<b>Modifikasi Guided Double Linked List dilakukan dengan penambahan operasi untuk menambah data, menghapus, dan update di tengah / di urutan tertentu yang diminta. Selain itu, buatlah agar tampilannya menampilkan Nama produk dan harga.</b>

| Nama Produk | Harga   |
| ----------- | ------- |
| Originote   | 60.000  |
| Somethinc   | 150.000 |
| Skintific   | 100.000 |
| Wardah      | 50.000  |
| Hanasui     | 30.000  |

![Screenshot 2024-05-10 102105](https://github.com/egydestf/datstruct-practicum/assets/152776726/ba621d8b-c317-4113-bc37-0e7265b49a98)

| Nama Produk | Harga   |
| ----------- | ------- |
| Originote   | 60.000  |
| Somethinc   | 150.000 |
| Azarine     | 65.000  |
| Skintific   | 100.000 |
| Cleora      | 55.000  |

#### Program: 
```C++
#include <iostream>
#include <iomanip>
using namespace std;

// deklarasi struct node
class Node {
public:
    string namaProduk;
    int harga;
    Node* prev;
    Node* next;
};

// deklarasi struct DLL
class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    // constructor
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // fungsi untuk menambahkan produk ke daftar
    void tambah(string namaProduk, int harga) {
        Node* newNode = new Node;
        newNode->namaProduk = namaProduk;
        newNode->harga = harga;
        newNode->prev = nullptr;
        newNode->next = nullptr;

        // jika daftar kosong, tambahkan node sebagai kepala
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // fungsi untuk menambahkan produk setelah produk tertentu
    void tambahSetelah(string namaProduk, int harga, string namaProdukSebelumnya) {
        Node* current = head;
        while (current != nullptr && current->namaProduk != namaProdukSebelumnya) {
            current = current->next;
        }
        if (current != nullptr) {
            Node* newNode = new Node;
            newNode->namaProduk = namaProduk;
            newNode->harga = harga;
            newNode->prev = current;
            newNode->next = current->next;
            if (current->next != nullptr) {
                current->next->prev = newNode;
            } else {
                tail = newNode;
            }
            current->next = newNode;
        } else {
            cout << "Produk sebelumnya tidak ditemukan" << endl;
        }
    }

    // fungsi untuk menampilkan daftar produk beserta harga
    void tampilkan() {
        Node* current = head;
        cout << "============================" << endl;
        cout << left << setw(20) << "Nama Produk" << "Harga" << endl;
        cout << "============================" << endl;
        while (current != nullptr) {
            cout << left << setw(20) << current->namaProduk << right << setw(5) << current->harga << endl;
            current = current->next;
        }
        cout << "============================" << endl;
        cout << endl;
    }

    // fungsi hapus produk berdasarkan nama
    void hapusBerdasarkanNama(string namaProduk) {
        Node* current = head;
        while (current != nullptr && current->namaProduk != namaProduk) {
            current = current->next;
        }
        if (current != nullptr) {
            if (current->prev != nullptr) {
                current->prev->next = current->next;
            } else {
                head = current->next;
            }
            if (current->next != nullptr) {
                current->next->prev = current->prev;
            } else {
                tail = current->prev;
            }
            delete current;
        } else {
            cout << "Produk tidak ditemukan" << endl;
        }
    }

    // fungsi update nama produk dan harga berdasarkan nama produk lama
    bool update(string namaProdukLama, string namaProdukBaru, int hargaBaru) {
        Node* current = head;
        while (current != nullptr) {
            if (current->namaProduk == namaProdukLama) {
                current->namaProduk = namaProdukBaru;
                current->harga = hargaBaru;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    // fungsi hapus semua produk
    void hapusSemua() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }
};

// main program
int main() {
    DoublyLinkedList list;

    // menambahkan produk awal ke daftar
    list.tambah("Originote", 60000);
    list.tambah("Somethinc", 150000);
    list.tambah("Skintific", 100000);
    list.tambah("Wardah", 50000);
    list.tambah("Hanasui", 30000);

    // menampilkan daftar produk skincare
    cout << "============================" << endl;
    cout << ">> Daftar Produk Skincare <<" << endl;
    list.tampilkan();

    // menampilkan menu admin
    while (true) {
        cout << "============================" << endl;
        cout << "= Toko Skincare Purwokerto =" << endl;
        cout << "============================" << endl;
        cout << "         Menu Admin         " << endl;
        cout << "============================" << endl;
        cout << "1. Tambah Data" << endl;
        cout << "2. Hapus Data" << endl;
        cout << "3. Update Data" << endl;
        cout << "4. Tambah Data Urutan Tertentu" << endl;
        cout << "5. Hapus Data Urutan Tertentu" << endl;
        cout << "6. Hapus Seluruh Data" << endl;
        cout << "7. Tampilkan Data" << endl;
        cout << "8. Exit" << endl;
        cout << "============================" << endl;

        // meminta input menu
        int choice;
        cout << "Masukkan menu pilihan: ";
        cin >> choice;

        // switch case menu
        switch (choice) {
            case 1: {
                string namaProduk;
                int harga;
                cout << "Masukkan nama produk: ";
                cin >> namaProduk;
                cout << "Masukkan harga: ";
                cin >> harga;
                list.tambah(namaProduk, harga);
                break;
            }
            case 2: {
                string namaProduk;
                cout << "Masukkan nama produk yang ingin dihapus: ";
                cin >> namaProduk;
                list.hapusBerdasarkanNama(namaProduk);
                break;
            }
            case 3: {
                string namaProdukLama, namaProdukBaru;
                int hargaBaru;
                cout << "Masukkan nama produk yang ingin diupdate: ";
                cin >> namaProdukLama;
                cout << "Masukkan nama produk baru: ";
                cin >> namaProdukBaru;
                cout << "Masukkan harga baru: ";
                cin >> hargaBaru;
                bool berhasil = list.update(namaProdukLama, namaProdukBaru, hargaBaru);
                if (!berhasil) {
                    cout << "Data tidak ditemukan" << endl;
                }
                break;
            }
            case 4: {
                string namaProduk, namaProdukSebelumnya;
                int harga;
                cout << "Masukkan nama produk yang ingin ditambahkan: ";
                cin >> namaProduk;
                cout << "Masukkan harga: ";
                cin >> harga;
                cout << "Masukkan nama produk sebelumnya: ";
                cin >> namaProdukSebelumnya;
                list.tambahSetelah(namaProduk, harga, namaProdukSebelumnya);
                break;
            }
            case 5: {
                string namaProduk;
                cout << "Masukkan nama produk yang ingin dihapus: ";
                cin >> namaProduk;
                list.hapusBerdasarkanNama(namaProduk);
                break;
            }
            case 6: {
                list.hapusSemua();
                break;
            }
            case 7: {
                list.tampilkan();
                break;
            }
            case 8: {
                return 0;
            }
            default: {
                cout << "Pilihan tidak valid." << endl;
                break;
            }
        }
    }
    return 0;
}
```
#### Output:
##### Menambahkan produk Azarine harga 65000 di antara Somethinc dan Skintific
![Screenshot 2024-05-10 101411](https://github.com/egydestf/datstruct-practicum/assets/152776726/5c84b99f-921d-46cc-aa0a-6464f91953a5)
##### Menghapus produk Wardah
![Screenshot 2024-05-10 101426](https://github.com/egydestf/datstruct-practicum/assets/152776726/90c4205c-711e-492d-818f-3f0c2f744481)
##### Update Hanasui menjadi Cleora dengan harga 55000
![Screenshot 2024-05-10 101444](https://github.com/egydestf/datstruct-practicum/assets/152776726/02882180-7b0a-4054-8acd-7d35224a679e)
##### Menampilkan seluruh produk setelah diubah
![Screenshot 2024-05-10 101507](https://github.com/egydestf/datstruct-practicum/assets/152776726/207228db-458a-4c05-bf86-e3ca3f13a280)
##### Keluar program
![Screenshot 2024-05-10 101523](https://github.com/egydestf/datstruct-practicum/assets/152776726/394a6351-c3b4-46b2-8427-dbd5d009a666)

Program C++ di atas adalah program untuk menampilkan produk toko skincare dan menu admin toko Skincare.

#### Penjelasan fungsi:
- Fungsi `tambah` pada program ini digunakan untuk menambahkan produk ke dalam daftar produk skincare. Fungsi ini memungkinkan pengguna untuk menambahkan nama produk dan harga produk yang ingin ditambahkan ke dalam daftar. Ketika fungsi ini dipanggil, program akan membuat sebuah node baru yang berisi informasi produk yang ingin ditambahkan. Jika daftar produk masih kosong, fungsi ini akan membuat node baru sebagai kepala daftar. Jika daftar tidak kosong, fungsi ini akan menambahkan node baru sebagai akhir daftar.
- Fungsi `tambahSetelah` pada program ini digunakan untuk menambahkan produk setelah produk tertentu yang sudah ada di dalam daftar. Fungsi ini memungkinkan pengguna untuk menambahkan nama produk dan harga produk yang ingin ditambahkan setelah produk yang telah ditentukan. Ketika fungsi ini dipanggil, program akan mencari node produk yang ingin dijadikan sebagai referensi untuk menambahkan produk baru. Jika produk yang ingin dijadikan referensi ditemukan, fungsi ini akan menambahkan node baru setelah produk tersebut dan mengupdate referensi produk yang baru ditambahkan.
- Fungsi `tampilkan` pada program digunakan untuk menampilkan daftar produk skincare yang telah ditambahkan. Fungsi ini memungkinkan pengguna untuk melihat daftar produk yang telah ditambahkan dengan nama produk dan harga produk. Ketika fungsi ini dipanggil, program akan mulai dari node kepala daftar dan menampilkan informasi produk yang ada di dalam daftar secara berurutan.
- Fungsi `hapusBerdasarkanNama` pada program digunakan untuk menghapus produk berdasarkan nama produk. Fungsi ini memungkinkan pengguna untuk menghapus produk yang telah ditambahkan ke dalam daftar dengan nama produk yang telah ditentukan. Ketika fungsi ini dipanggil, program akan mencari node produk yang ingin dihapus dan menghapusnya dari daftar. Jika produk yang ingin dihapus tidak ditemukan, fungsi ini akan menampilkan pesan bahwa produk tidak ditemukan.
- Fungsi `update` pada program digunakan untuk mengupdate nama produk dan harga produk yang telah ditambahkan ke dalam daftar. Fungsi ini memungkinkan pengguna untuk mengupdate informasi produk yang telah ditambahkan dengan nama produk lama dan harga baru. Ketika fungsi ini dipanggil, program akan mencari node produk yang ingin diupdate dan mengupdate informasinya jika ditemukan. Jika produk yang ingin diupdate tidak ditemukan, fungsi ini akan menampilkan pesan bahwa data tidak ditemukan.
- Fungsi `hapusSemua` pada program digunakan untuk menghapus semua produk yang telah ditambahkan ke dalam daftar. Fungsi ini memungkinkan pengguna untuk menghapus semua produk yang telah ditambahkan. Ketika fungsi ini dipanggil, program akan menghapus semua node produk yang ada di dalam daftar dan mengosongkan daftar.

## Kesimpulan

Praktikum Modul 6 Linked List ini membahas pengenalan dari metode linked list pada C++ yaitu Single Linked List (SLL) dan Double Linked List (DLL). Linked List adalah struktur data yang terdiri dari elemen-elemen yang disambungkan secara langsung menggunakan pointer. Single Linked List (SLL) adalah jenis linked list yang paling sederhana, di mana setiap node memiliki pointer yang mengarahkan ke node berikutnya. Dalam SLL, setiap node memiliki dua bagian utama yaitu data dan pointer. Data adalah nilai yang disimpan dalam node, sedangkan pointer mengarahkan ke node berikutnya dalam linked list. Double Linked List (DLL) adalah jenis linked list yang lebih kompleks dibandingkan dengan Single Linked List (SLL), di mana setiap node memiliki dua pointer yaitu pointer "next" yang mengarahkan ke node berikutnya dan pointer "prev" yang mengarahkan ke node sebelumnya. Dengan demikian, DLL memungkinkan akses ke node secara berurutan dalam dua arah, baik dari awal maupun dari akhir linked list.

## Referensi
[1] L. S. Castillo III, "Interactive System for Visualization of Linked List Operations in C++," 2016.

[2] Q. Xiong, C. Wu, J. Xing, L. Wu, and H. Zhang, "A linked-list data structure for advance reservation admission control," in International Conference on Networking and Mobile Computing, Aug. 2005, pp. 901-910.

[3] Trivusi. Algoritma Pencarian: Pengertian, Karakteristik, dan Jenis-Jenisnya. diakses dari https://www.trivusi.web.id/2022/11/pengertian-algoritma-pencarian.html?m=1#google_vignette 
