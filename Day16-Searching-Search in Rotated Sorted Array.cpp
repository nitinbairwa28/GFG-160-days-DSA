// Given a sorted and rotated array arr[] of distinct elements, the task is to find the index of a target key. Return -1 if the key is not found.
#include <iostream>
#include <vector>
using namespace std;

int searchInRotatedArray(const vector<int>& arr, int key) {
    int left = 0, right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key) {
            return mid;
        }

        if (arr[left] <= arr[mid]) {
            if (arr[left] <= key && key < arr[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } else {
            if (arr[mid] < key && key <= arr[right]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }

    return -1;
}

int main() {
    vector<int> arr = {5, 6, 7, 8, 9, 10, 1, 2, 3};
    int key = 3;

    int result = searchInRotatedArray(arr, key);
    if (result != -1) {
        cout << "Key found at index: " << result << endl;
    } else {
        cout << "Key not found" << endl;
    }

    return 0;
}
// output= Key found at index: 8
