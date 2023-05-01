template<class T> using min_pq = priority_queue<T, vector<T>, greater<T>>;

class Solution {
public:
    
    int minimumCost(vector<int>& start, 
                    vector<int>& target, 
                    vector<vector<int>>& specialRoads) {
        
        const int INF = 1e9+10;
        int n = specialRoads.size();
        vector<int> d(n, INF);
        min_pq<pair<int, int>> pq;
        for (int i = 0; i < n; i++) {
            d[i] = abs(start[0] - specialRoads[i][0]) 
                 + abs(start[1] - specialRoads[i][1]) + specialRoads[i][4];
            pq.push({d[i], i});
        }
        int ans = abs(start[0] - target[0]) + abs(start[1] - target[1]);
        while (pq.size()) {
            auto [d_c, c] = pq.top(); pq.pop();
            if (d_c != d[c]) continue;
            ans = min(ans, d_c + 
                      abs(target[0] - specialRoads[c][2]) + 
                      abs(target[1] - specialRoads[c][3]));

            for (int nxt = 0; nxt < n; nxt++) {
                int w = abs(specialRoads[c][2] - specialRoads[nxt][0]) 
                    + abs(specialRoads[c][3] - specialRoads[nxt][1]) 
                    + specialRoads[nxt][4];
                if (d_c + w < d[nxt]) 
                    d[nxt] = d_c + w,
                    pq.push({d[nxt], nxt});
            }
        }
        return ans;
    }
};