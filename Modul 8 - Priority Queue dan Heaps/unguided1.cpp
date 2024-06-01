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
