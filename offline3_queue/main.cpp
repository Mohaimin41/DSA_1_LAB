#include <iostream>
#include <string>

// #include "Abstract_queue.h"
#include "ArrQueue.h"
#include "LinkedQueue.h"

int main()
{
    int len = 0, num = 0, task = 1;
    std::cin >> len;
    // dsa1::ArrQueue<int> numbers(len);
    dsa1::LinkedQueue<int> numbers(len);

    for (int i = 0; i < len; i++)
    {
        std::cin >> num;
        numbers.enqueue(num);
    }

    std::cout << numbers;

    do
    {
        int param = -1, val = -1;
        std::cin >> task >> param;

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
            numbers.enqueue(param);
        }
        else if (task == 3)
        {
            try
            {
                val = numbers.dequeue();
            }
            catch (const char* err)
            {
                std::cout << "ERROR: " << err << " " << std::endl;
            }
        }
        else if (task == 4)
        {
            val = numbers.length();
        }
        else if (task == 5)
        {
            try
            {
                val = numbers.frontValue();
            }
            catch (const char* err)
            {
                std::cout << "ERROR: " << err << " " << std::endl;
            }
        }
        else if (task == 6)
        {
            try
            {
                val = numbers.rearValue();
            }
            catch (const char* err)
            {
                std::cout << "ERROR: " << err << " " << std::endl;
            }
        }
        else if (task == 7)
        {
            try
            {
                val = numbers.leaveQueue();
            }
            catch (const char* err)
            {
                std::cout << "ERROR: " << err << " " << std::endl;
            }
        }
        else
        {
            break;
        }

        // cout << "stck len: " << numbers.length() << endl;

        std::cout << numbers;
        std::cout << val << std::endl;
    } while (task != 0);

    return 0;
}