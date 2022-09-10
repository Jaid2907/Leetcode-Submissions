class Solution {
public:
    void merge (int low, int mid, int high, vector<pair<int,int>>& nums, vector<int>& ans){
        vector<pair<int,int>> a(high - low + 1);
        int i = low;
        int j = mid+1;
        int k = 0;
        
        while(i<=mid && j<=high){
            if(nums[i].first > nums[j].first){
                ans[nums[i].second] += high-j+1;
                a[k++] = nums[i++];
            }
            else{
                a[k++] = nums[j++];
            }
        }
        while(i<=mid){
            a[k++] = nums[i++];
        }
        while(j<=high){
            a[k++] = nums[j++];
        }
        
        k = 0;
        for(int m = low; m<=high; m++)
            nums[m] = a[k++];
        
    }
    void mergeSort(int low, int high, vector<pair<int,int>>& nums, vector<int>& ans){
        
        if(low < high){
            int mid = (low + high)/2;
            mergeSort(low,mid,nums,ans);
            mergeSort(mid+1,high,nums,ans);
            merge(low, mid, high,nums,ans);
        }
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        vector<pair<int,int>> v(n);
        
        for(int i = 0; i<n; i++){
            v[i] = {nums[i],i};
        }
        mergeSort(0,n-1,v,ans);
        
        return ans;
    }
};