class compare{
  public:
    bool operator()(int a, int b){
        return a > b;
    }
};
class Solution {
public:

    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        int n = heights.size();
        priority_queue<int, vector<int> , compare> pq;
        int sum = 0;
        int i = 1;
        
        while(i<n){
            
            int jump = heights[i] - heights[i-1];
            
            if(jump <= 0){
                i++;
                continue;
            }
            if(ladders == 0){
                sum += jump;
            }    
            else if(pq.size() < ladders){
                pq.push(jump);
            }
            else {
                if(pq.top() < jump){
                    sum  += pq.top();
                    pq.pop();
                    pq.push(jump);
                }
                else{
                    sum += jump;
                }
            }
            
            if(sum > bricks)
                break;
            i++;
            
        }
        
        return i-1;
    }
};