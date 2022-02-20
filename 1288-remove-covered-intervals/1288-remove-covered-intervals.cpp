class Solution {
public:
    static bool compare(vector<int> interval1, vector<int> interval2)
    {
        if(interval1[0] == interval2[0])
            return interval1[1]>interval2[1];
        
        return interval1[0]<interval2[0];
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end(),compare);
        int cnt = 0;
        int max_end_seen = intervals[0][1];
        for(int i=1; i<n; i++)
        {
           if(intervals[i][1]<=max_end_seen)
               cnt++;
            
            max_end_seen = max (max_end_seen, intervals[i][1]);
               
            
        }
        
        return n-cnt;
    }
};