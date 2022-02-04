#include <iostream>
#include <algorithm>

int main()
{
    int N, friends;
    long long cost = 0;

    std::cin >> N >> friends;

    int *prices = new int[N];

    for (int idx = 0; idx < N; idx++)
    {
        std::cin >> prices[idx];
    }

    std::sort(prices, prices + N);

    std::reverse(prices, prices + N);

    int pass = 0;

    for (int idx = 0; idx < N; idx++)
    {
        if (idx % friends == 0)
        {
            pass++;
            //we increase pass as each time N passes friends, price is increased
        }

        cost += prices[idx] * pass;
    }

    std::cout << cost << "\n";

    return 0;
}