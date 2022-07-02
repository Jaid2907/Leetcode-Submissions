class Solution {
public:
    static bool compare (vector<int>& a, vector<int>& b){
        return a[0]<b[0];
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        vector<vector<int>> ans;
        int n = intervals.size();
        int start = newInterval[0];
        int end = newInterval[1];
        
        int i = 0;
        int flag = 0;
        while(i<n){
            
            if((start<=intervals[i][1] && start>=intervals[i][0]) || (end>=intervals[i][0] && end<=intervals[i][1]) || (start<=intervals[i][0] && end>=intervals[i][1])){
                int newStart = intervals[i][0]<start?intervals[i][0]:start;
                flag = 1;
                while(i<n && end>=intervals[i][0]){
                    i++;
                }
                
                int newEnd = end>intervals[i-1][1]?end:intervals[i-1][1];
                
                ans.push_back({newStart,newEnd});
            }
            else{
                ans.push_back(intervals[i]);
                i++;
            }
        }
            
        if(flag == 0){
           ans.push_back({start,end});
        }
        
        sort(ans.begin(), ans.end(), compare);
            

        
        return ans;
    }
};