class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int area = 0;
        while(left < right) {
            auto minHeight = min(height[left], height[right]);
            area = max(area, (right-left) * minHeight);
            if (height[left] > height[right]) {
                right--;
            } else left++;
        }
        return area;
    }
};