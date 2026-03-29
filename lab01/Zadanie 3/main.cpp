#include <iostream>

using namespace std;

// Zadanie 3 - obmen po znacheniyu
void obmen1(int a, int b)
{
    int t = a;
    a = b;
    b = t;

    cout << "Vnutri obmen1: a = " << a << ", b = " << b << endl;
}

// cherez ukazateli
void obmen2(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

// cherez ssylki
void obmen3(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}

int main()
{
    setlocale(LC_ALL, "");

    int x = 2, y = 5;

    cout << "Do obmen1: x = " << x << ", y = " << y << endl;
    obmen1(x, y);
    cout << "Posle obmen1: x = " << x << ", y = " << y << endl << endl;

    cout << "Do obmen2: x = " << x << ", y = " << y << endl;
    obmen2(&x, &y);
    cout << "Posle obmen2: x = " << x << ", y = " << y << endl << endl;

    cout << "Do obmen3: x = " << x << ", y = " << y << endl;
    obmen3(x, y);
    cout << "Posle obmen3: x = " << x << ", y = " << y << endl;

    return 0;
}
