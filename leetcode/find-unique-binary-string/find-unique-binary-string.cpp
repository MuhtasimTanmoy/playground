class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        
        int n = size(nums);
        
        string res;
        res.resize(n);
        
        for(int i = 0; i < size(nums); i++)
            res[i] = nums[i][i] == '0' ? '1' : '0';
        
        return res;
    }
};