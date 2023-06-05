//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int kthElement(int row1[], int row2[], int m, int n, int k)
    {
        int low = 0, high = m-1;
        int ans = -1;

    while(low <= high){
        int mid = low + (high-low)/2;
        int elements;


        auto it = upper_bound(row2, row2+n, row1[mid]);
        if(it == row2){
            elements = 0;
        }
        else{
            it--;
            elements = it - row2 + 1;
        }

        if(mid+1+elements == k)
            return max(row1[mid],row2[k-mid-2]);
        else if(mid+1+elements > k){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid + 1;
        }
    }
    
    if(ans == -1)
        return row2[k-m-1];
    int ind = k-ans-1; 
    return max(row2[ind],row1[ans-1]);
    }
};

//{ Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}
// } Driver Code Ends