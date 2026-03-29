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

int partitionQuick(vector<int> &a, int left, int right)
{
    int pivot = a[(left + right) / 2];

    while (left <= right)
    {
        while (a[left] < pivot) left++;
        while (a[right] > pivot) right--;

        if (left <= right)
        {
            swap(a[left], a[right]);
            left++;
            right--;
        }
    }

    return left;
}

void quickSort(vector<int> &a, int left, int right)
{
    if (left >= right) return;

    int index = partitionQuick(a, left, right);

    if (left < index - 1) quickSort(a, left, index - 1);
    if (index < right) quickSort(a, index, right);
}

int main()
{
    // Zadanie 3 - fast sortirovka
    vector<int> a;
    a.push_back(12);
    a.push_back(5);
    a.push_back(-8);
    a.push_back(1);
    a.push_back(-4);
    a.push_back(6);
    a.push_back(3);
    a.push_back(-5);
    a.push_back(-9);
    a.push_back(13);
    a.push_back(0);
    a.push_back(4);
    a.push_back(9);

    printArray(a, "Ishodnyi massiv");
    quickSort(a, 0, (int)a.size() - 1);
    printArray(a, "Posle sort");
    return 0;
}
