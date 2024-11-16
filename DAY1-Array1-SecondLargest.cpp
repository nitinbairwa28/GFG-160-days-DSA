// Given an array of positive integers arr[], return the second largest element from the array. If the second largest element doesn't exist then return -1.
#include <iostream>
#include <vector>
using namespace std;

int secondLargest( vector<int>& arr) {
   

    int largest = arr[0];
    int slargest = -1; 

    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > largest) {
            slargest = largest;
            largest = arr[i];
        } else if (arr[i] > slargest && arr[i] < largest) {
            slargest = arr[i];
        }
    }

   

    return slargest;
}

int main() {
    vector<int> vec = {1, 2, 4, 7, 70, 54,80};
    int result = secondLargest(vec);
    
        cout << "The second largest is: " << result << endl;
    
    return 0;
}

// output= 5
