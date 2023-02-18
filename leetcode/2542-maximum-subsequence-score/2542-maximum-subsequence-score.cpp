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