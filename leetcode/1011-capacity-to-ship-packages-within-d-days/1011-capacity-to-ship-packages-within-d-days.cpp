/*
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
};*/



class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        auto count = [&](int targetCap) {
            int needed = 1, sum = 0;
            for (auto w: weights) {
                sum += w;
                if (sum > targetCap) needed++, sum = w;
            }
            return needed;
        };
        
        int l = 0, r = 0;
        for (auto &w: weights) l = max(l, w), r += w;
        while (l < r) {
            auto m = l + (r - l) / 2;
            auto dneed = count(m);
            if (dneed > days) l = m + 1;
            else r = m;
        }
        return r;
    }
};
