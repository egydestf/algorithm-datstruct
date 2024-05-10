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
    cout << "====================" << endl;
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