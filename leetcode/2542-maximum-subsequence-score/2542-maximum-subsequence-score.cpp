/*
class Solution {
public:
    long long maxScore(vector<int>& l, vector<int>& r, int k) {
        auto gen_key = [](auto l, auto ...r) { return (to_string(l) + ... + (to_string(r))); };
        unordered_map<string, long long> c;
        function<long long(int, int, int, int)> 
            go = [&](auto i, auto left, auto sum, auto min_so_far) {
            if (left == 0) return 1LL * min_so_far * sum;
            if (i == l.size()) return 0LL;
            auto key = gen_key(i, left, sum, min_so_far);
            if (c.count(key)) return c[key];
            long long take = go(i + 1, left - 1, sum + l[i], min(min_so_far, r[i])),
                      no_take = go(i + 1, left, sum, min_so_far);
            return c[key] = max(take, no_take);
        };
        return go(0, k, 0, INT_MAX);
    }
};
*/

class Solution {
public:
    long long maxScore(vector<int>& speed, vector<int>& efficiency, int k) {
        int n = speed.size();
        vector<pair<int, int>> ess(n);
        for (int i = 0; i < n; ++i) ess[i] = {efficiency[i], speed[i]};
        
        sort(rbegin(ess), rend(ess));
        long long sumS = 0, res = 0;
        priority_queue <int, vector<int>, greater<int>> pq;
        
        for (auto& [e, s] : ess) {
            pq.emplace(s);
            sumS += s;
            
            if (pq.size() > k) sumS -= pq.top(), pq.pop();
            if (pq.size() == k) res = max(res, sumS * e);
        }
        return res;
    }
};