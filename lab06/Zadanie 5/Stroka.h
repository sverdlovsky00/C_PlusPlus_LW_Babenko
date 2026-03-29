#ifndef STROKA_H
#define STROKA_H

class Stroka
{
private:
    char *str;
    int len;

public:
    // Konstruktor po umolchaniyu
    Stroka();

    // Konstruktor iz C-stroki
    Stroka(const char *s);

    // Konstruktor kopirovaniya
    Stroka(const Stroka &other);

    // Konstruktor po razmeru
    Stroka(int size);

    // Destruktor
    ~Stroka();

    // Operator prisvaivaniya
    Stroka& operator=(const Stroka &other);

    // Dlina stroki
    int dlina() const;

    // Vyvod stroki
    void vyvod() const;

    // Dostup k simvolu po indeksu
    char& operator[](int index);
    const char& operator[](int index) const;

    // Sravnenie
    bool operator==(const Stroka &other) const;
    bool operator!=(const Stroka &other) const;

    // Konkatinaciya
    Stroka operator+(const Stroka &other) const;
};

#endif
