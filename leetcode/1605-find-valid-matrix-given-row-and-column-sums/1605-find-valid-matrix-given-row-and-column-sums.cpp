class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        vector<vector<int>> res(rowSum.size(), vector<int>(colSum.size()));
        for (int i = 0; i < res.size(); i++) 
            for (int j = 0; j < res[0].size() && rowSum[i]; j++) 
                res[i][j] = min(rowSum[i], colSum[j]), 
                rowSum[i] -= res[i][j], 
                colSum[j] -= res[i][j];
        return res;
    }
};