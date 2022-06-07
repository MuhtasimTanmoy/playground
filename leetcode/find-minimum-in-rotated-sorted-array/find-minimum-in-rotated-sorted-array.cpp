class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int left = 0;
        int right = size(nums) - 1;
        
        while(left <= right) {
            int mid = left + (right-left)/2;
            int current = nums[mid];
            
            cout<<current<<endl;
            
            if ( mid - 1 >= 0 ? nums[mid-1] > nums[mid] : true 
                && 
                mid + 1 < size(nums) ? nums[mid+1] > nums[mid] : true ) {
                return nums[mid];
            } 
            else if (nums[left] <= current) {
                if (nums[left] < nums[right]) right = mid - 1;
                else left = mid + 1;
            }
            else {
                if (nums[left] < nums[right]) left = mid + 1;
                else right = mid - 1;
            }
        }
        
        return nums[left];
    }
};