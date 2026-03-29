#include <iostream>

using namespace std;

// Zadanie 2 - Rabota s ukazatelyami
template <class T>
void showInfo(T *p, const char *name)
{
    cout << name << ": address = " << p << ", value = " << *p << endl;
}

int main()
{
    setlocale(LC_ALL, "");

    int a = 100;
    double b = 12.5;
    char c = 'Z';

    int *pa = &a;
    double *pb = &b;
    char *pc = &c;

    // Pokazyvaem adres i znachenie do izmeneniya
    showInfo(pa, "pa");
    showInfo(pb, "pb");
    showInfo(pc, "pc");

    // Menyaem dannye cherez ukazateli
    *pa += 23;
    *pb *= 2;
    *pc = 'Q';

    cout << endl << "Posle izmeneniya cherez ukazateli:" << endl;
    showInfo(pa, "pa");
    showInfo(pb, "pb");
    showInfo(pc, "pc");

    return 0;
}
