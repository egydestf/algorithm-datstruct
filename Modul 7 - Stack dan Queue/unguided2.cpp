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