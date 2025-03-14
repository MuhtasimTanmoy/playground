class Solution {
public:
   vector<int> dfs(vector<int> &nums, vector<int> &arr, int p) {    
        if (p == arr.size()) return arr;
        if (arr[p] != 0) return dfs(nums, arr, p + 1);
        for (int i = nums.size() - 1; i >= 1; --i) {
            int dist = i == 1 ? 0 : i;
            if (nums[i] != 0 && dist + p < arr.size() && arr[dist + p] == 0) {
                arr[p] = arr[p + dist] = i;
                nums[i] = 0;
                auto res = dfs(nums, arr, p + 1);
                if (res.size()) return res;
                nums[i] = 1;
                arr[p] = arr[p + dist] = 0;
            }
        }
        return {};
    }
    vector<int> constructDistancedSequence(int n) {
        vector<int> arr((n - 1) * 2 + 1), nums(n + 1, 1);
        return dfs(nums, arr, 0);     
    }
};