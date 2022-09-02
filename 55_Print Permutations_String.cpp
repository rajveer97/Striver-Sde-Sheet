/*
Algorithm Paradigm: Backtracking 
*/

void findpermutations(int index, string&s, vector<string>&ans)
{
    // Base case
    if(index==s.size())
    {
        ans.push_back(s);
        return;
    }
    //Permutation made
    for(int i=index;i<s.size();i++)
    {
        swap(s[index],s[i]);      // Swapping done 
        findpermutations(index+1,s,ans);  // Recursion called 
        swap(s[index],s[i]); // Backtracking
    }
}

vector<string> findPermutations(string &s) {
    // Write your code here.
    vector<string>ans;
    int index=0;
    findpermutations(index,s,ans);
    return ans;
}
/*
Time Complexity: O(n*n!) Note that there are n! permutations and it requires O(n) time to 
store a permutation.

Auxiliary Space: O(r – l)
*/
