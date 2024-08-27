class Solution {
public:
    int maxProfitAssignment(vector<int>& ds, vector<int>& ps, vector<int>& ws) {
        sort(ws.begin(), ws.end());
        vector<int> idx(ds.size());
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](auto i, auto j) {
            return ds[i] < ds[j];
        });
        int res = 0, i = 0, profit = 0;
        for (auto w: ws) {
            while (i < ds.size() && w >= ds[idx[i]]) profit = max(profit, ps[idx[i]]), i++;
            res += profit;
        }
        return res;
    }
};

// class Solution {
// public:
//     int maxProfitAssignment(vector<int>& difficulty, 
//                             vector<int>& profit, 
//                             vector<int>& worker) {
        
//         vector<pair<int, int>> minusPlus;
//         for (int i = 0; i < difficulty.size(); i++) 
//             minusPlus.emplace_back(profit[i], difficulty[i]);
        
//         sort(minusPlus.begin(), minusPlus.end(), greater<pair<int, int>>());
//         sort(worker.begin(), worker.end(), greater<int>());
        
//         int res = 0;
//         int workerIndex = 0, index = 0;
//         while (workerIndex < worker.size() && index < minusPlus.size())
//             if (worker[workerIndex] >= minusPlus[index].second) {
//                 res += minusPlus[index].first;
//                 workerIndex++;
//             } else index++;
//         return res;
//     }
// };