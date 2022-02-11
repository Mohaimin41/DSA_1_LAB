#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>
#include <cstring>

#define MAXCITIES 10

const long long int inf = std::numeric_limits<long long int>::max();

int costs[MAXCITIES][MAXCITIES];
long long dp[MAXCITIES][1 << MAXCITIES];

long long solve(int, int, int);

int main()
{
    int cities;
    std::cin >> cities;

    std::fill(dp[0], dp[0] + MAXCITIES * (1 << MAXCITIES), -1);
    
    for (int row = 0; row < cities; row++)
        for (int col = 0; col < cities; col++)
            std::cin >> costs[row][col];

    // calling with 0 city to visit and highest bitmask, taking all city as visited at first backtracking recursive call
    std::cout << solve(0, (1 << cities ) - 1, cities);
    return 0;
}

long long solve(int curr, int mask, int total)
{
    // base case: if we have all city to visit, that means visti started, cost 0
    if (curr == total)
        return 0;

    // if previously calculated value, return that
    if (dp[curr][mask] != -1)
        return dp[curr][mask];

    // we recursively calculate cost here
    long long prev_cities_cost, curr_city_cost = inf;

    // count cost for each city in given range
    for (int city = 0; city < total; city++)
    {

        // first add up cost for all pre visited cities from the mask
        prev_cities_cost = 0;
        for (int prev_city = 0; prev_city < total; prev_city++)
        {
            // if bit on, city was visited
            if (!(mask & (1 << prev_city)))
                prev_cities_cost += costs[city][prev_city];
        }

        // now find min cost for the city by going through all non visited cites recursively
        // each call has one more city to visit
        // bit on means city visited, so we take min of visiting prev total and 
        if ((mask & (1 << city)))
        {
            // min of current cost and cost of visiting this city
            curr_city_cost = std::min(curr_city_cost,
                                      costs[city][city] + prev_cities_cost + solve(curr + 1, (mask | (1 << city)), total));
        }
    }

    return dp[curr][mask] = curr_city_cost;
}