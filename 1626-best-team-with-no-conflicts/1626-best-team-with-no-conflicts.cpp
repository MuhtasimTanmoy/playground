// class Solution {
// public:
//     int bestTeamScore(vector<int>& scores, vector<int>& ages, int res = 0, int maxSoFar = 0) {
//         vector<vector<int>> ageToScore(1001, vector<int>{});
        
//         for (int i = 0; i < ages.size(); i++) {
//             auto age = ages[i], score = scores[i];
//             ageToScore[age].push_back(score);
//         }
        
//         for (auto row: ageToScore)
//             for (auto elem: row) {
//                 if (elem < maxSoFar) continue;
//                 res += elem;
//                 maxSoFar = max(maxSoFar, elem);
//             }
                
//         return res;
//     }
// };


// class Solution {
// public:
//     int bestTeamScore(vector<int>& scores, vector<int>& ages) {
//         vector<pair<int, int>> g;
//         for (int i = 0; i < scores.size(); i++) g.push_back({scores[i], ages[i]});
//         sort(g.begin(), g.end());
        
//         unordered_map<string, int> dp;
//         auto key = [](int a, int b) { return to_string(a) + "-" + to_string(b); };
//         function<int(int, int)> go = [&](auto index, auto prev) {
//             if (index == g.size()) return 0;
//             auto k = key(index, prev);
//             if (dp.count(k)) return dp[k];
//             auto calc = go(index + 1, prev);
//             if (g[index].second >= prev) 
//                 calc = max(calc, g[index].first + go(index + 1, g[index].second));
//             return dp[k] = calc;
//         };
//         return go(0, 0);
//     }
// };

class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>> arr;
        vector<int> ans ((int) scores.size(), 0);
        for(int i = 0; i < scores.size(); i++) arr.push_back({ages[i], scores[i]});
        sort(arr.begin(), arr.end());
        
        int best = 0;
        for(int i = 0; i < arr.size(); i++) {
            ans[i] = arr[i].second; 
            for(int j = 0; j < i; j++)
                if (arr[i].second >= arr[j].second) 
                    ans[i] = max(ans[i], ans[j] + arr[i].second);
            best = max(best, ans[i]);
        }
        return best;
    }
};