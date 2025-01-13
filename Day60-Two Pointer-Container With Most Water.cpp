// Given an array arr[] of non-negative integers, where each element arr[i] represents the height of the vertical lines, find the maximum amount of water that can be contained between any two lines, together with the x-axis.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    int maxWater(vector<int> &arr) {
        int r = arr.size() - 1;
        int l = 0;
        int maxlen = 0;

        while (l < r) {
            int wt = r - l;
            int ht = min(arr[l], arr[r]);
            int area = wt * ht;
            maxlen = max(maxlen, area);

            if (arr[l] < arr[r]) {
                l++;
            } else {
                r--;
            }
        }
        
        return maxlen;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << "Maximum water trapped: " << sol.maxWater(arr) << endl;
    return 0;
}
// output: Maximum water trapped: 49
