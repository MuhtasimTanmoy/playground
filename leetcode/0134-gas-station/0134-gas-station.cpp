class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0, local = 0, start = 0;
        for (int i = 0; i < gas.size(); i++) {
            auto gain = gas[i] - cost[i];
            total += gain;
            local += gain;
            
            if (local < 0) {
                start = i + 1;
                local = 0;
            }
        }
        return total < 0 ? -1: start;
    }
};