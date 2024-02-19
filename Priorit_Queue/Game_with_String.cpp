#include <iostream>
#include <map>
#include <queue>

using namespace std;

class Solution {
public:
    int minValue(string s, int k) {
        priority_queue<pair<int, char>> pq;
        map<char, int> mp;

        // Count the frequency of each character
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
        }

        // Push the frequencies into a priority queue
        for (auto it = mp.begin(); it != mp.end(); it++) {
            pq.push({it->second, it->first});
        }

        // Remove k characters
        while (k-- && pq.size() > 0) {
            auto temp = pq.top();
            pq.pop();
            pq.push({(temp.first - 1), temp.second});
        }

        // Calculate the value
        int ans = 0;
        while (pq.size() > 0) {
            ans += (pq.top().first * pq.top().first);
            pq.pop();
        }
        return ans;
    }
};

int main() {
    Solution solution;
    string s;
    int k;

    // Input string and k from the user
    cout << "Enter the string: ";
    cin >> s;
    cout << "Enter the value of k: ";
    cin >> k;

    // Calculate and print the minimum value
    int result = solution.minValue(s, k);
    cout << "Minimum value after removal of " << k << " characters: " << result << endl;

    return 0;
}
