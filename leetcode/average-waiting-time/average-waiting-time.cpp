class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        
        int startTime = 0;
        int endtime = 0;
        
        double waitingTime = 0;
        for(auto customer: customers) {
            
            startTime = customer[0];
            if (startTime >= endtime) endtime = customer[0] + customer[1];
            else { endtime += customer[1];}
            
            waitingTime += (endtime - startTime);
        }
        
        return waitingTime / (double)size(customers);
    }
};