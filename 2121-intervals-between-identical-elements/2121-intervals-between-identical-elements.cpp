class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        
        int n = arr.size();
        unordered_map<int, vector<int>> mp;
        vector<long long> ans(n,0);
        
        
        for(int i = 0; i<n; i++){
            mp[arr[i]].push_back(i);
        }
//         for(auto &it: mp){
//             sort(it.second.begin(), it.second.end());
//         }
        
        // for(auto it: mp){
        //     cout<<it.first<<"--> ";
        //     for(int i = 0; i<it.second.size(); i++)
        //         cout<<it.second[i]<<" ";
        //     cout<<endl;
        // }
        
        for(auto &it: mp){
            
            int size = it.second.size();
            
            vector<long long int> left(size+1,0);
            vector<long long int> right(size+1,0);
            long long int sum = 0;
            
            for(int i = 0; i<size; i++){
                sum += it.second[i];
                left[i+1] = sum;
            }
            
            sum = 0;
            
            for(int i = size-1; i>=0; i--){
                sum += it.second[i];
                right[i] = sum;
            }
            
            for(int i = 0; i<size; i++){
                long long int cnt = -left[i] + right[i+1] + i*1ll*it.second[i] - (size-1-i)*1ll*it.second[i];
                ans[it.second[i]] = cnt;
            }
        }
       
    
        return ans;
    }
};