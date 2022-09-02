
/*
Brute Force Solution
Approach:  
The extreme naive solution is to generate all the possible 
permutations of the given sequence.  This is achieved using 
recursion and every permutation generated is stored in some 
other data structure (here we have used a vector). 
Finally, we sort the data structure in which we have stored 
all the sequences and return the Kth sequence from it.

#include<algorithm>
#include<vector>

void solve(int index,vector<string>&ans,string &s){
    if(index>=s.size()){
        ans.push_back(s);
        return;
    }
    
    for(int i=index;i<s.size();i++){
        swap(s[index],s[i]);
        solve(index+1,ans,s);
        swap(s[index],s[i]);
    }
}

string kthPermutation(int n, int k) {
    vector<string>ans;
    string s;
    for(int i=1;i<=n;i++){
        s.push_back(i + '0');
    }
    solve(0,ans,s);
    
    sort(ans.begin(),ans.end());
    
    auto out= ans.begin()+(k-1);
    return *out;
    
}

Time complexity: O(N! * N) +O(N! Log N!)
Reason:  The recursion takes O(N!)  time because we generate 
every possible permutation and another O(N)  time is required 
to make a deep copy and store every sequence in the data structure. 
Also, O(N! Log N!)  time required to sort the data structure

Space complexity: O(N) 
Reason: Result stored in a vector, we are auxiliary space taken 
by recursion
*/

/*
Optimal approach:
Intuition:
Since this is a permutation we can assume that there are four positions that need to be filled using the four numbers of the sequence. First, we need to decide which number is to be placed at the first index. Once the number at the first index is decided we have three more positions and three more numbers.  Now the problem is shorter. We can repeat the technique that was used previously until all the positions are filled. 
*/

string kthPermutation(int n, int k) {
    int fact = 1;
      vector < int > numbers;
      for (int i = 1; i < n; i++) {
        fact = fact * i;
        numbers.push_back(i);
      }
      numbers.push_back(n);
      string ans = "";
      k = k - 1;
      while (true) {
        ans = ans + to_string(numbers[k / fact]);
        numbers.erase(numbers.begin() + k / fact);
        if (numbers.size() == 0) {
          break;
        }

        k = k % fact;
        fact = fact / numbers.size();
      }
      return ans;
}
/*
Time Complexity: O(N) * O(N) = O(N^2)
Reason: We are placing N numbers in N positions. 
This will take O(N) time. For every number, we are reducing 
the search space by removing the element already placed in 
the previous step. This takes another O(N) time.

Space Complexity: O(N) 
Reason: We are storing  the numbers in a data structure(here vector)
*/

