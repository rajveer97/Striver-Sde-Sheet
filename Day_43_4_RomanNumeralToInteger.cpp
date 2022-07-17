#include<unordered_map>
int romanToInt(string s) {
    // Write your code here
    unordered_map<char, int> m = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
        {'C', 100}, {'D', 500}, {'M', 1000}
    };
    
    int result = 0, n = s.size();
    
    for(int i = 0; i < n; i++) {
        int curr = m[s[i]];
        
        // next will be 0 if we reach the end of the string
        int next = m[s[i + 1]];
        if(curr >= next)
            result += curr;
        else
            result -= curr;
    }
    
    return result;   
}
