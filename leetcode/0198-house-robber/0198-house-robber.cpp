class Solution {
public:
    int rob(vector<int>& nums) {
        vector<vector<int>> cache(2, vector<int>(100, -1));
        function<int(int, bool)> go = [&](int index, bool prevTaken) {
            if (index == nums.size()) return 0;
            
            if (cache[prevTaken ? 0: 1][index] != -1) 
                return cache[prevTaken ? 0: 1][index];
            
            auto res = 0;
            if (prevTaken == false) {
                auto val = go(index + 1, true) + nums[index];
                res = max(val, res);
            }
            auto skipVal = go(index + 1, false);
            res = max(skipVal, res);
            return cache[prevTaken ? 0: 1][index] = res;
        };
        
        return go(0, false);
    }
};