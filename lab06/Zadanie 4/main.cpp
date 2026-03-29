#include <iostream>
#include "Stroka.h"

using namespace std;

int main()
{
    // Zadanie 4 - Sravnenie strok
    Stroka s1("abc");
    Stroka s2("abc");
    Stroka s3("xyz");

    cout << "s1 = "; s1.vyvod(); cout << endl;
    cout << "s2 = "; s2.vyvod(); cout << endl;
    cout << "s3 = "; s3.vyvod(); cout << endl;

    if (s1 == s2)
        cout << "s1 ravna s2" << endl;
    else
        cout << "s1 ne ravna s2" << endl;

    if (s1 != s3)
        cout << "s1 ne ravna s3" << endl;
    else
        cout << "s1 ravna s3" << endl;

    return 0;
}
