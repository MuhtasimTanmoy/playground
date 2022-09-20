class Solution {
public:
    int nthUglyNumber(int n) {
        int one = 0, two = 0, three = 0;
        vector<int> res = {1};
        
        for (int i = 1; i < n; i++) {
            
            auto first = 2 * res[one], second = 3 * res[two], third = 5 * res[three];
            auto minOf = min(first, min(second, third));
            res.push_back(minOf);
            
            if (minOf == first) one++;
            if (minOf == second) two++;
            if (minOf == third) three++;
        }
        return res.back();
    }
};