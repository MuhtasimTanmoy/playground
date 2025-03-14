class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string res = nums[0];
        for(int i = 0; i < size(nums); i++) 
            res[i] = nums[i][i] == '0' ? '1' : '0';
        return res;
    }
};