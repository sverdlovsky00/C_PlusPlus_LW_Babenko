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

void countSymbols(const string &name)
{
    ifstream fin(name.c_str(), ios::binary);
    if (!fin)
    {
        cout << "Fail ne otkryt: " << name << endl;
        return;
    }

    int emptyCount = 0;
    int nonEmptyCount = 0;
    char ch;

    while (fin.get(ch))
    {
        // Pustye - probely i nepechatnye simvoly.
        if (isspace((unsigned char)ch) || !isprint((unsigned char)ch))
            emptyCount++;
        else
            nonEmptyCount++;
    }

    cout << "Pustyh simvolov: " << emptyCount << endl;
    cout << "Nepustyh simvolov: " << nonEmptyCount << endl;
}

int main()
{
    // Zadanie 2 - Poschitat pust i nepust symb
    string name;
    cout << "Imya faila: ";
    getline(cin, name);
    countSymbols(name);
    return 0;
}
