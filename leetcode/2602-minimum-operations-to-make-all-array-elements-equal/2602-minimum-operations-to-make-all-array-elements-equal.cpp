class Solution {
public:
    // vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
    //     vector<long long> res;
    //     for (auto query: queries) {
    //         long long sum = 0;
    //         for (auto num: nums) sum += abs(num - query);
    //         res.push_back(sum);
    //     }
    //     return res;
    // }
    
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        vector<long long> p {0}, res;
        sort(begin(nums), end(nums));
        for (auto num: nums) p.push_back(p.back() + num);
        
        for (auto q: queries) {
            auto mid = upper_bound(nums.begin(), nums.end(), q) - nums.begin();
            long long l = q * mid - p[mid];
            long long r =  (p.back() - p[mid]) - (nums.size() - mid) * q;
            res.push_back(l + r);
        }
        return res;
    }
};