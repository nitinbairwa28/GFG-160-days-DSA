// You are given an array of integer arr[] where each number represents a vote to a candidate. Return the candidates that have votes greater than one-third of the total votes, If there's not a majority vote, return an empty array.
#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;


    vector<int> findMajority(vector<int>& arr) {
        int n = arr.size();
        vector<int> result;
        sort(arr.begin(), arr.end());

        int count = 1;
        for (int i = 1; i < n; i++) {
            if (arr[i] == arr[i - 1]) {
                count++;
            } else {
                if (count > n / 3) {
                    result.push_back(arr[i - 1]);
                }
                count = 1;
            }
        }

        if (count > n / 3) {
            result.push_back(arr[n - 1]);
        }

        return result;
    }
;

int main() {
    
    vector<int> arr = {2 ,1 ,5 ,5 ,5 ,5 ,6 ,6 ,6 ,6 ,6};
    vector<int> result = findMajority(arr);
    
    for (int num : result) {
        cout << num << " ";
    }
    return 0;
}
// Output= 5 6
