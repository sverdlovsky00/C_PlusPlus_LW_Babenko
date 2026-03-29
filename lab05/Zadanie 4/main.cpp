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

void movePageNumbers(const string &inName, const string &outName)
{
    ifstream fin(inName.c_str(), ios::binary);
    ofstream fout(outName.c_str(), ios::binary);

    if (!fin)
    {
        cout << "Fail ne otkryt: " << inName << endl;
        return;
    }

    string all;
    char fileCh;
    while (fin.get(fileCh))
        all += fileCh;

    vector<string> pages;
    string cur;

    for (size_t i = 0; i < all.length(); i++)
    {
        char ch = all[i];
        if (ch == '\f')
        {
            pages.push_back(cur);
            cur.clear();
        }
        else
        {
            cur += ch;
        }
    }
    pages.push_back(cur);

    for (size_t p = 0; p < pages.size(); p++)
    {
        string page = pages[p];
        size_t pos = page.find('\n');

        string firstLine;
        string rest;

        if (pos == string::npos)
        {
            firstLine = page;
            rest = "";
        }
        else
        {
            firstLine = page.substr(0, pos);
            rest = page.substr(pos + 1);
        }

        string number = digitsOnly(firstLine);

        if (!rest.empty() && rest[rest.length() - 1] != '\n')
            rest += '\n';

        rest += number;
        fout << rest;

        if (p + 1 < pages.size())
            fout << '\f';
    }

    cout << "Nomera stranic pereneseny v " << outName << endl;
}

int main()
{
    // Zadanie 4 - Perenesti nomera stranic vniz
    string inName, outName;
    cout << "Vhodnoi fail: ";
    getline(cin, inName);
    cout << "Vyhodnoi fail: ";
    getline(cin, outName);
    movePageNumbers(inName, outName);
    return 0;
}
