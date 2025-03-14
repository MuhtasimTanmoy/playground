class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size(), res = 0;
        unordered_map<int,int> umap;
        for(int i = 0 ; i < n ; ++i)
            for(int j = 0 ; j < i ; ++j) {
                int prod = nums[i] * nums[j];
                res += 8 * umap[prod];
                ++umap[prod];
            }
        return res;
    }
};