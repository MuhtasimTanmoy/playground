class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre {1}, post {1};
        for (auto num: nums) 
            pre.push_back(pre.back() * num);
        for (auto i = n - 1; i >= 0; i--) 
            post.push_back(post.back() * nums[i]);
        
        vector<int> res;
        for (auto i = 0; i < n; i++)
            res.push_back(pre[i] * post[n - 1 - i]);
        return res;
    }
};