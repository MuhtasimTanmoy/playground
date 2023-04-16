class Solution {
public:
    // Failed attempt
    // int findSmallestInteger(vector<int>& nums, int v, int mex = 0) {
    //     for (auto &num: nums) 
    //         if (num >= 0) num %= v;
    //         else {
    //             num = v - abs(num) % v;
    //         }
    //     sort(nums.begin(), nums.end());
    //     for (auto num: nums) 
    //         if (num == mex) mex++;
    //         else if (num > mex) return mex;
    //     return mex;
    // }
    
    int findSmallestInteger(vector<int>& nums, int v) {
        int m[100001] = {}, sz = nums.size();
        for (auto n : nums)
            // C++ fix for negative remainder: (b + (a % b)) % b
            ++m[(v + n % v) % v];
        for (int i = 0; i < sz; ++i)
            if (--m[i % v] < 0)
                return i;
        return sz;
    }
};