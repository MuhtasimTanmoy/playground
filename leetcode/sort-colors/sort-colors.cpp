class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0;
        int two = size(nums) - 1;
        
        for(int i = 0; i < size(nums);) {
            if (nums[i] == 1) i++;
            else if (nums[i] == 0) swap(nums[i++], nums[zero++]);
            else if (nums[i] == 2 && i < two) swap(nums[two--], nums[i]);
            else break;
        }
    }
};