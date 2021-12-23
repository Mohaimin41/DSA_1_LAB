#include <iostream>

#include "BST.h"

int main()
{
    dsa1::BST<int, int> my_bst;
    // int x = 1, y = 1;
    my_bst.insert(8, 8);
    my_bst.insert(10, 10);
    my_bst.insert(3, 3);
    my_bst.insert(1, 1);
    my_bst.insert(14, 14);
    my_bst.insert(6, 6);
    my_bst.insert(4, 4);
    my_bst.insert(13, 13);
    my_bst.insert(7, 7);
    my_bst.traverse("In");
    my_bst.traverse("Pre");
    my_bst.traverse("Post");
    
   // my_bst.print();
    my_bst.remove(8);
   // my_bst.print();
    my_bst.remove(7);
    // my_bst.print();
    my_bst.remove(10);
    // my_bst.print();
    my_bst.remove(1);
    my_bst.remove(3);
    my_bst.remove(14);
    my_bst.remove(6);
    my_bst.remove(4);
    my_bst.remove(13);
    
    try
    {
        my_bst.remove(10);
    }
    catch (const char *error)
    {
        std::cout << error << std::endl;
    }
    try
    {
        my_bst.remove(7);
    }
    catch (const char *error)
    {
        std::cout << error << std::endl;
    }
    std::cout << "Find 1: " << my_bst.find(1) << std::endl;
    // my_bst.print();
    return 0;
}