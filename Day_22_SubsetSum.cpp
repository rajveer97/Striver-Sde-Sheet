#include<algorithm>

void solve(int index, vector<int> &num, vector<int> &res,int sum) {
    if(index==num.size()) {
        res.push_back(sum);
        return;
    }
    
    //element is picked
    solve(index+1, num, res, sum + num[index]);
    
    //element is not picked
    solve(index+1, num, res, sum);
}

vector<int> subsetSum(vector<int> &num)
{
    vector<int> res;
    solve(0, num, res, 0); //(index, array, res, sum);
    sort(res.begin(), res.end());
    return res;
}
/*
Time Complexity: O(2^n)+O(2^n log(2^n)). 
Each index has two ways. 
You can either pick it up or not pick it. 
So for n index time complexity for O(2^n) and 
for sorting it will take (2^n log(2^n)).

Space Complexity: O(2^n) for storing subset sums, 
since 2^n subsets can be generated for an array of size n.
*/
