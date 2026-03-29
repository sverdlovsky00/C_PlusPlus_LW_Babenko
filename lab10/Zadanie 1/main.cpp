#include <iostream>
#include "SinglyList.h"

using namespace std;

void printInt(const int &x)
{
    cout << x << " ";
}

// Zadanie 1 - Prostaya demonstraciya odnosvyaznogo spiska.
int main()
{
    SinglyList<int> lst;
    lst.pushBack(1);
    lst.pushBack(2);
    lst.pushBack(3);
    lst.pushFront(0);

    cout << "Spisok posle dobavleniya: ";
    lst.print(printInt);
    cout << endl;

    int removed = -1;
    lst.removeValue(2, &removed);

    cout << "Udalili element: " << removed << endl;
    cout << "Spisok teper: ";
    lst.print(printInt);
    cout << endl;

    return 0;
}
