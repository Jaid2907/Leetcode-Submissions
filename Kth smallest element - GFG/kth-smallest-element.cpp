//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class heap
{ public:
  vector<int> heap;
  
  void insert(int val)
  {
    heap.push_back(val);
    int j = heap.size() - 1;

    while (j > 0)
    {
      int parent = (j - 1) / 2;
      
      if (heap[parent] < heap[j])
      {
        swap(heap[j], heap[parent]);
        j = parent;
      }
      else
      {
        break;
      }
    }
  }

  void pop()
  {

    int val = heap.back();
    heap.pop_back();
    heap[0] = val;
    int j = 0;

    while (j < heap.size())
    {
      
      if(2*j+2 < heap.size()){
          int c1 = heap[2 * j + 1];
          int c2 = heap[2 * j + 2];
          
          if(c1>=c2 && c1 > heap[j]){
              swap(heap[j], heap[2*j+1]);
              j = 2*j+1;
          }
          else if(c2 > c1 && c2 > heap[j]){
              swap(heap[j], heap[2*j+2]);
              j = 2*j+2;
          }
          else
            break;  
        
    
      }
      else if(2*j+1 < heap.size()){
          if(heap[2*j+1] > heap[j]){
              swap(heap[j], heap[2*j+1]);
              j = 2*j+1;
          }
          else
            break;
      }
      else
        break;
     
    }
  }
  int top()
  {
    return heap[0];
  }
  int size(){
      return heap.size();
  }
};
class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        heap* h = new heap();
        
        for(int i = l; i<=r; i++){
            h->insert(arr[i]);
            if(h->size() > k)
                h->pop();
        }
        
        return h->top();
        
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