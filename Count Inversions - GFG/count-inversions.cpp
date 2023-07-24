//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    void merge(long long arr[], long long low, long long mid, long long high, long long &cnt){
        
        long long temp[high-low+1];
        int i = low, j = mid +1, k = 0;
        
        while(i<=mid && j<=high){
            
            if(arr[i] > arr[j]){
                cnt += (mid-i+1);
                temp[k++] = arr[j++];
            }
            else{
                temp[k++] = arr[i++];
            }
        }
        
        while(i<=mid){
            temp[k++] = arr[i++];
        }
        
        while(j<=high){
            temp[k++] = arr[j++];   
        }
        
        k = 0;
        for(int i = low; i<=high; i++){
            arr[i] = temp[k++];
        }
    }
    void mergeSort(long long arr[], long long low, long long high, long long &cnt){
        if(low >= high)
            return;
        
        long long mid = low + (high-low)/2;
        mergeSort(arr,low,mid,cnt);
        mergeSort(arr,mid+1,high,cnt);
        merge(arr,low,mid,high,cnt);
    }
    long long int inversionCount(long long arr[], long long n)
    {
        long long cnt = 0;   
        mergeSort(arr,0,n-1,cnt);
        return cnt;
       
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends