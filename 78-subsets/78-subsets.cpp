class Solution {
    void traverse(vector<int>& nums, 
                  vector<int>& calc, 
                  vector<vector<int>> &res, 
                  int numberTaken) {
        
        if (numberTaken == size(nums)) {
            res.push_back(calc);
            return;
        }
        
        calc.push_back(nums[numberTaken]);
        traverse(nums, calc, res, numberTaken + 1);
        calc.pop_back();
        traverse(nums, calc, res, numberTaken + 1);
    }
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> calc;
        traverse(nums, calc, res, 0);
        return res;
    }
};