int compareVersions(string a, string b) 
{
    // Write your code here
    int a_size = a.length(), b_size = b.length();
    int i=0, j=0;
    while(i<a_size || j<b_size)
    {
        long long n1 = 0, n2 = 0;
        while(i < a_size && a[i] != '.')
        {
            n1 = n1 * 10 + (long long)(a[i] - '0');
            i++;
        }
        
        while(j < b_size && b[j] != '.')
        {
            n2 = n2 * 10 + (long long)(b[j] - '0');
            j++;
        }
        
        if(n1 < n2)
            return -1;
        else if(n1 > n2)
            return 1;
        
        i++;
        j++;        
    }
    return 0;
}

// TC : O(max(m,n))