class Solution {
public:
    // int sumOfBeauties(vector<int>& nums) {
    //     bool once = false, validEach = true;
    //     for (int i = 1; i < nums.size() - 1; i++) 
    //         if (nums[i-1] < nums[i] && nums[i] < nums[i+1]) once = true;
    //         else validEach = false;
    //     if (validEach) return 2;
    //     else if (once) return 1;
    //     else return 0;
    // }
    
    int sumOfBeauties(vector<int>& nums) {
        int n = nums.size();
        vector<int> minOnRight(n, 0);
        minOnRight[n - 1] = nums[n - 1];

        for(int i = n - 2; i >= 2; i--) 
            minOnRight[i] = min(minOnRight[i + 1], nums[i]);           

        int maxOnLeft = nums[0];
        int ans = 0;
        for(int i = 1; i < n - 1; i++) {
            if (nums[i] > maxOnLeft && nums[i] < minOnRight[i + 1]) ans += 2;
            else if (nums[i] > nums[i - 1] && nums[i] < nums[i + 1]) ans += 1;
            maxOnLeft = max(nums[i], maxOnLeft);
        }

        return ans;
    }
};


