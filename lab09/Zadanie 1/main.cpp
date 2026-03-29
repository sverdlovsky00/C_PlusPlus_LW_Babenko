#include <iostream>

using namespace std;

// Zadanie 1 - Shablonnaya funkciya Sort dlya int
template <class T>
void Sort(T array[], size_t size)
{
    for (size_t i = 0; i < size - 1; i++)
        for (size_t j = size - 1; j > i; j--)
            if (array[j - 1] > array[j])
            {
                T tmp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = tmp;
            }
}

template <class T>
void printMas(T mas[], size_t n, const string &title)
{
    cout << title << ": ";
    for (size_t i = 0; i < n; i++)
        cout << mas[i] << " ";
    cout << endl;
}

int main()
{
    int mas1[] = {10, 20, 30, 11, 25, 32, 0};
    size_t n1 = sizeof(mas1) / sizeof(mas1[0]);

    printMas(mas1, n1, "Do Sort");
    Sort(mas1, n1);
    printMas(mas1, n1, "Posle Sort");
    return 0;
}
