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