/*
Aproach:
Use XOR operator, 
since XOR operator removes the duplicate number
*/

int uniqueElement(vector<int> arr, int n)
{
	// Write your code here
    int ans = arr[0];
    for(int i=1; i<n; i++) {
        ans ^= arr[i];
    }
    return ans;
}
/*
TC : O(N)
AS : O(1)
*/