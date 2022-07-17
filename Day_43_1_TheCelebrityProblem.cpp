#include<stack>
/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/


// Method 1:
// TC : O(N)
int findCelebrity(int n) {
    // Write your code here.
    int  celebrity = 0;
    for(int i=1; i<n; i++)
    {
        if(knows(celebrity, i)==1)
            celebrity = i;
    }
    
    // if they don't know each other
    for(int i=0; i<n; i++)
    {
        if(i!=celebrity && (knows(celebrity, i)==1 || knows(i, celebrity)==0))
            return -1;
    }
     
    return celebrity;
}



// Method 2:
/* LOGIC:
   if n=3, and suppose matrix is like
            guy1 guy2  guy3
   guy 1:     0    1    0
   guy 2:     0    0    0    
   guy 3:     0    1    0
   so for a person to be celebrity it's all row elements should be 0;
   and
   total 1 in its col should have n-1 number of 1s
   In this case, guy 2 is the celebrity
*/
int findCelebrity(int n) {
    // Write your code here.
    stack<int> s;
    
    for(int i=0; i<n; i++)
        s.push(i);
    
    while(s.size() > 1)
    {
        int a = s.top();
        s.pop();
        
        int b = s.top();
        s.pop();
        
        if(knows(a, b))
            s.push(b);
        else
            s.push(a);       
    }
    
    int ans = s.top(); // possible candidate
    // checking for 0, if we found 1 in the row then it is not celebrity
    for(int i=0; i<n; i++)
    {
        if(knows(ans, i))
            return -1;
    }
    
    // checking for number of 1
    int count = 0;
    for(int i=0; i<n; i++)
    {
        if(knows(i, ans))
            count++;
    }
    
    //if count(number of 1 in column) = number of candidates - 1
    //then that candidate is out celebrity.
    //else, there is no celebrity among these people
    if(count == n-1)
        return ans;
    
    return -1;
}
