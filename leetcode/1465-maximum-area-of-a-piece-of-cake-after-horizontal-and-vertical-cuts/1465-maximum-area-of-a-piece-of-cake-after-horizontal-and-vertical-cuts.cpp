class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        
        horizontalCuts.push_back(0);
        horizontalCuts.push_back(h);
        
        verticalCuts.push_back(0);
        verticalCuts.push_back(w);
        
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        long long l = INT_MIN;
        for(int i = 1; i < size(horizontalCuts); i++)
            l = max((int)l, horizontalCuts[i] - horizontalCuts[i-1]);
        
        long long r = INT_MIN;
        for(int i = 1; i < size(verticalCuts); i++)
            r = max((int)r, verticalCuts[i] - verticalCuts[i-1]);
        
        return (l * r) % 1000000007;
    }
};