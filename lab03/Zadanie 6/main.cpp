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

void sortRangeDesc(vector<int> &a, int n1, int n2)
{
    for (int i = n1; i <= n2; i++)
        for (int j = n1; j < n2 - (i - n1); j++)
            if (a[j] < a[j + 1]) swap(a[j], a[j + 1]);
}

int main()
{
    // Zadanie 6 - sortirovka po ubyvaniyy na intervale
    vector<int> a;
    a.push_back(12);a.push_back(5);a.push_back(-8);a.push_back(1);
    a.push_back(-4);a.push_back(6);a.push_back(3);a.push_back(-5);
    a.push_back(-9);a.push_back(13);a.push_back(0);a.push_back(4);
    a.push_back(9);

    int n1, n2;

    printArray(a, "Ishodnyi massiv");
    cout << "Vvedite granicy intervala N1 i N2: ";
    cin >> n1 >> n2;

    if (n1 < 0 || n2 >= (int)a.size() || n1 > n2)
    {
        cout << "Nevernyi interval" << endl;
        return 0;
    }

    sortRangeDesc(a, n1, n2);
    printArray(a, "Posle sortirovki na intervale");
    return 0;
}
