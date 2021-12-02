#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

using namespace std;

template <typename T>
class node
{
public:
    T element;
    node<T> *next;
    node(const T &element, node *next = nullptr)
    {
        this->element = element;
        this->next = next;
    }
    node(node *next = nullptr) { this->next = next; }
};

template <typename T>
class LinkedStack : public stack<T>
{
private:
    node<T> *tos;
    int StackLength;
    int dir = 1;

public:
    LinkedStack()
    {
        tos = nullptr;
        StackLength = 0;
    }
    LinkedStack(int len)
    {
        tos = nullptr;
        StackLength = 0;
    }
    ~LinkedStack() {}
    void clear()
    {
        tos = nullptr;
        StackLength = 0;
        //        dir = 1;
    }
    void push(const T &item)
    {
        tos = new node<T>(item, tos);
        StackLength++;
    }
    T pop()
    {
        if (tos == nullptr)
        {
            cout << "Empty stack @pop call" << endl;
            return (T)-1;
        }
        StackLength--;
        T res = tos->element;
        node<T> *temp = tos->next;
        delete tos;
        tos = temp;
        // tos = tos->next;
        return res;
    }
    int length() { return StackLength; }
    const T &topValue()
    {
        if (tos == nullptr)
        {
            cout << "Empty stack @topValue call" << endl;
        }
        return tos->element;
    }
    void setDirection(int dir = 1) {}
};

#endif