/* Given an array prices[] of length n, representing the prices of the stocks on different days. The task is to find the maximum profit possible by buying and selling the stocks on different days when at most one transaction is allowed. Here one transaction means 1 buy + 1 Sell. If it is not possible to make a profit then return 0.
Note: Stock must be bought before being sold.*/
#include<iostream>
#include<vector>
using namespace std;
int stock(vector<int>& prices){
    int bestbuy=prices[0];
    int profit=0;
    for(int i=1;i<prices.size();i++){
          bestbuy=min(bestbuy,prices[i]);
      
                profit=max(profit,prices[i]-bestbuy);
            
      
        }
    return profit;
}
int main(){
    vector<int> prices={7, 10, 1, 3, 6, 9, 2};
   cout<< stock(prices);

}
// output = 8
