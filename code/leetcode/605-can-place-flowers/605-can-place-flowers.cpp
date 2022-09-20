class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (!n) return true;
        
        int canPlaceCount = 0;
        for(int i = 0; i < size(flowerbed); i++) {
            if (flowerbed[i]) continue;
            
            auto leftEmpty = i > 0 ? flowerbed[i-1] == 0 : true;
            auto rightEmpty = i < size(flowerbed) - 1 ? flowerbed[i+1] == 0 : true;
            
            if (leftEmpty && rightEmpty)  {
                flowerbed[i] = 1;
                canPlaceCount++;
                if (canPlaceCount == n) return true;
            }
        }
        return false;
    }
};