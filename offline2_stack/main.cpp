#include <iostream>
#include "ArrStack.h"
#include "LinkedStack.h"

using namespace std;

template <typename T>
void printStack(stack<T>&);

int main()
{
    int len = 0, num = 0, task = 1;
    cin >> len;
    // ArrStack<int> numbers(len);
    LinkedStack<int> numbers(len);

    for (int i = 0; i < len; i++)
    {
        cin >> num;
        numbers.push(num);
    }

    do
    {
        int param = -1, val = -1;
        cin >> task >> param;

        if (task == 0)
        {
            break;
        }
        else if (task == 1)
        {
            numbers.clear();
        }
        else if (task == 2)
        {
            numbers.push(param);
        }
        else if (task == 3)
        {
            val = numbers.pop();
        }
        else if (task == 4)
        {
            val = numbers.length();
        }
        else if (task == 5)
        {
            val = numbers.topValue();
        }
        else if (task == 6)
        {
            numbers.setDirection(param);
        }
        else
        {
            break;
        }

        // cout << "stck len: " << numbers.length() << endl;

        printStack(numbers);
        cout << val << endl;
    } while (task != 0);

    return 0;
}

template <typename T>
void printStack(stack<T> &stck)
{
    int len = stck.length();
    T *tempArray = new T[len];

    for (int i = 0; i < len; i++)
        tempArray[i] = stck.pop();

    cout << "<";

    for (int i = 0; i < len; i++)
    {
        cout << tempArray[i];
        if (i < len - 1)
            cout << " ";
    }

    cout << ">" << endl;
  
    for (int i = len - 1; i >= 0; i--)
        stck.push(tempArray[i]);
    
    // cout << "stck len: " << stck.length() << endl;
}