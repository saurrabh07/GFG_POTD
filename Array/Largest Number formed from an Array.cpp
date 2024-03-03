#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Brute force solution to print the largest number
string printLargest_BruteForce(int n, vector<string>& arr) {
    sort(arr.begin(), arr.end(), [](const string& a, const string& b) {
        return a + b > b + a;
    });

    string ans = "";
    for (const string& str : arr) {
        ans += str;
    }

    return ans;
}

// Optimal solution to print the largest number
string printLargest_Optimal(int n, vector<string>& arr) {
    sort(arr.begin(), arr.end(), [](const string& a, const string& b) {
        return a + b > b + a;
    });

    string ans = "";
    for (const string& str : arr) {
        ans += str;
    }

    return ans;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<string> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << "Brute Force Solution: " << printLargest_BruteForce(n, arr) << endl;
    cout << "Optimal Solution: " << printLargest_Optimal(n, arr) << endl;

    return 0;
}
