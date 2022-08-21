class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    long long x = (long long)target 
                                - (long long)nums[i]
                                - (long long)nums[j]
                                - (long long)nums[k];
                    
                    if (binary_search(nums.begin() + k + 1, nums.end(), x)) {
                        vector<int> v = {nums[i], nums[j], nums[k], (int)x};
                        ans.insert(v);
                    }
                }
            }
        }
        
        vector<vector<int>> res(ans.begin(), ans.end());
        return res;
    }
};



