/*
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size(), ramp = 0;
        for (auto i = 0; i < n - 1; i++) 
            for (int j = n - 1; n > i; j--) {
                if (j - i < ramp) break;
                if (nums[j] >= nums[i]) ramp = j - i;
            }
        return ramp;
    }
};


// 6,0,8,2,1,5
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int res = -1;
        vector<int> stk;
        for (auto i = 0; i < nums.size(); i++) {
            cout<<i<<endl;
            while (stk.size() && nums[stk.back()] <= nums[i]) 
                stk.pop_back();
            cout<<i<<endl;
            if (stk.size()) res = max(res, i - stk.back()));
            cout<<i<<endl;
            stk.push_back(i);
        }
        return res;
    }
};
*/


// https://leetcode.com/problems/maximum-width-ramp/discuss/208348/JavaC%2B%2BPython-O(N)-Using-Stack


class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int res = 0, n = nums.size();
        vector<int> stk;
        for (auto i = 0; i < n; i++) 
            if (stk.empty() || nums[stk.back()] > nums[i])
                stk.push_back(i);
        for (int i = n - 1; i > res; --i) 
            while (stk.size() && nums[stk.back()] <= nums[i]) 
                res = max(res, i - stk.back()),
                stk.pop_back();
        return res;
    }
};