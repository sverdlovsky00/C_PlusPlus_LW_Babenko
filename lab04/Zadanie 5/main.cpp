#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int dlina1(const char *s)
{
    int i = 0;
    while (s[i] != '\0') i++;
    return i;
}

int dlina2(const char *s)
{
    int len = 0;
    while (*s != '\0')
    {
        len++;
        s++;
    }
    return len;
}

int dlina3(const char *s)
{
    if (*s == '\0') return 0;
    return 1 + dlina3(s + 1);
}

void kopir(char *dest, const char *src)
{
    while (*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}

int sravn(const char *a, const char *b)
{
    while (*a != '\0' && *b != '\0')
    {
        if (*a != *b) return *a - *b;
        a++;
        b++;
    }
    return *a - *b;
}

void konkat(char *dest, const char *src)
{
    while (*dest != '\0') dest++;
    while (*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}

void showStringArray(char arr[][50], int n)
{
    for (int i = 0; i < n; i++)
        cout << i << ": " << arr[i] << endl;
}

int main()
{
    // Zadanie 5 - mass strok i obrabotka
    char arr[4][50] =
    {
        "student",
        "program",
        "string",
        "cpp"
    };

    showStringArray(arr, 4);
    cout << endl;

    for (int i = 0; i < 4; i++)
        cout << "Stroka \"" << arr[i] << "\" -> dlina = " << dlina1(arr[i]) << endl;

    cout << endl << "Skleika pervyh dvuh strok:" << endl;
    char joined[100];
    kopir(joined, arr[0]);
    konkat(joined, "_");
    konkat(joined, arr[1]);
    cout << joined << endl;

    return 0;
}
