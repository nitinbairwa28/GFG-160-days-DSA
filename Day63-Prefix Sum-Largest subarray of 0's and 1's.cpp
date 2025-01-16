//Given an array arr of 0s and 1s. Find and return the length of the longest subarray with equal number of 0s and 1s.
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int longestSubarrayWithEqual0sAnd1s(vector<int>& arr) {
    int n = arr.size();
    unordered_map<int, int> prefixSumIndex;
    int maxLength = 0;
    int prefixSum = 0;

    for (int i = 0; i < n; i++) {
        prefixSum += (arr[i] == 0) ? -1 : 1;

        if (prefixSum == 0) {
            maxLength = i + 1;
        }

        if (prefixSumIndex.find(prefixSum) != prefixSumIndex.end()) {
            maxLength = max(maxLength, i - prefixSumIndex[prefixSum]);
        } else {
            prefixSumIndex[prefixSum] = i;
        }
    }

    return maxLength;
}

int main() {
    vector<int> arr = {0, 1, 0, 1, 1, 0, 0};
    cout << "The length of the longest subarray is: " << longestSubarrayWithEqual0sAnd1s(arr) << endl;
    return 0;
}
// output : The length of the longest subarray is: 6
