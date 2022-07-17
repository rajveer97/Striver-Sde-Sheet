// atoi() -> string to int
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