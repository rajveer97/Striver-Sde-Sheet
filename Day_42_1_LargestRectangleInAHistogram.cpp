#include<bits/stdc++.h> 
/*
// Brute Force: O(n^2)(too slow TLE)
// we can compute area of every subarray and return the max of them all.
*/
int largestRectangle(vector < int > & heights) {
    // Write your code here.
    int n = heights.size();
    int max_area = 0;
    for(int i=0; i<n; i++)
    {
        int curr_area = 0;
        int min_height = INT_MAX;
        for(int j = i; j < n; j++)
        {
            min_height = min(min_height, heights[j]);
            curr_area = max(curr_area, min_height * (j - i + 1));
        }
        max_area = max(max_area, curr_area);
    }
    
    return max_area;
}



/*
Methode 2: Using left_smaller and right_smaller O(N)(2 pass)
we use two arrays left and right which store the next smaller element 
to the left and right respectively.
then for every index we calculate area as 
heights[i] * (right[i] - left[i] + 1)
*/
int largestRectangle(vector < int > & heights) {
    // Write your code here.
    int n = heights.size();
    int leftSmall[n], rightSmall[n];
    stack<int> st;
    
    // to get the leftSmall elements
    for(int i=0; i<n; i++)
    {
        while(!st.empty() && heights[st.top()] >= heights[i])
        {
            st.pop();
        }
        if(st.empty()) leftSmall[i] = 0; //minimum element
        else leftSmall[i] = st.top() + 1;
        st.push(i);
    }
    
    // clear the stack to be re-used
    while(!st.empty()) st.pop() ; 
    
    // to get the rightSmall elements
    for(int i=n-1; i>=0; i--)
    {
        while(!st.empty() && heights[st.top()] >= heights[i])
        {
            st.pop();
        }
        if(st.empty()) rightSmall[i] = n-1; //minimum element
        else rightSmall[i] = st.top()-1;
        st.push(i);
    }
    
    int maxArea = 0;
    for(int i = 0; i<n; i++)
    {
        maxArea = max(maxArea, heights[i]*(rightSmall[i] - leftSmall[i] + 1));
    }
    return maxArea;
}


/*
Methode 3: using only one stack O(N)(1 pass)
same as approach 3 but better space complexity (O(N) space)
*/
int largestRectangle(vector<int> & heights) {
    // Write your code here.
    int n = heights.size() , max_area = INT_MIN , i = 0 ; 
    stack<int> s ;
    while(i < n) {
        if(s.empty() || heights[s.top()] <= heights[i]) {
            s.push(i) ; 
            i++ ; 
        } else {
            int prev_top = s.top() ; 
            s.pop() ; 
            max_area = max(max_area , heights[prev_top] * (s.empty() ? i : i - s.top() - 1)) ;
        }
    }
    while(!s.empty()) {
        int prev_top = s.top() ; 
        s.pop() ; 
        max_area = max(max_area , heights[prev_top] * (s.empty() ? i : i - s.top() - 1)) ;
    }  
    return max_area ;
}


