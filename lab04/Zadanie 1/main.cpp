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
    // Zadanie 1 - Bibliotechnye funkcii dlya strok
    char str1[100] = "qwerty";
    char str2[100] = "1234567890";

    cout << "strlen(str1) = " << strlen(str1) << endl;
    cout << "strlen(str2) = " << strlen(str2) << endl;

    char copy1[100];
    strcpy(copy1, str1);
    cout << "Posle strcpy: " << copy1 << endl;

    cout << "strcmp(str1, str2) = " << strcmp(str1, str2) << endl;

    char cat1[100] = "hello_";
    strcat(cat1, str1);
    cout << "Posle strcat: " << cat1 << endl;
    return 0;
}
