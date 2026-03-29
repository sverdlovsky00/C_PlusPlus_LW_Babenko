#ifndef SINGLY_LIST_H
#define SINGLY_LIST_H

#include <iostream>

template <class T>
class SinglyList
{
private:
    struct Node
    {
        T data;
        Node *next;
    };

    Node *head;

public:
    SinglyList()
    {
        head = NULL;
    }

    ~SinglyList()
    {
        clear();
    }

    bool empty() const
    {
        return head == NULL;
    }

    void clear()
    {
        while (head != NULL)
        {
            Node *tmp = head;
            head = head->next;
            delete tmp;
        }
    }

    void pushBack(const T &value)
    {
        Node *p = new Node;
        p->data = value;
        p->next = NULL;

        if (head == NULL)
        {
            head = p;
            return;
        }

        Node *cur = head;
        while (cur->next != NULL)
            cur = cur->next;

        cur->next = p;
    }

    void pushFront(const T &value)
    {
        Node *p = new Node;
        p->data = value;
        p->next = head;
        head = p;
    }

    bool removeValue(const T &value, T *removedValue)
    {
        if (head == NULL)
            return false;

        if (head->data == value)
        {
            Node *tmp = head;
            if (removedValue != NULL)
                *removedValue = head->data;
            head = head->next;
            delete tmp;
            return true;
        }

        Node *cur = head;
        while (cur->next != NULL)
        {
            if (cur->next->data == value)
            {
                Node *tmp = cur->next;
                if (removedValue != NULL)
                    *removedValue = tmp->data;
                cur->next = tmp->next;
                delete tmp;
                return true;
            }
            cur = cur->next;
        }

        return false;
    }

    T *findValue(const T &value)
    {
        Node *cur = head;
        while (cur != NULL)
        {
            if (cur->data == value)
                return &cur->data;
            cur = cur->next;
        }
        return NULL;
    }

    template <class Printer>
    void print(Printer printer) const
    {
        if (head == NULL)
        {
            std::cout << "(spisok pust)" << std::endl;
            return;
        }

        Node *cur = head;
        while (cur != NULL)
        {
            printer(cur->data);
            cur = cur->next;
        }
    }
};

#endif
