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

char *makeCopyCalloc(const char *src)
{
    int len = dlina1(src);
    char *p = (char *)calloc(len + 1, sizeof(char));
    if (p == NULL) return NULL;
    kopir(p, src);
    return p;
}

int main()
{
    // Zadanie 4 - dinamich pamyat cherez cal
    char str2[100] = "1234567890";
    char *dyn2 = makeCopyCalloc(str2);

    if (dyn2 != NULL)
    {
        cout << "Kopiya cherez calloc: " << dyn2 << endl;
        free(dyn2);
    }

    return 0;
}
