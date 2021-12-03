#include <iostream>
#include "LinkedStack.h"
#include "ArrStack.h"

using namespace std;

class dish_event
{

public:
    int friend_num, dish_DS_time, dish_size;
    dish_event() {}
    dish_event(int friend_num, int dish_DS_time, int dish_size)
    {
        this->friend_num = friend_num;
        this->dish_size = dish_size;
        this->dish_DS_time = dish_DS_time;
    }
    dish_event(dish_event *d)
    {
        this->friend_num = d->friend_num;
        this->dish_size = d->dish_size;
        this->dish_DS_time = d->dish_DS_time;
    }
};

int main()
{
    int friend_total, dish_total;
    int friend_num, dish_DS_time, dish_size;
    int iter = 0;

    cin >> friend_total >> dish_total;
    int all_dish_size[dish_total] ;

    for (int i = 0; i < dish_total; i++)
        cin >> all_dish_size[i];

    // LinkedStack<dish_event> dirty_stack(friend_total * dish_total);
    // LinkedStack<int> clean_stack(friend_total * dish_total);
    // LinkedStack<int> complete_meal(friend_total);

    ArrStack<dish_event> dirty_stack(friend_total * dish_total);
    ArrStack<int> clean_stack(friend_total * dish_total);
    ArrStack<int> complete_meal(friend_total);

    while (1)
    {
        cin >> friend_num >> dish_DS_time >> dish_size;
        iter++;
        if (!friend_num)
            break;

        if (dish_total == dish_size)
            complete_meal.push(friend_num);

        dirty_stack.push(new dish_event(friend_num, dish_DS_time, dish_size));

        if (iter == 1)
        {
            clean_stack.push(dish_DS_time + all_dish_size[dish_size - 1] - 1);
            dirty_stack.pop();
        }
        while (dirty_stack.length() > 0)
        {
            dish_event temp = dirty_stack.topValue();
            if (temp.dish_DS_time + all_dish_size[dish_size - 1] - 1 == clean_stack.topValue())
            {
                clean_stack.push(clean_stack.topValue() + all_dish_size[dish_size - 1]);
                dirty_stack.pop();
            }
            else if (temp.dish_DS_time == clean_stack.topValue())
            {
                clean_stack.push(temp.dish_DS_time + all_dish_size[dish_size - 1]);
                dirty_stack.pop();
            }
            else if (temp.dish_DS_time < clean_stack.topValue())
            {
                break;
            }
            else
            {
                clean_stack.push(temp.dish_DS_time + all_dish_size[dish_size - 1] - 1);
                dirty_stack.pop();
            }
        }
    }

    cout << "ds len: " << dirty_stack.length() << " cs len: " << clean_stack.length() << endl;
    while (dirty_stack.length() > 0)
    {
        dish_event temp = dirty_stack.topValue();
        if (clean_stack.topValue() >= temp.dish_DS_time)
        {
            clean_stack.push(clean_stack.topValue() + all_dish_size[temp.dish_size - 1]);
            dirty_stack.pop();
        }
        else
        {
            clean_stack.push(clean_stack.topValue() + all_dish_size[temp.dish_size - 1] - 1);
            dirty_stack.pop();
        }
    }

    int total_time = clean_stack.topValue();
    cout << total_time << endl;

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
        while (complete_meal.length() > 0)
        {
            cout << complete_meal.pop() << ",";
        }
    }
    else
    {
        cout << "N" << endl;
        while (complete_meal.length() > 0)
        {
            cout << complete_meal.pop() << ",";
        }
    }

    return 0;
}