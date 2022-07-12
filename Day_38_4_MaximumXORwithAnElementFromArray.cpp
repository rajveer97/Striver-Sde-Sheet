#include<bits/stdc++.h>
/*
Naive Solution : Use two loops

vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
    //Write your coode here.
    sort(arr.begin(), arr.end());
    vector<int> ans;
    
    for(int i=0; i<queries.size(); i++)
    {
        int xo = queries[i][0];
        int limit = queries[i][1];
        int maxi = -1;
        
        for(int j=0; j<arr.size(); j++)
        {
            if(arr[j] > limit) 
                break;
            else {
                int res = xo ^ arr[j];
                maxi = max(maxi, res);
            }
                
        }
        
        ans.push_back(maxi);
    }
    
    return ans;
}
/*
TC : O(N^2)
-----------------------------------------------------------------
*/


/*
Optimal Approeach : Use Trie data structure
*/
class Node {
private:
    Node* links[2];
public:
    bool contains(int bit) {
        return (links[bit] != NULL);
    }
    void put(int bit, Node* node) {
        links[bit] = node;
    }
    Node* get(int bit) {
        return links[bit];
    }
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    void insert(int num) {
        Node* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->contains(bit)) {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }
    int maxXOR(int num) {
        Node* node = root;
        int mx = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->contains(1-bit)) {
                node = node->get(bit);
            } else {
                mx = mx | (1 << i);
                node = node->get(1-bit);
            }
        }
        return mx;
    }
};

vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
    int n = arr.size(), m = queries.size();
    Trie trie;
    vector<int> result(m, 0);
    sort(arr.begin(), arr.end());
    for (int i = 0; i < queries.size(); i++) {
        queries[i].push_back(i);
    }
    sort(queries.begin(), queries.end(), [](vector<int> &lhs, vector<int> &rhs) {
        return lhs[1] < rhs[1];
    });
    int i = 0;
    for (auto query : queries) {
        int x = query[0], a = query[1], ind = query[2];
        while (i < n && arr[i] <= a) {
            trie.insert(arr[i]);
            i++;
        }
        if (i == 0) result[ind] = -1;
        else result[ind] = trie.maxXOR(x);
    }
    return result;
}
