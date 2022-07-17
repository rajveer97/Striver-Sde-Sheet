#include<vector>


// Method 1: TLE
// Travese the string from beginning
string reverseString(string str)
{
    // Write your code here.
    int n = str.length();
    string result;
    int i = 0;
    
    while(i < n)
    {
        while(i<n && str[i] == ' ')
            i++;
        
        if(i >= n)
            break;
        
        int j = i + 1;
        
        while(j<n && str[j] != ' ')
            j++;
        
        string sub = str.substr(i, j-i);
        
        if(result.length() == 0)
            result = sub;
        else 
            result = sub + " " + result;
        
        i = j+1;
    }
    return result;
}



// Methode 2: Traverse the string from end
// TC & SC : O(N)
string reverseString(string str)
{
    // Write your code here.
    int n = str.length();
    string ans = "";
    
    for(int i=n-1; i>=0; i--)
    {
        if(str[i] == ' ') 
            continue;
        
        int j = i;
        while(str[j] != ' ' && j >= 0)
        {
            j--;
        }
        
        ans += str.substr(j+1, i-j);
        ans += ' ';
        i = j;
    }   
    return ans;
}


// Method 3: 
string reverseString(string str)
{
    // Write your code here.
    vector<string> v;
    int start = 0, count = 0;
    for(int i=0; i<str.length(); i++)
    {
        start = i;
        if(str[i] != ' ')
        {
            count = 0;
            while(str[i] != ' ')
            {
                count++;
                i++;
            }
            v.push_back(str.substr(start, count));
        }
    }
    
    string result;
    for(int i=v.size() - 1; i >= 0; i--)
    {
        result.append(v[i]);
        result.append(" ");
    }
    return result;
}
