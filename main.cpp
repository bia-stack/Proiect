#include <iostream>
#include <string>
#include "Header.h"

using namespace std;

int main() {
    string filename;
    char mode;

    cout << "Introdu numele fisierului de criptat: \n";
    getline(cin >> ws, filename);

    cout << "Doriti sa criptati sau sa decriptati? ";
    cin >> mode;

    if (mode == 'c' || mode == 'C') {
        if (criptareFisier(filename, true)) {
            cout << "Criptare completa!" << endl;
        }
        else {
            cout << "Eroare la criptarea fisierului" << endl;
        }
    }
    else if (mode == 'd' || mode == 'D') {
        if (criptareFisier(filename, false)) {
            cout << "Decriptare completa!" << endl;
        }
        else {
            cout << "Eroare la decriptarea fisierului" << endl;
        }
    }
    else {
        cout << "Comanda nerecunoscuta. Folositi 'c' pentru criptare si 'd' pentru a decripta." << endl;
    }

    return 0;
}