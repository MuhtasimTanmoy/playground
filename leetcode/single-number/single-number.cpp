class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int target = 0;
        
        for(int i: nums){
            target^=i;
        }
        return target;
    }
};