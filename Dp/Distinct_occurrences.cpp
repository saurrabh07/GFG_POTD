#include <iostream>
#include <vector>
#include <string>

#define mod 1000000007

using namespace std;

class Solution
{
public:
    // Recursive solution
    int solveRecursive(int i, int j, int n, int m, string s, string t) 
    {
        if(j == m)
            return 1;
            
        if(i == n)
            return 0;
        
        if(s[i] == t[j]) 
        {
            int notTake = solveRecursive(i + 1, j, n, m, s, t);
            int take = solveRecursive(i + 1, j + 1, n, m, s, t);
            return (notTake + take) % mod;
        } 
        else 
        {
            return solveRecursive(i + 1, j, n, m, s, t) % mod;
        }
    }        
    
    // Dynamic Programming solution
    int solveDP(string s, string t) 
    {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Base case: if t is empty, there is one subsequence, an empty string
        for (int i = 0; i <= n; ++i)
            dp[i][0] = 1;

        for (int i = 1; i <= n; ++i) 
        {
            for (int j = 1; j <= m; ++j) 
            {
                dp[i][j] = dp[i - 1][j];
                if (s[i - 1] == t[j - 1]) 
                {
                    dp[i][j] += dp[i - 1][j - 1];
                    dp[i][j] %= mod;
                }
            }
        }
        return dp[n][m];
    }

    // Tabulation solution
    int solveTabulation(string s, string t) 
    {
        int n = s.size(), m = t.size();
        vector<int> dp(m + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= n; ++i) 
        {
            for (int j = m; j >= 1; --j) 
            {
                if (s[i - 1] == t[j - 1]) 
                {
                    dp[j] = (dp[j] + dp[j - 1]) % mod;
                }
            }
        }
        return dp[m];
    }

    // Wrapper function for recursive solution
    int subsequenceCountRecursive(string s, string t)
    {
        return solveRecursive(0, 0, s.size(), t.size(), s, t) % mod;
    }

    // Wrapper function for dynamic programming solution
    int subsequenceCountDP(string s, string t)
    {
        return solveDP(s, t) % mod;
    }

    // Wrapper function for tabulation solution
    int subsequenceCountTabulation(string s, string t)
    {
        return solveTabulation(s, t) % mod;
    }
};

int main() {
    string s, t;
    cout << "Enter string s: ";
    cin >> s;
    cout << "Enter string t: ";
    cin >> t;

    Solution sol;

    // Recursive solution
    int countRecursive = sol.subsequenceCountRecursive(s, t);
    cout << "Number of subsequences of t in s (Recursive): " << countRecursive << endl;

    // Dynamic Programming solution
    int countDP = sol.subsequenceCountDP(s, t);
    cout << "Number of subsequences of t in s (Dynamic Programming): " << countDP << endl;

    // Tabulation solution
    int countTabulation = sol.subsequenceCountTabulation(s, t);
    cout << "Number of subsequences of t in s (Tabulation): " << countTabulation << endl;

    return 0;
}
