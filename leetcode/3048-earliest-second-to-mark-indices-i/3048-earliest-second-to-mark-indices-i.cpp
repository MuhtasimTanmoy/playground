class Solution {
public:
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& cis) {
        auto can = [&](auto m) {
            unordered_map<int, int> last;
            for (auto i = 0; i < m; i++) last[cis[i]] = i;
            if (last.size() != nums.size()) return false;
            
            int cnt = 0;
            for (auto i = 0; i < m; i++)
                if (i == last[cis[i]]) {
                    if (cnt < nums[cis[i] - 1]) return false;
                    cnt -= nums[cis[i] - 1];
                } else cnt++;
            return true;
        };
        
        int l = 0, r = cis.size() + 1;
        while (l < r) {
            auto m = (l + r) / 2;
            if (can(m)) r = m; else l = m + 1;
        }
        return r == cis.size() + 1 ? -1 : r;
    }
};  