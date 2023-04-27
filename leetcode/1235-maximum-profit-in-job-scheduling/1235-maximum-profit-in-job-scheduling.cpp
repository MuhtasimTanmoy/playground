/* TLE
class Solution {
public:
    int jobScheduling(vector<int>& st, vector<int>& et, vector<int>& p) {
        
        vector<array<int, 3>> ranges;
        for (int i = 0; i < st.size(); i++) ranges.push_back({st[i], et[i], p[i]});
        
        sort(ranges.begin(), ranges.end(), [](auto l, auto r) {
           return l[0] < r[0]; 
        });
        
        unordered_map<string, int> store;
        auto gen_key = [](auto l, auto ... r) {
            return (to_string(l) + ... + ("-" + to_string(r)));
        };
        
        function<int(int, int)> go = [&](auto i, auto till) {
            if (i == ranges.size()) return 0;
            
            auto key = gen_key(i, till);
            if (store.count(key)) return store[key]; 
                
            auto no_take = go(i + 1, till), take = 0;
            if (ranges[i][0] >= till)
                take = ranges[i][2] + go(i + 1, ranges[i][1]);
            return store[key] = max(no_take, take);
        };
        
        return go(0, 0);
    }
};
*/

class Solution {
public:
    // int jobScheduling(vector<int>& s, vector<int>& e, vector<int>& p) {
    //     unordered_map<int, vector<pair<int, int>>> um;
    //     for (auto i = 0; i < p.size(); i++) um[e[i]].emplace_back(s[i], p[i]);
    //     auto n = *max_element(e.begin(), e.end());
    //     unordered_map<int, int> dp; dp[0] = 0;
    //     for (int i = 1; i <= n; i++) {
    //         if (!um.count(i)) { dp[i] = dp[i - 1]; continue; }
    //         for (auto [l, p]: um[i]) {
    //             auto include = dp[l] + p, exclude = dp[i-1];
    //             dp[i] = max({dp[i], include, exclude});
    //         }
    //     }
    //     return dp[n];
    // }
    
    int jobScheduling(vector<int>& startTime, 
                      vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs;
        for (int i = 0; i < n; ++i) 
            jobs.push_back({endTime[i], startTime[i], profit[i]});
        
        sort(jobs.begin(), jobs.end());
        map<int, int> dp = {{0, 0}};
        for (auto& job : jobs) {
            int cur = prev(dp.upper_bound(job[1]))->second + job[2];
            if (cur > dp.rbegin()->second)
                dp[job[0]] = cur;
        }
        return dp.rbegin()->second;
    }
};