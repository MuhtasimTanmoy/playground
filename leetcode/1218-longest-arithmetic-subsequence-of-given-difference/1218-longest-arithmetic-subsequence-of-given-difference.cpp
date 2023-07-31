// class Solution {
// public:
//     int longestSubsequence(vector<int>& nums, int diff) {
//         auto gen_key = [](int a, int b, int c) {
//             return to_string(a) + "-" + to_string(b) + "-" + to_string(c);
//         };
//         unordered_set<string> um;
//         int n = nums.size(), res = 0;
//         function<void(int, int, int)> go = [&](auto i, auto target, int sum) {
//             if (i == n) {
//                 res = max(res, sum);
//                 return;
//             }
//             auto key = gen_key(i, target, sum);
//             if (um.count(key)) return;
//             int res = 0;
//             if (nums[i] == target)
//                 go(i + 1, nums[i] + diff, sum + 1);
//             else 
//                 go(i + 1, target, sum),
//                 go(i + 1, nums[i] + diff, 1);
//             um.insert(key);
//         };
//         go(0, nums[0], 0);
//         return res;
//     }
// };

class Solution {
public:
    int longestSubsequence(vector<int>& nums, int diff) {
        unordered_map<int, int> counter;
        int res = 0;
        for (auto num: nums) {
            if (counter.count(num - diff))
                counter[num] = counter[num - diff] + 1;
            else
                counter[num] = 1;
            res = max(res, counter[num]);
        }
        return res;
    }
};