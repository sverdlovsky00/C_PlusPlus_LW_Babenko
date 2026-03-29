#include <iostream>
#include <cstring>
#include "Stroka.h"

using namespace std;

// Konstruktor po umolchaniyu
Stroka::Stroka()
{
    len = 0;
    str = new char[1];
    str[0] = '\0';
}

// Konstruktor iz C-stroki
Stroka::Stroka(const char *s)
{
    if (s != NULL)
    {
        len = (int)strlen(s);
        str = new char[len + 1];
        strcpy(str, s);
    }
    else
    {
        len = 0;
        str = new char[1];
        str[0] = '\0';
    }
}

// Konstruktor kopirovaniya
Stroka::Stroka(const Stroka &other)
{
    len = other.len;
    str = new char[len + 1];
    strcpy(str, other.str);
}

// Konstruktor po razmeru
Stroka::Stroka(int size)
{
    if (size < 0)
        size = 0;

    len = size;
    str = new char[len + 1];

    for (int i = 0; i < len; i++)
        str[i] = '*';

    str[len] = '\0';
}

// Destruktor
Stroka::~Stroka()
{
    delete[] str;
}

// Operator prisvaivaniya
Stroka& Stroka::operator=(const Stroka &other)
{
    if (this != &other)
    {
        delete[] str;
        len = other.len;
        str = new char[len + 1];
        strcpy(str, other.str);
    }
    return *this;
}

// Dlina stroki
int Stroka::dlina() const
{
    return len;
}

// Vyvod stroki
void Stroka::vyvod() const
{
    cout << str;
}

// Dostup k simvolu po indeksu
char& Stroka::operator[](int index)
{
    return str[index];
}

const char& Stroka::operator[](int index) const
{
    return str[index];
}

// Sravnenie
bool Stroka::operator==(const Stroka &other) const
{
    return strcmp(str, other.str) == 0;
}

bool Stroka::operator!=(const Stroka &other) const
{
    return !(*this == other);
}

// Konkatinaciya
Stroka Stroka::operator+(const Stroka &other) const
{
    int newLen = len + other.len;
    char *buf = new char[newLen + 1];

    strcpy(buf, str);
    strcat(buf, other.str);

    Stroka temp(buf);
    delete[] buf;

    return temp;
}
