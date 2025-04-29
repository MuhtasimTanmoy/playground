
// 725 / 759 testcases passed

// class Solution {
// public:
//     long long minimumCost(vector<int>& N, vector<int>& C, int k) {
        
//         vector<long long> pre_sum = {0}, pre_cost = {0};
//         for (auto n: N) pre_sum.push_back(pre_sum.back() + n);
//         for (auto c: C) pre_cost.push_back(pre_cost.back() + c);

//         int len = N.size();
//         vector<vector<vector<long long>>> dp(len, 
//                                              vector<vector<long long>>(len, 
//                                              vector<long long>(len, -1)));

//         function<long long(int, int, int)> go = [&](auto i, auto pci, auto order) -> long long {
            
//             if (i == N.size() - 1)
//                 return ( pre_sum[i + 1] + order * k ) * ( pre_cost[i + 1] - pre_cost[pci] );
            
//             if (dp[i][pci][order] != -1) return dp[i][pci][order];

//             long long total = ( pre_sum[i + 1] + order * k ) 
//                             * ( pre_cost[i + 1] - pre_cost[pci] );

//             long long devide = total + go(i + 1, i + 1 ,order + 1),
//                       no_devide = go(i + 1, pci, order);

//             return dp[i][pci][order] = min(devide, no_devide);
//         };

//         return go(0, 0, 1);

//     }
// };



class Solution {
public:
    long long minimumCost(vector<int>& N, vector<int>& C, int K) {
        int n = N.size();

        vector<long long> sn = {0}, sc = {0};
        for (auto n: N) sn.push_back(sn.back() + n);
        for (auto c: C) sc.push_back(sc.back() + c);

        vector<long long> f(n + 1, 1e18);
        f[0] = 0;
        for (int i = 1; i <= n; i++) for (int j = 0; j < i; j++) {
            long long t = sn[i] * (sc[i] - sc[j]) + K * (sc[n] - sc[j]);
            f[i] = min(f[i], f[j] + t);
        }

        return f[n];
    }
};
