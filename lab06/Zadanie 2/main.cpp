#include <iostream>
#include "Stroka.h"

using namespace std;

int main()
{
    // Zadanie 2 - Operator prisvaivaniya
    Stroka s1("Privet");
    Stroka s2("Mir");

    cout << "Do prisvaivaniya:" << endl;
    cout << "s1 = "; s1.vyvod(); cout << endl;
    cout << "s2 = "; s2.vyvod(); cout << endl;

    s2 = s1;

    cout << "Posle prisvaivaniya s2 = s1:" << endl;
    cout << "s1 = "; s1.vyvod(); cout << endl;
    cout << "s2 = "; s2.vyvod(); cout << endl;

    return 0;
}
