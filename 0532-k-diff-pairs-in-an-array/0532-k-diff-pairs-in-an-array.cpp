class PairCache {
    unordered_set<string> tracker;
public:
    void insert(int a, int b) {   
        if (a > b) swap(a, b);
        auto to_str = to_string(a) + "-" + to_string(b);
        tracker.insert(to_str);
    }
    
    bool has(int a, int b) {
        if (a > b) swap(a, b);
        auto to_str = to_string(a) + "-" + to_string(b);
        return tracker.count(to_str);
    }
};

class Solution {
    PairCache pair_cache;
public:
    int findPairs(vector<int>& nums, int k, int res = 0) {        
        unordered_set<int> tracker;
        for (auto num: nums) {
            if (tracker.count(num + k) && pair_cache.has(num, num + k) == false) {
                pair_cache.insert(num, num + k);
                res++;
            }
            if (tracker.count(num - k) && pair_cache.has(num, num - k) == false) {
                pair_cache.insert(num, num - k);
                res++;
            }
            tracker.insert(num);
        }
        return res;
    }
};