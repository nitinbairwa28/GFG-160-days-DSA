// Given an array of integers arr[] in a circular fashion. Find the maximum subarray sum that we can get if we assume the array to be circular
#include<iostream>
#include<vector>

using namespace std;
int circularSubarraySum(vector<int>&arr){
      
       int maxsum = INT16_MIN, sum = 0;
        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            maxsum = max(maxsum, sum);
            if (sum < 0) {
                sum = 0;
            }
        }

        int totalsum = 0, minsum = INT16_MAX;
        sum = 0;

        for (int i = 0; i < arr.size(); i++) {
            totalsum += arr[i];
            sum += arr[i];
            minsum = min(minsum, sum);
            if (sum > 0) {
                sum = 0;
            }
        }

        int circularMax = totalsum - minsum;
        if (totalsum == minsum) {
            return maxsum;
        }

        return max(maxsum, circularMax);
        
    }

int main(){
     vector<int> arr={-1, 40, -14, 7, 6, 5, -4, -1};
    int ans=circularSubarraySum(arr);
     cout<<"the answer is:"<<ans;

}
// output= the answer is:52
