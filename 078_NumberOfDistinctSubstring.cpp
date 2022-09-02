#include<bits/stdc++.h>
/*
Naive Solution : 
Use unordered set since it stores only unique values

int distinctSubstring(string &word) {
    //  Write your code here.
    unordered_set<string> st;
    int n = word.size();
    for(int i=0; i<n; i++)
    {
        string substring = "";
        for(int j=i; j<n; j++)
        {
            substring.push_back(word[j]);
            st.insert(substring);
        }
    }
    return st.size();
}
/*
TC : O(N^2 * log M(adding elements to the set))
where M is the no. elements in the set
SC : O(N^3)
*/

/*
Optimized Approach : Use Trie 
*/
struct Node {
    Node* children[26];
    
    // returns, child is present or not
    bool containsKey(char ch)
    {
        return (children[ch - 'a'] != NULL);
    }
    
    // return child node(reference child node)
    Node* get(char ch)
    {
        return (children[ch - 'a']);
    }
    
    // set the child
    void set(Node* node, char ch)
    {
        children[ch - 'a'] = node;
    }
};

class Trie
{
    Node* root;
    
    public:
    // constructor
    Trie() {
        root = new Node();
    }
    
    public:
    void insert(string word, int &ans)
    {
        Node* node = root;
        
        for(int i=0; i<word.length(); i++)
        {
            //if child is not present set the value ans increment ans
            if(!node->containsKey(word[i]))
            {
                node->set(new Node(), word[i]);
                ans++;
            }
            
            //get child node 
            node = node->get(word[i]);
        }
    }
};

int distinctSubstring(string &word) {
    //  Write your code here.
    int ans = 0;
    Trie trie;
    
    for(int i=0; i<word.length(); i++)
    {
        string st = "";
        
        for(int j=i; j<word.length(); j++)
        {
            st += word[j];
            trie.insert(st, ans);
        }
    }
    
    return ans;
}

// TC : O(N^2)
