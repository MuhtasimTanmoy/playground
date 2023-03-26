class PairCache {
    unordered_set<string> tracker;
public:
    void insert(int a, int b) {   
        if (a > b) swap(a, b);
        auto to_str = to_string(a) + "-" + to_string(b);
        tracker.insert(to_str);
    }
    
    bool has_no(int a, int b) {
        if (a > b) swap(a, b);
        auto to_str = to_string(a) + "-" + to_string(b);
        return !tracker.count(to_str);
    }
};

class Solution {
    PairCache pair_cache;
public:
    int findPairs(vector<int>& nums, int k, int res = 0) {        
        unordered_set<int> tracker;
        for (auto num: nums) {
            for (auto can_be: {num + k, num - k}) 
                 if (tracker.count(can_be) && pair_cache.has_no(num, can_be)) 
                    pair_cache.insert(num, can_be),
                    res++;
            tracker.insert(num);
        }
        return res;
    }
};