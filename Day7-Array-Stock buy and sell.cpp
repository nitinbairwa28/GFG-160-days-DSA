// The cost of stock on each day is given in an array price[]. Each day you may decide to either buy or sell the stock at price[i], you can even buy and sell the stock on the same day. Find the maximum profit that you can get.
#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    
    int n=prices.size();
        int profit=0;
        for(int i=1;i<n;i++){
            if(prices[i]>prices[i-1]){
                        int totalprofit=prices[i]-prices[i-1];
                profit=profit+totalprofit;
            }
        }

    return profit;
}

int main() {
    
    vector<int> prices = {100, 180, 260, 310, 40, 535, 695};
    cout << "Maximum Profit: " << maxProfit(prices) << endl;

    return 0;
}

// output= Maximum Profit: 865
