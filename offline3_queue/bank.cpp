#include <iostream>

#include "Abstract_queue.h"
#include "ArrQueue.h"
#include "LinkedQueue.h"

template <typename E>
void equalize_queues(dsa1::Queue<E> &, dsa1::Queue<E> &);

int main()
{
    struct customer
    {
        int in_time;
        int service_time;
        customer() : in_time(-1), service_time(-1) {}
        customer(int in, int service) : in_time(in), service_time(service)
        {
        }
    };

    int total;
    std::cin >> total;
    dsa1::ArrQueue<customer> que1;
    dsa1::ArrQueue<customer> que2;
    // dsa1::LinkedQueue<customer> que1;
    // dsa1::LinkedQueue<customer> que2;

    int queue1_time{0};
    int queue2_time{0};

    bool que1_first = true;
    bool que2_first = true;

    for (int i = 0; i < total; i++)
    {
        int in, service;
        std::cin >> in >> service;
        customer temp(in, service);
        // if (!i)
        // {
        //     //choose queue1 for first customer
        //     //queue1_time = temp.in_time + temp.service_time;
        //     que1.enqueue(temp);
        // }
        // else
        // {

        while (que1.length() && que2.length())
        {

            //process queue1
            if (temp.in_time >= queue1_time + que1.frontValue().service_time)
            {
                queue1_time += que1.frontValue().service_time;
                que1.dequeue();
            }

            //process queue 2
            if (temp.in_time >= queue2_time + que2.frontValue().service_time)
            {
                queue2_time += que2.frontValue().service_time;
                que2.dequeue();
            }

            if ((temp.in_time < queue1_time + que1.frontValue().service_time) && (temp.in_time < queue2_time + que2.frontValue().service_time))
            {
                break;
            }
        }
        //enqueue temp in shortest queue
        if (que1.length() <= que2.length())
        {
            que1.enqueue(temp);
            if (que1_first)
            {
                queue1_time += temp.in_time;
                que1_first = false;
            }
        }
        else
        {
            que2.enqueue(temp);
            if (que2_first)
            {
                queue2_time += temp.in_time;
                que2_first = false;
            }
        }

        //equalize
        equalize_queues(que1, que2);
        // }
    }

    // std::cout << "TIMES: " << queue1_time << " " << queue2_time << std::endl;

    while ((que1.length() || que2.length()))
    {
        if (que1.length())
        {
            queue1_time += que1.frontValue().service_time;
            que1.dequeue();
        }
        if (que2.length())
        {
            queue2_time += que2.frontValue().service_time;
            que2.dequeue();
        }
        equalize_queues(que1, que2);
        // std::cout << "TIMES: " << queue1_time << " " << queue2_time << std::endl;
    }

    std::cout << "Booth 1 finishes at t=" << queue1_time << std::endl;
    std::cout << "Booth 2 finishes at t=" << queue2_time << std::endl;
    return 0;
}

template <typename E>
void equalize_queues(dsa1::Queue<E> &Que1, dsa1::Queue<E> &Que2)
{
    while (true)
    {
        if (Que1.length() - 1 > Que2.length())
        {
            Que2.enqueue(Que1.leaveQueue());
        }
        else if (Que2.length() - 1 > Que1.length())
        {
            Que1.enqueue(Que2.leaveQueue());
        }
        else
        {
            break;
        }
    }
}