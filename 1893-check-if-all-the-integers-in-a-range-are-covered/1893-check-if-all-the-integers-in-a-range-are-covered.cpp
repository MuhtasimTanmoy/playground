class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<int> rangemark(51, 0);
        for (auto range: ranges)
            for (int i = range[0]; i <= range[1]; i++)
                rangemark[i] = 1;    
        for (int i = left; i <= right; i++) if (!rangemark[i]) return false;
        return true;
    }
};