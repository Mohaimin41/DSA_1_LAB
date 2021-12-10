#pragma once

#include <ostream>

namespace dsa1
{
    template <typename E>
    class Queue
    {
    private:
        Queue(const Queue &) {}
        void operator=(const Queue &) {}

    public:
        Queue() {}
        virtual void clear() = 0;
        virtual void enqueue(const E &item) = 0;
        virtual E dequeue() = 0;                 //Returns front element, removes it
        virtual int length() = 0;                //Return the number of elements in the queue.
        virtual const E &frontValue() const = 0; //returns copy of front element
        virtual const E &rearValue() const = 0;  //returns copy of last element
        virtual E leaveQueue() = 0;              //Return the rear element which has left the queue
    };

    template <typename E>
    std::ostream &operator<<(std::ostream &os, Queue<E> &my_queue)
    {
        int len = my_queue.length();
        E temp[] = new E[len];

        os << "<";
        for (int i = 0; i < len; i++)
        {
            temp[i] = my_queue.dequeue();
            os << temp[i];
            if (i < len - 1)
            {
                os << ", ";
            }
        }
        os << ">" << std::endl;

        for (int i = 0; i < len; i++)
            my_queue.enqueue(temp[i]);

        return os;
    }
} //namespace dsa1