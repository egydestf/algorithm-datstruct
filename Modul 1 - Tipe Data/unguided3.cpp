#include <iostream>
#include <map> // library untuk map
using namespace std;

// main program
int main() {
    /* inisialisasi map dengan nama "dookie"
     -- int untuk key map dan string untuk value map -- */
    map <int, string> dookie;

    /* setiap key diisi dengan value berupa string data
     -- isian key bisa dimulai dari key indeks 0 -- */
    dookie[0] = "Burnout";
    dookie[1] = "Having a Blast";
    dookie[2] = "Chump";
    dookie[3] = "Longview";
    dookie[4] = "Welcome to Paradise";
    dookie[5] = "Pulling Teeth";
    dookie[6] = "Basket Case";
    dookie[7] = "She";
    dookie[8] = "Sassafras Roots";
    dookie[9] = "When I Come Around";
    dookie[10] = "Coming Clean";
    dookie[11] = "Emenius Sleepus";
    dookie[12] = "In The End";
    dookie[13] = "F.O.D.";
    dookie[14] = "All by Myself";

    // cetak map dari masing-masing key map
    cout << "===== DOOKIE TRACK LIST =====" << endl;
    cout << "Track-01: " << dookie[0] << endl;
    cout << "Track-02: " << dookie[1] << endl;
    cout << "Track-03: " << dookie[2] << endl;
    cout << "Track-04: " << dookie[3] << endl;
    cout << "Track-05: " << dookie[4] << endl;
    cout << "Track-06: " << dookie[5] << endl;
    cout << "Track-07: " << dookie[6] << endl;
    cout << "Track-08: " << dookie[7] << endl;
    cout << "Track-09: " << dookie[8] << endl;
    cout << "Track-10: " << dookie[9] << endl;
    cout << "Track-11: " << dookie[10] << endl;
    cout << "Track-12: " << dookie[11] << endl;
    cout << "Track-13: " << dookie[12] << endl;
    cout << "Track-14: " << dookie[13] << endl;
    cout << "Track-15: " << dookie[14] << endl;
    cout << "=============================" << endl;
    // output akan berupa value dari masing-masing key tsb.

    return 0;
}
