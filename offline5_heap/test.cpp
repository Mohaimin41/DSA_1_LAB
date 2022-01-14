#include <iostream>
#include "heap.h"
#include <vector>
using namespace std;
int main()
{
    vector<int> temp;
    int x;
    for (int i = 1; i < 100; i *= 2)
    {
        cout << i << " ";
        temp.push_back(i );
    }
    temp.push_back(48);
    temp.push_back(79);
    temp.push_back(59);
    temp.push_back(-3);
    temp.push_back(5838);
    cout << "\n";
    Heap test(temp);
    // for (int i = 0; i < 10; i++)
    // {
    //     cout << temp[i] << " ";
    // }
    cout << test.size() << "\n";
    test.print();
}