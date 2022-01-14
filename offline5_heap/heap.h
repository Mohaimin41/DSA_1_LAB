#include <iostream>
#include <vector>

class Heap
{
private:
    int m_capacity; //size of heap array, always +1 of actual m_capacity for 1-indexed tree
    int m_curr_pos; //currently where last value in array is, insert at m_curr_pos + 1
    int *m_heapArr;

public:
    Heap() : m_capacity(8), m_curr_pos(0), m_heapArr(new int[m_capacity]) {}

    Heap(int sz) : m_capacity(sz + 1), m_curr_pos(0), m_heapArr(new int[m_capacity]) {}

    Heap(std::vector<int> &given_V) : m_capacity(given_V.size() + 1), m_curr_pos(0), m_heapArr(new int[m_capacity])
    {
        int sz = given_V.size();

        for (int i = 0; i < sz; i++)
            insert(given_V[i]);
    }

    ~Heap() { delete[] m_heapArr; }

    void insert(int num_to_insert)
    {
        if (m_curr_pos == m_capacity)
        {
            std::cout << "ERROR: Heap full, insert not possible\n";
        }
        else
        {
            //first we put it in first empty slot in array
            m_heapArr[++m_curr_pos] = num_to_insert;
            //then we sift it down
            siftDown_inArray(m_curr_pos);
        }
    }

    int size() const { return m_curr_pos; }

    int getMax() const { return m_heapArr[1]; }

    void deleteKey()
    {
        if (!m_curr_pos)
        {
            std::cout << "ERROR: Heap empty, deletion of key not possible\n";
        }
        else
        {
            m_heapArr[1] = m_heapArr[m_curr_pos--];
            siftUp_inArray(1);
        }
    }

    void print()
    {
        std::cout << "\nArray index:\t";
        for (int i = 0; i < m_curr_pos; i++)
        {
            std::cout << i + 1<< "\t";
        }
        std::cout << "\nArray content:\t";
        for (int i = 0; i < m_curr_pos; i++)
        {
            std::cout << m_heapArr[i + 1] << " \t";
        }
    }

private:
    int left(int pos) { return pos << 1; }

    int right(int pos) { return (pos << 1) | 1; }

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
        while (parent(pos) && m_heapArr[parent(pos)] < m_heapArr[pos])
        {
            std::swap(m_heapArr[parent(pos)], m_heapArr[pos]);
            pos /= 2; //
        }
    }

    void siftUp_inArray(int pos)
    {
        //first we compare pos with its children, if they be larger than pos
        //we swap, then we do same again, till reaching half of array

        while (pos < m_curr_pos / 2) //till m_curr_pos / 2 is penultimate level, next all leaves
        {
            int larger_child = m_heapArr[left(pos)] >= m_heapArr[right(pos)]
                                   ? left(pos)
                                   : right(pos);

            if (m_heapArr[pos] < m_heapArr[larger_child])
            {
                std::swap(m_heapArr[pos], m_heapArr[larger_child]);
                pos = larger_child;
            }
            else
            {
                return; // break out of loop and function as the value reached proper place
            }
        }
    }
};

void heapsort(std::vector<int> &given_V)
{
    Heap sortHeap(given_V);

    int sz = given_V.size();

    for (int i = 0; i < sz; i++)
    {
        given_V[i] = sortHeap.getMax();
        sortHeap.deleteKey();
    }
}