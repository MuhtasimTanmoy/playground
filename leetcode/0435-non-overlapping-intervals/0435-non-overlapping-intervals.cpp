// 54 / 58 test cases passed.

/*
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        unordered_map<string, int> dp;
        auto gen_key = [](auto i, auto j) {
            return to_string(i) + "-" + to_string(j);
        };
        
        function<int(int, int)> go = [&](auto i, auto to) {
            if (i == intervals.size()) return 0;
            
            auto key = gen_key(i, to);
            if (dp.count(key)) return dp[key];
            
            int calc = go(i + 1, to);
            if (to <= intervals[i][0]) {
                auto take = 1 + go(i + 1, intervals[i][1]);
                calc = max(calc, take);
            }
            return dp[key] = calc;
        };
        return intervals.size() - go(0, -100000);
    }
};
*/

// if two intervals are overlapping, we want to remove the interval that has the longer end point -- the longer interval will always overlap with more or the same number of future intervals compared to the shorter one

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [&](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        int prevMax = INT_MIN, res = 0;
        for (auto interval: intervals) {
            auto left = interval[0], right = interval[1];
            if (left < prevMax) res++;
            else prevMax = max(prevMax, right);
        }
        return res;
    }
};