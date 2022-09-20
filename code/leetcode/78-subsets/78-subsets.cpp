class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        function<void(vector<int>&, int)> traverse = [&](vector<int>& li, int index) {
            if (index == size(nums)) {
                res.push_back(li);
                return;
            }
            li.push_back(nums[index]);
            traverse(li, index + 1);
            li.pop_back();
            traverse(li, index + 1);
        };
        vector<int> test;
        traverse(test, 0);
        return res;
    }
};