class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int maxWater = 0;
        
        int left = 0;
        int right = size(height) - 1;
        
        while (left < right) {
            
            int ht = min(height[left], height[right]);            
                
            int width = ( right - left);
                        
            maxWater = max(maxWater, width * ht );
            
            if ( ht == height[left] ) {
                left++;
            } else {
                right--;
            }
        }
        
        return maxWater;
    }
};