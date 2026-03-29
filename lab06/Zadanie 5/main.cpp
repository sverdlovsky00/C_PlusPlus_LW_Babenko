#include <iostream>
#include "Stroka.h"

using namespace std;

int main()
{
    // Zadanie 5 - Dlina stroki
    Stroka s1("Programmirovanie");

    cout << "Stroka = ";
    s1.vyvod();
    cout << endl;

    cout << "Dlina = " << s1.dlina() << endl;

    return 0;
}
