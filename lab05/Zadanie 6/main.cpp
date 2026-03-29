#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

string digitsOnly(const string &s)
{
    string res;
    for (size_t i = 0; i < s.length(); i++)
    {
        unsigned char ch = (unsigned char)s[i];
        if (isdigit(ch))
            res += s[i];
    }
    return res;
}

void xorCipher(const string &inName, const string &outName, const string &key)
{
    ifstream fin(inName.c_str(), ios::binary);
    ofstream fout(outName.c_str(), ios::binary);

    if (!fin || key.empty())
    {
        cout << "Ne udalos otkryt fail ili pustoi klyuch." << endl;
        return;
    }

    char ch;
    int i = 0;

    while (fin.get(ch))
    {
        char code = ch ^ key[i % key.size()];
        fout.put(code);
        i++;
    }

    cout << "Gotovo. Rezultat zapisan v " << outName << endl;
}

int main(int argc, char *argv[])
{
    // Zadanie 6 - XOR parametry iz komand
	    if (argc != 4)
    {
        cout << "Primer zapuska: meow.txt count.txt key" << endl;
        return 0;
    }

    xorCipher(argv[1], argv[2], argv[3]);
    return 0;
}
