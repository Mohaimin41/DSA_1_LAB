#include <iostream>

#include "catch.hpp"

#include "ArrQueue.h"
#include "LinkedQueue.h"

TEMPLATE_PRODUCT_TEST_CASE("Basic test", "[LinkedQueue]", (dsa1::ArrQueue, dsa1::LinkedQueue), (int))
{
    TestType queue;

    SECTION("Enqueue and non modifying operations")
    {
        REQUIRE(queue.length() == 0);
        queue.enqueue(23);
        queue.enqueue(49);
        queue.enqueue(14);
        queue.enqueue(99);

        REQUIRE(queue.length() == 4);
        CHECK(queue.frontValue() == 23);
        CHECK(queue.rearValue() == 99);
    }
    SECTION("Enqueue and dequeue")
    {
        REQUIRE(queue.length() == 0);
        queue.enqueue(23);
        queue.enqueue(49);
        queue.enqueue(14);
        queue.enqueue(99);

        REQUIRE(queue.length() == 4);
        CHECK(queue.dequeue() == 23);
        CHECK(queue.dequeue() == 49);
        CHECK(queue.dequeue() == 14);
        CHECK(queue.dequeue() == 99);
        REQUIRE(queue.length() == 0);
    }
    SECTION("Enqueue and leaveQueue")
    {
        REQUIRE(queue.length() == 0);
        queue.enqueue(23);
        queue.enqueue(49);
        queue.enqueue(14);
        queue.enqueue(99);

        REQUIRE(queue.length() == 4);
        CHECK(queue.leaveQueue() == 99);
        CHECK(queue.leaveQueue() == 14);
        CHECK(queue.leaveQueue() == 49);
        CHECK(queue.leaveQueue() == 23);
        REQUIRE(queue.length() == 0);
    }
}

TEMPLATE_PRODUCT_TEST_CASE("Bulk test", "[LinkedQueue]", (dsa1::ArrQueue, dsa1::LinkedQueue), (int))
{
    TestType queue;

    REQUIRE(queue.length() == 0);

    SECTION("enqueue and non modifying operations")
    {
        for (int i = 0; i < 201; i++)
        {
            queue.enqueue(i);
            CHECK(queue.frontValue() == 0);
            CHECK(queue.rearValue() == i);
            CHECK(queue.length() == i + 1);
        }
        REQUIRE(queue.length() == 201);
    }

    SECTION("enqueue and dequeue")
    {
        for (int i = 0; i < 201; i++)
        {
            queue.enqueue(i);
        }
        for (int i = 0; i < 201; i++)
        {
            CHECK(queue.dequeue() == i);
        }
        REQUIRE(queue.length() == 0);
    }
    SECTION("enqueue and leaveQueue")
    {
        for (int i = 0; i < 201; i++)
        {
            queue.enqueue(i);
        }
        REQUIRE(queue.length() == 201);
        for (int i = 200; i >= 0; i--)
        {
            CHECK(queue.leaveQueue() == i);
        }
        REQUIRE(queue.length() == 0);
    }
}