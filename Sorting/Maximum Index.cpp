#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Brute force solution
    int maxDistance_BruteForce(vector<int>& a) {
        int n = a.size();
        int maxDist = 0;
        
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (a[i] <= a[j]) {
                    maxDist = max(maxDist, j - i);
                }
            }
        }
        
        return maxDist;
    }

    // Optimal solution
    int maxDistance_Optimal(vector<int>& a) {
        int n = a.size();
        vector<pair<int, int>> ar(n);
        
        // Create a vector of pairs where the second value of the pair is the index
        for (int i = 0; i < n; ++i) {
            ar[i] = {a[i], i};
        }
        
        // Sort the vector based on the first value of the pairs
        sort(ar.begin(), ar.end());
        
        // Initialize variables for answer and index
        int ans = 0, i = ar[0].second;
        
        // Traverse the sorted vector
        for (int j = 0; j < n; ++j) {
            // Update the minimum index encountered so far
            i = min(ar[j].second, i);
            // Update the maximum distance encountered so far
            ans = max(ar[j].second - i, ans);
        }
        
        return ans;
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> a(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    cout << "Brute Force Solution: " << sol.maxDistance_BruteForce(a) << endl;
    cout << "Optimal Solution: " << sol.maxDistance_Optimal(a) << endl;

    return 0;
}
