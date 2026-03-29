#include <iostream>
#include "Stroka.h"

using namespace std;

int main()
{
    // Zadanie 3 - Slozhenie strok
    Stroka s1("Privet");
    Stroka s2(" mir");
    Stroka s3;

    s3 = s1 + s2;

    cout << "s1 = "; s1.vyvod(); cout << endl;
    cout << "s2 = "; s2.vyvod(); cout << endl;
    cout << "s3 = s1 + s2 = "; s3.vyvod(); cout << endl;

    return 0;
}
