# <h1 align="center">Laporan Praktikum Modul Priority Queue dan Heaps</h1>

<p align="center">Egy Destiar Firmandani</p>
<p align="center">2311110061</p>

## Dasar Teori

### 1. Priority Queue

Priority Queue dalam pemrograman adalah struktur data yang memungkinkan elemen-elemen data untuk memiliki prioritas tertentu. Dalam implementasinya, elemen dengan prioritas tertinggi akan diambil terlebih dahulu. Struktur data ini sangat berguna dalam berbagai aplikasi, seperti manajemen antrean, penjadwalan proses, dan pengelolaan sumber daya [1].

Elemen-elemen data disusun dalam urutan linier, dan penambahan serta penghapusan elemen hanya terjadi pada dua ujung barisan tersebut [1]. Elemen dengan prioritas tertinggi akan diambil terlebih dahulu, sehingga aplikasi dapat menangani tugas-tugas yang paling penting dengan lebih cepat dan efisien [2].

Contoh implementasi priority queue dapat dilihat dalam Azure Architecture Center, di mana sistem tersebut menggunakan properti Priority untuk menentukan prioritas pesan yang dikirim ke layanan. Dalam contoh ini, pesan dengan prioritas tinggi diterima dan diproses lebih cepat daripada pesan dengan prioritas rendah. Hal ini memungkinkan sistem untuk menangani tugas-tugas yang paling penting dengan lebih cepat dan efisien.

Berikut adalah contoh operasi yang dapat dilakukan pada priority queue:
- Operasi `enqueue` digunakan untuk menambahkan elemen baru ke dalam priority queue. Elemen ini akan ditempatkan berdasarkan prioritasnya, sehingga elemen dengan prioritas tertinggi akan diambil terlebih dahulu.
- Operasi `dequeue` digunakan untuk menghapus elemen teratas dari priority queue. Elemen yang dihapus adalah elemen dengan prioritas tertinggi.
- Operasi `peek` digunakan untuk melihat elemen teratas dari priority queue tanpa menghapusnya. Elemen yang dilihat adalah elemen dengan prioritas tertinggi.
- Operasi `isEmpty` digunakan untuk mengecek apakah priority queue kosong atau tidak. Jika priority queue kosong, maka operasi dequeue akan menghasilkan error.
- Operasi `size` digunakan untuk mengecek ukuran priority queue. Ukuran priority queue adalah jumlah elemen yang ada di dalamnya.
- Operasi `clear` digunakan untuk menghapus semua elemen dari priority queue.
- Operasi `contains` digunakan untuk mengecek apakah elemen tertentu ada di dalam priority queue atau tidak.
- Operasi `remove` digunakan untuk menghapus elemen tertentu dari priority queue. Elemen yang dihapus adalah elemen yang memiliki nilai yang sama dengan elemen yang ditentukan.


### 2. Heap

Heap adalah struktur data yang berbentuk complete binary tree yang memenuhi heap property [3]. Struktur data ini digunakan dalam berbagai aplikasi, seperti heap sort, priority queue, dan algoritma grafik. Heap dapat dibedakan menjadi dua jenis, yaitu max-heap dan min-heap. Dalam max-heap, kunci atau nilai yang ada di simpul mana pun harus lebih besar dari kunci/nilai yang ada di kedua simpul anaknya. Kunci terbesar ada di simpul akar (root node). Sedangkan dalam min-heap, kunci yang ada di simpul mana pun harus lebih kecil dari kunci yang ada di kedua anaknya. Kunci terkecil ada di simpul akar [4].

Struktur data heap memiliki beberapa kelebihan, seperti dapat digunakan untuk mencari elemen dengan prioritas tertentu secara efisien. Namun, heap juga memiliki beberapa kekurangan, seperti kompleksitas waktu yang relatif tinggi untuk beberapa operasi, seperti mencari elemen, menemukan penerus atau pendahulu, dan mencetak semua elemen dalam urutan [4].

Operasi-operasi yang umum dilakukan pada heap antara lain heapify, penyisipan heap (insert), pengurutan heap (heap sort), dan pengurutan kembali (sift up dan sift down). Heapify digunakan untuk mengatur ulang heap agar memenuhi properti heap. Penyisipan heap dilakukan dengan cara menempatkan elemen baru di posisi yang sesuai dan kemudian melakukan reorganisasi heap [3]. Pengurutan heap digunakan untuk mengurutkan elemen dalam heap secara efisien. Pengurutan kembali digunakan untuk mengurutkan kembali elemen yang telah diurutkan sebelumnya.

## Guided 

### 1. Guided 1

