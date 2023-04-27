class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        vector<int> st;
        int res = 0;
        for (int i = 0; i < heights.size(); i++) {
            while (st.size() && heights[st.back()] >= heights[i]) {
                auto min_height_so_far = heights[st.back()]; st.pop_back();
                auto l = st.size() ? st.back(): -1;
                res = max(res, min_height_so_far * (i - l - 1));
            }
            st.push_back(i);
        }
        return res;
    }
};