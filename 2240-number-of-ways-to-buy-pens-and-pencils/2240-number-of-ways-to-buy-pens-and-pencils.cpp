class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        
        long long int max_pens = total/cost1;
        long long int max_pencils = total/cost2;
        long long int cnt = 0;
        
        for(int i=0; i<=max_pens; i++){
            long long int money_left = total - i*cost1;
            
            long long int no_of_pencils = money_left/cost2;
            cnt += no_of_pencils+1;
                
        }
        
        return cnt;
    }
};