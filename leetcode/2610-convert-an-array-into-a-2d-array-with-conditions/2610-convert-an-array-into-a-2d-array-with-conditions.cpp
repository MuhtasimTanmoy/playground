class Solution {
public:
//     vector<vector<int>> findMatrix(vector<int>& nums) {
//         vector<int> cnt(201, 0);
//         for (auto num: nums) cnt[num]++;
        
//         vector<vector<int>> res;
//         bool added = true;
//         while (added) {
//             added = false;
//             for (int i = 1; i < cnt.size(); i++)
//                 if (cnt[i] && cnt[i]--) {
//                     if (added) res.back().push_back(i); 
//                     else res.push_back({i});
//                     added = true;
//                 }
//         }
//         return res;
//     }
    
// Runtime: 27 ms, faster than 12.50% of C++ online submissions for Convert an Array Into a 2D Array With Conditions.
// Memory Usage: 30.6 MB, less than 12.50% of C++ online submissions for Convert an Array Into a 2D Array With Conditions.
    
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<int> cnt(201, 0);
        for (auto num: nums) cnt[num]++;
        
        vector<vector<int>> res;
        for (int c = 1; c < cnt.size(); c++) 
            for (int i = 0; i < cnt[c]; i++)
                if (res.size() == i) res.push_back({c});
                else res[i].push_back(c);
        return res;
    }
};