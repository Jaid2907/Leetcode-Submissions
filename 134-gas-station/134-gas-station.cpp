class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum_gas = accumulate(gas.begin(), gas.end(),0);
        int sum_cost = accumulate(cost.begin(), cost.end(), 0);
        if(sum_cost > sum_gas)
            return -1;
        int gas_rem = 0;
        int n = gas.size();
        int ans = 0;
        
        
        for(int i = 0; i<n; i++){
            
            gas_rem += gas[i]-cost[i];
            
            if(gas_rem <0){
                gas_rem = 0;
                ans = i+1;
            }
            
        }
        return ans;
    }
};