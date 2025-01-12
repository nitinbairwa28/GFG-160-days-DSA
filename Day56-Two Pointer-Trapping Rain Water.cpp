//Given an array arr[] with non-negative integers representing the height of blocks. If the width of each block is 1, compute how much water can be trapped between the blocks during the rainy season. 
/* 

int trapwater(vector<int> &arr){
    int n=arr.size();
    vector<int> prefixmax(n),suffixmax(n);
     prefixmax[0]= arr[0];
     suffixmax[n-1]=arr[n-1];

    int total=0;
    
    for(int i=1;i<n;i++){
       prefixmax[i] = max(prefixmax[i-1],arr[i]);
    }
    for(int i=n-1;i>=0;i--){
        suffixmax[i]= max(suffixmax[i+1],arr[i]);
    }
    for(int i=0;i<n;i++){
        total+=min(prefixmax[i],suffixmax[i]) -arr[i];
    }
    return total;
} 
//it's time complexity is O(n)
*/


// here is it's optimal code

#include<iostream>
#include<vector>
using namespace std;
int trapwater(vector<int> &arr){
    int lmax=0,rmax=0,total=0;
    int l=0,r=arr.size()-1;
    while(l<=r){
        if(arr[l]<=arr[r]){
           if(lmax>arr[l] ){
           total+= lmax-arr[l];}
         
        else{
            lmax=arr[l];
          
        }  l++;
        }
        else{
            if(rmax>arr[r]){
                total+= rmax-arr[r];
            } else{
                rmax=arr[r];
              
            } 
              r=r-1;
        }

    }
    return total;
}
int main(){
    vector<int> arr={3, 0, 1, 0, 4, 0 ,2};
    int result=trapwater(arr);
    cout<<"the contained water is:"<<result<<endl;
}  

// Output : the contained water is:10

