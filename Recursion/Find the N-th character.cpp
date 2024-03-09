#include <iostream>
using namespace std;

class Solution {
public:
    // Function to find nth character in the string using brute force approach
    char nthCharacterBruteForce(string s, int r, int n) {
        for(int i = 0 ; i < r ; i++) {
            string ans ="";
            for(int j = 0 ; j < s.length() ; j++) {
                if(s[j] == '1') {
                    ans += "10";
                }
                else {
                    ans += "01";
                }
            }
            s = ans ;
        }
        return s[n];
    }

    // Function to find nth character in the string using optimal solution with recursion
    char nthCharacterOptimal(string s, int r, int n) {
        if(r == 0) {
            return s[n];
        }

        char ch = nthCharacterOptimal(s, r - 1, n / 2);

        if(n % 2 == 0) {
            if(ch == '1') {
                return '1';
            }
            else {
                return '0';
            }
        }
        else {
            if(ch == '0') {
                return '1';
            }
            else {
                return '0';
            }
        }
    }
};

int main() {
    Solution solution;
    string s;
    int r, n;

    // Taking input from the user
    cout << "Enter the string: ";
    cin >> s;
    cout << "Enter the number of iterations (r): ";
    cin >> r;
    cout << "Enter the index (n): ";
    cin >> n;

    // Finding nth character using brute force approach
    cout << "Brute Force Solution: ";
    cout << solution.nthCharacterBruteForce(s, r, n) << endl;

    // Finding nth character using optimal solution with recursion
    cout << "Optimal Solution: ";
    cout << solution.nthCharacterOptimal(s, r, n) << endl;

    return 0;
}
