#pragma once

#include <iostream>

#include "Abstract_queue.h"

namespace dsa1
{

    template <typename E>
    class ArrQueue : public Queue<E>
    {
    private:
        /* data */
        int m_chunkSize = (51);
        int m_front;
        int m_rear;
        E *m_Arr;

    public:
        //constructor with size, chunkSize is +1 to it
        ArrQueue(int sz = 50) : m_chunkSize(sz + 1), m_front(1), m_rear(0), m_Arr(new E[m_chunkSize]) {}

        //constructor that takes an array to use as empty queue
        ArrQueue(E *newArr, int sz) : m_chunkSize(sz), m_front(1), m_rear(0), m_Arr(newArr) {}

        ~ArrQueue()
        {
            delete[] m_Arr;
        }

    private:
        void extend_size_and_copy()
        {
            int prev_chunkSize = m_chunkSize;
            m_chunkSize *= 2;

            E *temp = new E[m_chunkSize];
            int len = length();

            //copy elements
            //BIG MISTAKES HERE
            for (int i = 0, k = m_front; i < len; i++, (k++) % prev_chunkSize)
            {
                temp[i] = m_Arr[k];
            }

            //change all other members
            m_front = 0;
            m_rear = len - 1;

            //delete old Arr
            delete[] m_Arr;

            //assign temp to Arr
            m_Arr = temp;
        }

    public:
        void clear() override
        {
            //deallocate memory, as we shall check for size in enqueue and resize if needed
            // delete[] m_Arr;
            m_front = 1;
            m_rear = 0;
        }

        void enqueue(const E &item) override
        {
            //check size, we have chunkSize = len + 1, so if rear + 2 loops back to front, whole queue is full
            if (((m_rear + 2) % m_chunkSize) == m_front)
            {
                extend_size_and_copy();
            }
            //add at rear with rear incrementing by modulus
            m_rear = (m_rear + 1) % m_chunkSize;
            m_Arr[m_rear] = item;
            // std::cout << "enqueued at: " << m_rear << " val: " << m_Arr[m_rear] << std::endl;
        }

        E dequeue() override
        {
            if (!this->length())
            {
                throw "Queue is empty, dequeuing not possible";
            }
            E res = m_Arr[m_front];
            //circular increment of front by modulus with chunkSize
            m_front = (m_front + 1) % m_chunkSize;
            return res;
        }

        inline int length() override
        {
            //first we unroll circular queue by adding chunkSize to rear, subtract and get length
            //modulus it with chunkSize again as unrolled circular queue may have drifted
            return ((m_rear + m_chunkSize) - m_front + 1) % m_chunkSize;
        }

        inline const E &frontValue() const override
        {
            if (!(((m_rear + m_chunkSize) - m_front + 1) % m_chunkSize))
            {
                throw "Queue is empty, no front element";
            }
            return m_Arr[m_front];
        }

        inline const E &rearValue() const override
        {
            if (!(((m_rear + m_chunkSize) - m_front + 1) % m_chunkSize))
            {
                throw "Queue is empty, no rear element";
            }
            return m_Arr[m_rear];
        }

        E leaveQueue() override
        {
            if (!this->length())
            {
                throw "Queue is empty, no rear element for leaving queue";
            }

            E res = m_Arr[m_rear];

            //check where is rear and update
            // if (m_front != m_rear)
            // {
            //     m_rear = (m_rear + m_chunkSize - 1) % m_chunkSize;
            // }
            m_rear = (m_rear + m_chunkSize - 1) % m_chunkSize;
            
            return res;
        }
    };

} //namespace dsa1