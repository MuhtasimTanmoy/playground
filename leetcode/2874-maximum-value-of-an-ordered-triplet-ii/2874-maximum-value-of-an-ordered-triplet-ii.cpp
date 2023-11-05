class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        vector<int> st;
        st.push_back(0);
        
        long long res = 0;
        for (int i = 2, max_so_far = 0; i < nums.size(); i++) {
            auto mid = nums[i - 1];
            while (st.size() && nums[st.back()] < mid) st.pop_back();
            max_so_far = max(max_so_far, st.size() ? nums[st.front()] - mid: 0);
            res = max(res, 1LL * max_so_far * nums[i]);
            st.push_back(i - 1);
        }
        return res;
    }
};