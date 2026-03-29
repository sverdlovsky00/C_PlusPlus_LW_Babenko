#include <iostream>
#include <cstring>

using namespace std;

// Zadanie 3 - Peregruzka shablonov getmax.
template <class T>
T getmax(T a, T b)
{
    return (a > b) ? a : b;
}

template <class T>
T getmax(T arr[], size_t size)
{
    T mx = arr[0];
    for (size_t i = 1; i < size; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

const char *getmax(const char *a, const char *b)
{
    return (strcmp(a, b) > 0) ? a : b;
}

int main()
{
    cout << "getmax(3, 5) = " << getmax(3, 5) << endl;

    int mas3[] = {3, 9, 5, 8};
    cout << "getmax(mas3) = " << getmax(mas3, sizeof(mas3) / sizeof(mas3[0])) << endl;

    const char *s1 = "stroka1";
    const char *s2 = "stroka2";
    cout << "getmax(\"stroka1\", \"stroka2\") = " << getmax(s1, s2) << endl;
    return 0;
}
