class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> res;
        function<void(vector<int>&, int)> traverse = [&](vector<int>& li, int index) {
            if (index == size(nums)) {
                res.insert(li);
                return;
            }
            li.push_back(nums[index]);
            traverse(li, index + 1);
            li.pop_back();
            traverse(li, index + 1);
        };
        vector<int> test;
        traverse(test, 0);
        
        vector<vector<int>> last;
        for (auto v: res) last.push_back(v);
        return last;
    }
};