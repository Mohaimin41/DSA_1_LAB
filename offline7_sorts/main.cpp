#include <iostream>
#include <fstream>
#include <chrono>
#include <algorithm>
#include <iomanip>

#include "mySort.h"

int *generator(int total)
{
    int *res = new int[total];
    for (int idx = 0; idx < total; idx++)
    {
        res[idx] = std::rand();
    }
    return res;
}

double stlSort_test(int testArr_size)
{
    int tests = 20;
    double total = 0.0;
    while (tests--)
    {
        int *testArray = generator(testArr_size);

        // std::chrono::system_clock::time_point start = std::chrono::high_resolution_clock::now();
        auto start = std::chrono::high_resolution_clock::now();
        std::sort(testArray, testArray + testArr_size);
        total += double(std::chrono::duration_cast<std::chrono::nanoseconds>(
                            std::chrono::high_resolution_clock::now() - start)
                            .count() /
                        1000000.0);
    }

    return total / 20.0;
}

double insertion_test(int testArr_size)
{
    int tests = 20;
    double total = 0.0;
    while (tests--)
    {
        int *testArray = generator(testArr_size);

        // std::chrono::system_clock::time_point start = std::chrono::high_resolution_clock::now();
        auto start = std::chrono::high_resolution_clock::now();
        insertionSort(testArray, testArr_size - 1);
        total += double(std::chrono::duration_cast<std::chrono::nanoseconds>(
                            std::chrono::high_resolution_clock::now() - start)
                            .count() /
                        1000000.0);
    }

    return total / 20.0;
}

double quicksort_test(int testArr_size, bool sorted = false)
{
    int tests = 20;
    double total = 0.0;
    while (tests--)
    {
        int *testArray = generator(testArr_size);

        if (sorted)
            std::sort(testArray, testArray + testArr_size);

        // std::chrono::system_clock::time_point start = std::chrono::high_resolution_clock::now();
        auto start = std::chrono::high_resolution_clock::now();
        quicksort(testArray, 0, testArr_size - 1);
        total += double(std::chrono::duration_cast<std::chrono::nanoseconds>(
                            std::chrono::high_resolution_clock::now() - start)
                            .count() /
                        1000000.0);
    }

    return total / 20.0;
}

double rand_quicksort_test(int testArr_size, bool sorted = false)
{
    int tests = 20;
    double total = 0.0;
    while (tests--)
    {
        int *testArray = generator(testArr_size);

        if (sorted)
            std::sort(testArray, testArray + testArr_size);

        // std::chrono::system_clock::time_point start = std::chrono::high_resolution_clock::now();
        auto start = std::chrono::high_resolution_clock::now();
        RandQuicksort(testArray, 0, testArr_size - 1);
        total += double(std::chrono::duration_cast<std::chrono::nanoseconds>(
                            std::chrono::high_resolution_clock::now() - start)
                            .count() /
                        1000000.0);
    }

    return total / 20.0;
}

double mergesort_test(int testArr_size)
{
    int tests = 20;
    double total = 0.0;
    while (tests--)
    {
        int *testArray = generator(testArr_size);
        // std::chrono::system_clock::time_point start = std::chrono::high_resolution_clock::now();
        auto start = std::chrono::high_resolution_clock::now();
        mergeSort(testArray, 0, testArr_size - 1);
        total += double(std::chrono::duration_cast<std::chrono::nanoseconds>(
                            std::chrono::high_resolution_clock::now() - start)
                            .count() / 
                        1000000.0);
    }

    return total / 20.0;
}

int main()
{

    //file output part
    std::ofstream outputFileStream("output.csv", std::ios::out);
    std::streambuf *stream_buffer_file_out = outputFileStream.rdbuf();

    // Backup streambuffers of cin cout
    std::streambuf *stream_buffer_cout = std::cout.rdbuf();

    //redirection part
    std::cout.rdbuf(stream_buffer_file_out);

    //csv headers
    std::cout << ",Time required in ms,,,,,,"
              << "\n";
    std::cout << "n,Merge Sort,Quicksort,Randomized Quicksort,Insertion Sort,Quicksort with Sorted Input,Randomized Quicksort with Sorted Input,STL sort() function"
              << "\n";

    //testing part

    int N[] = {5, 10, 100, 1000, 10000};
    std::srand(7);

    for (int n : N)
    {
        std::cout << std::fixed << std::setw(10) << std::setprecision(10)
                  << n
                  << "," << mergesort_test(n)
                  << "," << quicksort_test(n)
                  << "," << rand_quicksort_test(n)
                  << "," << insertion_test(n)
                  << "," << quicksort_test(n, true)
                  << "," << rand_quicksort_test(n, true)
                  << "," << stlSort_test(n)
                  << "\n";
    }

    // sets couts streambuffer and returns the old
    std::cout.rdbuf(stream_buffer_cout);
    //close file
    outputFileStream.close();
}