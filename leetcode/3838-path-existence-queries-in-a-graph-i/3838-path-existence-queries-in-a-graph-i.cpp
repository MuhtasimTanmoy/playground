// 533 / 550 testcases passed

// class Solution {
// public:
//     vector<bool> pathExistenceQueries(int n, 
//                                       vector<int>& N, 
//                                       int MAX_DIFF, 
//                                       vector<vector<int>>& Q) {
        
//         unordered_map<int, vector<int>> G;
//         for (auto i = 0; i < N.size() - 1; i++)
//             for (auto j = i + 1; j < N.size(); j++) {
//                 auto diff = abs(N[i] - N[j]);
//                 if (diff > MAX_DIFF) continue;
//                 G[i].push_back(j);
//                 G[j].push_back(i);
//             }
        
//         unordered_set<int> visited;
//         function<void(int, set<int>&)> go = [&](auto i, auto& now) {
//             visited.insert(i);
//             now.insert(i);
//             for (auto to: G[i]) if (!visited.count(to)) go(to, now);
//         };
        
//         vector<set<int>> groups;
//         for (auto i = 0; i < n; i++) {
//             set<int> now;
//             if (!visited.count(i)) go(i, now);
//             groups.push_back(now);
//         }

//         for (auto i = 0; i < Q.size(); i++) 
//             Q[i].push_back(i);

//         vector<bool> res(Q.size(), false);
//             for (auto group: groups) {
//                 vector<vector<int>> next;
//                 for (auto i = 0; i < Q.size(); i++) {
//                     auto q = Q[i];
//                     auto from = q.front(), to = q[1], index = q.back();
//                     if (group.count(from) && group.count(to)) res[index] = true;
//                     else next.push_back(q);
//                 }
//                 Q = next;
//             }
//         return res;
//     }
// };

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, 
                                    vector<int>& nums, 
                                    int maxDiff, 
                                    vector<vector<int>>& queries) {
        vector<int> cuts = {0};
        for (int i = 1; i < n; ++i) 
            if (nums[i] - nums[i - 1] > maxDiff) 
                cuts.push_back(i);

        vector<bool> res;
        for (auto& q : queries)
            res.push_back(upper_bound(cuts.begin(), cuts.end(), q[0]) 
                          == upper_bound(cuts.begin(), cuts.end(), q[1]));
        return res;
    }
};