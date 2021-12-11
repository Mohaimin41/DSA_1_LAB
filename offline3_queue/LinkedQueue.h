#pragma once

#include <iostream>

#include "Abstract_queue.h"

namespace dsa1
{

    template <typename E>
    class LinkedQueue : public Queue<E>
    {
    private:
        /* data */
        struct node
        {
            E item;
            node *next;
            //struct constructors
            node(node *next) : item{}, next(next) {}
            node(const E &item, node *next = nullptr) : item(item), next(next) {}
        };

        //front and rear pointers, front->next is start of list
        node *m_front;
        node *m_rear;

        int m_length;

    public:
        LinkedQueue(int sz = 50) : m_front(new node(nullptr)), m_rear(m_front), m_length(0)
        {
        }

        ~LinkedQueue()
        {
            //loop and delete all nodes
            clear();
            //delete front
            delete m_front;
        }

        void clear() override
        {
            //loop and delete all node from front
            while (m_front->next != nullptr)
            {
                node *temp = m_front;
                m_front = m_front->next;
                delete temp;
            }
            m_rear = m_front;
            m_length = 0;
        }

        void enqueue(const E &item) override
        {
            m_rear->next = new node(item, nullptr);
            m_rear = m_rear->next;
            m_length++;
            // std::cout << "enqueud val: " << m_rear->item << " at " << m_length << std::endl;
        }

        E dequeue() override
        {
            if (!m_length)
            {
                throw "Queue empty, dequeing not possible";
            }
            //return item from node
            E res = m_front->next->item;
            //temp node
            node *temp = m_front->next;
            //advance front's next to next node
            m_front->next = temp->next;
            //check if reached rear, then rear should be set as front, essentially cleared queue
            if (temp == m_rear)
            {
                m_rear = m_front;
            }

            delete temp;

            m_length--;
            return res;
        }

        int length() override { return m_length; }

        const E &frontValue() const override
        {
            if (!m_length)
            {
                throw "Queue empty, no front element";
            }
            return m_front->next->item;
        }

        const E &rearValue() const override
        {
            if (!m_length)
            {
                throw "Queue empty, no rear element";
            }
            return m_rear->item;
        }

        E leaveQueue() override
        {
            if (!m_length)
            {
                throw "Queue empty, no rear element to leave queue";
            }

            //traverse list from front to find rear
            node *temp = m_front;
            while (temp->next->next != NULL)
            {
                temp = temp->next;
            }
            //take item from rear
            E res = temp->next->item;

            //set rear - 1 node as rear
            m_rear = temp;
            //delete next node i.e. old rear
            delete temp->next;
            //set rear's next to null, cause previous node has just been deleted
            m_rear->next = nullptr;

            m_length--;

            return res;
        }
    };

} //namespace dsa1