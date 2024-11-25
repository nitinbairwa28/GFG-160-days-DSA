// Given an array arr[] that contains positive and negative integers (may contain 0 as well). Find the maximum product that we can get in a subarray of arr.
#include<iostream>
#include<vector>
using namespace std;
int subarr(vector<int> &arr){
    int n=arr.size();
    int pre=1;
    int suff=1;
    int maxproduct=INT16_MIN;
    for(int i=0;i<n;i++){
        if(pre==0) pre=1;
        if(suff==0) suff=1;
    
           pre=pre*arr[i];
           suff=suff*arr[n-i-1];
           maxproduct=max(maxproduct,max(pre,suff));
    }
    return maxproduct;
}
int main(){
     vector<int> arr={-2,3,4,-1,0,-2,3,1,4,-2};
     cout<<subarr(arr);
}
// output= 48 ( 1 as initialize,cancel by -2,again by 3,4,-1,0, then when 0 occur it will turn 1 and next forward values are taken in and multiply with it)
  
