class Solution {
public:
//     int minimizeMax(vector<int>& nums, int p) {
//         sort(nums.begin(), nums.end());
//         for (auto num: nums) cout<<num<<" ";
//         int res = 0;
//         while (p--) {
//             int min_diff = INT_MAX;
//             pair<int, int> found;
//             for (int i = 0, prev_index = -1; i < nums.size(); i++) {
//                 if (nums[i] == -1) continue;
//                 if (prev_index != -1) {
//                     auto diff = nums[i] - nums[prev_index];
//                     if (diff < min_diff) 
//                         min_diff = diff,
//                         found = {i, prev_index};
//                 }
//                 prev_index = i;
//             }
//             res = max(min_diff, res);
//             auto [i, j] = found;
//             nums[i] = -1;
//             nums[j] = -1;
//         }
//         return res;
//     }
    
    int minimizeMax(vector<int>& n, int p) {
        sort(begin(n), end(n));
        int l = 0, r = n.back() - n.front();
        while (l < r) {
            int m = (l + r) / 2, cnt = 0;
            for (int i = 0; i + 1 < n.size(); ++i)
                if (m >= (n[i + 1] - n[i])) 
                    ++cnt,
                    ++i;
            if (cnt >= p) r = m;
            else l = m + 1;
        }
        return l;
    }
};