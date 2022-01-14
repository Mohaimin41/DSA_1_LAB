#include <iostream>
#include <vector>

class Heap
{
private:
    int capacity; //size of heap array, always +1 of actual capacity for 1-indexed tree
    int curr_pos; //currently where last value in array is, insert at curr_pos + 1
    int *heapArr;

public:
    Heap() : capacity(1), curr_pos(0), heapArr(new int[capacity]) {}

    Heap(int sz) : capacity(sz + 1), curr_pos(0), heapArr(new int[capacity]) {}

    Heap(std::vector<int> &given_V) : capacity(given_V.size() + 1), curr_pos(0), heapArr(new int[capacity])
    {
        while (!given_V.empty())
        {
            insert(given_V.back());
            given_V.pop_back();
        }
    }

    ~Heap() { delete[] heapArr; }

    void insert(int num_to_insert)
    {
        if (curr_pos == capacity)
        {
            std::cout << "ERROR: Heap full, insert not possible\n";
        }
        else
        {
            //first we put it in first empty slot in array
            heapArr[++curr_pos] = num_to_insert;
            //then we sift it down
            siftDown_inArray(curr_pos);
        }
    }

    int size() const { return curr_pos; }

    int getMax() const { return heapArr[1]; }

    void deleteKey()
    {
        if (!curr_pos)
        {
            std::cout << "ERROR: Heap empty, deletion of key not possible\n";
        }
        else
        {
            heapArr[1] = heapArr[curr_pos--];
            siftUp_inArray(1);
        }
    }

    void print()
    {
        for (int i = 0; i < curr_pos; i++)
        {
            std::cout << heapArr[i+1] << " ";
        }
    }

private:
    int leftChild(int pos) { return pos << 1; }

    int rightChild(int pos) { return (pos << 1) | 1; }

    int parent(int pos)
    {
        if (pos)
            return pos >> 1;
        else
            // return NULL;
            return 0;
        // pos > 0 ? return pos >> 1 : return NULL; }
    }

    void siftDown_inArray(int pos)
    {
        /*while(parent) && arr[parent] < arr[pos] 
                swap parent & current
                pos = parent(pos)*/
        while (parent(pos) && heapArr[parent(pos)] < heapArr[pos])
        {
            std::swap(heapArr[parent(pos)], heapArr[pos]);
            pos /= 2; //
        }
    }

    void siftUp_inArray(int pos)
    {
        //first we compare pos with its children, if they be larger than pos
        //we swap, then we do same again, till reaching half of array

        while (pos < curr_pos / 2) //till curr_pos / 2 is penultimate level, next all leaves
        {
            int larger_child = heapArr[pos << 1] >= heapArr[(pos << 1) | 1]
                                   ? pos << 1
                                   : (pos << 1) | 1;

            if (heapArr[pos] < heapArr[larger_child])
            {
                std::swap(heapArr[pos], heapArr[larger_child]);
                pos = larger_child;
            }
            else
            {
                return; // break out of loop and function as the value reached proper place
            }
        }
    }
};

void heapsort(std::vector<int> &given_V) {}