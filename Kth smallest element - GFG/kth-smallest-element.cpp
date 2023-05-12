//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class compare{
  public:
    bool operator()(int a, int b){
        return a<b;
    }
};
class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int partition(int low, int high, int arr[]){
        int pivot = arr[low];
        int i = low, j = high;
        
        while(i<j){
            while(arr[i] <= pivot)
                i++;
            while(arr[j] > pivot)
                j--;
            if(i<j)
                swap(arr[i], arr[j]);
        }
        swap(arr[low], arr[j]);
        return j;
    }
    int helper (int low, int high, int arr[],int k){
        if(low > high)
            return INT_MAX;
        
        int ind = partition(low,high,arr);
        
        if(ind == k-1)
            return arr[ind];
        else if(ind > k-1)
            return helper(low, ind-1,arr,k);
        else
            return helper(ind+1,high,arr,k);
    }
    int kthSmallest(int arr[], int l, int r, int k) {
        //code here
       return helper(l,r,arr,k);
        
    }
};

//{ Driver Code Starts.
 
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        Solution ob;
        cout<<ob.kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends