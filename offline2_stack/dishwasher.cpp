#include <iostream>
#include "LinkedStack.h"
#include "ArrStack.h"

using namespace std;

class dish_event
{

public:
    int dish_DS_time, dish_size;
    dish_event() {}
    dish_event(int dish_DS_time, int dish_size)
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

    // LinkedStack<dish_event> dirty_stack(friend_total * dish_total);
    LinkedStack<int> complete_meal(friend_total);
    // LinkedStack<dish_event> clean_stack(friend_total * dish_total);

    // ArrStack<dish_event> dirty_stack(friend_total * dish_total);
    // ArrStack<dish_event> clean_stack(friend_total * dish_total);
    // ArrStack<int> complete_meal(friend_total);

    //1 array of dish_event, 2 * friend_total * dish_total size
    dish_event stckArr[2 * friend_total* dish_total];

    // set dir 1 for ArrStack<dish_event> dirty stack, -1 for clean stack
    ArrStack<dish_event> dirty_stack(stckArr, 1, 2 * friend_total* dish_total);
    ArrStack<dish_event> clean_stack(stckArr, -1, 2 * friend_total* dish_total);

    while (1)
    {
        cin >> friend_num >> dish_DS_time >> dish_size;

        if (dish_total == dish_size)
            complete_meal.push(friend_num);

        dish_size = all_dish_size[dish_size - 1];
        if (!friend_num)
            break;

        //first time straight to clean with wash time
        if (iter++ == 1)
        {
            clean_stack.push(new dish_event(dish_DS_time + dish_size - 1, 0));
        }
        else
        { //first we check if any dish left to work in dirty stack
            while (dirty_stack.length() > 0)
            {
                //this means there is a dish being washed, so we cannot pop any dish from it to push in clean stack
                if (clean_stack.topValue().dish_DS_time >= dish_DS_time)
                {
                    break;
                }

                //this means there is a chance to wash dishes now, as the clean stack last had a dish earlier than current dish time
                else
                {
                    //this means this dirty dish at dirty stack top is being worked in future, so dish wash starts from current clean_stack top time
                    if (clean_stack.topValue().dish_DS_time + 1 > dirty_stack.topValue().dish_DS_time)
                    {
                        clean_stack.push(new dish_event(clean_stack.topValue().dish_DS_time + dirty_stack.topValue().dish_size, 0));
                    }

                    //otherwise dish wash starts in the time the dirty dish was pushed to dirty stack, immediately put to wash
                    else
                    {
                        clean_stack.push(new dish_event(dirty_stack.topValue().dish_DS_time + dirty_stack.topValue().dish_size - 1, 0));
                    }

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
        if (clean_stack.topValue().dish_DS_time + 1 > dirty_stack.topValue().dish_DS_time)
            clean_stack.push(new dish_event(clean_stack.topValue().dish_DS_time + dirty_stack.topValue().dish_size, 0));
        else
            clean_stack.push(new dish_event(dirty_stack.topValue().dish_DS_time + dirty_stack.topValue().dish_size - 1, 0));

        dirty_stack.pop();
    }

    cout << clean_stack.topValue().dish_DS_time << endl;

    int len = clean_stack.length();
    int dish_times[len];

    for (int j = len - 1; j >= 0; j--)
        dish_times[j] = clean_stack.pop().dish_DS_time;

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
