#ifndef STROKA_STREAM_H
#define STROKA_STREAM_H

#include <iostream>

class Stroka
{
private:
    char *str;
    int capacity;

    static int myLen(const char *s);
    static void myCopy(char *dest, const char *src);

public:
    Stroka(int size = 120);
    Stroka(const char *s);
    Stroka(const Stroka &other);
    ~Stroka();

    Stroka &operator=(const Stroka &other);

    friend std::ostream &operator<<(std::ostream &os, const Stroka &s);
    friend std::istream &operator>>(std::istream &is, Stroka &s);
};

#endif
