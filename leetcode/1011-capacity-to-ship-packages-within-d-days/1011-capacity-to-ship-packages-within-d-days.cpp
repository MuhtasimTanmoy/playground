class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = 0;
        int right = 0;
        
        for (auto &weight: weights) {
            left = max(left, weight);
            right += weight;
        }
        
        int res = 0;
        
        while(left <= right) {
            
            int capacity = left + (right-left) / 2;
            auto daysNeededWithCapacity = daysNeeded(capacity, weights);
        
            cout<<left<<"-"<<right<<"::"<<capacity<<endl;
            cout<<daysNeededWithCapacity<<endl;
            
            if (daysNeededWithCapacity > days) {
                left = capacity + 1;
            } else {
                res = capacity;
                right = capacity - 1;
            }
        }
        return res;
    }
    
private:
    int daysNeeded(int capacity, vector<int>& weights) {
        
        int daysNeeded = 1;
        int sum = 0;
        
        for (auto &weight: weights) {
            sum += weight;
            if (sum > capacity) {
                daysNeeded++;
                sum = weight;
            }
        }
        
        return daysNeeded;
    }
};