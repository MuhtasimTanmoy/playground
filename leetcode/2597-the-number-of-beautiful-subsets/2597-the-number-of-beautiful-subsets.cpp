// class Solution {
// public:
//     int beautifulSubsets(vector<int>& nums, int k) {
//         unordered_multiset<int> bag;
//         int res = 0;
//         for (auto l = 0, r = 0; r < nums.size(); r++) {
//             auto on_l = nums[r] + k, on_r = nums[r] - k;
//             while (bag.count(on_l) || bag.count(on_r))
//                    bag.erase(bag.find(nums[l++]));
//             res += r - l + 1;
//             bag.insert(nums[r]);
//         }
//         return res;
//     }
// };


// class Solution {
// public:
//     int beautifulSubsets(vector<int>& nums, int k) {
//         unordered_map<int, int> counter;
//         int res = 0;
//         for (auto i = 0; i < nums.size(); i++) {
//             auto find_l = nums[i] - k, find_r = nums[i] + k;
            
//             int deduct = 0;
//             if (counter.count(find_l)) deduct += counter[find_l];
//             if (counter.count(find_r)) deduct += counter[find_r];
            
//             res += i + 1 - deduct;
//             cout<<res<<endl;
//             counter[nums[i]]++;
//         }
//         return res;
//     }
// };


class Solution {
public:
    int beautifulSubsets(vector<int>& N, int k) {
        unordered_map<int, int> counter;
        int n = N.size();
        function<int(int)> go = [&](auto i) {
            if (i == n) return 1;
            int res = go(i + 1);
            if (!counter[N[i] + k] && !counter[N[i] - k]) 
                counter[N[i]]++,
                res += go(i + 1),
                counter[N[i]]--;
            return res;
        };
        return go(0) - 1;
    }
};