#include <iostream>
#include <vector>
#include <cstring> // for memset
using namespace std;

class Solution {
public:
    long long int dp[100001][3];
    vector<int> arr = {3, 5, 10};

    long long int solve(long long int n, int i) {
        if (n == 0) {
            return 1;
        }
        if (n < 0 || i == 3) {
            return 0;
        }
        if (dp[n][i] != -1)
            return dp[n][i];

        long long int sum = solve(n - arr[i], i);
        sum += solve(n, i + 1);

        return dp[n][i] = sum;
    }

    long long int countDP(long long int n) {
        memset(dp, -1, sizeof(dp));
        return solve(n, 0);
    }

    long long int countBruteForce(long long int n) {
        long long int ans = 0;
        for (int i = 0; i <= n; i += 3) {
            ans += (n - i) % 5 ? 0 : (n - i) / 10 + 1;
        }
        return ans;
    }
};

int main() {
    long long int n;
    cout << "Enter the value of n: ";
    cin >> n;

    Solution solution;
    
    // Dynamic Programming Solution
    long long int dpResult = solution.countDP(n);
    cout << "Using DP, Number of ways to express " << n << " as a sum of 3, 5, and 10: " << dpResult << endl;
    
    // Brute Force Solution
    long long int bruteForceResult = solution.countBruteForce(n);
    cout << "Using Brute Force, Number of ways to express " << n << " as a sum of 3, 5, and 10: " << bruteForceResult << endl;

    return 0;
}
