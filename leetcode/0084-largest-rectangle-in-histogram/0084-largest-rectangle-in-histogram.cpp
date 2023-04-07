class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        h.push_back(0);
        vector<int> stk;
        int res = 0;
        for (int i = 0; i < h.size(); i++) {
            while (stk.size() && h[i] < h[stk.back()]) {
                auto m = stk.back(), min_val = h[m]; stk.pop_back();
                auto w = i - (stk.size() ? stk.back(): -1);
                res = max(res, min_val * (w - 1));
            }
            stk.push_back(i);
        }
        return res;
    }
};