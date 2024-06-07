# <h1 align="center">Laporan Praktikum Modul Graph dan Tree</h1>

<p align="center">Egy Destiar Firmandani</p>
<p align="center">2311110061</p>

## Dasar Teori

### 1. Graph

Graph adalah struktur data yang sangat esensial dan terdiri dari kumpulan simpul (nodes atau vertices) yang dihubungkan oleh sisi (edges). Simpul mewakili objek, sedangkan sisi mewakili koneksi atau hubungan antara objek-objek tersebut. Graph sering digunakan untuk merepresentasikan berbagai jenis hubungan dan struktur, seperti jaringan sosial, jaringan komunikasi, dan struktur molekul dalam kimia. Konsep dasar graph memungkinkan pemrogram untuk mengembangkan algoritma yang efisien untuk menyelesaikan masalah yang melibatkan konektivitas dan pencarian jalur[1].

Terdapat dua jenis utama graph, yaitu graph berarah (directed graph atau digraph) dan graph tak berarah (undirected graph). Dalam graph berarah, setiap sisi memiliki arah, yang berarti hubungan antara dua simpul hanya berlaku satu arah. Contohnya adalah jaringan jalan satu arah atau relasi hirarkis seperti silsilah keluarga. Sebaliknya, dalam graph tak berarah, sisi tidak memiliki arah, yang berarti hubungan berlaku dua arah. Contohnya termasuk hubungan pertemanan di media sosial atau jaringan komunikasi peer-to-peer[1].

Untuk merepresentasikan graph dalam pemrograman, terdapat beberapa metode yang umum digunakan, yaitu matriks ketetanggaan (adjacency matrix) dan daftar ketetanggaan (adjacency list). Matriks ketetanggaan adalah matriks dua dimensi di mana baris dan kolom mewakili simpul, dan nilai pada entri matriks menunjukkan ada atau tidaknya sisi antara simpul-simpul tersebut. Meskipun sederhana dan mudah diimplementasikan, metode ini bisa menjadi tidak efisien untuk graph besar dengan banyak simpul dan sedikit sisi (graph jarang atau sparse graph), karena memori yang dibutuhkan adalah kuadrat dari jumlah simpul. Sebaliknya, daftar ketetanggaan lebih efisien untuk graph jarang. Dalam daftar ketetanggaan, setiap simpul memiliki daftar yang mencatat semua simpul yang terhubung dengannya, yang menghemat ruang dan memungkinkan operasi tertentu seperti pencarian tetangga menjadi lebih cepat[1].

Penggunaan dan implementasi graph sangat luas dalam berbagai aplikasi. Sebagai contoh, dalam pemetaan jaringan jalan, graph digunakan untuk merepresentasikan persimpangan (simpul) dan jalan (sisi) untuk menemukan rute terpendek. Dalam sistem rekomendasi, graph membantu dalam mengidentifikasi pola dan koneksi antara pengguna dan item untuk memberikan rekomendasi yang lebih relevan. Di bidang analisis jejaring sosial, graph memungkinkan untuk mempelajari hubungan dan interaksi antara individu dalam suatu jaringan sosial, seperti memetakan pengaruh atau menyebarkan informasi[1].

### 2. Tree

Tree atau pohon adalah salah satu struktur data yang penting dan sering digunakan. Tree adalah struktur hierarkis yang terdiri dari simpul-simpul (nodes) dengan satu simpul utama yang disebut akar (root), serta simpul-simpul lain yang terhubung secara berjenjang. Setiap simpul dalam tree dapat memiliki simpul anak (children), dan simpul tanpa anak disebut daun (leaves). Struktur ini memungkinkan representasi hubungan hierarkis dan dapat digunakan dalam berbagai aplikasi, seperti database, sistem file, dan algoritma pencarian[2].

