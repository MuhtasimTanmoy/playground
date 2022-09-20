class NumArray {
    vector<int> prefixSum;
public:
    NumArray(vector<int>& nums) {
        prefixSum.resize(size(nums), 0);
        prefixSum[0] = nums[0];
        for(int i = 1; i < size(nums); i++)
            prefixSum[i] = nums[i] + prefixSum[i-1];
    }
    
    int sumRange(int left, int right) {
        return prefixSum[right] - ( left == 0 ? 0 : prefixSum[left-1] );
    }
};