#include <iostream>
#include <algorithm>
#include <string>

#define MAXROW 51
#define MAXCOL 51

// dp array
int L[MAXROW][MAXCOL];

void solve(std::string, std::string);

std::string traceback(std::string, std::string);

int main()
{
    std::string s1, s2;
    std::cin >> s1 >> s2;
    
    solve(s1, s2);
    return 0;
}

void solve(std::string s1, std::string s2)
{
    // string lengths
    int m = s1.length(), n = s2.length();

    // filling up dp array
    for (int row = 1; row <= m; row++)
    {
        for (int col = 1; col <= n; col++)
        {
            if (s1[row - 1] == s2[col - 1])
            {
                // matches, so we discard this letter from both string and reduce length
                L[row][col] = L[row - 1][col - 1] + 1;
            }
            else
            {
                // doesn't match, we take max of the two case reducing both string lengths respectively
                L[row][col] = std::max(L[row - 1][col], L[row][col - 1]);
            }
        }
    }

    std::cout << L[m][n] << "\n";

    // traceback part
    std::cout << traceback(s1, s2);
}

std::string traceback(std::string s1, std::string s2)
{
    std::string lcs;
    int row = s1.length(), col = s2.length();
    while (row && col)
    {
        if (L[row][col] == L[row - 1][col - 1] + 1 && s1[row - 1] == s2[col - 1])
        {
            //this letter matches, add in lcs
            lcs.push_back(s1[row - 1]);
            row--;
            col--;
        }
        else if (L[row][col] == L[row - 1][col])
        {
            //go to upper row
            row--;
        }
        else if (L[row][col] == L[row][col - 1])
        {
            //go to previous col
            col--;
        }
    }
    std::reverse(lcs.begin(), lcs.end());
    return lcs;
}