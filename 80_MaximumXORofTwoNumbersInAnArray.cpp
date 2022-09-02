#include<bits/stdc++.h>
/*
Naive Approach: (TLE)
A Simple Solution is to generate all pairs of the given 
array and compute the XOR of the pairs. Finally, return the maximum XOR value. 
This solution takes O(N^{2}) time.

int maximumXor(vector<int> A)
{
    // Write your code here.   
    int maxXor = 0;
    
    for(int i=0; i<A.size(); i++)
    {
        for(int j=i+1; j<A.size(); j++)
        {
            maxXor = max(maxXor, A[i]^A[j]);
        }
    }
    return maxXor;
}
/*
Time Complexity: O(N^{2}) , where N is the size of the array
Auxiliary Space: O(1)
-----------------------------------------------------------
*/

/*
Efficient Approach: 
1. The idea is to change the problem statement from finding the 
maximum xor of two numbers in an array to -> find two numbers in 
an array, such that xor of which equals to a number X. In this case, 
X will be the maximum number we want to achieve till i-th bit.
2. To find the largest value of an XOR operation, the value of xor 
should have every bit to be a set bit i.e 1. In a 32-bit number, 
the goal is to get the most 1 set starting left to right.
3. To evaluate each bit, there is a mask needed for that bit. 
A mask defines which bit should be present in the answer and 
which bit is not. Here we will use a mask to keep the prefix 
for every number ( means by taking the ans with the mask how 
many bits are remaining from the number ) in the input till 
the i-th bit then with the list of possible numbers in our set, 
after inserting the number we will evaluate if we can update the max 
for that bit position to be 1.

int maximumXor(vector<int> arr)
{
    // Write your code here.   
    int maxx = 0, mask = 0, n = arr.size();
 
    set<int> se;
 
    for (int i = 30; i >= 0; i--) {
 
        // set the i'th bit in mask
        // like 100000, 110000, 111000..
        mask |= (1 << i);
 
        for (int i = 0; i < n; ++i) {
 
            // Just keep the prefix till
            // i'th bit neglecting all
            // the bit's after i'th bit
            se.insert(arr[i] & mask);
        }
 
        int newMaxx = maxx | (1 << i);
 
        for (int prefix : se) {
 
            // find two pair in set
            // such that a^b = newMaxx
            // which is the highest
            // possible bit can be obtained
            if (se.count(newMaxx ^ prefix)) {
                maxx = newMaxx;
                break;
            }
        }
 
        // clear the set for next
        // iteration
        se.clear();
    }
 
    return maxx;
}
/*
Time Complexity: O(Nlog(M)) , where N is the size of the array 
and M is the maximum number present in the array
Auxiliary Space: O(logM)
-------------------------------------------------------------
*/

/*
Better Approach: Use Trie data structure 
1) Put all numbers of array in trie
2) Again with each number of array find the maximum xor with trie.
*/
struct Node
{
    Node* links[2]; // for 0 and 1
    bool containsKey(int bit)
    {
        return (links[bit] != NULL);
    }
    
    Node* get(int bit)
    {
        return links[bit];
    }
    
    void put(int bit, Node* node)
    {
        links[bit] = node;
    } 
};

class Trie
{
    private: Node* root;
    public:
    
    Trie()
    {
        root = new Node();
    }
    
    void insert(int num)
    {
        Node* node = root;
        for(int i=31; i>=0; i--)
        {
            // this bit gives me set or not on ith index in binary
            int bit = (num >> i) & 1;
            
            if(!node->containsKey(bit))
            {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }
    
    int getMax(int num)
    {
        Node* node = root;
        int maxNum = 0;
        
        for(int i=31; i>=0; i--)
        {
            int bit = (num>>i) & 1;
            
            // since i want to maximise my bit by doing xor, 
            // so at that position i want opposite of it
            // because 1 ^ 0 = 1 && 0 ^ 1 = 1
            // and 1 ^ 1 = 0 && 0 ^ 0 = 1
            // !bit is opposite of bit
            if(node->containsKey(!bit))
            {
                maxNum = maxNum | (1 << i);
                node = node->get(!bit);
            }
            else
            {
                node = node->get(bit);
            }
        }
        return maxNum;
    }      
};

int maximumXor(vector<int> arr)
{
    // Write your code here.   
    int n = arr.size();
    
    Trie  trie; // trie class object
    for(int i=0; i<n; i++) // put every number into the trie
    {
        trie.insert(arr[i]);
    }
    
    // see, what i have to find
    //to select two indexes ‘x’ and ‘y’ such that ‘x’ <= ‘y’ and 
    //bitwise xor of values present in these indexes is maximum 
    //possible among all such pairs.
    int ans = 0;
    for(int i=0; i<n; i++)
    {
        ans = max(ans, trie.getMax(arr[i]));
    }
    return ans;
}
/*
Time Complexity: O(N)
Auxiliary Space: O(N)
*/


