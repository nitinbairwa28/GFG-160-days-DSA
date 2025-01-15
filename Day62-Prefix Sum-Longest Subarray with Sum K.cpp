// Given an array arr[] containing integers and an integer k, your task is to find the length of the longest subarray where the sum of its elements is equal to the given value k. If there is no subarray with sum equal to k, return 0.
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {
        unordered_map<int, int> prefixSumMap;
        int maxLength = 0;
        int prefixSum = 0;

        for (int i = 0; i < arr.size(); ++i) {
            prefixSum += arr[i];

            if (prefixSum == k) {
                maxLength = i + 1;
            }

            if (prefixSumMap.find(prefixSum - k) != prefixSumMap.end()) {
                maxLength = max(maxLength, i - prefixSumMap[prefixSum - k]);
            }

            if (prefixSumMap.find(prefixSum) == prefixSumMap.end()) {
                prefixSumMap[prefixSum] = i;
            }
        }

        return maxLength;
    }
};

int main() {
    Solution solution;
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 9;
    cout << solution.longestSubarray(arr, k) << endl;
    return 0;
}
// output : 3
