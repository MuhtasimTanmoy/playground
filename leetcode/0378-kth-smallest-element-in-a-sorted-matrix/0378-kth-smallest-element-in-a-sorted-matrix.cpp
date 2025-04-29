// class Solution {
// public:
//     int kthSmallest(vector<vector<int>>& M, int k) {
//         priority_queue<int> que;
//         for(auto col: M)
//             for(auto item: col) {
//                 que.push(item);
//                 if (que.size() > k) que.pop();
//             }
//         return que.top();
//     }
// };


class Solution {
public:
    int kthSmallest(vector<vector<int>>& M, int k) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        for (auto i = 0; i < M.size(); i++) pq.push({M[i][0], i, 0});
        int res = 0;
        while (k--) {
            auto top = pq.top(); pq.pop();
            res = top.front();
            if (top.back() + 1 < M.back().size())
                pq.push({M[top[1]][top.back() + 1], top[1], top.back() + 1});
        }
        return res;
    }
};



// [[1, 5, 9]
// [10,11,13]
// [12,13,15]]