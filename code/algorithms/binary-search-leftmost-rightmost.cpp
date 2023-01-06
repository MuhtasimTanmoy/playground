
int main() {
    int leftmost = -1; 
    int left = 0, right = nums.length - 1;
    while (left <= right) {
        mid = (left + right) / 2; 
        if (nums[mid] < target) {
            left = mid + 1; 
        } else if (nums[mid] > target) {
            right = mid - 1; 
        } else {
            // binary search for leftmost index 
            leftmost = mid; 
            right = mid - 1; 
        }
    }

    left = 0; right = nums.length - 1;
    int rightmost = -1; 
    while (left <= right) {
        mid = (left + right) / 2; 
        if (nums[mid] < target) {
            left = mid + 1; 
        } else if (nums[mid] > target) {
            right = mid - 1; 
        } else {
            // binary search for rightmost index
            rightmost = mid; 
            left = mid + 1; 
        }
    }
}