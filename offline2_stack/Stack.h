// #pragma once
#ifndef STACK_H
#define STACK_H

template <typename T>
class stack
{
private:
    void operator=(const stack &) {} //protect assignment operator and copy constructor
    stack(const stack &) {}

public:
    stack() {}                               //default constructor
    virtual ~stack() {};                       //destructor
    virtual void clear() = 0;                   //clears stack, frees up array for use
    virtual void push(const T &item) = 0;       //pushes an item to top of the stack
    virtual T pop() = 0;                        //removes and return item from top of stack
    virtual int length() = 0;                   //returns length
    virtual const T &topValue() = 0;            //returns item from top of stack
    virtual void setDirection(int dir = 1) = 0; //sets growing direction for ArrStack,
                                                //1 for upward from first positon in array
                                                //-1 for downward from last position in array
};

#endif