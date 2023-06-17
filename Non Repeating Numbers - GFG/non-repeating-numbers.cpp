//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        int xor_ans = 0;
        int n = nums.size();
        
        for(int i = 0; i<n; i++){
            xor_ans ^= nums[i];
        }
        
        int rightmost = xor_ans & ~(xor_ans-1);
        int p = 0, q = 0;
        
        for(int i = 0; i<n; i++){
            if(rightmost & nums[i])
                p ^= nums[i];
            else
                q ^= nums[i];
        }
        
        return {min(p,q),max(p,q)};
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends