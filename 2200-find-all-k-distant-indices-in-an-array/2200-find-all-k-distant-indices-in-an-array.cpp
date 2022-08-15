class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> v;
        for(int j = 0; j < nums.size(); j++) 
            if (nums[j] == key)
                v.push_back(j);
        vector<int> ans;
        for (int i = 0; i < nums.size() ; i++)
            for (auto j : v) 
                if (abs(i - j) <= k) {
                    ans.push_back(i);
                    break;
                }
        sort(ans.begin(),ans.end());
        return ans;
    }
};