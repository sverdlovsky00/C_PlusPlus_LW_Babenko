#include <iostream>

using namespace std;

// Zadanie 1 - Funkcia stepeni s lyubym osnovaniem
long long stepen(int x, int n)
{
    long long p = 1;

    for (int i = 0; i < n; i++)
    {
        p *= x;
    }

    return p;
}

int main()
{
    setlocale(LC_ALL, "");

    int x, n;
    cout << "Vvedite osnovanie: ";
    cin >> x;
    cout << "Vvedite stepen: ";
    cin >> n;

    cout << x << "^" << n << " = " << stepen(x, n) << endl;
    return 0;
}
