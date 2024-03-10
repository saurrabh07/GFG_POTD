#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
    // Recursion
    bool solveRecursion(int arr[], int n, int r) {
        if (r == 0) {
            return true;
        }
        if (n == 0) {
            return false;
        }
        if (r >= arr[n - 1]) {
            return solveRecursion(arr, n - 1, r - arr[n - 1]) || solveRecursion(arr, n - 1, r);
        } else {
            return solveRecursion(arr, n - 1, r);
        }
    }

    // Memoization
    bool solveMemoization(int arr[], int n, int r, vector<vector<int>>& dp) {
        if (r == 0) {
            return true;
        }
        if (n == 0) {
            return false;
        }
        if (dp[n][r] != -1) {
            return dp[n][r];
        }
        if (r >= arr[n - 1]) {
            return dp[n][r] = solveMemoization(arr, n - 1, r - arr[n - 1], dp) || solveMemoization(arr, n - 1, r, dp);
        } else {
            return dp[n][r] = solveMemoization(arr, n - 1, r, dp);
        }
    }

    int minDifferenceRecursion(int arr[], int n) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
        }
        return sum - 2 * maxSubsetSum(arr, n, sum / 2);
    }

    int minDifferenceMemoization(int arr[], int n) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
        }
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
        solveMemoization(arr, n, sum, dp);
        return sum - 2 * maxSubsetSumMemoization(dp, n, sum / 2);
    }

    // Tabulation
    int minDifferenceTabulation(int arr[], int n) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
        }

        bool t[n + 1][sum + 1];

        // Initialization
        for (int i = 0; i < n + 1; i++) {
            for (int j = 0; j < sum + 1; j++) {
                if (i == 0) {
                    t[i][j] = false;
                }
                if (j == 0) {
                    t[i][j] = true;
                }
            }
        }

        // Dynamic Programming
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < sum + 1; j++) {
                if (arr[i - 1] <= j) {
                    t[i][j] = (t[i - 1][j - arr[i - 1]] || t[i - 1][j]);
                } else {
                    t[i][j] = t[i - 1][j];
                }
            }
        }

        // Find the maximum sum achievable in one subset
        int maxSum = 0;
        for (int j = sum / 2; j >= 0; j--) {
            if (t[n][j] == true) {
                maxSum = j;
                break;
            }
        }

        return sum - 2 * maxSum;
    }

    // Utility function to find the maximum sum of a subset
    int maxSubsetSum(int arr[], int n, int sum) {
        if (sum == 0) {
            return 0;
        }
        if (n == 0) {
            return 0;
        }
        if (arr[n - 1] <= sum) {
            return max(arr[n - 1] + maxSubsetSum(arr, n - 1, sum - arr[n - 1]), maxSubsetSum(arr, n - 1, sum));
        } else {
            return maxSubsetSum(arr, n - 1, sum);
        }
    }

    // Utility function to find the maximum sum of a subset using memoization
    int maxSubsetSumMemoization(vector<vector<int>>& dp, int n, int sum) {
        if (sum == 0) {
            return 0;
        }
        if (n == 0) {
            return 0;
        }
        if (dp[n][sum] != -1) {
            return dp[n][sum];
        }
        if (arr[n - 1] <= sum) {
            return dp[n][sum] = max(arr[n - 1] + maxSubsetSumMemoization(dp, n - 1, sum - arr[n - 1]), maxSubsetSumMemoization(dp, n - 1, sum));
        } else {
            return dp[n][sum] = maxSubsetSumMemoization(dp, n - 1, sum);
        }
    }
};

int main() {
    Solution solution;
    int arr[] = {1, 2, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Using Recursion: " << solution.minDifferenceRecursion(arr, n) << endl;
    cout << "Using Memoization: " << solution.minDifferenceMemoization(arr, n) << endl;
    cout << "Using Tabulation: " << solution.minDifferenceTabulation(arr, n) << endl;

    return 0;
}
