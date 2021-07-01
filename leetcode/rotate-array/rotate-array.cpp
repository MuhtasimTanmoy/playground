class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        vector<int> cache = nums;
        auto swapWithOffset = [&](int first) {
            int num = cache[first];
            int replaceToIndex = (first + k ) % nums.size();
            nums[ replaceToIndex ] = num;
        };
        
        for( int i = 0; i< nums.size(); i++) {
            swapWithOffset(i);
        }
    }
};