// #pragma once
#ifndef ARRSTACK_H
#define ARRSTACK_H

#include <iostream>
#include "Stack.h"

using namespace std;

template <typename T>
class ArrStack : public stack<T>
{
private:
    /* data */
    int StackLength;
    int size;
    int tos;
    const int chunkSize = 50;
    T *StackArr;
    int dir = 1;

    void extendSizeAndCopy()
    {
        if (size == 0)
            size = chunkSize;
        if (size <= StackLength)
            size = StackLength;

        // cout << "size @extendSizeAndCopy: old: " << size;
        size *= 2;
        // cout << "new: " << size << endl;
        T *tempStackArr = new T[size];

        for (int i = 0; i < StackLength; i++)
            tempStackArr[i] = StackArr[i];

        delete[] StackArr;

        StackArr = tempStackArr;
    }
    void rightShift(T *arr, int shiftCellNum, int occupiedCellNum)
    {
        if (shiftCellNum + occupiedCellNum > /*sizeof(arr) / sizeof(T)*/ size)
        {
            cout << "Not enough space in array to shift elements right" << endl;
            cout << "size needed: " << shiftCellNum + occupiedCellNum << ", size is: " << sizeof(arr) / sizeof(T *) << endl;
        }
        else
        {
            for (int i = 0; i < occupiedCellNum; i++)
                arr[i + shiftCellNum] = arr[i];
        }
    }

public:
    ArrStack() {}
    ArrStack(int init_size = 50)
    {
        size = init_size;
        StackArr = new T[size];
        StackLength = tos = 0; //tos = 0 means empty stack
    }
    ArrStack(T *newArr, int dir)
    {
        StackArr = newArr;
        size = sizeof(newArr) / sizeof(T *);
        StackLength = tos = 0;
        this.dir = dir;
    }

    ~ArrStack() { delete[] StackArr; }
    void clear()
    {
        StackLength = tos = 0;
        delete[] StackArr;
        if (!size)
            size = chunkSize;
        StackArr = new T[size];
    }
    void push(const T &item)
    {
        if (dir == 1)
        {
            if (tos == size - 1)
                extendSizeAndCopy();

            StackArr[tos++] = item;
            StackLength++;
        }
        else
        {
            if (tos == 0)
            {
                extendSizeAndCopy();
                rightShift(StackArr, StackLength, StackLength);

                tos += StackLength;
            }
            StackArr[tos--] = item;
            StackLength++;
        }
    }
    T pop()
    {
        if (dir == 1)
        {
            if (tos == 0)
            {
                cout << "tos: " << tos << ", Stack is empty @pop call" << endl;
                return -1;
            }
            StackLength--;
            // cout << "tos: " << tos << " len: " << StackLength << " @ok pop call" << endl;
            return StackArr[--tos];
        }
        else
        {
            if (tos == size - 1)
            {
                cout << "tos: " << tos << " Stack is empty" << endl;
                return -1;
            }
            StackLength--;
            // cout << "tos: " << tos << " len: " << StackLength << " @ok pop call" << endl;
            return StackArr[++tos];
        }
    }
    int length() { return StackLength; }
    const T &topValue()
    {
        if (dir == 1)
        {
            if (tos == 0)
            {
                cout << "tos: " << tos << ", Stack is empty @topValue call" << endl;
                return (T)-1;
            }
            return StackArr[tos - 1];
        }
        else
        {
            if (tos == size - 1)
            {
                cout << "tos: " << tos << " Stack is empty @topValue call" << endl;
                return (T)-1;
            }
            return StackArr[tos + 1];
        }
    }
    void setDirection(int dir = 1)
    {
        if (dir != this->dir)
        {
            this->dir = dir;
            for (int i = 0, j = size - 1; i <= j; i++, j--)
                swap(StackArr[i], StackArr[j]);

            tos = size - 1 - tos;
        }
    }
};

#endif