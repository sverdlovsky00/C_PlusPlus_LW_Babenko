#include <iostream>

using namespace std;

// Zadanie 4 - Shablon klassa TArray i specializaciya dlya const char*.
template <class T>
class TArray
{
private:
    T data[100];
    int count;

public:
    TArray()
    {
        count = 0;
    }

    void add(T item)
    {
        data[count++] = item;
    }

    void print() const
    {
        for (int i = 0; i < count; i++)
            cout << data[i] << " ";
        cout << endl;
    }
};

template <>
class TArray<const char *>
{
private:
    const char *data[100];
    int count;

public:
    TArray()
    {
        count = 0;
    }

    void add(const char *item)
    {
        data[count++] = item;
    }

    void print() const
    {
        for (int i = 0; i < count; i++)
            cout << data[i] << " | ";
        cout << endl;
    }
};

int main()
{
    TArray<int> iarr;
    iarr.add(10);
    iarr.add(20);
    iarr.add(30);
    iarr.print();

    TArray<const char *> sarr;
    sarr.add("pervaya");
    sarr.add("vtoraya");
    sarr.add("tretya");
    sarr.print();
    return 0;
}
