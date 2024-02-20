#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool solve(int ind, int n, string s, unordered_set<string>& st) {
        if (ind == n) {
            return true;
        }

        for (int i = ind; i < n; i++) {
            string subStr = s.substr(ind, i - ind + 1);
            if (st.find(subStr) != st.end()) {
                if (solve(i + 1, n, s, st)) {
                    return true;
                }
            }
        }

        return false;
    }

    int wordBreak(int n, string s, vector<string>& dictionary) {
        unordered_set<string> st;
        for (int i = 0; i < n; i++)
            st.insert(dictionary[i]);
        bool ans = solve(0, s.size(), s, st);
        return ans;
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter the size of the dictionary: ";
    cin >> n;
    vector<string> dictionary(n);
    cout << "Enter the words in the dictionary:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> dictionary[i];
    }
    string s;
    cout << "Enter the string to check word break: ";
    cin >> s;
    bool result = sol.wordBreak(s.size(), s, dictionary);
    if (result) {
        cout << "Word break is possible." << endl;
    } else {
        cout << "Word break is not possible." << endl;
    }
    return 0;
}
