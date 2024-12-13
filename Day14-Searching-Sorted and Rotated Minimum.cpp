// A sorted array of distinct elements arr[] is rotated at some unknown point, the task is to find the minimum element in it. 
#include <iostream>
#include <vector>
using namespace std;

int findMin(const vector<int>& arr) {
    int low = 0, high = arr.size() - 1;

    if (arr[low] <= arr[high]) {
        return arr[low];
    }

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] > arr[mid + 1]) {
            return arr[mid + 1];
        }

        if (arr[mid - 1] > arr[mid]) {
            return arr[mid];
        }

        if (arr[mid] > arr[high]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

int main() {
    vector<int> arr = {5, 6, 1, 2, 3, 4};
    cout << "The minimum element is: " << findMin(arr) << endl;
    return 0;
}
// output= 1
