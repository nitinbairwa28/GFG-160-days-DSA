// Given an array arr[]. Push all the zeros of the given array to the right end of the array while maintaining the order of non-zero elements.
#include<iostream>
#include<vector>
using namespace std;
void pushzerotoend(vector<int> &arr){
  int n=arr.size();

 // step-1:
 int j=-1;
 for(int i=0;i<n;i++){
  if(arr[i]==0){
    j=i;
    break;
  }
 } 
 //step-2:
 if(j==-1) return;
for(int i=j+1;i<n;i++){
  if(arr[i]!=0){
        swap(arr[i],arr[j]);
        j++;
  }

}

}
int main(){
  vector<int> arr={0,0,10,20,30};
   pushzerotoend(arr);
  for(int value: arr){
    cout<<value<<" ";
  }
}
// otuput = 10,20,30,0,0
