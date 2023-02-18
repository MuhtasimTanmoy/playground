class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> res;
        for (auto num: nums) {
            auto numStr = to_string(num);
            for (auto c: numStr) res.push_back(c - '0');
        }
        return res;
    }
};