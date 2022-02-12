#include <iostream>
#include <limits>

#define MAXCITIES 10

const long int inf = std::numeric_limits<long int>::max();

const int nm = 1 << MAXCITIES;
int costs[MAXCITIES][MAXCITIES];
long long dp[MAXCITIES][nm];

int total;

long solve(int, int);

int main()
{

    std::cin >> total;

    std::fill(dp[0], dp[0] + MAXCITIES * nm, -1);

    for (int row = 0; row < total; row++)
        for (int col = 0; col < total; col++)
            std::cin >> costs[row][col];

    // we start with first city with no city visited
    std::cout << solve(0, (1 << total) - 1);
    return 0;
}

long solve(int curr, int mask)
{

    // base case: if all city visited, then no need to travel so cost for this cell 0
    if (curr >= total)
        return 0;

    if (dp[curr][mask] != -1)
        return dp[curr][mask];

    long curr_city_cost = inf;

    // value for current city with this mask isn't counted yet, we do that here
    // looping for all cities and counting if it is univisited in mask
    for (int city = 0; city < total; city++)
    {
        // unvisited city
        if (mask & (1 << city))
        {
            long prev_cities_cost = 0;

            for (int prev_city = 0; prev_city < total; prev_city++)
            {
                // pre visited cities add cost
                if (!(mask & (1 << prev_city)))
                    prev_cities_cost += costs[city][prev_city];
            }

            // min of (cost for visiting this city from this mask
            // , min from costs of visiting all previous allowable cities from this mask)
            // thus we keep taking the minimum cost, at lowest mask, all city will be visited with min cost
            // to find cost for visiting all the ciites in the mask without current city
            // recursive call is made with current city's bit set in the mask and increasing the number of cities visited

            curr_city_cost = std::min(curr_city_cost,
                                      costs[city][city] + prev_cities_cost + solve(curr + 1, (mask ^ (1 << city))));
        }
    }

    return dp[curr][mask] = curr_city_cost;
}