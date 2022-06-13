class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        
        int n = gas.size();
        int index=0;
        int fuel = 0;
        int tot_gas= 0, tot_cost = 0;
        
        for(int i = 0; i<n;i++)
        {
            tot_gas+=gas[i];
            tot_cost+=cost[i];
        }
        
        if(tot_cost>tot_gas)
            return -1;
        
        for(int i = 0; i<n;i++)
        {
            
            fuel  = fuel  + gas[i]-cost[i];
            
            if(fuel<0)
            {
                fuel = 0;
                index = i+1;
            }
        }
        
        return index;
        
            
            
        
        
        
       
        
          
        
      
     
    }
};