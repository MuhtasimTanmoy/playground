// class Solution {
// public:
//     vector<vector<int>> kSmallestPairs(vector<int>& l, vector<int>& r, int k) {
//         vector<vector<int>> res;
//         for (int j = 0; j < min(k, (int) l.size()); j++)
//             for (int m = 0; m < min(k, (int) r.size()); m++)
//                 res.push_back({l[j], r[m]});
//         sort(res.begin(), res.end(), [](auto l, auto r) {
//             return (l[0] + l[1]) < (r[0] + r[1]);
//         }); 
//         res.resize(min(k, (int) res.size()));
//         return res;
//     }
// };

typedef pair<int, pair<int, int>> wp;
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& l, vector<int>& r, int k) {
        vector<vector<int>> ans;
        priority_queue<wp, vector<wp>, greater<wp>> pq;
        for (int i = 0; i < r.size(); i++)
            pq.push({l[0] + r[i], {0, i}});
        while (pq.size() && k--) {
            auto top = pq.top().second; pq.pop();
            auto x = top.first, y = top.second;
            ans.push_back({l[x], r[y]});
            if (x < (l.size() - 1))
                pq.push({l[x+1] + r[y], {x+1, y}});
        }
        return ans;
    }
};