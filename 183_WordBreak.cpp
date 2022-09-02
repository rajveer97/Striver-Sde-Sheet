// Method 1: Bottom Up DP Approach
#include<vector>
#include<algorithm>
bool wordBreak(vector < string > & wordDict, int n, string & s) {
    // Write your code here.
    if(wordDict.size()==0)
    {
        return false;
    }
    vector<bool>dp(s.size()+1,false);
    dp[0] = true;
    for(int i=1;i<=s.size();i++)
    {
        for(int j=i-1;j>=0;j--)
        {
            if(dp[j])    //usse pehle ki string exist krti h dict mein
            {
                string word = s.substr(j,i-j);
                auto it = find(wordDict.begin(),wordDict.end(),word);
                if(it!=wordDict.end())
                {
                    dp[i] = true;
                    break;
                }
            }
        }
    }
    return dp[s.size()];
}