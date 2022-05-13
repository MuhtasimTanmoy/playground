class Solution {
    
    // https://stackoverflow.com/questions/11483060/stdnext-permutation-implementation-explanation

    // https://www.techiedelight.com/std_next_permutation-overview-implementation

    // 1 2 3 4
    // 1 2 4 3
    // 1 3 2 4
    // 1 3 4 2
    // 1 4 2 3
    // 1 4 3 2
    // 2 1 3 4
    
    bool nextPermutation(vector<int>& nums) {
        
        int lastIndex = size(nums) - 1;
        if (!lastIndex) return false;
        
        while(nums[lastIndex-1] >= nums[lastIndex]) 
            if(--lastIndex == 0) return false;
        
        int toSwapWith = size(nums) - 1;
        while(toSwapWith >lastIndex 
              && nums[lastIndex - 1] >= nums[toSwapWith]) toSwapWith--;
        
        swap(nums[lastIndex - 1], nums[toSwapWith]);
        reverse(nums.begin() + lastIndex, nums.end());
        return true;
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(begin(nums), end(nums));
        vector<vector<int>> result;
        do {
            result.push_back(nums);
        } while (nextPermutation(nums));
        return result;
    }
};