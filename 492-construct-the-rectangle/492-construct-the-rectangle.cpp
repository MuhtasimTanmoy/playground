class Solution {
public:
    vector<int> constructRectangle(int area) {
        int areaSqrt = sqrt(area);
        for(int i = areaSqrt; i > 0; i--) 
            if (area % i == 0 ) return { area / i, i};
        return {area, 1};
    }
};