// Given an array of integers arr[] representing a permutation, implement the next permutation that rearranges the numbers into the lexicographically next greater permutation. If no such permutation exists, rearrange the numbers into the lowest possible order (i.e., sorted in ascending order). 
#include <iostream>
#include <vector>

using namespace std;

void reverse(vector<int>& arr, int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void nextPermutation(vector<int>& arr) {
    int n = arr.size();
    int i = n - 2;
    while (i >= 0 && arr[i] >= arr[i + 1]) {
        i--;
    }
    if (i >= 0) {
        int j = n - 1;
        while (arr[j] <= arr[i]) {
            j--;
        }
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    reverse(arr, i + 1, n - 1);
}

int main() {
    vector<int> arr = {2, 4, 1, 7, 5, 0};
    nextPermutation(arr);
    for (int num : arr) {
        cout << num << " ";
    }
    return 0;
}
// output= 2,4,5,0,1,7
