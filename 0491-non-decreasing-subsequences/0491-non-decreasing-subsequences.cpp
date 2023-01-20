// class Solution {
// public:
//     vector<vector<int>> findSubsequences(vector<int>& nums) {
//         set<vector<int>> res;
//         vector<int> curr;
//         function<void(int)> go = [&](auto index) {
//             if (index == nums.size()) return;
//             if (curr.empty() || curr.back() <= nums[index]) curr.push_back(nums[index]);
//             if (curr.size() > 1) res.insert(curr);
//             go(index + 1);
//             if (curr.size()) curr.pop_back();
//             go(index + 1);
//         };
//         go(0);
//         return vector<vector<int>>(res.begin(), res.end());
//     }
// };

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> result;
        vector<int> sequence;
        function<void(int)> backtrack;
        backtrack = [&nums, &sequence, &result, &backtrack](int index) -> void {
            if (index == nums.size()) {
                if (sequence.size() >= 2) result.insert(sequence);
                return;
            }
            if (sequence.empty() || sequence.back() <= nums[index]) {
                sequence.push_back(nums[index]);
                backtrack(index + 1);
                sequence.pop_back();
            }
            backtrack(index + 1);
        };
        backtrack(0);
        return vector(result.begin(), result.end());
    }
};