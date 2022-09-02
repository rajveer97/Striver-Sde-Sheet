void sortedInsert(stack<int> &stack, int num)
{
    // base case => stack empty/chota element mil jayega
    if(stack.empty() || (!stack.empty() && stack.top() < num))
    {
        // seg fault de skta hai 2nd condn
        // seedhe push kr do
        stack.push(num);
        return;
    }
    
    //aage bado to no. ko side me rakh rahe
    int n = stack.top();
    stack.pop(); //side me
    
    // recursive call
    sortedInsert(stack, num);
    
    //wapas jate hue n ko lete jao jo side me rakha tha
    stack.push(n);    
}

void sortStack(stack<int> &stack)
{
    // base case
    if(stack.empty())
        return;
    
    // aage jao to upar wala side me rakho
    int num = stack.top();
    stack.pop(); // side me
    
    // recursive call
    sortStack(stack);
    
    //wapas aao jab do sortedInsert
    sortedInsert(stack, num);   
}
/*
Time Complexity: O(n^2). 
In the worst case for every sortstack(), sortedinsert() 
is called for ‘N’ times recursively for putting the element 
in the right place
Auxiliary Space: O(N)
Use of stack data structure for storing values
*/
