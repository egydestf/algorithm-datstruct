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