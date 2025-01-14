// Given an array of integers arr[], the task is to find the first equilibrium point in the array.

//The equilibrium point in an array is an index (0-based indexing) such that the sum of all elements before that index is the same as the sum of elements after it. Return -1 if no such point exists. 
#include <iostream>
#include <vector>
using namespace std;

int findEquilibriumPoint(const vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return -1;

    vector<int> prefixSum(n, 0);
    prefixSum[0] = arr[0];

    for (int i = 1; i < n; ++i) {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }

    for (int i = 0; i < n; ++i) {
        int leftSum = (i == 0) ? 0 : prefixSum[i - 1];
        int rightSum = prefixSum[n - 1] - prefixSum[i];

        if (leftSum == rightSum) {
            return i;
        }
    }

    return -1;
}

int main() {
    vector<int> arr = {1, 3, 5, 2, 2};
    int equilibriumPoint = findEquilibriumPoint(arr);

    cout << "Equilibrium Point: " << equilibriumPoint << endl;
    return 0;
}
// output : Equilibrium Point: 2
