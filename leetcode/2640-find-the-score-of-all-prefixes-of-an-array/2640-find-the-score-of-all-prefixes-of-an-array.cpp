class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        vector<long long> res;
        long long max_so_far = 0, prev = 0;
        for (auto num: nums) {
            max_so_far = max(max_so_far, 1LL* num);
            res.push_back(0LL +num + max_so_far + prev);
            prev = res.back();
        }
        return res;
    }
};