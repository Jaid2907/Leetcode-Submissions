// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int nums[], int n)
    {
       // Your code here
       vector<int> ans(n,1);
       stack <pair<int,int>> st;
       
       st.push({nums[0],0});
       
       for(int i=1; i<n; i++){
           
           while(!st.empty() && st.top().first<=nums[i])
                st.pop();
            
            if(!st.empty() && st.top().first>nums[i])
                ans[i] = i - st.top().second;
            else if(st.empty())
                ans[i] = i+1;
            
            st.push({nums[i],i});
       }
       return ans;
    }
};



// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
  // } Driver Code Ends