class Solution {
    bool nextPermutation(vector<int>& s) {
        int i = size(s) - 1;
        if (!i) return false;
        while (s[i-1] >= s[i]) if (--i == 0) return false;

        int j = size(s) - 1;
        while (j > i && s[j] <= s[i-1]) j--;

        std::swap(s[i-1], s[j]);
        std::reverse (s.begin() + i, s.end());
        return true;
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(begin(nums), end(nums));
        vector<vector<int>> result;
        do {
            result.push_back(nums);
        } while (nextPermutation(nums));
        return result;
    }
};