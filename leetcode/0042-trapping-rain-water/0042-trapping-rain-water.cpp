class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0, current = 0;
        stack<int> st;
        while (current < height.size()) {
            while (st.size() && height[current] > height[st.top()]) {
                auto top = st.top(); st.pop();
                if (st.empty()) break;
                auto distance = current - st.top() - 1;
                auto bounded_height = min(height[current], height[st.top()]) - height[top];
                ans += distance * bounded_height;
            }
            st.push(current++);
        }
        return ans;
    }
};