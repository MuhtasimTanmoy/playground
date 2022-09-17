class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_set<int> bag;
        for (int i = 1; i < nums.size(); i++) {
            auto sum = nums[i-1] + nums[i];
            if (bag.count(sum)) return true;
            else bag.insert(sum);
        }
        return false;
    }
};

// bool findSubarrays(vector<int>& nums) {
//     unordered_set<int> s;
//     for (int i = 1; i < nums.size(); ++i)
//         if(!s.insert(nums[i - 1] + nums[i]).second)
//             return true;
//     return false;
// }