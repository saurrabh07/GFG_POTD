#include <iostream>
using namespace std;

class Solution {
public:
    bool isMaxHeap(int arr[], int n) {
        for (int i = 0; i < (n / 2); i++) {
            // Check left child
            if (arr[i] < arr[2 * i + 1]) {
                return false;
            }
            // Check right child
            if (2 * i + 2 < n && arr[i] < arr[2 * i + 2]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution solution;
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if (solution.isMaxHeap(arr, n)) {
        cout << "The given array is a max heap." << endl;
    } else {
        cout << "The given array is not a max heap." << endl;
    }

    return 0;
}
