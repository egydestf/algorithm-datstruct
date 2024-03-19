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