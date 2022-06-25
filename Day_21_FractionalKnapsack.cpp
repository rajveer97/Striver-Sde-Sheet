#include<iostream>
#include<algorithm>

// Comparison function to sort Item according to val/weight
// ratio
bool comparator(pair<int,int> a, pair<int, int> b) {
    double r1 = (double)a.second / (double)a.first;
    double r2 = (double)b.second / (double)b.first;
    
    return r1>r2;
}

double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // ITEMS contains {weight, value} pairs.
    
    //    sorting Item on basis of ratio
    sort(items.begin(), items.end(), comparator);
    
    int currWeight = 0;
    double finalValue = 0.0; // Result (value in Knapsack)
    
    // Looping through all Items
    for(int i=0; i<n; i++) {
        // If adding Item won't overflow, add it completely
        if(currWeight+items[i].first <= w) {
            currWeight += items[i].first;
            finalValue += items[i].second;
        }
        // If we can't add current Item, add fractional part
        // of it
        else {
            int remaining = w-currWeight;
            finalValue += (double)items[i].second/(double)items[i].first * (double)remaining;
            break;
        }
    }
    
    return finalValue; // Returning final value
}
/*
Time Complexity: O(nlogn)
Auxiliary Space: O(1)
*/
