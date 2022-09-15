 

class segTree{
    public:
 
    vector<int> seg;
    segTree(int n){
        int x = 1;
        while(x <= 200000) x *= 2;
        seg.resize(2 * x, 0);
    }
    void update(int ind, int low, int high, int i, int val)
  {
    if (low == high)
    {
      seg[ind] = max(seg[ind], val);
      return;
    }
    int mid = (low + high) / 2;

    if (i <= mid)
      update(2 * ind + 1, low, mid, i, val);
    else
      update(2 * ind + 2, mid + 1, high,i, val);

    seg[ind] = max(seg[2 * ind + 1] , seg[2 * ind + 2]);
  }
    
    int query (int ind, int low, int high, int l, int r){
        int mid = low + (high - low)/2;
        
        if(l<=low && high <= r){
            return seg[ind];
        }
        else if(high < l || low > r){
            return 0;
        }
        else{
            return max(query(2*ind+1,low,mid,l,r), query(2*ind+2,mid+1,high,l,r));
        }
    }
    
    
};
class Solution {
public:
    int lengthOfLIS(vector<int>& nums, int k) {
        
        segTree* segObj = new segTree(1e5+5);
        
        
        int n = nums.size();
        
        for(int i = 0; i<n; i++){
            int l = max(nums[i]-k,0);
            int r = nums[i]-1;
            
            int ans = 1 + segObj->query(0,0,1e5+4,l,r);
            segObj->update(0,0,1e5+4,nums[i],ans);
        }
        
        return segObj->query(0,0,1e5+4,0,1e5+4);
    }
};