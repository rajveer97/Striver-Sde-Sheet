// atoi() -> string to int

// Leetcode
class Solution {
public:
    int myAtoi(string str) 
    {
        if (str.empty()) return 0;
        int i = 0, sign = 1;

        while (i + 1 < str.size() && isspace(str[i])) 
            ++i;            // ignore leading white space

        long res = 0;
        if (str[i] == '-' || str[i] == '+')    // check if number +ve or -ve
            sign = (str[i++]=='-') ? -1 : 1;

        
        while (i < str.size()) 
        {
            if (isdigit(str[i])) res = 10 * res + str[i++] - '0';
            else return res * sign;

            if (res > INT_MAX) return sign == -1 ? INT_MIN : INT_MAX;
        }
        return res * sign;
    }
};


//--------------------------------------------------------------------------------------

int atoi(string str) {
    // Write your code here.
    int result = 0;
    
    for(int i=0; i<str.size(); i++)
    {
        if(str[i] >= '0' && str[i] <= '9')
            result = result*10 + (str[i] - '0');
    }
    
    return str[0]=='-' ? -result : result;
}
