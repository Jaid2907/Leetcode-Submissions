//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;

class Shop
{
    vector<int> chocolates;
    int countOfCalls;
    public:
    Shop()
    {
        countOfCalls = 0;
    }
    void addChocolate(int x)
    {
        chocolates.push_back(x);
    }
    long long get(int i)
    {
        countOfCalls++;
        if(i<0 || i>=(int)chocolates.size() || countOfCalls>50)return -1;
        return chocolates[i];
    }
};


// } Driver Code Ends
//User function Template for Java

/*
Instructions - 

    1. 'shop' is object of class Shop.
    2. User 'shop.get(int i)' to enquire about the price
            of the i^th chocolate.
    3. Every chocolate in shop is arranged in increasing order
            i.e. shop.get(i) <= shop.get(i + 1) for all 0 <= i < n - 1
*/
class Solution{
    public:
    Shop shop;
    Solution(Shop s)
    {
        this->shop = s;
    }
long long find(int n, long k){
        // Return the number of chocolates Geek had
        // enjoyed out of 'n' chocolates availabe in the
        // 'shop'.
        unordered_map<int,int> mp;
        long long int cnt = 0;
        
        
        while(k){
            // cout<<k<<endl;
            int low = 0, high = n-1, f = 0;
            int max_affordable = INT_MIN;
            
            while(high - low > 1){
                
                int mid = low + (high-low)/2;
                // cout<<mid<<" ";
                if(mp.find(mid) == mp.end())
                    mp[mid] = shop.get(mid);
                // cout<<mp[mid]<<" ";
            
                if(mp[mid] == k){
                    f = 1;
                    max_affordable = mp[mid];
                    break;
                }
                else if(mp[mid] > k){
                    high =  mid - 1;
                }
                else{
                    max_affordable = mp[mid];
                    low = mid + 1;
                }
                // cout<<low<<" "<<high<<" ";
            }
            // cout<<endl;
            // cout<<max_affordable<<endl;
            
            
            if(k < max_affordable){
                break;
            }
            
           if(!f){
                if(mp.find(high) == mp.end())
                    mp[high] = shop.get(high);
            
                if(mp.find(low) == mp.end())
                    mp[low] = shop.get(low);
                    
                if(mp[high] <= k){
                    max_affordable = mp[high];
                }
                else if(mp[low] <= k){
                    max_affordable = max(max_affordable,mp[low]);
                }
                
            }
            
            // cout<<max_affordable<<endl;
            if(max_affordable == INT_MIN)
                break;
            
            
            cnt += k/max_affordable;
            k = k%max_affordable;
        }
        
        return cnt;
        
    }

};

//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        long long k;
        cin >> k;
        
        Shop shop;
        for(int i = 0; i<n; i++)
        {
            int x;
            cin >> x;
            shop.addChocolate(x);
        }
        
        Solution obj(shop);
        long long res = obj.find(n, k);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends