class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> pairList;
        int index = 0;
        for (auto row: mat) {
            int left = 0, right = row.size() - 1, res = -1;
            while (left <= right) {
                auto mid = left + (right - left) / 2;
                if (row[mid]) res = mid, left = mid + 1; else right = mid - 1;
            }
            pairList.push_back({res == -1 ? 0: res + 1, index++});
        }
        sort(pairList.begin(), pairList.end());
        vector<int> res(k, 0);
        for (int i = 0; i < res.size(); i++) res[i] = pairList[i].second;
        return res;
    }
};