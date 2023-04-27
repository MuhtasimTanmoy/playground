class Solution {
public:
    int largestRectangleArea(vector<int>& histo) {
        stack<int> st;
        int maxA = 0, n = histo.size();
        for (int i = 0; i <= n; i++) {
            while (st.size() && (i == n || histo[st.top()] >= histo[i])) {
                int height = histo[st.top()]; st.pop();
                int width = st.empty() ? i: i - st.top() - 1;
                maxA = max(maxA, width * height);
            }
            st.push(i);
        }
        return maxA;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxiArea = 0, n = matrix.size(), m = matrix[0].size();
        vector<int> height(m, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) 
                if (matrix[i][j] == '1') height[j]++; else height[j] = 0;
            int area = largestRectangleArea(height);
            maxiArea = max(maxiArea, area);
        }
        return maxiArea;
    }
};