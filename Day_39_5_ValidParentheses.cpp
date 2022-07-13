#include<bits/stdc++.h>
bool isValid(char a, char b)
{
    return (a == '(' && b == ')' || 
            a == '{' && b == '}' ||
            a == '[' && b == ']');
}

bool isValidParenthesis(string expression)
{
    // Write your code here.
    stack<char> st;
    
    for(int i=0; i<expression.length(); i<i++)
    {
        // if opening bracket is found then push it to the stack
        if(expression[i] == '(' || expression[i] == '{' || expression[i] == '[')
        {
            st.push(expression[i]);
        }
        
        // closing bracket is found i.e ), }, ] 
        else 
        {
            // stack is empty then return false
            if(st.empty()) 
                return false;
            
            // Invalid bracket return false
            if(isValid(st.top(), expression[i]) == false) return false;
            
            // if bracket is valid then remove the top bracket from stack
            else st.pop();        
        }
    }
    
    // is all the opening and closing brackets are valid then 
    // the stack should be empty
    return (st.empty());
}
/*
Time Complexity: O(n) 
Auxiliary Space: O(n) for stack. 
*/
