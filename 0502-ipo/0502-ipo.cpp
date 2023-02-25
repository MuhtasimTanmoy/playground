class Solution {
public:
    int findMaximizedCapital(int k, 
                             int w, 
                             vector<int>& pfs, 
                             vector<int>& cap) {
        int n = pfs.size();
        vector<pair<int, int>> projects;
        for (int i = 0; i < n; i++) projects.emplace_back(cap[i], pfs[i]);
        sort(projects.begin(), projects.end());
        
        priority_queue<int> pq;
        int curr = 0;
        for (int i = 0; i < k; i++) {
            while (curr < n && projects[curr].first <= w) pq.push(projects[curr++].second);
            if (pq.empty()) break;
            w += pq.top();
            pq.pop();
        }
        return w;
    }
};