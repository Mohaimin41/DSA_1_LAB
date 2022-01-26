#include <iostream>
#include <limits>

const int inf = std::numeric_limits<int>::max();

void insertionSort(int *A, int sz)
{
    for (int curr = 0; curr < sz - 1; curr++)
    {
        int min_val_idx = curr;
        for (int next = curr + 1; next < sz; next++)
        {
            if (A[min_val_idx] > A[next])
                min_val_idx = next;
        }

        std::swap(A[curr], A[min_val_idx]);
    }
}

int Partition(int A[], int start_idx, int end_idx)
{
    int pivot = A[end_idx];

    int next_val_to_swap = start_idx - 1;

    for (int curr = start_idx; curr <= end_idx - 1; curr++)
    {
        if (A[curr] <= pivot)
        {
            next_val_to_swap++;
            std::swap(A[next_val_to_swap], A[curr]);
        }
    }
    std::swap(A[next_val_to_swap + 1], A[end_idx]);
    return next_val_to_swap + 1;
}

void quicksort(int A[], int start_idx, int end_idx)
{
    if (start_idx < end_idx)
    {
        int next_pivot = Partition(A, start_idx, end_idx);
        quicksort(A, start_idx, next_pivot - 1);
        quicksort(A, next_pivot + 1, end_idx);
    }
}

int RandPartition(int A[], int start_idx, int end_idx)
{
    int pivot_idx = start_idx + std::rand() % (end_idx - start_idx);
    std::swap(A[end_idx], A[pivot_idx]);

    int pivot = A[end_idx];

    int next_val_to_swap = start_idx - 1;

    for (int curr = start_idx; curr <= end_idx - 1; curr++)
    {
        if (A[curr] <= pivot)
        {
            next_val_to_swap++;
            std::swap(A[next_val_to_swap], A[curr]);
        }
    }
    std::swap(A[next_val_to_swap + 1], A[end_idx]);
    return next_val_to_swap + 1;
}

void RandQuicksort(int A[], int start_idx, int end_idx)
{
    if (start_idx < end_idx)
    {
        int next_pivot = RandPartition(A, start_idx, end_idx);
        RandQuicksort(A, start_idx, next_pivot - 1);
        RandQuicksort(A, next_pivot + 1, end_idx);
    }
}

void merge(int *A, int start_idx, int mid_idx, int end_idx)
{
    int left_Arr_Size = mid_idx - start_idx + 1;
    int right_Arr_Size = end_idx - mid_idx;
    int *left_Arr = new int[left_Arr_Size + 1];
    int *Right_Arr = new int[right_Arr_Size + 1];

    for (int i = 0; i < left_Arr_Size; i++)
        left_Arr[i] = A[start_idx + i];

    for (int j = 0; j < right_Arr_Size; j++)
        Right_Arr[j] = A[mid_idx + j + 1];

    left_Arr[left_Arr_Size] = inf;
    Right_Arr[right_Arr_Size] = inf;

    int curr_left = 0, curr_right = 0;

    for (int curr = start_idx; curr <= end_idx; curr++)
    {
        if (left_Arr[curr_left] <= Right_Arr[curr_right])
        {
            A[curr] = left_Arr[curr_left];
            curr_left++;
        }
        else
        {
            A[curr] = Right_Arr[curr_right];
            curr_right++;
        }
    }
}

void mergeSort(int *A, int start_idx, int end_idx)
{
    if (start_idx < end_idx)
    {
        int mid_idx = (start_idx + end_idx) / 2;
        mergeSort(A, start_idx, mid_idx);
        mergeSort(A, mid_idx + 1, end_idx);
        merge(A, start_idx, mid_idx, end_idx);
    }
}