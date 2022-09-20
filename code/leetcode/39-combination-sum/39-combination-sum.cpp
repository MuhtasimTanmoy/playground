class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        function<void(vector<int>, int)> combination = [&](vector<int> elems, int index) {
            auto elemSum = accumulate(elems.begin(), elems.end(), 0);
            if (elemSum > target) return;
            if (elemSum == target) res.push_back(elems);
            for (int i = index; i < candidates.size(); i++) {
                auto candidate = candidates[i];
                elems.push_back(candidate);
                combination(elems, i);
                elems.pop_back();
            }
        };
        combination({}, 0);
        return res;
    }
};