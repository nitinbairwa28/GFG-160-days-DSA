// Given an array of positive integers arr[], return the second largest element from the array. If the second largest element doesn't exist then return -1.
#include<iostream>
#include<vector>
using namespace std;
int secondlargest(vector<int>&arr,int n){
    int largest=arr[0];
    int slargest=-1;
    for(int i=0;i<n;i++){
        if(arr[i]>largest){
            slargest=largest;
            largest=arr[i];
        }
        else if(arr[i]<largest && arr[i]>slargest){
            slargest=arr[i];
        }
    }
    return slargest;
}
int main(){
 vector<int> vec={1,2,4,7,7,5};
 int n=vec.size();
 int result= secondlargest(vec,n);
 cout<<"the second largest is:"<<result;

}
// output= 5
