#include<algorithm>
// Method 1: TC→ O(m*n) SC → O(m)
string longestCommonPrefix(vector<string> &arr, int n)
{
    // Write your code here
    string result = "";
    
    for(int i=0; i<arr[0].length(); i++)
    {
        char ch = arr[0][i];
        
        bool flag = true;
        for(int j = 1; j<n; j++)
        {
            if(arr[j].size() < i || ch!=arr[j][i])
            {
                flag = false;
                break;
            }
        }
        if(flag == false)
            break;
        else
            result.push_back(ch);
    }
    
    return result;
}



// Method 2: 
// TC : O(NlogN)
string longestCommonPrefix(vector<string> &arr, int n)
{
    // Write your code here
    if(n==0) return "";
    string result = "";
    
    sort(begin(arr), end(arr));
    
    string a = arr[0];
    string b = arr[n-1];
    
    for(int i=0; i<a.size(); i++)
    {
        if(a[i] == b[i])
            result = result + a[i];
        else
            break;
    }
    
    return result;
}



