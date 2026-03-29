#include <iostream>
#include "TStack.h"

using namespace std;

// Zadanie 5 - Razvorot vagonov cherez stek i tupik
void sortTrainByDeadEnd(const int inMas[], int n)
{
    TStack<int> st(n + 5);

    cout << "Vhodnoi sostav: ";
    for (int i = 0; i < n; i++)
    {
        cout << inMas[i] << " ";
        st.push(inMas[i]);
    }
    cout << endl;

    cout << "Vyhodnoi sostav: ";
    while (!st.empty())
        cout << st.pop() << " ";
    cout << endl;
}

int main()
{
    int train[] = {1, 5, 3, 7, 2};
    sortTrainByDeadEnd(train, sizeof(train) / sizeof(train[0]));
    return 0;
}
