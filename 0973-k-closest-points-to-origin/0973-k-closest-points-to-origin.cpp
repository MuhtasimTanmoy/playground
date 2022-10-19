class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto distance = [](vector<int> &point) -> double {
            auto calc = point[0] * point[0] + point[1] * point[1];
            double val = sqrt(calc);
            return val;
        };
        
        priority_queue<pair<double, vector<int>>> pq;
        for (auto point: points) {
            auto dis = distance(point);
            pq.push(make_pair(-dis, point));
        }
        
        vector<vector<int>> res;
        while(k--) {
            auto item = pq.top(); pq.pop();
            res.push_back(item.second);
        }
        return res;
    }
};