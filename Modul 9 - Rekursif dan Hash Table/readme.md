# <h1 align="center">Laporan Praktikum Modul Rekursif dan Hash Table</h1>

<p align="center">Egy Destiar Firmandani</p>
<p align="center">2311110061</p>

## Dasar Teori

### 1. Rekursif

Rekursi adalah suatu konsep dalam pemrograman yang memungkinkan suatu fungsi memanggil dirinya sendiri secara terus-menerus. Rekursi digunakan untuk menyelesaikan masalah yang kompleks dengan cara membagi masalah menjadi bagian-bagian yang lebih kecil dan menyelesaikan masing-masing bagian tersebut dengan cara yang sama[1]. Ada dua jenis rekursi yang umum digunakan dalam pemrograman, yaitu rekursi langsung dan rekursi tidak langsung. Rekursi langsung adalah suatu fungsi yang memanggil dirinya sendiri secara langsung, sedangkan rekursi tidak langsung adalah suatu fungsi yang memanggil fungsi lain yang kemudian memanggil fungsi tersebut.

Rekursi digunakan dalam berbagai aplikasi, seperti mencari nilai faktorial, mencari nilai fibonacci, dan mencari nilai pangkat. Namun, rekursi juga memiliki beberapa kelemahan, seperti dapat menyebabkan error jika fungsi tidak didefinisikan dengan benar dan dapat menyebabkan overhead waktu yang besar jika fungsi dipanggil terlalu banyak[2]. Oleh karena itu, rekursi harus digunakan dengan hati-hati dan harus dipertimbangkan dengan baik sebelum digunakan dalam suatu aplikasi.

### 2. Hash Table

Hash table adalah struktur data yang digunakan dalam pemrograman untuk menyimpan dan mengakses data secara efisien. Pengertian dasar dari hash table adalah sebagai suatu koleksi pasangan nilai dan kunci yang disimpan dalam bentuk tabel[3]. Kunci ini digunakan untuk mengidentifikasi nilai yang terkait dengan kunci tersebut. Fungsi utama dari hash table adalah untuk memungkinkan akses cepat dan efektif terhadap data, serta memudahkan proses pencarian, penghapusan, dan pengubahan data[3].

Operasi yang dapat dilakukan pada hash table meliputi pengisian data, pencarian data berdasarkan kunci, penghapusan data, dan pengubahan data. Dalam pengisian data, hash table akan mengkonversi kunci menjadi nilai hash yang digunakan sebagai indeks untuk menemukan nilai terkait. Pencarian data berdasarkan kunci dilakukan dengan menghitung nilai hash dari kunci yang dicari dan mencari nilai terkait di tabel berdasarkan nilai hash tersebut. Penghapusan data dilakukan dengan menghapus pasangan kunci dan nilai terkait dari tabel. Pengubahan data dilakukan dengan mengupdate nilai terkait dengan kunci yang telah ditemukan. Dengan demikian, hash table sangat berguna dalam aplikasi yang memerlukan akses cepat dan efektif terhadap data, seperti sistem database, sistem operasi, dan aplikasi lainnya[4].

## Guided 

### 1. Guided 1
<b>Rekursif Langsung (Direct Recursion)</b>

