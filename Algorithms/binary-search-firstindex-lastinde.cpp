class Solution {
    
    int getFirst(vector<int>& nums, int target) {
        int first = 0;
        int last = size(nums) - 1;
        int res = -1;
        while(first <= last) {
            int mid = first + ( (last - first) >> 1 );
            if (nums[mid] > target) last = mid - 1;
            else if (nums[mid] < target) first = mid + 1;
            else { res = mid; last = mid - 1; }
        }
        return res;
    }
    
    int getLast(vector<int>& nums, int target) {
        int first = 0;
        int last = size(nums) - 1;
        int res = -1;
        while(first <= last) {
            int mid = first + ( (last - first) >> 1 );
            if (nums[mid] > target) last = mid - 1;
            else if (nums[mid] < target) first = mid + 1;
            else { res = mid; first = mid + 1; }
        }
        return res;
    }
    
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = getFirst(nums, target);
        int right = getLast(nums, target);
        return {left, right};
    }
};