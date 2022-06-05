class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int total = 0, partial = 0, start = 0;
        
        for (int i = 0; i < gas.size(); ++i) {
            
            total += gas[i]-cost[i];
            partial += gas[i]-cost[i];
            
            // cout<< total << " " << partial << endl;
            
            if (partial < 0) {
                start = i+1;
                partial = 0;
            }
        }
        return total < 0 ? -1 : start;
    }
};