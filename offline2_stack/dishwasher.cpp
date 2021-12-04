#include <iostream>
#include "LinkedStack.h"
#include "ArrStack.h"

using namespace std;

class dish_event
{

public:
    int dish_DS_time, dish_size;
    dish_event() {}
    dish_event( int dish_DS_time, int dish_size)
    {
        this->dish_size = dish_size;
        this->dish_DS_time = dish_DS_time;
    }
    dish_event(dish_event *d)
    {
        this->dish_size = d->dish_size;
        this->dish_DS_time = d->dish_DS_time;
     }
};

int main()
{
    int friend_total, dish_total;
    int friend_num, dish_DS_time, dish_size;
    int iter = 1;

    cin >> friend_total >> dish_total;
    int all_dish_size[dish_total];

    for (int i = 0; i < dish_total; i++)
        cin >> all_dish_size[i];

    LinkedStack<dish_event> dirty_stack(friend_total * dish_total);
    LinkedStack<int> clean_stack(friend_total * dish_total);
    LinkedStack<int> complete_meal(friend_total);

    // ArrStack<dish_event> dirty_stack(friend_total * dish_total);
    // ArrStack<int> clean_stack(friend_total * dish_total);
    // ArrStack<int> complete_meal(friend_total);
    
    while (1)
    {
        cin >> friend_num >> dish_DS_time >> dish_size;
        // iter++;

        if (dish_total == dish_size)
            complete_meal.push(friend_num);

        dish_size = all_dish_size[dish_size - 1];
        if (!friend_num)
            break;

        //first time straight to clean with wash time 
        if (iter++ == 1)
        {
            clean_stack.push(dish_DS_time + dish_size - 1);
        }
        else
        {   //first we check if any dish left to work in dirty stack
            while (dirty_stack.length() > 0)
            {   
                //this means there is a dish being washed, so we cannot pop any dish from it to push in clean stack
                if (clean_stack.topValue() >= dish_DS_time)
                    break;
                //this means there is a chance to wash dishes now, as the clean stack last had a dish earlier than current dish time
                else
                {
                    //this means this dirty dish at dirty stack top is being worked in future, so dish wash starts from current clean_stack top time
                    if (clean_stack.topValue() + 1 > dirty_stack.topValue().dish_DS_time)
                        clean_stack.push(clean_stack.topValue() + dirty_stack.topValue().dish_size);
                    //otherwise dish wash starts in the time the dirty dish was pushed to dirty stack, immediately put to wash
                    else
                        clean_stack.push(dirty_stack.topValue().dish_DS_time + dirty_stack.topValue().dish_size - 1);
                    //the top dirty dish is washed, popped from dirty stack
                    dirty_stack.pop();
                }
            }
            //after clearing allowable old dishes we push current dish to dirty stack
            dirty_stack.push(new dish_event(dish_DS_time, dish_size));
        }
    }
    while (dirty_stack.length() > 0)
    //now we clean up the remaining dishes in stack, same as in input loop
    {
        if (clean_stack.topValue() + 1 > dirty_stack.topValue().dish_DS_time)
            clean_stack.push(clean_stack.topValue() + dirty_stack.topValue().dish_size);
        else
            clean_stack.push(dirty_stack.topValue().dish_DS_time + dirty_stack.topValue().dish_size - 1);

        dirty_stack.pop();
    }

    cout << clean_stack.topValue() << endl;

    int len = clean_stack.length();
    int dish_times[len];

    for (int j = len - 1; j >= 0; j--)
        dish_times[j] = clean_stack.pop();

    for (int i = 0; i < len; i++)
    {
        cout << dish_times[i];
        if (i < len - 1)
            cout << ",";
    }
    cout << endl;

    if (complete_meal.length() == friend_total)
    {
        cout << "Y" << endl;
    }
    else
    {
        cout << "N" << endl;
    }
    
    for (int i = complete_meal.length(); i >= 1; i--)
    {
        cout << complete_meal.pop();
        if (i > 1)
            cout << ",";
    }

    return 0;
}
