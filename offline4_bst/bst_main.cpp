#include <iostream>
#include <fstream>
#include <string>

#include "BST.h"

int main()
{
    std::ifstream input_stream("input.txt");

    char operation;

    dsa1::BST<int, int> my_bst;

    //input loop
    while (input_stream >> operation)
    {
        int num_operand = 0;
        std::string str_operand;
        if (operation == 'I')
        {
            input_stream >> num_operand;
            // std::cout << num_operand << ' ';
            //we are keeping key = element here
            my_bst.insert(num_operand, num_operand);
        }
        else if (operation == 'D')
        {
            input_stream >> num_operand;
            try
            {
                my_bst.remove(num_operand);
//                std::cout << "REMOVED: " << num_operand << std::endl;

            }
            catch (const char *error)
            {
                std::cout << error << '\n';
            }
        }
        else if (operation == 'F')
        {
            input_stream >> num_operand;
            // std::cout << num_operand << ' ';
            std::cout << my_bst.find(num_operand) << '\n';
        }
        else if (operation == 'T')
        {
            input_stream >> str_operand;
            // std::cout << str_operand << ' ';
            my_bst.traverse(str_operand);
        }
        else
        {
            break;
        }
    }

    input_stream.close();
    return 0;
}
