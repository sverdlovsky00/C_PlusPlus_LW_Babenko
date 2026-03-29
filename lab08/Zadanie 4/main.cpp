#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    setlocale(LC_ALL, "");

    // Zadanie 4 - Sostoyaniya potokov.
    istringstream iss("10 20 abc 40");
    int x;

    while (iss >> x)
        cout << "Prochitano chislo: " << x << endl;

    cout << "good() = " << iss.good() << endl;
    cout << "fail() = " << iss.fail() << endl;
    cout << "eof()  = " << iss.eof() << endl;

    // Sbros oshibki i povtornaya popytka chteniya
    iss.clear();
    string tail;
    iss >> tail;

    cout << "Posle clear() dochitali stroku: " << tail << endl;
    cout << "fail() teper = " << iss.fail() << endl;
    return 0;
}
