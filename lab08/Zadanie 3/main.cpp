#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void cipherByStreams(const string &inName, const string &outName, const string &key)
{
    ifstream fin(inName, ios::binary);
    ofstream fout(outName, ios::binary);

    if (!fin || !fout || key.empty())
    {
        cout << "Oshibka pri otkrytii failov ili pustoi klyuch." << endl;
        return;
    }

    char ch;
    int i = 0;

    while (fin.get(ch))
    {
        ch = ch ^ key[i % key.size()];
        fout.put(ch);
        i++;
    }

    cout << "Fail obrabotan cherez potoki." << endl;
}

int main()
{
    setlocale(LC_ALL, "");

    // Zadanie 3 - Shifrovanie faila cherez potoki.
    string inName, outName, key;
    cout << "Vhodnoi fail: ";
    getline(cin, inName);
    cout << "Vyhodnoi fail: ";
    getline(cin, outName);
    cout << "Klyuch: ";
    getline(cin, key);

    cipherByStreams(inName, outName, key);
    return 0;
}
