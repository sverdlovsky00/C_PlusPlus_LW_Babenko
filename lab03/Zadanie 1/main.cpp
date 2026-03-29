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

void miniMaxSort(vector<int> &a)
{
    int left = 0;
    int right = (int)a.size() - 1;

    while (left < right)
    {
        int imin = left;
        int imax = left;

        for (int i = left; i <= right; i++)
        {
            if (a[i] < a[imin]) imin = i;
            if (a[i] > a[imax]) imax = i;
        }

        swap(a[left], a[imin]);

        // esli max stal na drugoe mesto posle pervogo obmena
        if (imax == left) imax = imin;

        swap(a[right], a[imax]);
        left++;
        right--;
    }
}

int main()
{
    // Zadanie 1 - sortirovka minmax
    vector<int> a;
    a.push_back(12);a.push_back(5);a.push_back(-8);a.push_back(1);
    a.push_back(-4);a.push_back(6);a.push_back(3);a.push_back(-5);
    a.push_back(-9);a.push_back(13);a.push_back(0);a.push_back(4);
    a.push_back(9);
    
    printArray(a, "Ishodnyi massiv");
    miniMaxSort(a);
    printArray(a, "Posle mini-max");
    return 0;
}
