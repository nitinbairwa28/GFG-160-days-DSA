// Given an array, arr[] construct a product array, res[] where each element in res[i] is the product of all elements in arr[] except arr[i]. Return this resultant array, res[].
#include <iostream>
#include <vector>
using namespace std;

vector<int> productArray(const vector<int>& arr) {
    int n = arr.size();
    vector<int> prefix(n, 1), suffix(n, 1), res(n);

    for (int i = 1; i < n; ++i) 
        prefix[i] = prefix[i - 1] * arr[i - 1];
    for (int i = n - 2; i >= 0; --i) 
        suffix[i] = suffix[i + 1] * arr[i + 1];
    for (int i = 0; i < n; ++i) 
        res[i] = prefix[i] * suffix[i];

    return res;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> result = productArray(arr);

    for (int x : result) 
        cout << x << " ";

    return 0;
}
// output : 120 60 40 30 24
