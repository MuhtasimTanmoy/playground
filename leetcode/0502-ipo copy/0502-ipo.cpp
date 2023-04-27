class Solution {
public:
    int findMaximizedCapital(int k, 
                             int w, 
                             vector<int>& pfs, 
                             vector<int>& cap) {
        int n = pfs.size();
        vector<pair<int, int>> p;
        for (int i = 0; i < n; i++) p.emplace_back(cap[i], pfs[i]);
        sort(p.begin(), p.end());
        
        priority_queue<int> pq;
        for (int i = 0, curr = 0; i < k; i++) {
            while (curr < n && p[curr].first <= w) pq.push(p[curr++].second);
            if (pq.empty()) break;
            w += pq.top();
            pq.pop();
        }
        return w;
    }
};