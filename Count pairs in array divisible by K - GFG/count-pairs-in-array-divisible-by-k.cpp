//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    long long countKdivPairs(int A[], int n, int K)
    {
        //code here
        long long int ans = 0;
        unordered_map<int,int> mp;
        
         for(int i = 0; i<n; i++){
            mp[A[i]%K]++;
        }

        for (int i = 0; i < n; i++) {
            if(A[i]%K == 0)
                continue;
            if(2*1ll*(A[i]%K) == K)
                ans += mp[A[i]%K]-1;
            else
                ans += mp[K - (A[i] % K)];
        }


        
    
        ans /= 2;
        if(mp.find(0) != mp.end() && mp[0] > 1)
            ans += (mp[0]*1ll*(mp[0]-1))/2;

        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;

		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		int k;
		cin >> k;

        Solution ob;
		cout << ob. countKdivPairs(a, n , k) << "\n";



	}


	return 0;
}

// } Driver Code Ends