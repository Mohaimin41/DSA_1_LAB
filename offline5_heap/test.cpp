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
        temp.push_back(i);
    }
    temp.push_back(48);
    temp.push_back(79);
    temp.push_back(59);
    temp.push_back(-3);
    temp.push_back(5838);
    cout << "\n";
    Heap test(temp);

    cout << test.size() << "\n";
    test.print();
    cout << "\nSORT temp: \n";

    heapsort(temp);

    for (int i = 0; i < temp.size(); i++)
        cout << temp[i] << " ";
    // cout << temp.size();
    cout << "\n";
    
    for (int i = 1; i < 14; i++)
    {
        cout << "\ntesting pos: " << i << "\n";
        //cout << "Max: " << test.getMax() << " now deleting max: ";
        test.deleteKey();
        test.print();
    }
}
// #include<iostream>
// #include "heap.h"
// #include<vector>
// using namespace std;
// int main()
// {
//     vector<int> temp;
//     int x;
//     for(int i=0;i<10;i++)
//     { cin>>x;
//       temp.push_back(x);
//     }
//     heapsort(temp);
//     for(int i=0;i<10;i++)
//     {
//         cout<<temp[i]<<" ";
//     }
// }