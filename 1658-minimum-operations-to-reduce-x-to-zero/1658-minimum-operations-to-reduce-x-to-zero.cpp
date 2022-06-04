class Solution {
public:
    int lenOfLongSubarr(vector<int> &A ,int N, int K)
{
 
    int i = 0, j = 0, sum = 0;
    int maxLen = INT_MIN;
   
    while (j < N) {
        sum += A[j];
        if (sum < K) {
            j++;
        }
        else if (sum == K) {
            maxLen = max(maxLen, j-i+1);
            j++;
        }
        else if (sum > K) {
            while (sum > K) {
                sum -= A[i];
                 i++;
            }
              if(sum == K){
              maxLen = max(maxLen, j-i+1);
            }
            j++;
        }
    }
    return maxLen;
}
 
    int minOperations(vector<int>& nums, int x) {
        
        int sum = accumulate(nums.begin(),nums.end(), 0);
        
        if(sum < x)
            return -1;
        int sum_req = sum - x;
        
        
        //Maximum subarray equal to given sum
        
        int temp = lenOfLongSubarr(nums,nums.size(),sum_req);
        
        if(temp == INT_MIN)
            return -1;
        
        return nums.size() - temp;
        
        
    }
};