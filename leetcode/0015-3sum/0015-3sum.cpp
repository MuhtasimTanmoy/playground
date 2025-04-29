// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& N) {
//         vector<vector<int>> res;
//         unordered_map<int, int> track;
//         track[N[0]] = 0;
//         for (auto i = 1; i < N.size(); i++) {
//             for (auto j = i + 1; j < N.size(); j++) {
//                 auto to_find = N[i] + N[j];
//                 if (track.count(-to_find)) {
//                     auto idx = track[-to_find];
//                     res.push_back({N[idx], N[i], N[j]});
//                 }
//             }
//             track[N[i]] = i;
//         }
//         return res;
//     }
// };

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i = 0; i < len - 2; i++) {
            if (i && nums[i] == nums[i - 1]) continue;
            auto l = i + 1, r = len - 1;
            while (l < r) {
                auto sum = nums[l] + nums[r] + nums[i];
                if (sum == 0) {
                    res.push_back( {nums[i], nums[l++], nums[r--]} );
                    while (l < r && nums[l] == nums[l - 1]) ++l;
                    while (l < r && nums[r] == nums[r + 1]) r--;
                } else if ( sum > 0 ) r--;
                else l++;
            }
        }
        return res;
    }
};