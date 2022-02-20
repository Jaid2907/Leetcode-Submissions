class Solution {
public:
    static bool compare(vector<int> interval1, vector<int> interval2)
    {
        return interval1[1]>interval2[1];
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        // sort(intervals.begin(),intervals.end(),compare);
        int cnt = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(j!=i)
                {
                     bool a = intervals[i][0]>=intervals[j][0];
                     bool b = intervals[i][1]<=intervals[j][1];
                    if((a == true && b == true))
                    {   
                        cnt++;
                        break;
                    }
                }
               
            }
        }
        
        return n-cnt;
    }
};