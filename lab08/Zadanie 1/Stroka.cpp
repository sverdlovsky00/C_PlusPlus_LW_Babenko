#include "Stroka.h"

int Stroka::myLen(const char *s)
{
    int len = 0;
    while (s[len] != '\0')
        len++;
    return len;
}

void Stroka::myCopy(char *dest, const char *src)
{
    while (*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}

Stroka::Stroka(int size)
{
    if (size < 2) size = 2;
    capacity = size;
    str = new char[capacity];
    str[0] = '\0';
}

Stroka::Stroka(const char *s)
{
    capacity = myLen(s) + 10;
    str = new char[capacity];
    myCopy(str, s);
}

Stroka::Stroka(const Stroka &other)
{
    capacity = other.capacity;
    str = new char[capacity];
    myCopy(str, other.str);
}

Stroka::~Stroka()
{
    delete[] str;
}

Stroka &Stroka::operator=(const Stroka &other)
{
    if (this == &other) return *this;
    delete[] str;
    capacity = other.capacity;
    str = new char[capacity];
    myCopy(str, other.str);
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Stroka &s)
{
    os << s.str;
    return os;
}

std::istream &operator>>(std::istream &is, Stroka &s)
{
    is.getline(s.str, s.capacity);
    return is;
}
