class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pre(n, 1), post(n, 1);
        
        for (auto i = 1; i < n; i++)
            if (nums[i - 1] < nums[i]) pre[i] = 1; 
            else pre[i] = pre[i - 1] + 1;
        
        for (auto i = n - 2; i >= 0; i--)
            if (nums[i + 1] < nums[i]) post[i] = 1; 
            else post[i] = post[i + 1] + 1;
        
        vector<int> res;
        for (int i = k; i < n - k; i++) 
            if (pre[i - 1] >= k && post[i + 1] >= k) 
                res.push_back(i);
        
        return res;
    }
};