#### Program:
```C++
#include <iostream>
#include <algorithm>
using namespace std;

int H[50];
int heapSize = -1;

int parent(int i) {
    return (i - 1) / 2;
}

int leftChild(int i) {
    return ((2 * i) + 1);
}

int rightChild(int i) {
    return ((2 * i) + 2);
}

void shiftUp(int i) {
    while (i > 0 && H[parent(i)] < H[i]) {
        swap(H[parent(i)], H[i]);
            i = parent(i);
    }
}

void shiftDown(int i) {
    int maxIndex = i;
    int l = leftChild(i);
    if (l <= heapSize && H[l] > H[maxIndex]) {
        maxIndex = l;
    }
    int r = rightChild(i);
    if (r <= heapSize && H[r] > H[maxIndex]) {
        maxIndex = r;
    }
    if (i != maxIndex) {
        swap(H[i], H[maxIndex]);
        shiftDown(maxIndex);
    }
}

void insert(int p) {
    heapSize = heapSize + 1;
    H[heapSize] = p;
    shiftUp(heapSize);
}

int extractMax() {
    int result = H[0];
    H[0] = H[heapSize];
    heapSize = heapSize - 1;
    shiftDown(0);
    return result;
}

void changePriority(int i, int p) {
    int oldp = H[i];
    H[i] = p;
    if (p > oldp) {
        shiftUp(i);
    } else {
        shiftDown(i);
    }
}

int getMax() {
    return H[0];
}

void remove(int i) {
    H[i] = getMax() + 1;
    shiftUp(i);
    extractMax();
}

// main program
int main() {
    insert(45);
    insert(20);
    insert(14);
    insert(12);
    insert(31);
    insert(7);
    insert(11);
    insert(13);
    insert(7);

    cout << "Priority Queue : ";
    for (int i = 0; i <= heapSize; ++i) {
        cout << H[i] << " ";
    }
    cout << "\n";

    cout << "Node with maximum priority : " << extractMax() << "\n";

    cout << "Priority queue after extracting maximum : ";
    for (int i = 0; i <= heapSize; ++i) {
        cout << H[i] << " ";
    }
    cout << "\n";

    changePriority(2, 49);
    cout << "Priority queue after priority change : ";
    for (int i = 0; i <= heapSize; ++i) {
        cout << H[i] << " ";
    }
    cout << "\n";

    remove(3);

    cout << "Priority queue after removing the element : ";
    for (int i = 0; i <= heapSize; ++i) {
        cout << H[i] << " ";
    }
    return 0;
}
```
#### Output:
![Screenshot 2024-06-01 203912](https://github.com/egydestf/datstruct-practicum/assets/152776726/a130670c-488c-4a61-903a-59f9b27930f6)

Program ini menggunakan array `H` untuk menyimpan elemen prioritas dan variabel `heapSize` untuk menghitung jumlah elemen dalam heap. `H` memiliki ukuran 50, namun `heapSize` dimulai dari -1 untuk menjamin bahwa tidak ada elemen yang diinputkan sebelumnya.

Penjelasan fungsi untuk operasi Heap tersebut, yaitu sebagai berikut:
- `parent(int i)`: Mengembalikan nilai dari induk elemen ke-i dalam heap.
- `leftChild(int i)`: Mengembalikan nilai dari anak kiri elemen ke-i dalam heap.
- `rightChild(int i)`: Mengembalikan nilai dari anak kanan elemen ke-i dalam heap.
- `shiftUp(int i)`: Menggeser elemen ke-i ke atas dalam heap jika prioritasnya lebih tinggi daripada prioritas induknya.
- `shiftDown(int i)`: Menggeser elemen ke-i ke bawah dalam heap jika prioritasnya lebih rendah daripada prioritas anaknya.
- `insert(int p)`: Menambahkan elemen baru `p` ke dalam heap dan menggeser elemen ke atas jika prioritasnya lebih tinggi.
- `extractMax()`: Menghapus elemen dengan prioritas tertinggi dari heap dan mengembalikan nilai prioritasnya.
- `changePriority(int i, int p)`: Mengubah prioritas elemen ke-i menjadi `p` dan menggeser elemen ke atas jika prioritasnya lebih tinggi, atau ke bawah jika prioritasnya lebih rendah.
- `getMax()`: Mengembalikan nilai prioritas elemen dengan prioritas tertinggi dalam heap.
- `remove(int i)`: Mengubah prioritas elemen ke-i menjadi prioritas tertinggi dalam heap, lalu menghapus elemen dengan prioritas tertinggi.

Pada main program, program ini memasukkan beberapa elemen ke dalam heap menggunakan fungsi `insert()`. Setelah itu, program mencetak elemen dalam heap dan menghapus elemen dengan prioritas tertinggi menggunakan fungsi `extractMax()`. Kemudian, program mengubah prioritas elemen ke-2 menjadi 49 menggunakan fungsi `changePriority()`. Akhirnya, program menghapus elemen ke-3 menggunakan fungsi `remove()` dan mencetak elemen dalam heap setelah operasi.

## Unguided

### 1. Unguided 1
<b>Modifikasi guided diatas yang mana heap dikonstruksi secara manual berdasarkan user!</b>

#### Program: 
```C++
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_SIZE = 50; // bisa diubah sesuai kebutuhan

int H[MAX_SIZE];
int heapSize = -1;

int parent(int i) {
    return (i - 1) / 2;
}

int leftChild(int i) {
    return ((2 * i) + 1);
}

int rightChild(int i) {
    return ((2 * i) + 2);
}

void shiftUp(int i) {
    while (i > 0 && H[parent(i)] < H[i]) {
        swap(H[parent(i)], H[i]);
        i = parent(i);
    }
}

void shiftDown(int i) {
    int maxIndex = i;
    int l = leftChild(i);
    if (l <= heapSize && H[l] > H[maxIndex]) {
        maxIndex = l;
    }
    int r = rightChild(i);
    if (r <= heapSize && H[r] > H[maxIndex]) {
        maxIndex = r;
    }
    if (i != maxIndex) {
        swap(H[i], H[maxIndex]);
        shiftDown(maxIndex);
    }
}

void insert(int p) {
    if (heapSize == MAX_SIZE - 1) {
        cout << "Heap penuh. Tidak bisa menambahkan elemen lebih banyak.\n";
        return;
    }
    heapSize = heapSize + 1;
    H[heapSize] = p;
    shiftUp(heapSize);
}

int extractMax() {
    if (heapSize < 0) {
        cout << "Heap kosong. Tidak bisa mengambil elemen maksimum.\n";
        return -1; // metode error handling
    }
    int result = H[0];
    H[0] = H[heapSize];
    heapSize = heapSize - 1;
    shiftDown(0);
    return result;
}

void changePriority(int i, int p) {
    int oldp = H[i];
    H[i] = p;
    if (p > oldp) {
        shiftUp(i);
    } else {
        shiftDown(i);
    }
}

int getMax() {
    if (heapSize < 0) {
        cout << "Heap kosong. Tidak bisa mendapatkan elemen maksimum.\n";
        return -1; // metode error handling
    }
    return H[0];
}

void remove(int i) {
    if (i < 0 || i > heapSize) {
        cout << "Indeks di luar rentang. Tidak bisa menghapus elemen.\n";
        return;
    }
    H[i] = getMax() + 1;
    shiftUp(i);
    extractMax();
}

// main program
int main() {
    int n;
    cout << "Masukkan jumlah elemen heap: ";
    cin >> n;

    if (n > MAX_SIZE) {
        cout << "Jumlah elemen melebihi ukuran maksimum heap yang diizinkan.\n";
        return 1; // metode error handling
    }

    for (int i = 0; i < n; ++i) {
        int element;
        cout << "Masukkan elemen ke-" << i+1 << " :";
        cin >> element;
        insert(element);
    }

    cout << "Priority Queue : ";
    for (int i = 0; i <= heapSize; ++i) {
        cout << H[i] << " ";
    }
    cout << "\n";

    cout << "Node with maximum priority : " << extractMax() << "\n";

    cout << "Priority queue after extracting maximum : ";
    for (int i = 0; i <= heapSize; ++i) {
        cout << H[i] << " ";
    }
    cout << "\n";

    int index, newPriority;
    cout << "Masukkan indeks elemen yang ingin diubah prioritasnya: ";
    cin >> index;
    cout << "Masukkan nilai prioritas baru: ";
    cin >> newPriority;
    changePriority(index, newPriority);
    cout << "Priority queue after priority change : ";
    for (int i = 0; i <= heapSize; ++i) {
        cout << H[i] << " ";
    }
    cout << "\n";

    int removeIndex;
    cout << "Masukkan indeks elemen yang ingin dihapus: ";
    cin >> removeIndex;
    remove(removeIndex);
    cout << "Priority queue after removing the element : ";
    for (int i = 0; i <= heapSize; ++i) {
        cout << H[i] << " ";
    }
    return 0;
}
```
#### Output:
![Screenshot 2024-06-01 203934](https://github.com/egydestf/datstruct-practicum/assets/152776726/6b9bb181-183a-4046-9362-6982d4dbd2ce)

Program ini menggunakan array `H` untuk menyimpan elemen prioritas dan variabel `heapSize` untuk menghitung jumlah elemen dalam heap. `H` memiliki ukuran 50 (bisa diubah sesuai dengan kebutuhan user), namun `heapSize` dimulai dari -1 untuk menjamin bahwa tidak ada elemen yang diinputkan sebelumnya.

Penjelasan fungsi untuk operasi Heap tersebut, yaitu sebagai berikut:
- `parent(int i)`: Mengembalikan nilai dari induk elemen ke-i dalam heap.
- `leftChild(int i)`: Mengembalikan nilai dari anak kiri elemen ke-i dalam heap.
- `rightChild(int i)`: Mengembalikan nilai dari anak kanan elemen ke-i dalam heap.
- `shiftUp(int i)`: Menggeser elemen ke-i ke atas dalam heap jika prioritasnya lebih tinggi daripada prioritas induknya.
- `shiftDown(int i)`: Menggeser elemen ke-i ke bawah dalam heap jika prioritasnya lebih rendah daripada prioritas anaknya.
- `insert(int p)`: Menambahkan elemen baru `p` ke dalam heap dan menggeser elemen ke atas jika prioritasnya lebih tinggi.
- `extractMax()`: Menghapus elemen dengan prioritas tertinggi dari heap dan mengembalikan nilai prioritasnya.
- `changePriority(int i, int p)`: Mengubah prioritas elemen ke-i menjadi `p` dan menggeser elemen ke atas jika prioritasnya lebih tinggi, atau ke bawah jika prioritasnya lebih rendah.
- `getMax()`: Mengembalikan nilai prioritas elemen dengan prioritas tertinggi dalam heap.
- `remove(int i)`: Mengubah prioritas elemen ke-i menjadi prioritas tertinggi dalam heap, lalu menghapus elemen dengan prioritas tertinggi.

Pada main program, program ini meminta user untuk memasukkan beberapa elemen ke dalam heap menggunakan fungsi `insert()`. Setelah itu, program mencetak elemen dalam heap dan menghapus elemen dengan prioritas tertinggi menggunakan fungsi `extractMax()`. Kemudian, program meminta input indeks elemen untuk mengubah prioritas elemen menggunakan fungsi `changePriority()`. Terakhir, program meminta input untuk menghapus elemen sesuai keinginan user menggunakan fungsi `remove()` dan mencetak elemen dalam heap setelah operasi.

## Kesimpulan

Praktikum Modul 8 Priority Queue dan Heaps ini membahas pengenalan dari metode Priority Queue dan Heaps pada C++. Priority Queue dalam pemrograman adalah struktur data yang memungkinkan elemen-elemen data untuk memiliki prioritas tertentu. Dalam implementasinya, elemen dengan prioritas tertinggi akan diambil terlebih dahulu. Struktur data ini sangat berguna dalam berbagai aplikasi, seperti manajemen antrean, penjadwalan proses, dan pengelolaan sumber daya. Heap adalah struktur data yang berbentuk complete binary tree yang memenuhi heap property. Struktur data ini digunakan dalam berbagai aplikasi, seperti heap sort, priority queue, dan algoritma grafik. Heap dapat dibedakan menjadi dua jenis, yaitu max-heap dan min-heap. Dalam max-heap, kunci atau nilai yang ada di simpul mana pun harus lebih besar dari kunci/nilai yang ada di kedua simpul anaknya. Kunci terbesar ada di simpul akar (root node). Sedangkan dalam min-heap, kunci yang ada di simpul mana pun harus lebih kecil dari kunci yang ada di kedua anaknya. Kunci terkecil ada di simpul akar.

## Referensi
[1] A. L. Arge, M. A. Bender, E. D. Demaine, B. Holland-Minkley, and J. I. Munro, "Cache-oblivious priority queue and graph algorithm applications," in Proceedings of the Thirty-Fourth Annual ACM Symposium on Theory of Computing, 2002, pp. 268-276.

[2] Y. Xu, K. Li, J. Hu, and K. Li, "A genetic algorithm for task scheduling on heterogeneous computing systems using multiple priority queues," Information Sciences, vol. 270, pp. 255-287, 2014.

[3] C. Lattner and V. Adve, "Data structure analysis: A fast and scalable context-sensitive heap analysis," Tech. Rep., UIUCDCS, 2003.

[4] Trivusi. Struktur Data Heap: Pengertian, Karakteristik, dan Operasinya. diakses dari https://www.trivusi.web.id/2023/01/struktur-data-heap.html 
