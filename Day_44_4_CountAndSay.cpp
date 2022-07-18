#include<string>
string writeAsYouSpeak(int n) 
{
    // Write your code here.
    if(n==1) return "1";
    if(n==2) return "11";
    string str = "11";  // Initialize previous term 
    for(int i=3; i<=n; i++)
    {
        str = str + '$';
        int len = str.length();        
        int cnt = 1;   // Initialize count of matching chars
        string temp = "";  // Initialize i'th term in series
        
        for(int j=1; j<len; j++)
        {
            if(str[j] != str[j-1])
            {
                // storing int to string variable
                temp += to_string(cnt);  //temp += cnt + '0';   
                temp += str[j-1];
                cnt = 1;
            }
            else 
                cnt++;
        }
        
        str = temp;
    }   
    return str;
}
// TC : O(N)
