#include <iostream>

#include "mySort.h"

int main()
{
    int A[] = {2, 8, 7, 1, 3, 5, 6, 4};
    
    std::srand(43);
    quicksort(A, 0, 7);
    // mergeSort(A, 0, 7);
    // insertionSort(A, 8);
    // RandQuicksort(A, 0, 7);
    
    
    int sz = sizeof(A) / sizeof(A[0]);
    std::cout << "Array size: " << sz << ", Array: ";
    for (int i = 0; i < 8; i++)
        std::cout << A[i] << " ";
    std::cout << "\n";
    return 0;
}