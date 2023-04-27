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
            if (daysNeededWithCapacity > days) 
                left = capacity + 1;
            else {
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
    int shipWithinDays(vector<int>& w, int days) {
        auto get = [&](int pivot, int count = 0, int need = 1) {
            for (auto i: w) {
                count += i;
                if (count > pivot) need++, count = i;
            }
            return need;
        };
        int l = *max_element(w.begin(), w.end()), r = accumulate(w.begin(), w.end(), 0);
        while (l < r) {
            auto m = (l + r) / 2;
            auto days_needed = get(m);
            if (days_needed > days) l = m + 1;
            else r = m;
        }
        return l;
    }
};