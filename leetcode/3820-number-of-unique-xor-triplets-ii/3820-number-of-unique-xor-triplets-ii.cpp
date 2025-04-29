class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> st, st2;
        int n = nums.size();
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < n; j++) 
                st2.insert(nums[i] ^ nums[j]);
        for (int x : st2) 
            for (int num : nums)
                st.insert(x ^ num);
        return st.size();
    }
};