class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> cnt, len;
        for (auto &num: nums) ++cnt[num];
        for (auto &num: nums) {
            if (!cnt[num]) continue;
            --cnt[num];
            
            if (len[num]) {
                --len[num];
                ++len[num + 1];
            } else if (cnt[num + 1] && cnt[num + 2]) {
                --cnt[num + 1];
                --cnt[num + 2];
                ++len[num + 3];
            } else return false;
        }
        return true;
    }
};