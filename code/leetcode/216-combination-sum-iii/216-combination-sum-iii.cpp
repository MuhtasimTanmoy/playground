class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        function<void(vector<int>&, int, int)> combination = [&](vector<int>& curr, int left, int num) {
            if (left < 0) return;
            auto sum = accumulate(curr.begin(), curr.end(), 0);
            if (sum > n) return;
            if (left == 0 && sum == n) {
                res.push_back(curr);
                return;
            }
            for (int i = num; i < 10; i++) {
                curr.push_back(i);
                combination(curr, left - 1, i + 1);
                curr.pop_back();
            }
        };
        vector<int> test;
        combination(test, k, 1);
        return res;
    }
};