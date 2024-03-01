#include <iostream>
using namespace std;

class Solution {
public:
    int peakElement(int arr[], int n) {
        if (n == 1)
            return 0;
        int low = 0;
        int high = n - 1;
        
        // Perform binary search to find a peak element.
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] >= arr[mid + 1])
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int peakIndex = sol.peakElement(arr, n);
    cout << "Peak element index is: " << peakIndex << endl;
    return 0;
}
