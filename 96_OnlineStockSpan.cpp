#include<stack>
#include<vector>
// Method 1: TLE
// use two loop
vector<int> findSpans(vector<int> &arr) {
    // Write your code here.
    int n = arr.size();
    vector<int> ans(n);
    
    for(int i=0; i<n; i++)
    {
        int j = i;
        while(j>=0 && arr[j] <= arr[i])
        {
            ans[i] = ans[i] + 1;
            j--;
        }
    }
    
    return ans;
}



// Method 2: Use stack
// variant of prev greater element
// TC & SC - O(n)
vector<int> findSpans(vector<int> &price) {
    // Write your code here.
    vector<int> ans;
    stack<int> st;
    ans.push_back(1);  // 1st index
    st.push(0);
    
    for(int i=1; i<price.size(); i++)
    {
        while(!st.empty() && price[st.top()] <= price[i])
            st.pop();
        
        if(st.empty())
            ans.push_back(i+1);
        else
            ans.push_back(i - st.top());
        
        st.push(i);
    }
    
    return ans;
}