#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void printArray(const vector<int> &a, const string &title)
{
    cout << title << ": ";
    for (size_t i = 0; i < a.size(); i++)
        cout << a[i] << " ";
    cout << endl;
}

void bubbleSort(vector<int> &a)
{
    for (int i = 0; i < (int)a.size() - 1; i++)
        for (int j = 0; j < (int)a.size() - 1 - i; j++)
            if (a[j] > a[j + 1]) swap(a[j], a[j + 1]);
}

vector<int> evenOddSort(const vector<int> &a)
{
    vector<int> even, odd, result;

    for (size_t i = 0; i < a.size(); i++)
    {
        if (a[i] % 2 == 0) even.push_back(a[i]);
        else odd.push_back(a[i]);
    }

    bubbleSort(even);
    bubbleSort(odd);

    // perevorachivaem dlya ubivaniya
    for (int i = 0, j = (int)odd.size() - 1; i < j; i++, j--)
        swap(odd[i], odd[j]);

    for (size_t i = 0; i < even.size(); i++) result.push_back(even[i]);
    for (size_t i = 0; i < odd.size(); i++) result.push_back(odd[i]);

    return result;
}

int main()
{
    // Zadanie 4 - chetniye po vozrastaniyu nechetniye po ubyvaniyu
    vector<int> a;
    a.push_back(12);a.push_back(5);a.push_back(-8);a.push_back(1);
    a.push_back(-4);a.push_back(6);a.push_back(3);a.push_back(-5);
    a.push_back(-9);a.push_back(13);a.push_back(0);a.push_back(4);
    a.push_back(9);

    printArray(a, "Ishodnyi massiv");
    vector<int> b = evenOddSort(a);
    printArray(b, "Rezult");
    return 0;
}
