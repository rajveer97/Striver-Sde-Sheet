int findMinimumCoins(int amount) 
{
    int currency[] = {1000, 500, 100, 50, 20, 10, 5, 2, 1};
    int n = sizeof(currency)/sizeof(int);
    int i = 0, minCoins = 0;
    
    while(amount > 0) {
        // amount is less than the ith currency then just increase the i
        if(amount < currency[i]) i++; 
        else if(amount >= currency[i]) {
            amount = amount - currency[i];
            minCoins++;
        }
    }
    return minCoins;
}
