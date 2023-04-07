/*
class CountedSum {
public:    
    CountedSum() {}
    
    void add(int num) {
        sum += num;
        in_count++;
    }
    
    void reset_then_add(int num) {
        reset();
        add(num);
        boats_count++;
    }
    
    int get_result() {
        return boats_count;
    }
    
    bool is_at_limit_cap() {
        return in_count == PASSENGER_LIMIT;
    }
    
    bool is_empty() {
        return in_count == 0;
    }
    
    bool will_cross_limit(int weight, int limit) {
        return sum + weight > limit;
    }
    
private:
    int in_count, sum, boats_count = 0;
    const int PASSENGER_LIMIT = 2;
    
    void reset() {
        sum = 0;
        in_count = 0;
    }
};


class Solution {
    CountedSum util;
public:
    int numRescueBoats(vector<int>& weights, int limit) {
        sort(weights.begin(), weights.end());
        for (auto weight: weights) {
            auto should_get_new_boat = util.is_at_limit_cap() 
                                    || util.will_cross_limit(weight, limit)
                                    || util.is_empty();
            if (should_get_new_boat) util.reset_then_add(weight);
            else util.add(weight);
        }
        return util.get_result();
    }
};
*/

class Solution {
public:
    int numRescueBoats(vector<int>& p, int limit) {
        sort(begin(p), end(p));
        int left = 0, right = size(p) - 1, res = 0;
        while (left <= right)
            if (p[right] + p[left] <= limit)
                res++, left++, right--;
            else
                res++, right--;
        return res;
    }
};