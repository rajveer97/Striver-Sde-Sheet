/*
Mathod 1 : Using bitwise operation
For a given set[] S, the power set can be found by generating 
all binary numbers between 0 and 2^n-1, where n is the size of the set. 

For example, for the set S {x, y, z}, generate all binary 
numbers from 0 to 2^3-1 and for each generated number, 
the corresponding set can be found by considering 
set bits in the number.
*/
vector<vector<int>> pwset(vector<int>v)
{
    //Write your code here
    vector<vector<int>> ans;
    int set_size = v.size();
    
    // Set_size of power set of a set with set_size
    // n is (2^n-1)
    int pow_set_size = pow(2, set_size); // or  (1 << set_size)
    
    // Run from counter 000..0 to 111..1
    for(int counter=0; counter < pow_set_size; counter++)
    {
        vector<int> subset;
        for(int j=0; j<set_size; j++) {
            // Check if jth bit in the counter is set
            // If set then print jth element from set
            if(counter & (1<<j))
            {
                subset.push_back(v[j]);
            }
        }
        ans.push_back(subset);        
    }
    
    return ans;
}
/*
Time Complexity: O(n2n)
Auxiliary Space: O(1)
--------------------------------------------------------------
*/


/*
Mehtod 2: 
We can use backtrack here, we have two choices first 
consider that element then don’t consider that element.

void helper(vector<int>& v, int i, vector<int>& subset,vector<vector<int>>& ans)
{
    if(i==v.size())
    {
        ans.push_back(subset);
        return;
    }
    
    subset.push_back(v[i]);
    helper(v, i+1, subset, ans);
    
    subset.pop_back();      // backtracking
    helper(v, i+1, subset, ans);
}

vector<vector<int>> pwset(vector<int>v)
{
    //Write your code here
    vector<vector<int>> ans;
    vector<int> subset;
    helper(v, 0, subset, ans);
    return ans;
}
/*
Time Complexity: O(n2^n)
Space Complexity: O(n)
*/
