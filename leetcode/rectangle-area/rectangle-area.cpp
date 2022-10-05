class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, 
                    int bx1, int by1, int bx2, int by2) {
        
        int a = (ax2 - ax1) * (ay2 - ay1);
        int b = (bx2 - bx1) * (by2 - by1);
        
        auto hasIntersection = [&]()-> bool {
            return max(ax1, bx1) < min(ax2, bx2) && max(ay1, by1) < min(ay2, by2); 
        };
        
        int area = a + b;
        if (hasIntersection()) {
            area -= ( max(ax1, bx1) - min(ax2, bx2) ) 
                * ( max(ay1, by1) - min(ay2, by2));
        }
        return area;
    }
};