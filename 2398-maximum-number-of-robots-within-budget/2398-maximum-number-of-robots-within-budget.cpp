class SegTree
{
public:
  vector<int> seg;
  int n;

  SegTree(int n)
  {
    this->n = n;
    seg.resize(4 * n);
  }

  int build(int ind, int low, int high, vector<int> &arr)
  {

    if (low == high)
    {
      seg[ind] = arr[low];
      return seg[ind];
    }

    int mid = (low + high) / 2;
    int left = build(2 * ind + 1, low, mid, arr);
    int right = build(2 * ind + 2, mid + 1, high, arr);

    return seg[ind] = max(left,right);
  }

  void update(int ind, int low, int high, vector<int> &arr, int i, int val)
  {
    if (low == high)
    {
      arr[i] = val;
      seg[ind] = val;
      return;
    }
    int mid = (low + high) / 2;

    if (i <= mid)
      update(2 * ind + 1, low, mid, arr, i, val);
    else
      update(2 * ind + 2, mid + 1, high, arr, i, val);

    seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
  }

  int query(int ind, int low, int high, vector<int> &arr, int l, int r)
  {

    int mid = (low + high) / 2;

    // Complete Overlap
    if (l <= low && high <= r)
    {
      return seg[ind];
    }
    // No Overlap
    else if (high < l || low > r)
    {
      return 0;
    } // Partial Overlap
    else
    {
      return max(query(2 * ind + 1, low, mid, arr, l, r), query(2 * ind + 2, mid + 1, high, arr, l, r));
    }
  }
};
class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int n = chargeTimes.size();
        SegTree seg(n);
        seg.build(0,0,n-1,chargeTimes);
        long long int s = 0;
        
        
        vector<long long int> prefix_sum (n+1,0);
        
        for(int i = 1; i<=n; i++){
            
            s += runningCosts[i-1];
            prefix_sum[i] = s;
        }
        
        int ans = 0;
        long long int curr_cost = 0;
        int i = 0;
        int j = 0;
        
        while(i<n){
            int l = j;
            int r = i;
            int max_val = seg.query(0,0,n-1,chargeTimes,l,r);
            
            curr_cost = max_val + (i-j+1)*1ll*(prefix_sum[i+1]-prefix_sum[j]);
            
            if(curr_cost <= budget)
            ans = max(ans, (i-j+1));
            if(curr_cost <= budget){
                i++;
            }
            else{
                
                while(j<=i && curr_cost > budget){
                    
                    l = j+1;
                    r = i;
                    j++;
                    int maxi = seg.query(0,0,n-1,chargeTimes,l,r); 
                    curr_cost = maxi + (i-j+1)*1ll*(prefix_sum[i+1]-prefix_sum[j]);
                }
            }
            
            
            
        }
        
        return ans;
        
        
        
    }
};