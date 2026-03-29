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

int main()
{
    // Zadanie 2 - Svoi funkcii dlya strok.
    char str1[100] = "qwerty";
    char str2[100] = "1234567890";

    cout << "dlina1(str1) = " << dlina1(str1) << endl;
    cout << "dlina2(str1) = " << dlina2(str1) << endl;
    cout << "dlina3(str1) = " << dlina3(str1) << endl;

    char copy2[100];
    kopir(copy2, str2);
    cout << "Posle kopir: " << copy2 << endl;

    cout << "sravn(str1, str2) = " << sravn(str1, str2) << endl;

    char cat2[100] = "abc_";
    konkat(cat2, str2);
    cout << "Posle konkat: " << cat2 << endl;
    return 0;
}