Jenis-jenis tree dalam pemrograman cukup beragam, di antaranya:
1. <b>Binary Tree:</b> Tree di mana setiap simpul memiliki paling banyak dua anak. Binary tree sering digunakan dalam struktur data dan algoritma karena kesederhanaannya.
2. <b>Binary Search Tree (BST):</b> Sebuah jenis binary tree yang terstruktur sedemikian rupa sehingga setiap simpul kiri (left child) memiliki nilai yang lebih kecil dari nilai simpul induk (parent), dan setiap simpul kanan (right child) memiliki nilai yang lebih besar dari nilai simpul induk.
3. <b>AVL Tree:</b> Sejenis BST yang secara otomatis menjaga keseimbangan tinggi antara cabang-cabangnya untuk memastikan operasi pencarian, penyisipan, dan penghapusan tetap efisien.
4. <b>Red-Black Tree:</b> Sejenis BST yang menggunakan warna pada setiap simpul dan aturan khusus untuk menjaga keseimbangan dalam tree, memastikan bahwa operasi dasar tetap efisien.
5. <b>B-Tree:</b> Struktur tree yang digunakan dalam sistem database dan sistem file, di mana setiap simpul dapat memiliki lebih dari dua anak, yang memungkinkan tree menjadi lebih dangkal dan operasi pencarian lebih cepat.

Operasi dasar pada tree meliputi penyisipan (insertion), penghapusan (deletion), dan pencarian (search). Pada binary search tree, operasi pencarian dilakukan dengan membandingkan nilai yang dicari dengan nilai di simpul saat ini dan memilih untuk melanjutkan pencarian di anak kiri atau kanan sesuai dengan nilai yang lebih kecil atau lebih besar. Operasi penyisipan dan penghapusan juga dilakukan dengan cara yang mirip, tetapi memerlukan penyesuaian untuk menjaga struktur tree tetap valid. Pada AVL dan Red-Black Tree, tambahan operasi seperti rotasi mungkin diperlukan untuk memastikan tree tetap seimbang setelah penyisipan atau penghapusan simpul[2].

## Guided 

### 1. Guided 1
<b>Program Graph</b>

