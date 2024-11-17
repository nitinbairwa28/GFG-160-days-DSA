// You are given an array of integers arr[]. Your task is to reverse the given array.
#include<iostream>
#include<vector>
using namespace std;
void reverse(vector<int>& vec){
    int start=0;
    int end=vec.size()-1;
    for(int i=0;i<end;i++){
        swap(vec[start],vec[end]);
        start++;
        end--;
    }
}
int main(){
    vector<int> vec={1,2,3,4};
    reverse(vec);
    for(int i: vec){
        cout<<i<<" ";
    }
}
// Output= 4 3 2 1
