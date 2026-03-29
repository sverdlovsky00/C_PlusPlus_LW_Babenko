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

char *makeCopyMalloc(const char *src)
{
    int len = dlina1(src);
    char *p = (char *)malloc((len + 1) * sizeof(char));
    if (p == NULL) return NULL;
    kopir(p, src);
    return p;
}

int main()
{
    // Zadanie 3 - dinamicheskaya pamyat cherez mal
    char str1[100] = "qwerty";
    char *dyn1 = makeCopyMalloc(str1);

    if (dyn1 != NULL)
    {
        cout << "Kopiya cherez mal: " << dyn1 << endl;
        free(dyn1);
    }

    return 0;
}