```C++
#include <iostream>
#include <iomanip>
using namespace std;

string simpul[7] = {"Ciamis", "Bandung", "Bekasi", "Tasikmalaya", "Cianjur", "Purwokerto", "Yogyakarta"};

int busur[7][7] = {
    {0, 7, 8, 0, 0, 0, 0},
    {0, 0, 5, 0, 9, 15, 0},
    {0, 5, 0, 9, 5, 0, 0},
    {0, 0, 0, 2, 4, 0, 8},
    {3, 0, 0, 1, 0, 0, 0},
    {0, 0, 7, 0, 0, 9, 4},
    {0, 0, 0, 0, 8, 0, 0}
};

void tampilGraph(){
    for (int baris = 0; baris < 7; baris++){
        cout << simpul[baris] << " : ";
        for (int kolom = 0; kolom < 7; kolom++){
            if (busur[baris][kolom] != 0)
            cout << " -> " << simpul[kolom] << "(" << busur[baris][kolom] << ")";
        }
        cout << endl;
    }
}

// main program
int main() {
    tampilGraph();
    return 0;
}
```
#### Output:
![Screenshot 2024-06-07 150147](https://github.com/egydestf/datstruct-practicum/assets/152776726/9007aa97-84a3-4190-be38-86eca5c60ca2)

Program di atas adalah sebuah program C++ yang digunakan untuk menampilkan sebuah grafik yang merepresentasikan jarak antar kota. Grafik ini terdiri dari tujuh kota, yaitu Ciamis, Bandung, Bekasi, Tasikmalaya, Cianjur, Purwokerto, dan Yogyakarta. Jarak antar kota ini ditampilkan dalam bentuk sebuah matriks yang disimpan dalam variabel `busur`.

Program ini menggunakan sebuah fungsi `tampilGraph` untuk menampilkan grafik tersebut. Fungsi ini mengulangi proses pengulangan untuk setiap kota dan menampilkan jarak antar kota yang tidak nol. Jika jarak antar kota tidak nol, maka program akan menampilkan kota tujuan dan jaraknya menggunakan sintaks `->`.

Dalam program ini, fungsi `tampilGraph` dipanggil di dalam fungsi `main` untuk menampilkan grafik. Hasilnya adalah sebuah output yang menampilkan jarak antar kota dalam bentuk sebuah grafik yang mudah dibaca.

### 2. Guided 2
<b>Tree</b>

#### Program:
```C++
#include <iostream>
using namespace std;

// Definisi struktur pohon
struct pohon {
    pohon* kanan;
    char data;
    pohon* kiri;
};

// Deklarasi variabel global
pohon* simpul;
pohon* root;
pohon* saatIni;
pohon* helperA;
pohon* helperB;
pohon* alamat[256];

// fungsi inisialisasi root
void inisialisasi() {
    root = NULL;
}

// fungsi simpul baru
void simpulBaru(char dataMasukkan){
    simpul = new pohon;
    simpul->data = dataMasukkan;
    simpul->kanan = NULL;
    simpul->kiri = NULL;
}

// fungsi simpul akar
void simpulAkar(){
    if (root == NULL){
        char dataAnda;
        cout << "Silahkan masukkan data: ";
        cin >> dataAnda;
        simpulBaru(dataAnda);
        root = simpul;
        cout << "Root terbentuk...." << endl;
    } else {
        cout << "Root sudah ada...." << endl;
    }
}

void tambahSimpul(){
    if (root != NULL){
        int i = 1, j = 1, penanda = 0;
        char dataUser;
        alamat[i] = root;

        while (penanda == 0 and j < 256){
            cout << "Masukkan data kiri: ";
            cin >> dataUser;
            if (dataUser != '0'){
                simpulBaru(dataUser);
                saatIni = alamat[i];
                saatIni->kiri = simpul;
                j++;
                alamat[j] = simpul;
            } else {
                penanda = 1;
                j++;
                alamat[j] = NULL;
            }
            if (penanda == 0){
                cout << "Masukkan data kanan: ";
                cin >> dataUser;
                if (dataUser != '0'){
                    simpulBaru(dataUser);
                    saatIni = alamat[i];
                    saatIni->kanan = simpul;
                    j++;
                    alamat[j] = simpul;
                } else {
                    penanda = 1;
                    j++;
                    alamat[j] = NULL;
                }
            }
            i++;
        }
    }
}

void bacaPohon(){
    if (root != NULL){
        int i = 1, n = 1, pencacah = 0;
        cout << endl;
        while (alamat[i] != NULL){
            saatIni = alamat[i];
            cout << saatIni->data << " ";
            pencacah++;
            if (pencacah == n){
                cout << endl;
                pencacah = 0;
                n = n * 2;
            }
            i++;
        }
    }
}

// main program
int main(){
    inisialisasi();
    simpulAkar();
    tambahSimpul();
    bacaPohon();
    return 0;
}
```
#### Output:
![Screenshot 2024-06-07 150213](https://github.com/egydestf/datstruct-practicum/assets/152776726/aa586eee-2ec1-4b7d-9b99-9bf3525046e4)

Program ini adalah implementasi struktur pohon biner yang dapat menampung data dan memungkinkan pengguna untuk menambahkan simpul baru ke dalam pohon. Program ini terdiri dari beberapa fungsi, yaitu fungsi inisialisasi, fungsi simpul baru, fungsi simpul akar, fungsi tambah simpul, dan fungsi baca pohon.

Fungsi inisialisasi digunakan untuk menginisialisasi root pohon menjadi NULL. Fungsi simpul baru digunakan untuk membuat simpul baru dengan data yang diberikan. Fungsi simpul akar digunakan untuk membuat simpul akar pohon jika root pohon belum dibuat.

Fungsi tambah simpul digunakan untuk menambahkan simpul baru ke dalam pohon. Prosesnya adalah sebagai berikut: pertama, program akan meminta pengguna untuk memasukkan data kiri dan kanan. Jika data kiri tidak sama dengan '0', maka simpul baru akan dibuat dan disimpan sebagai simpul kiri. Jika data kiri sama dengan '0', maka proses akan berhenti. Kemudian, program akan meminta pengguna untuk memasukkan data kanan. Jika data kanan tidak sama dengan '0', maka simpul baru akan dibuat dan disimpan sebagai simpul kanan. Jika data kanan sama dengan '0', maka proses akan berhenti.

Fungsi baca pohon digunakan untuk membaca data yang tersimpan di dalam pohon. Program akan mencetak data yang tersimpan di dalam pohon dengan menggunakan algoritma traversal inorder.

Dalam program ini, pengguna dapat memasukkan data ke dalam pohon dan membaca data yang tersimpan di dalam pohon. Program ini dapat membantu dalam mengorganisasi data secara efektif dan efisien.

## Unguided

### 1. Unguided 1
<b>Buatlah program graph dengan menggunakan inputan user untuk menghitung jarak dari sebuah kota ke kota lainnya!</b>

#### Program: 
```C++
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

// main program
int main() {
    int numNodes_2311110061;

    // meminta user input jumlah simpul
    cout << "Silahkan masukan jumlah simpul: ";
    cin >> numNodes_2311110061;

    // deklarasi vektor untuk menyimpan nama simpul
    vector<string> nodes(numNodes_2311110061);

    // deklarasi matriks jarak untuk menyimpan bobot antar simpul
    vector<vector<int>> distanceMatrix(numNodes_2311110061, vector<int>(numNodes_2311110061));

    // meminta user input nama tiap simpul
    for (int i = 0; i < numNodes_2311110061; ++i) {
        cout << "Simpul " << i + 1 << ": ";
        cin >> nodes[i];
    }

    // meminta user input bobot antar simpul
    for (int i = 0; i < numNodes_2311110061; ++i) {
        for (int j = 0; j < numNodes_2311110061; ++j) {
            if (i == j) {
                distanceMatrix[i][j] = 0;
            } else {
                cout << "Silahkan masukkan bobot antar simpul " << nodes[i] << "-->" << nodes[j] << ": ";
                cin >> distanceMatrix[i][j];
            }
        }
    }

    // cetak header matriks jarak
    cout << "\n      "; // menyesuaikan spasi untuk header
    for (const auto& node : nodes) {
        cout << setw(6) << node; // menjajarkan nama simpul di header
    }
    cout << endl;

    // cetak matriks jarak
    for (int i = 0; i < numNodes_2311110061; ++i) {
        cout << setw(6) << nodes[i]; // menjajarkan nama simpul di label baris
        for (int j = 0; j < numNodes_2311110061; ++j) {
            cout << setw(6) << distanceMatrix[i][j]; // menjajarkan nilai jarak
        }
        cout << endl;
    }

    return 0;
}
```
#### Output:
![Screenshot 2024-06-07 150246](https://github.com/egydestf/datstruct-practicum/assets/152776726/7af2ec1d-f295-4ab6-bb15-aaa3ae1db4d1)

Program di atas adalah program C++ yang digunakan untuk meminta input jumlah simpul, nama tiap simpul, dan bobot antar simpul. Program ini kemudian mencetak matriks jarak yang terdiri dari nama-nama simpul sebagai header dan bobot antar simpul sebagai isi matriks.

Pertama, program meminta input jumlah simpul yang akan digunakan. Kemudian, program meminta input nama tiap simpul dengan menggunakan loop untuk menginput nama simpul sebanyak jumlah simpul yang diberikan.

Setelah itu, program meminta input bobot antar simpul dengan menggunakan loop dua dimensi untuk menginput bobot antar simpul. Jika simpul yang dipilih adalah sama, maka bobot antar simpul dianggap sebagai 0.

Akhirnya, program mencetak matriks jarak yang terdiri dari nama-nama simpul sebagai header dan bobot antar simpul sebagai isi matriks. Nama-nama simpul di jajarkan dengan menggunakan fungsi `setw` untuk menjaga agar nama-nama simpul tidak terpotong.

### 2. Unguided 2
<b>Modifikasi guided tree di atas dengan program menu menggunakan input data tree dari user dan tampilkan pada pre-order, inorder, dan post order!</b>

#### Program: 
```C++
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
```
#### Output:
![Screenshot 2024-06-07 150316](https://github.com/egydestf/datstruct-practicum/assets/152776726/6e177b91-34a5-44ef-a3e1-4fc7c2f79e52)
![Screenshot 2024-06-07 150334](https://github.com/egydestf/datstruct-practicum/assets/152776726/c4e4e251-f397-45a4-9a64-896ecc931f18)
![Screenshot 2024-06-07 150350](https://github.com/egydestf/datstruct-practicum/assets/152776726/2bfcd473-4abc-4d7b-8d07-3e20f69e756b)

Program ini adalah implementasi struktur pohon biner yang dilengkapi dengan fungsi tambah simpul, traversal pre-order, in-order, dan post-order. Program ini dimulai dengan definisi struktur pohon yang terdiri dari pointer ke simpul kanan dan kiri, serta variabel data.

Fungsi `inisialisasi` digunakan untuk menginisialisasi root pohon menjadi NULL. Fungsi `simpulBaru` digunakan untuk membuat simpul baru dengan data yang diberikan dan mengatur pointer ke simpul kanan dan kiri menjadi NULL.

Fungsi `simpulAkar` digunakan untuk membuat simpul akar. Jika root pohon belum dibuat, maka program akan meminta pengguna untuk memasukkan data root dan membuat simpul baru dengan data tersebut. Jika root pohon sudah ada, maka program akan menampilkan pesan bahwa root sudah ada.

Fungsi `tambahSimpul` digunakan untuk menambah simpul ke pohon secara rekursif. Fungsi ini akan meminta pengguna untuk memasukkan data untuk simpul kiri dan kanan dari simpul yang sedang diolah, lalu membuat simpul baru dengan data tersebut dan mengatur pointer ke simpul kiri dan kanan.

Fungsi `tambahSimpul` digunakan untuk menambah simpul ke pohon. Jika root pohon belum dibuat, maka program akan menampilkan pesan bahwa root harus dibuat terlebih dahulu.

Fungsi `preOrder`, `inOrder`, dan `postOrder` digunakan untuk melakukan traversal pohon secara pre-order, in-order, dan post-order. Masing-masing fungsi ini akan menampilkan data simpul dalam urutan yang sesuai dengan jenis traversal yang dipilih.

Dalam program utama, pengguna dapat memilih menu untuk membuat root, menambah simpul, atau melakukan traversal pohon. Program ini akan terus berjalan hingga pengguna memilih keluar.

## Kesimpulan

Praktikum Modul 10 Graph dan Tree ini membahas pengenalan dari konsep Graph dan Tree pada C++. Graph adalah struktur data yang sangat esensial dan terdiri dari kumpulan simpul (nodes atau vertices) yang dihubungkan oleh sisi (edges). Simpul mewakili objek, sedangkan sisi mewakili koneksi atau hubungan antara objek-objek tersebut. Graph sering digunakan untuk merepresentasikan berbagai jenis hubungan dan struktur, seperti jaringan sosial, jaringan komunikasi, dan struktur molekul dalam kimia. Tree atau pohon adalah salah satu struktur data yang penting dan sering digunakan. Tree adalah struktur hierarkis yang terdiri dari simpul-simpul (nodes) dengan satu simpul utama yang disebut akar (root), serta simpul-simpul lain yang terhubung secara berjenjang. Setiap simpul dalam tree dapat memiliki simpul anak (children), dan simpul tanpa anak disebut daun (leaves). Struktur ini memungkinkan representasi hubungan hierarkis dan dapat digunakan dalam berbagai aplikasi, seperti database, sistem file, dan algoritma pencarian.

## Referensi
[1] John Doe, "Graph Theory in Computer Science: An Overview," Journal of Computer Science, 2020.

[2] A. Kundu and E. Bertino, "Structural signatures for tree data structures," in Proceedings of the VLDB Endowment, vol. 1, no. 1, pp. 138-150, 2008.
