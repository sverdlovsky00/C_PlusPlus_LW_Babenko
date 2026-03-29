#include <iostream>
#include "Stroka.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "");

    // Zadanie 1 - Vvod-vyvod obekta klassa cherez operatory potokov
    Stroka s;
    cout << "Vvedite stroku dlya objekta Stroka: ";
    cin >> s;
    cout << "Vy ввeli: " << s << endl;
    return 0;
}
