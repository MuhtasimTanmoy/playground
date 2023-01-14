// class Solution {
// public:
//     bool canPartition(vector<int>& nums) {
//         unordered_map<string, bool> cache;
//         function<bool(int, int, int)> go = [&](auto i, auto l, auto r) {
//             if (i == nums.size()) return l == r;
//             auto key = to_string(i) + to_string(l) + to_string(r);
//             if (cache.count(key)) return cache[key];
//             return cache[key] = go(i + 1, l + nums[i], r) 
//                              || go(i + 1, l, r + nums[i]);
//         };
//         return go(0, 0, 0);
//     }
// };

class Solution {
public:
    using VI = vector<int>;
    using fun = function<bool(int, int)>;
    using Map = unordered_map<string, bool>;
    bool canPartition(VI& A, Map m = {}) {
        auto total = accumulate(A.begin(), A.end(), 0);
        if (total & 1)                                                  
            return false;
        auto target = total / 2;
        fun go = [&](auto i, auto t) {
            stringstream key; key << i << ',' << t;
            if (m.find(key.str()) != m.end())                           
                return m[key.str()];
            if (i == A.size() || target < t)                          
                return m[key.str()] = false;
            if (t == target)                                            
                return m[key.str()] = true;
            return m[key.str()] = go(i + 1, t + A[i]) || go(i + 1, t);
        };
        return go(0, 0);
    }
};