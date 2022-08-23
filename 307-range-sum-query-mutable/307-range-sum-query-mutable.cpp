
class NumArray {
public:
    vector<int> seg;
    vector<int> arr;
    int n;
    int build(int ind, int low, int high)
  {

    if (low == high)
    {
      seg[ind] = arr[low];
      return seg[ind];
    }

    int mid = (low + high) / 2;
    int left = build(2 * ind + 1, low, mid);
    int right = build(2 * ind + 2, mid + 1, high);

    return seg[ind] = left + right;
  }
    NumArray(vector<int>& nums) {
        n = nums.size();
        arr = nums;
        seg.resize(4*n);
        build(0,0,n-1);
    }
    void update_helper(int ind, int low, int high, int i, int val)
  {
    if (low == high)
    {
      arr[i] = val;
      seg[ind] = val;
      return;
    }
    int mid = (low + high) / 2;

    if (i <= mid)
      update_helper(2 * ind + 1, low, mid,  i, val);
    else
      update_helper(2 * ind + 2, mid + 1, high, i, val);

    seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
  }
    
    void update(int index, int val) {
        update_helper(0,0,n-1,index,val);
    }
    
    int query_helper(int ind, int low, int high, int l, int r)
  {

    int mid = (low + high) / 2;

    // Complete Overlap
    if (l <= low && high <= r)
    {
      return seg[ind];
    }
    // Partial Overlap
    else if (high < l || low > r)
    {
      return 0;
    }
    else
    {
      return query_helper(2 * ind + 1, low, mid, l, r) + query_helper(2 * ind + 2, mid + 1, high, l, r);
    }

    // No Overlap
  }
    int sumRange(int left, int right) {
       return query_helper(0,0,n-1,left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */