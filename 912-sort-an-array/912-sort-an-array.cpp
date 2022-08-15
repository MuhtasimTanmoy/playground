class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        divide(0, nums.size()-1, nums);
        return nums;
    }
    
    void divide(int start, int end, vector<int> &nums) {
        if (start < end) {
            int mid = partition(start, end, nums);
            divide(start, mid-1, nums);
            divide(mid+1, end, nums);
        }
    }
    
    int partition(int start, int end, vector<int> &nums) {
        int pivot = random() % (end-start+1) + start, idx = start-1;
        swap(nums[pivot], nums[end]);
        for (int i = start; i < end; ++i)
            if (nums[i] < nums[end])
                swap(nums[++idx], nums[i]);
        swap(nums[++idx], nums[end]);
        return idx;
    }
};