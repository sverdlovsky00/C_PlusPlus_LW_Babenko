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

void findSubstringInFile(const string &name, const string &sub, const string &outName)
{
    ifstream fin(name.c_str());
    ofstream fout(outName.c_str());

    if (!fin)
    {
        cout << "Fail ne otkryt: " << name << endl;
        return;
    }

    string line;
    int lineNo = 1;
    bool found = false;

    while (getline(fin, line))
    {
        if (line.find(sub) != string::npos)
        {
            fout << "Stroka " << lineNo << ": " << line << endl;
            found = true;
        }
        lineNo++;
    }

    if (!found)
        fout << "Podstroka ne naidena." << endl;

    cout << "Rezultat zapisan v " << outName << endl;
}

int main()
{
    // Zadanie 3 - Poisk podstrok v faile
    string name, sub, outName;
    cout << "Imya faila: ";
    getline(cin, name);
    cout << "Podstroka: ";
    getline(cin, sub);
    cout << "Vyhodnoi fail: ";
    getline(cin, outName);

    findSubstringInFile(name, sub, outName);
    return 0;
}
