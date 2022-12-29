//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    bool helper (int i, int n, long long int sum, vector<long long int>& vec, vector<int>& nums, int k){
        if(i == n){
            for(int j = 1; j<k; j++){
                if(vec[j] != vec[j-1])
                    return false;
            }

            return true;
        }
            
        bool ans = false;
        for(int j = 0; j<k; j++){
            if(vec[j] + nums[i] <= sum){
                vec[j] += nums[i];
                ans = ans || helper(i+1,n,sum,vec,nums,k);
                vec[j] -= nums[i];
            }
        }

        return ans;

    }
    bool isKPartitionPossible(int a[], int n, int k)
    {
         //Your code here
         vector<int> nums(a,a+n);
        long long int sum = accumulate(nums.begin(), nums.end(), 0);
        int maxi = *max_element(nums.begin(), nums.end());
        if(maxi > (sum/k))
            return false;
        vector<long long int> vec(k,0);
        if(sum % k != 0)
            return false;

        return helper(0,n,sum/k,vec,nums,k);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	int k;
    	cin>>k;
    	Solution obj;
    	cout<<obj.isKPartitionPossible(a, n, k)<<endl;
    }
}
// } Driver Code Ends