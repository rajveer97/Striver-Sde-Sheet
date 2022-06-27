/*
Approach: The initial idea will be to make partitions to generate substring 
and check if the substring generated out of the partition will be a palindrome.
Partitioning means we would end up generating every substring and checking for 
palindrome at every step. Since this is a repetitive task being done again and
again, at this point we should think of recursion. The recursion continues until 
the entire string is exhausted. After partitioning, every palindromic substring 
is inserted in a data structure When the base case has reached the list of 
palindromes generated during that recursion call is inserted in a vector of
vectors/list of list.
*/

#include<bits/stdc++.h>
bool isPalindrome(string s, int start, int end)
{
    while(start <= end) {
        if(s[start++] != s[end--])
            return false;
    }
    return true;
}

void findpaths(int index, string &s, vector<vector<string>>&ans, vector<string>&path)
{
    if(index==s.size()) 
    {
        ans.push_back(path);
        return;
    }
    
    for(int i=index; i<s.size(); i++) {
        if(isPalindrome(s, index, i)== true)
        {
            path.push_back(s.substr(index, i-index+1));
            findpaths(i+1, s, ans, path);
            path.pop_back(); // backtracking
        }
    }
}

vector<vector<string>> partition(string &s) 
{
    // Write your code here.
    vector<vector<string>> res;
    vector<string> path;
    findpaths(0, s, res, path);
    
    return res;
}
/*
Time Complexity: O( (2^n) *k*(n/2) )
Reason: O(2^n) to generate every substring and O(n/2)  to check if the substring
generated is a palindrome. O(k) is for inserting the palindromes in another data
structure, where k  is the average length of the palindrome list.

Space Complexity: O(k * x)
Reason: The space complexity can vary depending upon the length of the answer. 
k is the average length of the list of palindromes and if we have x such list 
of palindromes in our final answer. The depth of the recursion tree is n, so 
the auxiliary space required is equal to the O(n).
*/
