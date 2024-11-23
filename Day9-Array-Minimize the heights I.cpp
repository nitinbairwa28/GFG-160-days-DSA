/* Given a positive integer k and an array arr[] denoting heights of towers, you have to modify the height of each tower either by increasing or decreasing them by k only once.
Find out what could be the possible minimum difference of the height of shortest and longest towers after you have modified each tower. */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

    int getMinDiff(int k, vector<int> &arr) {
        int n = arr.size();
        if (n == 1) return 0;
        sort(arr.begin(), arr.end());
        int minDiff = arr[n - 1] - arr[0];
        int smallest = arr[0] + k;
        int largest = arr[n - 1] - k;
        for (int i = 1; i < n; i++) {
            int currMin = min(smallest, arr[i] - k);
            int currMax = max(largest, arr[i - 1] + k);
            minDiff = min(minDiff, currMax - currMin);
        }
        return minDiff;
    }
;

int main() {
    
    vector<int> arr1 = {1, 15, 10};
    int k1 = 6;
    cout << "Minimum Difference for Test Case 1: " << getMinDiff(k1, arr1) << endl;

    vector<int> arr2 = {3, 9, 12, 16, 20};
    int k2 = 3;
    cout << "Minimum Difference for Test Case 2: " << getMinDiff(k2, arr2) << endl;

    return 0;
}
/* output= Minimum Difference for Test Case 1: 5
Minimum Difference for Test Case 2: 11 */
