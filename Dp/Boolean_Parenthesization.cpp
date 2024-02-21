#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int mod = 1003;

    // Brute force recursive function
    int solveBruteForce(int i, int j, int isTrue, string& S) {
        // Base case: empty string
        if (i > j) return 0;
        // Base case: single character
        if (i == j) {
            if (isTrue) return S[i] == 'T';
            else return S[i] == 'F';
        }
        int ways = 0;
        // Iterate over operators between i and j
        for (long long ind = i + 1; ind <= j - 1; ind = ind + 2) {
            // Recursively compute left and right subproblems
            int lT = solveBruteForce(i, ind - 1, 1, S);
            int lF = solveBruteForce(i, ind - 1, 0, S);
            int rT = solveBruteForce(ind + 1, j, 1, S);
            int rF = solveBruteForce(ind + 1, j, 0, S);
            // Based on the operator, compute the result
            if (S[ind] == '&') {
                if (isTrue) ways += (lT * rT) % mod;
                else ways += ((lT * rF) % mod + (lF * rT) % mod + (lF * rF) % mod) % mod;
            } else if (S[ind] == '|') {
                if (isTrue) ways += ((lT * rT) % mod + (lT * rF) % mod + (lF * rT) % mod) % mod;
                else ways += (lF * rF) % mod;
            } else {
                if (isTrue) ways += ((lT * rF) % mod + (lF * rT) % mod) % mod;
                else ways += (lT * rT) % mod + (lF * rF) % mod;
            }
        }
        return ways;
    }

    // Function to count the number of ways to evaluate expression to true using brute force
    int countWaysBruteForce(int n, string s) {
        return solveBruteForce(0, n - 1, 1, s);
    }

    // Optimized solution using dynamic programming
    int solveOptimized(int i, int j, int isTrue, string& S, vector<vector<vector<long long>>>& dp) {
        // Base cases
        if (i > j) return 0;
        if (i == j) return isTrue ? (S[i] == 'T') : (S[i] == 'F');
        // Check if already computed
        if (dp[i][j][isTrue] != -1) return dp[i][j][isTrue];
        int ways = 0;
        // Iterate over operators between i and j
        for (long long ind = i + 1; ind <= j - 1; ind = ind + 2) {
            // Recursively compute left and right subproblems
            int lT = solveOptimized(i, ind - 1, 1, S, dp);
            int lF = solveOptimized(i, ind - 1, 0, S, dp);
            int rT = solveOptimized(ind + 1, j, 1, S, dp);
            int rF = solveOptimized(ind + 1, j, 0, S, dp);
            // Based on the operator, compute the result
            if (S[ind] == '&') {
                if (isTrue) ways += (lT * rT) % mod;
                else ways += ((lT * rF) % mod + (lF * rT) % mod + (lF * rF) % mod) % mod;
            } else if (S[ind] == '|') {
                if (isTrue) ways += ((lT * rT) % mod + (lT * rF) % mod + (lF * rT) % mod) % mod;
                else ways += (lF * rF) % mod;
            } else {
                if (isTrue) ways += ((lT * rF) % mod + (lF * rT) % mod) % mod;
                else ways += (lT * rT) % mod + (lF * rF) % mod;
            }
        }
        // Memoize the result
        return dp[i][j][isTrue] = ways;
    }

    // Function to count the number of ways to evaluate expression to true using dynamic programming
    int countWaysOptimized(int n, string s) {
        vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(n, vector<long long>(2, -1)));
        return solveOptimized(0, n - 1, 1, s, dp);
    }
};

int main() {
    // Input
    int n;
    string expression;
    cout << "Enter the length of the expression: ";
    cin >> n;
    cout << "Enter the expression: ";
    cin >> expression;

    // Create an instance of the Solution class
    Solution sol;

    // Output
    cout << "Number of ways to evaluate expression to true (Brute Force): " << sol.countWaysBruteForce(n, expression) << endl;
    cout << "Number of ways to evaluate expression to true (Optimized): " << sol.countWaysOptimized(n, expression) << endl;

    return 0;
}
