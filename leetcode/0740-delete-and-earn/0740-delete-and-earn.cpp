/*
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<pair<int, int>> wn;
        
        sort(nums.begin(), nums.end());
        for (auto num: nums) 
            if (wn.empty() || wn.back().first != num) wn.push_back({num, 1});
            else wn.back().second++;
        
        sort(wn.begin(), wn.end(), [](auto l, auto r) {
            return l.first * l.second > r.first * r.second; 
        });
        
        for (auto [val, count]: wn) cout<<val<<" - "<<count<<endl;
        
        int res = 0;
        unordered_set<int> bag;
        for (auto [val, count]: wn) {
            if (bag.count(val + 1)) continue;
            if (bag.count(val - 1)) continue;
            bag.insert(val);
            res += val * count;
        }
        return res;
    }
};
*/

/*
There are two characteristics of this problem that hint towards the use of dynamic programming (DP). The first is that the problem is asking us to find the maximum of something. The second is that we need to make decisions on which numbers to take, and each decision may influence future decisions. For example, if we wanted to take all the fives, then we can no longer take the fours or sixes.
*/

// class Solution {
// public:
//     int deleteAndEarn(vector<int>& nums) {
//         unordered_map<int, int> um;
//         for (auto num: nums) um[num]++;
        
//         int take = 0, skip = 0;
//         for (int i = 1; i < 10001; i++) {
//             auto taking = skip + um[i] * i;
//             skip = max(take, skip);
//             take = taking;
//         } 
//         return take;
//     }
// };

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = 10001;
        vector<int> values(n, 0);
        for (int num : nums)
            values[num] += num;

        int take = 0, skip = 0;
        for (int i = 0; i < n; i++) {
            int takei = skip + values[i];
            skip = max(skip, take);
            take = takei;
        }
        return max(take, skip);
    }
};

