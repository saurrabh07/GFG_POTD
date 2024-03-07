#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    string longestSubstring(string s, int n) {
        string s1 = s;
        string s2 = s;
        int maxi = INT_MIN;
        int maxIdxRow = -1;
        int maxIdxCol = -1;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i < j) {
                    if (s1[i - 1] == s2[j - 1]) {
                        dp[i][j] = 1 + dp[i - 1][j - 1];
                        if (dp[i][j] > j - i) dp[i][j] = 0;
                        if (maxi < dp[i][j]) {
                            maxi = dp[i][j];
                            maxIdxRow = i;
                            maxIdxCol = j;
                        }
                    }
                }
            }
        }
        if (maxi == INT_MIN) return "-1";
        string ans = "";
        while (dp[maxIdxRow][maxIdxCol] != 0) {
            ans = s1[maxIdxRow - 1] + ans;
            maxIdxRow--;
            maxIdxCol--;
        }
        return ans;
    }
};

// Brute-force approach
string longestSubstringBruteForce(string s) {
    int maxLength = 0;
    string longestSubstr = "";

    // Iterate through all possible substrings
    for (int i = 0; i < s.length(); i++) {
        for (int j = i + 1; j <= s.length(); j++) {
            string substr = s.substr(i, j - i);
            bool isUnique = true;

            // Check if all characters in the substring are unique
            for (int k = 0; k < substr.length(); k++) {
                if (substr.find(substr[k], k + 1) != string::npos) {
                    isUnique = false;
                    break;
                }
            }

            // Update maximum length and longest substring
            if (isUnique && substr.length() > maxLength) {
                maxLength = substr.length();
                longestSubstr = substr;
            }
        }
    }

    return longestSubstr;
}

int main() {
    Solution sol;
    string input;
    int n;
    cout << "Enter the string: ";
    cin >> input;
    n = input.length();
    cout << "Longest unique substring: " << sol.longestSubstring(input, n) << endl;

    // Brute-force
    cout << "Longest unique substring (Brute-force): " << longestSubstringBruteForce(input) << endl;

    return 0;
}
