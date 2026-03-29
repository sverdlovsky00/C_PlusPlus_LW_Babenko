#include <iostream>
#include "Stroka.h"

using namespace std;

int main()
{
    // Zadanie 6 - Dostup k simvolam po indeksu
    Stroka s1("qwerty");

    cout << "Ishodnaya stroka: ";
    s1.vyvod();
    cout << endl;

    cout << "Simvol s indexom 2 = " << s1[2] << endl;

    s1[2] = 'Z';

    cout << "Posle izmeneniya: ";
    s1.vyvod();
    cout << endl;

    return 0;
}
