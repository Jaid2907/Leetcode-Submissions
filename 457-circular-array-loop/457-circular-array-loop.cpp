class Solution {
public:
//     bool dfs (int start, vector<int>& nums,vector<int>& color){
        
//         if(color[i] == 2)
//             return false;
//         color[i] = 1;
//         int n = nums.size();
//         int next = start + nums[start];
//         if(next<0)
//             next = (next + n)%n;
//         else if(next>=n)
//             next = next%n;
        
//         if(nums[next]*nums[start]<0 || next==start){
//             color[i] = 2;
//             return false;
//         }
        
            
        
//     }
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        vector<int> color(n,0);
        for(int i=0; i<n; i++){
            nums[i] %= n;
        }
        for(int i=0; i<n; i++){
            
           vector<int> visited(n,0);
            visited[i] = 1;
            int flag = 0;
            int curr = i;
            while(true){
                int temp = curr;
                curr = curr + nums[curr];
                if(curr<0)
                    curr = (curr+n)%n;
                else if(curr>=n)
                    curr %= n;
                
                if(nums[temp] * nums[curr]<0 || temp == curr ||nums[curr] == 0){
                    flag = 1;
                     break;
                }
                else if(visited[curr]){
                    flag = 2;
                    break;
                }
                visited[curr] = 1;
            }
            
            if(flag == 2)
                return true;
        }
        return false;
    }
};