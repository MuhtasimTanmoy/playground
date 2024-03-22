// class Solution {
// public:
//     vector<int> leftmostBuildingQueries(vector<int>& hs, vector<vector<int>>& qs) {
//         vector<int> res;
//         for (auto q: qs) {
//             auto alice = q.front(), bob = q.back();
//             if (alice == bob) {
//                 res.push_back(alice);
//                 continue;
//             }
            
//             auto max_in_two = max(hs[alice], hs[bob]), max_i = max(alice, bob), now = -1;
//             if (hs[max_i] == max_in_two && hs[alice] != hs[bob]) {
//                 res.push_back(max_i);
//                 continue;
//             }
            
//             for (auto i = max_i + 1; i < hs.size(); i++) 
//                 if (hs[i] > max_in_two) {
//                     now = i;
//                     break;
//                 }
//             res.push_back(now);
//         }
//         return res;
//     }
// };


class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& A, vector<vector<int>>& queries) {
        int n = A.size(), qn = queries.size();
        vector<vector<vector<int>>> que(n);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> h;
        vector<int> res(qn, -1);
        for (int qi = 0; qi < qn; qi++) {
            int i = queries[qi][0], j = queries[qi][1];
            if (i < j && A[i] < A[j]) res[qi] = j;
            else if (i > j && A[i] > A[j]) res[qi] = i;
            else if (i == j) res[qi] = i;
            else que[max(i, j)].push_back({max(A[i], A[j]), qi});
        }
        for (int i = 0; i < n; i++) {
            while (h.size() && h.top()[0] < A[i]) res[h.top()[1]] = i,  h.pop();
            for (auto& q : que[i]) h.push(q);
        }
        return res;
    }
};