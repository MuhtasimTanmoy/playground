class Solution {
public:
    bool isPerfectSquare(int num) {
        
        float result = sqrt(num);
        
        return floor(result) == ceil(result);
    }
};