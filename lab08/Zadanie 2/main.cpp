#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void copyFile(const string &inName, const string &outName)
{
    ifstream fin(inName.c_str(), ios::binary);
    ofstream fout(outName.c_str(), ios::binary);

    if (!fin || !fout)
    {
        cout << "Oshibka pri otkrytii failov" << endl;
        return;
    }

    char ch;
    while (fin.get(ch))
        fout.put(ch);

    cout << "Fail skopirovan" << endl;
}

int main()
{
    setlocale(LC_ALL, "");

    // Zadanie 2 - Rabota s failovymi potokami
    string inName, outName;
    cout << "Vhodnoi fail: ";
    getline(cin, inName);
    cout << "Vyhodnoi fail: ";
    getline(cin, outName);

    copyFile(inName, outName);
    return 0;
}
