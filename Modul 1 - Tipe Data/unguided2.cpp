#include <iostream>
using namespace std;

/* membuat isian struct
-- struct desc untuk isian deskripsi album -- */
struct desc {
    string albumName; // nama album
    string bandName; // nama band
    int releasedYear; // tahun rilis
};

/* membuat isian class yg bersifat publik
-- class detail untuk detail album -- */
class detail {
    public:
    string genre; // genre album
    string studio; // alamat studio
    string label; // label album
    string producer; // produser album
};

// main program
int main() {
    // inisialisasi struct dan membuat variabel untuk menampung isian struct
    struct desc var1;

    /* mengisi struct sesuai dengan masing-masing isian
     -- ini akan mengisi struct pada var1 -- */
    var1.albumName = "Dookie";
    var1.bandName = "Green Day";
    var1.releasedYear = 1994;

    // cetak output struct dari variabel var1
    cout << "========= ALBUM DESCRIPTION (struct) ===" << endl;
    cout << "Name\t: " << var1.albumName << endl;
    cout << "By\t: " << var1.bandName << endl;
    cout << "Year\t: " << var1.releasedYear << endl;

    // inisialisasi class dan membuat variabel untuk menampung isian class
    detail var2;

    /* mengisi class sesuai dengan masing-masing isian
     -- ini akan mengisi class pada var2 -- */
    var2.genre = "Pop Punk,Punk Rock,Skate Punk";
    var2.studio = "Fantasy, Berkeley, California";
    var2.label = "Reprise";
    var2.producer = "Rob Cavallo and Green Day";

    // cetak output class dari variabel var2
    cout << "========= ALBUM DETAIL (class) =========" << endl;
    cout << "Genre\t: " << var2.genre << endl;
    cout << "Studio\t: " << var2.studio << endl;
    cout << "Label\t: " << var2.label << endl;
    cout << "Prod\t: " << var2.producer << endl;
    cout << "========================================" << endl;

    return 0;
}