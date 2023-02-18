class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> pre(n + 1, 0);
        for (int i = 1; i < pre.size(); i++) 
            pre[i] = pre[i-1] + nums[i-1];
        
        vector<int> res(n, 0);
        for (int i = 0; i < n; i++) {
            auto left = i * nums[i] - pre[i];
            auto right = pre[n] - pre[i + 1] - (n - i - 1) * nums[i];
            res[i] =  left + right;
        }
        return res;
    }
};
