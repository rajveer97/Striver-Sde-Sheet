// Method 1: Brut Force (TLE)
bool findPattern(string p, string s)
{
    // Write your code here.
    bool flag = false;
    int j = 0;
    for(int i=0; i<s.length(); i++)
    {
        int k = i;
        while(s[k]==p[j] && j<p.length() && k<s.length())
        {
            k++;
            j++;
            
        }
        if(j==p.length())
        {
            flag = true;
            break;
        }
        j = 0;
        
    }
    return flag;
}


//-----------------------------------------------------

// Method 2: Use In-built find function 
bool findPattern(string p, string s)
{
    // Write your code here.
    if(s.length()!=0 && s.find(p)<=s.length())
        return true;
    else
        false;
}

//-----------------------------------------------------

// Method 3: KMP Algorithm
// TC : O(N+M)
bool findPattern(string p, string s)
{
    // Write your code here.
    
    // create lps vector
    vector<int> lps(p.size(), 0); // longest prefix suffix
    for(int i=1; i<p.size(); i++)
    {
        int j = lps[i-1];
        while(j>0 && p[i] != p[j])
        {
            j = lps[j-1];
        }
        
        if(p[i]==p[j]) 
            j++;
        
        lps[i] = j;
    }
    
    int n = s.size();
    int m = p.size();
    int i = 0;
    int j = 0;
    bool flag = false;
    while(i<n)
    {
        if(p[j]==s[i])
        {
            i++;
            j++;
        }
        
        if(j==m)
        {
            flag = true;
            break;
        }
        else if(p[j] != s[i])
        {
            if(j==0) i++;
            j = lps[j-1];
        }
    }
    
    return flag;
}
