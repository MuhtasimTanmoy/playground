class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        for (int i = 0; i < dist.size(); ++i)
            dist[i] = (dist[i] - 1) / speed[i];
        priority_queue<int, vector<int>, greater<int>> pq(dist.begin(), dist.end());
        for (int i = 0; i < dist.size(); i++) {
            auto top = pq.top(); pq.pop();
            if (i > top) return i;
        }
        return dist.size();
    }
};