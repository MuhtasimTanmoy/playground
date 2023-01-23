/*
Got TLE
class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if (finalSum & 1) return {};
        
        vector<long long> res, ans;
        unordered_map<string, bool> cache;
        auto key = [](int a, int b) {
            return to_string(a) + "-" + to_string(b);
        };
        
        function<bool(int, int)> go = [&](auto val, auto sum) {
            
            if (sum <= 0 || val > sum) {
                if (!sum)  ans = res;
                return !sum;
            }
    
            auto k = key(val, sum);
            if (cache.count(k)) return cache[k];
            
            res.push_back(val);
            cache[k] = go(val + 2, sum - val);
            if (cache[k]) return true;
            
            res.pop_back();
            return cache[k] = go(val + 2, sum);
        };
        go(2, finalSum);
        return ans;
    }
};
*/

class Solution {
public:
    vector<long long> maximumEvenSplit(long long s) {
        if (s % 2) return {};
        vector<long long> ans;
        function<bool(long, long)>dfs = [&](long i, long target) {
            if (target == 0) return true;
            if (target < i) return false;
            ans.push_back(i);
            if (dfs(i + 2, target - i)) return true; // use `i`
            ans.pop_back();
            return dfs(i + 2, target); // skip `i`
        };
        dfs(2, s);
        return ans;
    }
};