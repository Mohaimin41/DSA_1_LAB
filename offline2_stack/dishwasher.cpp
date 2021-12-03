#include <iostream>
#include "LinkedStack.h"
#include "ArrStack.h"

using namespace std;

class dish_event
{

public:
    int friend_num, dish_DS_time, dish_size;
    bool is_washed = false;
    dish_event() {}
    dish_event(int friend_num, int dish_DS_time, int dish_size)
    {
        this->friend_num = friend_num;
        this->dish_size = dish_size;
        this->dish_DS_time = dish_DS_time;
        is_washed = false;
    }
    dish_event(dish_event *d)
    {
        this->friend_num = d->friend_num;
        this->dish_size = d->dish_size;
        this->dish_DS_time = d->dish_DS_time;
        is_washed = false;
    }
};

int main()
{
    int friend_total, dish_total;
    int friend_num, dish_DS_time, dish_size;
    int iter = 0;

    cin >> friend_total >> dish_total;
    int all_dish_size[dish_total];

    for (int i = 0; i < dish_total; i++)
        cin >> all_dish_size[i];

    // LinkedStack<dish_event> dirty_stack(friend_total * dish_total);
    // LinkedStack<int> clean_stack(friend_total * dish_total);
    // LinkedStack<int> complete_meal(friend_total);

    ArrStack<dish_event> dirty_stack(friend_total * dish_total);
    ArrStack<int> clean_stack(friend_total * dish_total);
    ArrStack<int> complete_meal(friend_total);
    dish_event dirtyArr[friend_total * dish_total];
    while (1)
    {
        cin >> friend_num >> dish_DS_time >> dish_size;
        // iter++;
        if (!friend_num)
            break;

        if (dish_total == dish_size)
            complete_meal.push(friend_num);

        dish_size = all_dish_size[dish_size - 1];

        dirtyArr[iter++] = new dish_event(friend_num, dish_DS_time, dish_size);
    }

    clean_stack.push(dirtyArr[0].dish_DS_time + dirtyArr[0].dish_size - 1);
    dirtyArr[0].is_washed = true;

    for (int i = 1; i < iter; i++)
    {
        if (clean_stack.topValue() < dirtyArr[i].dish_DS_time)
        {
            for (int j = i - 1; !dirtyArr[j].is_washed; j--)
            {
                clean_stack.push(clean_stack.topValue() + dirtyArr[j].dish_size);
                dirtyArr[j].is_washed = true;
            }
            clean_stack.push(dirtyArr[i].dish_DS_time + dirtyArr[i].dish_size - 1);
            dirtyArr[i].is_washed = true;
        }
    }

    for (int j = iter - 1; !dirtyArr[j].is_washed; j--)
    {
        clean_stack.push(clean_stack.topValue() + dirtyArr[j].dish_size);
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
