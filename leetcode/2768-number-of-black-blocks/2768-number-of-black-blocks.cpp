class Solution {
public:
    // vector<long long> countBlackBlocks(int m, int n, vector<vector<int>>& coords) {
    //     unordered_set<string> g;
    //     for (auto coord: coords) {
    //         string key = to_string(coord[0]) + "-" + to_string(coord[1]);
    //         g.insert(key);
    //     }
    //     auto check = [&](int x, int y) {
    //         string key = to_string(x) + "-" + to_string(y);
    //         return g.count(key) ? 1: 0;
    //     };
    //     vector<long long> res(5, 0);
    //     for (int i = 1; i < m; i++)
    //         for (int j = 1; j < n; j++) {
    //             auto total = check(i, j) + 
    //                          check(i - 1, j - 1) + 
    //                          check(i - 1, j) + 
    //                          check(i, j - 1);
    //             res[total]++;
    //         }
    //     return res;
    // }
    
    vector<long long> countBlackBlocks(int m, int n, vector<vector<int>>& coords) {
        vector<long long> res{ (m - 1L) * (n - 1), 0, 0, 0, 0};
        unordered_map<long long, int> cnt;
        for (auto c: coords) 
            for (int i = c[0]; i < c[0] + 2; i++)
                for (int j = c[1]; j < c[1] + 2; j++)
                    if (0 < i && i < m && 0 < j && j < n) {
                        auto idx = i * 100000L + j;
                        res[cnt[idx]]--;
                        cnt[idx]++;
                        res[cnt[idx]]++;
                    }
        return res;
    }
};