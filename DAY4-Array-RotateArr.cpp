// Given an unsorted array arr[]. Rotate the array to the left (counter-clockwise direction) by d steps, where d is a positive integer. Do the mentioned change in the array in place.
#include <iostream>
#include <vector>
using namespace std;


void reverse(vector<int>& arr, int start, int end) {
    while (start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}


void rotateLeft(vector<int>& arr, int d) {
    int n = arr.size();
    if (n == 0 || d == 0) return;

    d = d % n; 
    if (d == 0) return; 

    reverse(arr, 0, d - 1);      
    reverse(arr, d, n - 1);      
    reverse(arr, 0, n - 1);      
}


int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    int d = 2;

    rotateLeft(arr, d);

    
    for (int num : arr) {
        cout << num << " ";
    }

    return 0;
}
// Output= 3,4,5,6,7,1,2
