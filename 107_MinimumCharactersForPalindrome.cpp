/*
Naive Solution:
s = “ababad” 

Now for this the solution would be 1. how????

we can add ‘d’ to the front and the string s would become 
“dababad” which is a palindrome.

→ How to write a code for this???

1. Check if the string is palindrome or not. If palindrome return 0.
2. If the string isn't a palindrome. Delete the last element and 
check if s becomes palindrome. We are deleting the last element 
because of two reasons
> We can add characters only to the front.
> We delete the last element to check if it is the hurdle that 
is preventing the string to become palindrome so that we can add 
the same character in the front to make it a palindrome.
3. Keep on deleting the last character until s becomes empty 
or palindrome.
4. Return the number of deleted characters.

Space complexity  = O(1) 
Time Complexity = O(n^2)  → checking for palindrome for each 
character we delete. This could be n in the worst case (ex - “abcde”).

Looking at the time constraint (n <= 10^5) only O(nlogn) or O(n) time complexity would be acceptable.

Optimal Solution: (Using KMP algorithm)

The intuition behind using KMP. 
s = “ababad”

Lets make a new string → ns = s + $ + reverse(s)
Here $ chan be any character that is not present in s.

ns = ababad$dababa

lps = [0 0 1 2 3 0 0 0 1 2 3 4 5]

solution = s.length() - lps.back() = 6 - 5 = 1

Why does this solution work???

lps[i] → length of suffix from index ‘i’ that is also a prefix.

1. As we see in the previous approach we were trying to maximize 
the number of characters from the front (deleting the minimum 
element from the back) so that the remaining string is a palindrome.
2. Now the longest suffix from the last element in ns which is also 
a prefix of ns will give us the maximum elements that can be kept in 
the string s so that it is a palindrome.
 
see this → lps.back() = 5 so suffix = “ababa” (remember last n 
elements are reversed) prefix of length 5:  prefix = “ababa”. 
As you can see it's a palindrome.
*/
#include<vector>
#include<string>
#include<algorithm>
vector<int> generateLPS(string ns)
{
    int n = ns.size();
    vector<int> lps(n, 0);
     for(int i=1; i<n; i++)
     {
         int len = lps[i-1];
         
         while(len>0 && ns[i]!=ns[len])
             len = lps[len-1];
         
         if(ns[i] == ns[len])
             len++;
         
         lps[i] = len;
     }
    
    return lps;
}

int minCharsforPalindrome(string str) {
    // Write your code here.
    string rev = str;
    reverse(rev.begin(), rev.end());
    
    string ns = str + '#' + rev;
    
    auto lps = generateLPS(ns);
    
    return str.size() - lps.back();    
}
