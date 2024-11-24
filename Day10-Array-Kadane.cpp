// Given an integer array arr[]. You need to find the maximum sum of a subarray.
#include <bits/stdc++.h>
using namespace std;


    int maxSubarraySum(vector<int> &arr) {
        int maxSum = INT_MIN;
        int currSum = 0;

        for (int num : arr) {
            currSum += num;
            maxSum = max(maxSum, currSum);
            if (currSum < 0) {
                currSum = 0;
            }
        }

        return maxSum;
    
};

int main() {
    vector<int> vec = {-2, -3, 4, -1, -2, 1, 5, -3};
    
    int ans = maxSubarraySum(vec);
    cout << "The maximum subarray sum is: " << ans << endl;

    return 0;
}

// output= The maximum subarray sum is: 7
