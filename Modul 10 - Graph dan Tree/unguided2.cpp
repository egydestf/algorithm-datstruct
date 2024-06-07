#include <iostream>
using namespace std;

// definisi struktur pohon
struct pohon {
    pohon* kanan;
    char data;
    pohon* kiri;
};

// definisi variabel global
pohon* root;
pohon* simpul;

// fungsi inisialisasi root
void inisialisasi_2311110061() {
    root = NULL;
}

// fungsi untuk membuat simpul baru
void simpulBaru(char dataMasukkan) {
    simpul = new pohon;
    simpul->data = dataMasukkan;
    simpul->kanan = NULL;
    simpul->kiri = NULL;
}

// fungsi untuk membuat simpul akar
void simpulAkar() {
    if (root == NULL) {
        char dataAnda;
        cout << "Silahkan masukkan data root: ";
        cin >> dataAnda;
        simpulBaru(dataAnda);
        root = simpul;
        cout << "Root terbentuk...." << endl;
    } else {
        cout << "Root sudah ada...." << endl;
    }
}

// fungsi untuk menambah simpul secara rekursif
void tambahSimpul(pohon* node) {
    char dataUser;
    if (node != NULL) {
        cout << "Masukkan data untuk simpul kiri dari " << node->data << " (atau '0' untuk kosong): ";
        cin >> dataUser;
        if (dataUser != '0') {
            simpulBaru(dataUser);
            node->kiri = simpul;
            tambahSimpul(node->kiri);
        }

        cout << "Masukkan data untuk simpul kanan dari " << node->data << " (atau '0' untuk kosong): ";
        cin >> dataUser;
        if (dataUser != '0') {
            simpulBaru(dataUser);
            node->kanan = simpul;
            tambahSimpul(node->kanan);
        }
    }
}

// fungsi untuk menambah simpul ke tree
void tambahSimpul() {
    if (root != NULL) {
        tambahSimpul(root);
    } else {
        cout << "Silakan buat root terlebih dahulu!" << endl;
    }
}

// fungsi pre-order traversal
void preOrder(pohon* node) {
    if (node != NULL) {
        cout << node->data << " ";
        preOrder(node->kiri);
        preOrder(node->kanan);
    }
}

// fungsi in-order traversal
void inOrder(pohon* node) {
    if (node != NULL) {
        inOrder(node->kiri);
        cout << node->data << " ";
        inOrder(node->kanan);
    }
}

// fungsi post-order traversal
void postOrder(pohon* node) {
    if (node != NULL) {
        postOrder(node->kiri);
        postOrder(node->kanan);
        cout << node->data << " ";
    }
}

// main program
int main() {
    int pilihan;
    inisialisasi_2311110061();

    do {
        cout << "\nMenu: \n";
        cout << "1. Buat Root\n";
        cout << "2. Tambah Simpul\n";
        cout << "3. Tampilkan Pre-Order\n";
        cout << "4. Tampilkan In-Order\n";
        cout << "5. Tampilkan Post-Order\n";
        cout << "6. Keluar\n";
        cout << "Masukkan pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                simpulAkar();
                break;
            case 2:
                tambahSimpul();
                break;
            case 3:
                cout << "\nPre-Order Traversal: ";
                preOrder(root);
                cout << endl;
                break;
            case 4:
                cout << "\nIn-Order Traversal: ";
                inOrder(root);
                cout << endl;
                break;
            case 5:
                cout << "\nPost-Order Traversal: ";
                postOrder(root);
                cout << endl;
                break;
            case 6:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 6);

    return 0;
}
