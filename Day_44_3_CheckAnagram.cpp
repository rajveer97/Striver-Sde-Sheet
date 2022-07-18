//Method 1: Brut force
bool areAnagram(string &str1, string &str2){
    // Write your code here.
    if(str1.size() != str2.size())
        return false;
    
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    
    return str1==str2;
}
// TC : O(N*logN)
// sc : O(1)


//------------------------------------------------

#include<unordered_map>
// Method 2: use hash-map
bool areAnagram(string &str1, string &str2){
    // Write your code here.
    int n = str1.size();
    int m = str2.size(); 
    if(n != m) return false;
    
    unordered_map<char, int> mp;
    for(auto it : str1)
    {
        mp[it]++;
    }
    
    for(auto it : str2)
    {
        mp[it]--;
    }
    
    for(auto x : mp)
    {
        if(x.second != 0)
            return false;
    }
    
    return true;
}

// TC : O(N)
// SC : O(N)



