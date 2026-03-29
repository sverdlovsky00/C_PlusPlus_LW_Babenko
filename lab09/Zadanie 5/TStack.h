#ifndef TSTACK_H
#define TSTACK_H

#include <iostream>
#include <stdexcept>

template <class T>
class TStack
{
private:
    T *item;
    int numItem;
    int topIndex;

public:
    TStack(int size = 10)
    {
        numItem = size;
        topIndex = 0;
        item = new T[numItem];
    }

    ~TStack()
    {
        delete[] item;
    }

    void push(T t)
    {
        if (topIndex >= numItem)
            throw std::runtime_error("Stek perepolnen");
        item[topIndex++] = t;
    }

    T pop()
    {
        if (topIndex <= 0)
            throw std::runtime_error("Stek pust");
        return item[--topIndex];
    }

    bool empty() const
    {
        return topIndex == 0;
    }
};

#endif
