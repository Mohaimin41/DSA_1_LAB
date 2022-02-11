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

    for (int i = 0; i < MAXCITIES; i++)
        for (int j = 0; j < nm; j++)
            dp[i][j] = -1;

    for (int row = 0; row < total; row++)
        for (int col = 0; col < total; col++)
            std::cin >> costs[row][col];

    std::cout << solve(0, (1 << total) - 1);
    return 0;
}

long solve(int curr, int mask)
{
    if (curr >= total)
        return 0;

    if (dp[curr][mask] != -1)
        return dp[curr][mask];

    long curr_city_cost = inf;

    for (int city = 0; city < total; city++)
    {
        
        if ((mask & (1 << city)) != 0)
        {
            long prev_cities_cost = 0;
           
            for (int prev_city = 0; prev_city < total; prev_city++)
            {
                if ((mask & (1 << prev_city)) == 0)
                    prev_cities_cost += costs[city][prev_city];
            }
            
            curr_city_cost = std::min(curr_city_cost,
                                      costs[city][city] + prev_cities_cost + solve(curr + 1, (mask ^ (1 << city))));
        }
    }

    return dp[curr][mask] = curr_city_cost;
}