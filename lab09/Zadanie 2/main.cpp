#include <iostream>

using namespace std;

// Zadanie 2 - Sort dlya polzovatelskogo tipa Money.
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

class Money
{
private:
    long dollars;
    int cents;

public:
    Money()
    {
        dollars = 0;
        cents = 0;
    }

    Money(long d, int c)
    {
        dollars = d;
        cents = c;
    }

    bool operator>(const Money &amt) const
    {
        return (dollars > amt.dollars) ||
               (dollars == amt.dollars && cents > amt.cents);
    }

    friend ostream &operator<<(ostream &os, const Money &amt)
    {
        os << "$" << amt.dollars << "." << amt.cents;
        return os;
    }
};

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
    Money mas2[] =
    {
        Money(19, 10),
        Money(99, 99),
        Money(99, 95),
        Money(19, 95)
    };
    size_t n2 = sizeof(mas2) / sizeof(mas2[0]);

    printMas(mas2, n2, "Do Sort");
    Sort(mas2, n2);
    printMas(mas2, n2, "Posle Sort");
    return 0;
}
