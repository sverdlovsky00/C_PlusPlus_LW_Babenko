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

int main()
{
    // Zadanie 2 - puzirek sortirovka
    vector<int> a;
    a.push_back(12);a.push_back(5);a.push_back(-8);a.push_back(1);
	a.push_back(-4);a.push_back(6);a.push_back(3);a.push_back(-5);
    a.push_back(-9);a.push_back(13);a.push_back(0);a.push_back(4);
    a.push_back(9);

    printArray(a, "Ishodnyi massiv");
    bubbleSort(a);
    printArray(a, "Posle puzirki");
    return 0;
}
