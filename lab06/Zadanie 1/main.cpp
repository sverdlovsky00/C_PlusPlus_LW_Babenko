#include <iostream>
#include "Stroka.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "");

    // Zadanie 1 - Demonstraciya konstrukt i kop
    Stroka s1("qwert");
    Stroka s2;
    Stroka s3(s1);
    Stroka s4(20);

    cout << "s1 = "; s1.vyvod(); cout << endl;
    cout << "s2 = "; s2.vyvod(); cout << endl;
    cout << "s3 (kopiya s1) = "; s3.vyvod(); cout << endl;
    cout << "s4 (po razmeru) = "; s4.vyvod(); cout << endl;

    return 0;
}
