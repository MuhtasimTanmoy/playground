class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, 
                    int bx1, int by1, int bx2, int by2) {
        
        auto firstArea = abs(ax2-ax1) * abs(ay2-ay1);
        auto secondArea = abs(bx2-bx1) * abs(by2-by1);
        
        auto intersectH = min(ay2, by2) - max(ay1, by1);
        auto intersectY = min(ax2, bx2) - max(ax1, bx1);
        
        if (intersectH > 0 && intersectY > 0) 
            return firstArea + secondArea - intersectH * intersectY;
        
        return firstArea + secondArea;
    }
};