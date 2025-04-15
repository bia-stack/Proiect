#include <iostream>
#include <fstream>
#include <cctype>
#include <iterator>
#include <string>
#include "Header.h"

using namespace std;

void codCezar(string& cuvant, bool criptare) {
    int mutare = criptare ? 3 : -3;

    for (char& ch : cuvant) {
        if (isalpha(static_cast<unsigned char>(ch))) {
            char base = isupper(static_cast<unsigned char>(ch)) ? 'A' : 'a';
            ch = static_cast<char>((ch - base + mutare + 26) % 26 + base);
        }
    }
}

string adaugaSufixLaNumeFisier(const string& filename, const string& sufix) {
    size_t pozPunct = filename.rfind('.');

    if (pozPunct == string::npos) {
        return filename + "_" + sufix;
    }
    else {
        return filename.substr(0, pozPunct) + "_" + sufix + filename.substr(pozPunct);
    }
}

bool criptareFisier(const string& filename, bool criptare) {
    ifstream inFile(filename);
    if (!inFile) {
        return false;
    }

    string cuvant((istreambuf_iterator<char>(inFile)), {});

    codCezar(cuvant, criptare);

    string sufix = criptare ? "criptat" : "decriptat";
    string outFilename = adaugaSufixLaNumeFisier(filename, sufix);

    ofstream outFile(outFilename);
    if (!outFile) {
        return false;
    }

    outFile << cuvant;

    return true;
}