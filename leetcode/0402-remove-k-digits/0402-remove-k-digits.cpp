class Solution {
public:
    string removeKdigits(string nums, int k) {
        int n = nums.size();
        string res;
        deque<char> st;
        for (auto i = 0; i < nums.size(); i++) {
            while (st.size() && st.back() > nums[i]) st.pop_back();
            st.push_back(nums[i]);
            if (i >= k) res += st.front(), st.pop_front();
        }
        int to = 0;
        while (res[to] == '0') to++;
        auto ans = res.substr(to);
        return ans.empty() ? "0": ans;
    }
};