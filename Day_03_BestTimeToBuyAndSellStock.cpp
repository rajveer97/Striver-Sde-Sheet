#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    int buy = prices[0], maxProfit = 0;
    for(int i=1; i<prices.size(); i++) {
        // Checking for lower buy value
        if(buy > prices[i]) {
            buy = prices[i];
        }
        // Checking for higher Profit
        else if(prices[i]-buy > maxProfit) {
            maxProfit = prices[i]-buy;
        }
    }
    return maxProfit;
}