#### Program:
```C++
#include <iostream>
using namespace std;

// Fungsi hitung mundur dari angka yang diinputkan
void countdown(int n) {
    if (n == 0) {
        return;
    }
    cout << n << " ";
    countdown(n - 1);
}

// main program
int main() {
    cout << "Rekursif Langsung: ";
    countdown(5); // 5 merupakan input
    cout << endl;
    return 0;
}
```
#### Output:
![Screenshot 2024-06-05 151754](https://github.com/egydestf/datstruct-practicum/assets/152776726/544327c4-b107-4538-a514-e9db015602d9)

Program di atas adalah contoh program yang dapat menghitung mundur dari suatu angka yang diinputkan. Program ini menggunakan fungsi rekursif `countdown` yang memanggil dirinya sendiri dengan argumen yang berkurang secara terus-menerus hingga mencapai angka 0.

Dalam program ini, fungsi `countdown` dipanggil dengan argumen `5`, yang berarti program akan menghitung mundur dari 5 hingga 0. Fungsi ini akan mencetak angka yang sedang dihitung, lalu memanggil dirinya sendiri dengan argumen yang berkurang 1. Proses ini akan terus berulang hingga mencapai angka 0, di mana fungsi `countdown` akan berhenti memanggil dirinya sendiri dan menghentikan proses penghitungan mundur.

### 2. Guided 2
<b>Rekursif Tidak Langsung (Indirect Recursion)</b>

#### Program:
```C++
#include <iostream>
using namespace std;

void functionB(int n);

void functionA(int n) {
    if (n > 0) {
        cout << n << " ";
        functionB(n - 1); // Panggilan rekursif tidak langsung
    }
}

void functionB(int n) {
    if (n > 0) {
        cout << n << " ";
        functionA(n / 2); // Panggilan rekursif tidak langsung
    }
}

// main program
int main() {
    int num = 5;
    cout << "Rekursif Tidak Langsung: ";
    functionA(num);
    return 0;
}
```
#### Output:
![Screenshot 2024-06-05 151943](https://github.com/egydestf/datstruct-practicum/assets/152776726/c738c1c4-ce2b-4529-b79b-72710c6435e4)

Program di atas adalah contoh program yang menggunakan fungsi rekursif tidak langsung untuk menghitung dan mencetak angka. Program ini terdiri dari dua fungsi, yaitu `functionA` dan `functionB`, yang memanggil diri mereka sendiri secara tidak langsung.

Fungsi `functionA` dipanggil dengan argumen `num`, yang berarti program akan mencetak angka dan memanggil fungsi `functionB` dengan argumen yang berkurang 1. Fungsi `functionB` kemudian mencetak angka dan memanggil fungsi `functionA` dengan argumen yang berkurang secara tidak langsung, yaitu dengan menggunakan operasi pembagian.

Dalam proses ini, fungsi `functionA` dan `functionB` memanggil diri mereka sendiri secara tidak langsung, sehingga program dapat mencetak angka secara berurutan dan berkesinambungan. Contoh program ini dapat digunakan untuk menghitung dan mencetak angka secara rekursif tidak langsung.

### 3. Guided 3
<b>Hash Table</b>

#### Program:
```C++
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int TABLE_SIZE = 11;

class HashNode {
public:
    string name;
    string phone_number;

    HashNode(string name, string phone_number) {
        this->name = name;
        this->phone_number = phone_number;
    }
};

class HashMap {
private:
    vector<HashNode*> table[TABLE_SIZE];

public:
    int hashFunc(string key) {
        int hash_val = 0;
        for (char c : key) {
            hash_val += c;
        }
        return hash_val % TABLE_SIZE;
    }

    void insert(string name, string phone_number) {
        int hash_val = hashFunc(name);
        for (auto node : table[hash_val]) {
            if (node->name == name) {
                node->phone_number = phone_number;
                return;
            }
        }
        table[hash_val].push_back(new HashNode(name, phone_number));
    }

    void remove(string name) {
        int hash_val = hashFunc(name);
        for (auto it = table[hash_val].begin(); it != table[hash_val].end(); it++) {
            if ((*it)->name == name) {
                table[hash_val].erase(it);
                return;
            }
        }
    }

    string searchByName(string name) {
        int hash_val = hashFunc(name);
        for (auto node : table[hash_val]) {
            if (node->name == name) {
                return node->phone_number;
            }
        }
        return "";
    }

    void print() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << ": ";
            for (auto pair : table[i]) {
                if (pair != nullptr) {
                    cout << "[" << pair->name << ", " << pair->phone_number << "]";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    HashMap employee_map;
    employee_map.insert("Mistah", "1234");
    employee_map.insert("Pastah", "5678");
    employee_map.insert("Ghana", "91011");

    cout << "Nomer Hp Mistah : " << employee_map.searchByName("Mistah") << endl;
    cout << "Phone Hp Pastah : " << employee_map.searchByName("Pastah") << endl;

    employee_map.remove("Mistah");

    cout << "Nomer Hp Mistah setelah dihapus : " << employee_map.searchByName("Mistah") << endl << endl;

    cout << "Hash Table : " << endl;
    employee_map.print();

    return 0;
}
```
#### Output:
![Screenshot 2024-06-05 152003](https://github.com/egydestf/datstruct-practicum/assets/152776726/dad8bbee-df4d-4657-be26-ade1f715af71)

Program di atas menampilkan contoh implementasi Hash Table untuk manajemen data pegawai. Dalam program ini, terdapat kelas `HashMap` yang digunakan untuk menyimpan data pegawai dengan nama dan nomor telepon. Terdapat juga kelas `HashNode` yang merepresentasikan setiap data pegawai.

Dalam program ini, dibuat objek `HashMap` bernama `employee_map` dan kemudian dimasukkan tiga data pegawai: Mistah dengan nomor telepon 1234, Pastah dengan nomor telepon 5678, dan Ghana dengan nomor telepon 91011.

Selanjutnya program mencari nomor telepon Mistah dan Pastah menggunakan fungsi `searchByName` dan menampilkan hasilnya. Setelah itu, program menghapus data Mistah menggunakan fungsi `remove`.

Terakhir, program menampilkan isi Hash Table menggunakan fungsi `print`. Hasilnya menunjukkan bahwa data Mistah telah dihapus, sedangkan data Pastah dan Ghana masih tersimpan.

## Unguided

### 1. Unguided 1
<b>Buatlah sebuah program Rekursif Langsung (Direct Recursion) yang menghitung nilai faktorial dari sebuah inputan bilangan bulat positif!</b>

#### Program: 
```C++
#include <iostream>
using namespace std;

// Fungsi faktorial
int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

// main program
int main() {
    int num;
    cout << "Masukkan bilangan bulat positif: ";
    cin >> num;

    if (num < 0) {
        cout << "Input harus bilangan bulat positif!"; // error handling
    } else {
        cout << "Faktorial dari " << num << " adalah: " << factorial(num) << endl;
    }

    return 0;
}
```
#### Output:
![Screenshot 2024-06-05 152403](https://github.com/egydestf/datstruct-practicum/assets/152776726/7435eb56-ecdc-4b14-9272-8dfba7c665b0)

Program di atas adalah program untuk menghitung faktorial dari suatu bilangan bulat positif. Program ini meminta pengguna untuk memasukkan bilangan bulat positif melalui input. Jika pengguna memasukkan bilangan bulat negatif, program akan menampilkan pesan error yang berbunyi "Input harus bilangan bulat positif!".

Jika pengguna memasukkan bilangan bulat positif, program akan menghitung faktorial dari bilangan tersebut menggunakan fungsi `factorial`. Fungsi `factorial` menggunakan metode rekursif untuk menghitung faktorial, yaitu dengan mengalikan bilangan dengan faktorial dari bilangan sebelumnya. Misalnya, faktorial dari 5 adalah 5 * 4 * 3 * 2 * 1.

### 2. Unguided 2
<b>Buatlah versi program Rekursif Tidak Langsung (Indirect Recursion) dari soal nomor 1 (unguided 1) di atas!</b>

#### Program: 
```C++
#include <iostream>
using namespace std;

int factorialB(int n);

// Fungsi pertama memulai panggilan rekursi tidak langsung
int factorialA(int n) {
    if (n == 0) {  
        return 1;
    } else {  
        return n * factorialB(n - 1);
    }
}

// Fungsi kedua melanjutkan panggilan rekursi tidak langsung
int factorialB(int n) {
    if (n == 0) {  
        return 1;
    } else {  
        return n * factorialA(n - 1);
    }
}

// main program
int main() {
    int num;
    cout << "Masukkan bilangan bulat positif: ";
    cin >> num;

    if (num >= 0) {
        cout << "Faktorial dari " << num << " adalah: " << factorialA(num) << endl;
    } else {
        cout << "Input harus bilangan bulat positif!"; // error handling
    }

    return 0;
}
```
#### Output:
![Screenshot 2024-06-05 152421](https://github.com/egydestf/datstruct-practicum/assets/152776726/52c03f5c-ab1b-4cc2-897a-55ae87a03564)

Program di atas adalah program untuk menghitung faktorial suatu bilangan bulat positif. Program ini menggunakan dua fungsi rekursif, yaitu `factorialA` dan `factorialB`, untuk menghitung faktorial.

Fungsi `factorialA` memulai panggilan rekursi tidak langsung dengan memanggil fungsi `factorialB` dengan argumen `n - 1`. Jika `n` sama dengan 0, fungsi `factorialA` akan mengembalikan nilai 1. Fungsi `factorialB` melanjutkan panggilan rekursi tidak langsung dengan memanggil fungsi `factorialA` dengan argumen `n - 1`. Jika `n` sama dengan 0, fungsi `factorialB` juga akan mengembalikan nilai 1.

Dalam program utama, pengguna diminta untuk memasukkan bilangan bulat positif. Jika bilangan yang dimasukkan adalah bilangan bulat positif, program akan menghitung faktorial bilangan tersebut menggunakan fungsi `factorialA` dan menampilkan hasilnya. Jika bilangan yang dimasukkan bukan bilangan bulat positif, program akan menampilkan pesan error yang berbunyi "Input harus bilangan bulat positif!"

### 3. Unguided 3
<b>Implementasikan hash table untuk menyimpan data mahasiswa. Setiap mahasiswa memiliki NIM dan nilai. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan nilai. Dengan ketentuan :</b>
<pre>
a. Setiap mahasiswa memiliki NIM dan nilai.
b. Program memiliki tampilan pilihan menu berisi poin C.
c. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan rentang nilai (80 – 90).
</pre>

#### Program: 
```C++
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int TABLE_SIZE = 11;

// struktur data mahasiswa
struct Mahasiswa {
    string nim;
    string nama;
    double nilai;
    Mahasiswa(string nim, string nama, double nilai) : nim(nim), nama(nama), nilai(nilai) {}
};

class HashMap {
private:
    vector<Mahasiswa*> table[TABLE_SIZE];

    // fungsi hash menghasilkan indeks dari NIM
    int hashFunc(string nim) {
        int hash_val = 0;
        for (size_t i = 0; i < nim.length(); ++i) {
            hash_val += nim[i];
        }
        return hash_val % TABLE_SIZE;
    }

public:
    // fungsi tambah data mahasiswa baru
    void tambahData(string nim, string nama, double nilai) {
        int index = hashFunc(nim);
        table[index].push_back(new Mahasiswa(nim, nama, nilai));
    }

    // fungsi hapus data mahasiswa berdasarkan NIM
    void hapusData(string nim) {
        int index = hashFunc(nim);
        for (size_t i = 0; i < table[index].size(); ++i) {
            if (table[index][i]->nim == nim) {
                delete table[index][i];
                table[index].erase(table[index].begin() + i);
                return;
            }
        }
        cout << "Mahasiswa dengan NIM '" << nim << "' tidak ditemukan." << endl;
    }

    // fungsi cari data mahasiswa berdasarkan NIM
    void cariNIM(string nim) {
        int index = hashFunc(nim);
        for (size_t i = 0; i < table[index].size(); ++i) {
            if (table[index][i]->nim == nim) {
                cout << "Mahasiswa dengan NIM '" << nim << "' ditemukan.\nNama: " << table[index][i]->nama << ", Nilai: " << table[index][i]->nilai << endl;
                return;
            }
        }
        cout << "Mahasiswa dengan NIM '" << nim << "' tidak ditemukan." << endl;
    }

    // fungsi cari data mahasiswa berdasarkan rentang nilai
    void cariNilai(double minNilai, double maxNilai) {
        bool found = false;
        for (int i = 0; i < TABLE_SIZE; ++i) {
            for (size_t j = 0; j < table[i].size(); ++j) {
                if (table[i][j]->nilai >= minNilai && table[i][j]->nilai <= maxNilai) {
                    found = true;
                    cout << "NIM: " << table[i][j]->nim << ", Nama: " << table[i][j]->nama << ", Nilai: " << table[i][j]->nilai << endl;
                }
            }
        }
        if (!found) {
            cout << "Mahasiswa dengan nilai antara " << minNilai << " dan " << maxNilai << " tidak ditemukan." << endl;
        }
    }

    // fungsi untuk menampilkan semua data mahasiswa
    void tampilkanSemua() {
        bool found = false;
        for (int i = 0; i < TABLE_SIZE; ++i) {
            for (size_t j = 0; j < table[i].size(); ++j) {
                found = true;
                cout << "NIM: " << table[i][j]->nim << ", Nama: " << table[i][j]->nama << ", Nilai: " << table[i][j]->nilai << endl;
            }
        }
        if (!found) {
            cout << "Tidak ada data mahasiswa yang ditemukan." << endl;
        }
    }

    // destructor untuk membersihkan memori
    ~HashMap() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            for (size_t j = 0; j < table[i].size(); ++j) {
                delete table[i][j];
            }
        }
    }
};

// main program
int main() {
    HashMap mahasiswa_map;
    int choice;
    string nim, nama;
    double nilai;

    do {
        cout << "\nMenu:\n";
        cout << "1. Tambah Data Mahasiswa\n";
        cout << "2. Hapus Data Mahasiswa\n";
        cout << "3. Cari Mahasiswa Berdasarkan NIM\n";
        cout << "4. Cari Mahasiswa Berdasarkan Rentang Nilai (80 - 90)\n";
        cout << "5. Tampilkan Semua Data Mahasiswa\n";
        cout << "6. Keluar\n";
        cout << "Pilihan Anda: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Masukkan NIM Mahasiswa: ";
                cin >> nim;
                cout << "Masukkan Nama Mahasiswa: ";
                cin.ignore();
                getline(cin, nama);
                cout << "Masukkan Nilai Mahasiswa: ";
                cin >> nilai;
                mahasiswa_map.tambahData(nim, nama, nilai);
                break;
            case 2:
                cout << "Masukkan NIM Mahasiswa yang akan dihapus: ";
                cin >> nim;
                mahasiswa_map.hapusData(nim);
                break;
            case 3:
                cout << "Masukkan NIM Mahasiswa yang ingin dicari: ";
                cin >> nim;
                mahasiswa_map.cariNIM(nim);
                break;
            case 4:
                mahasiswa_map.cariNilai(80.0, 90.0);
                break;
            case 5:
                mahasiswa_map.tampilkanSemua();
                break;
            case 6:
                cout << "Terima kasih! Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silahkan masukkan pilihan yang benar.\n";
                break;
        }
    } while (choice != 6);

    return 0;
}

```
#### Output:
##### Tambah Data Mahasiswa
![Screenshot 2024-06-05 153211](https://github.com/egydestf/datstruct-practicum/assets/152776726/23962cd8-6b85-4763-8bf1-e90ce8eec146)
##### Hapus Data Mahasiswa
![Screenshot 2024-06-05 153240](https://github.com/egydestf/datstruct-practicum/assets/152776726/88cb83ec-e038-4691-9c0c-c9c3bd98367c)
##### Cari Mahasiswa (NIM)
![Screenshot 2024-06-05 153256](https://github.com/egydestf/datstruct-practicum/assets/152776726/ec2a8896-4b3f-43c4-b1f5-929ccb932b57)
##### Cari Mahasiswa (Nilai)
![Screenshot 2024-06-05 153311](https://github.com/egydestf/datstruct-practicum/assets/152776726/e81e9bec-81e1-4ace-ba06-c8b2969031ea)
##### Tampilkan Semua Data
![Screenshot 2024-06-05 153330](https://github.com/egydestf/datstruct-practicum/assets/152776726/1f5e269e-0b7b-428b-b504-0c47db1d756d)
##### Keluar Program
![Screenshot 2024-06-05 153351](https://github.com/egydestf/datstruct-practicum/assets/152776726/14f3e8f8-4114-45ef-ab44-3b6cba6431bb)

Program di atas adalah implementasi dari struktur data hash map untuk menyimpan, menghapus, mencari, dan menampilkan data mahasiswa. Setiap mahasiswa memiliki atribut NIM (Nomor Induk Mahasiswa), nama, dan nilai. Program ini menggunakan hashing untuk mengindeks data mahasiswa dalam tabel berukuran 11 (TABLE_SIZE).

Program dimulai dengan mendefinisikan struktur `Mahasiswa` yang memiliki konstruktor untuk menginisialisasi objek mahasiswa dengan NIM, nama, dan nilai. Kemudian, kelas `HashMap` didefinisikan dengan array vektor untuk menyimpan pointer ke objek `Mahasiswa`. Fungsi hash (`hashFunc`) dalam kelas `HashMap` menghitung indeks dari NIM dengan menjumlahkan nilai ASCII dari setiap karakter dalam NIM dan mengambil sisa bagi 11.

Fungsi `tambahData` menambahkan data mahasiswa baru ke dalam tabel hash berdasarkan NIM. Fungsi `hapusData` menghapus data mahasiswa dari tabel berdasarkan NIM. Jika NIM ditemukan, mahasiswa tersebut dihapus dari tabel dan memori dibebaskan. Fungsi `cariNIM` mencari dan menampilkan data mahasiswa berdasarkan NIM yang diberikan. Fungsi `cariNilai` mencari dan menampilkan semua mahasiswa yang nilai mereka berada dalam rentang tertentu (80 - 90 dalam hal ini). Fungsi `tampilkanSemua` menampilkan semua data mahasiswa dalam tabel hash.

Destruktor (`~HashMap`) membersihkan memori dengan menghapus semua objek `Mahasiswa` yang dialokasikan secara dinamis dalam tabel.

Pada bagian `main`, program menyediakan menu interaktif untuk pengguna. Pengguna dapat memilih untuk menambah data mahasiswa, menghapus data mahasiswa, mencari mahasiswa berdasarkan NIM, mencari mahasiswa berdasarkan rentang nilai, menampilkan semua data mahasiswa, atau keluar dari program. Input pengguna diproses dalam loop yang terus berjalan sampai pengguna memilih untuk keluar.

## Kesimpulan

Praktikum Modul 9 Rekursif dan Hash Table ini membahas pengenalan konsep Rekursif dan Hash Table dalam pemrograman. Rekursi adalah suatu konsep dalam pemrograman yang memungkinkan suatu fungsi memanggil dirinya sendiri secara terus-menerus. Rekursi digunakan untuk menyelesaikan masalah yang kompleks dengan cara membagi masalah menjadi bagian-bagian yang lebih kecil dan menyelesaikan masing-masing bagian tersebut dengan cara yang sama. Hash table adalah struktur data yang digunakan dalam pemrograman untuk menyimpan dan mengakses data secara efisien. Pengertian dasar dari hash table adalah sebagai suatu koleksi pasangan nilai dan kunci yang disimpan dalam bentuk tabel. Kunci ini digunakan untuk mengidentifikasi nilai yang terkait dengan kunci tersebut. Rekursi harus digunakan dengan hati-hati dan harus dipertimbangkan dengan baik sebelum digunakan dalam suatu aplikasi. Hash Table sangat berguna dalam aplikasi yang memerlukan akses cepat dan efektif terhadap data, seperti sistem database, sistem operasi, dan aplikasi lainnya.

## Referensi
[1] E. Lutfina dan F. L. Ramadhan, "Perbandingan Kinerja Metode Iteratif dan Metode Rekursif dalam Algoritma Binary Search," in Seminar Nasional APTIKOM (SEMNASTIK) 2019, Nov. 2019, pp. 53-60.

[2] E. Lutfina, N. Inayati, dan G. W. Saraswati, "Analisis Perbandingan Kinerja Metode Rekursif dan Metode Iteratif dalam Algoritma Linear Search," Komputika: Jurnal Sistem Komputer, vol. 11, no. 2, pp. 143-150, 2022.

[3] P. A. Larson, "Dynamic hash tables," Communications of the ACM, vol. 31, no. 4, pp. 446-457, 1988.

[4] C. Papamanthou, R. Tamassia, dan N. Triandopoulos, "Authenticated hash tables," in Proceedings of the 15th ACM Conference on Computer and Communications Security, Oct. 2008, pp. 437-448.