// Method 1:
void expand(string s, int l,int r, string &ans, int & ansLen) {
    while(l>=0 && r<s.length() && s[l]==s[r]) {
        if(r-l+1 > ansLen) {
            ansLen = r - l + 1;
            ans = s.substr(l, ansLen);
        }
        l--; r++;
    }
} 
string longestPalinSubstring(string str)
{
    // Write your code here.
    string ans="";
    int ansLen=0;
    int n=str.length();
    for(int i=0;i<n;i++) {
        // for odd length
        expand(str,i,i,ans,ansLen);
        // for even length
        expand(str,i,i+1,ans,ansLen);
    }
    return ans;
}



// Method 2:
void expandBothSides(string &str, int left, int right, 
                     int &start_idx, int &max_len, const int n)
{
    // expand the palindrome on both sides if there is a match
    while(left>=0 && right<n && str[left]==str[right])
    {
        // keep the max len palindromic substring
        if(right - left + 1 > max_len)
        {
            start_idx = left;
            max_len = right - left + 1;
        }
        
        // expand the window
        left--;
        right++;
    }
}

string longestPalinSubstring(string str)
{
    // Write your code here.
    const int n = (int)str.size();
    int start_idx = 0; // starting index where the substring starts
    int max_len = 1; // single char is considered to be a substring
    int left, right; // 2 pointers
    
    for(int i=1; i<n; i++)
    {
        // consecutive pointers _ _
        left = i-1;
        right = i;       
        expandBothSides(str, left, right, start_idx, max_len, n);
        
        // pointers with 1 gap in between _x_
        left = i-1;
        right = i+1;
        expandBothSides(str, left, right, start_idx, max_len, n);
    }
    return str.substr(start_idx, max_len);
}
