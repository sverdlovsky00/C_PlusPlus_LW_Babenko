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

void showFile(const string &name)
{
    ifstream fin(name.c_str());
    if (!fin)
    {
        cout << "Fail ne otkryt: " << name << endl;
        return;
    }

    string line;
    while (getline(fin, line))
        cout << line << endl;
}

int main()
{
    // Zadanie 1 - Vyvesti fail na ekran
    string name;
    cout << "Imya faila: ";
    getline(cin, name);
    showFile(name);
    return 0;
}
