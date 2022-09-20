class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = size(numbers) - 1;
        
        while(left < right) {
            int calculated = numbers[left] + numbers[right];
            if (calculated == target) 
                return { left + 1, right + 1 };
            else if (calculated > target) right--;
            else left++;
        }
        
        return {-1, -1};
    }
};