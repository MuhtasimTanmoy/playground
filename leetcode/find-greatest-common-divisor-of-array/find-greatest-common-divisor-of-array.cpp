class Solution {
public:
    int findGCD(vector<int>& nums) {
        int minS = INT_MAX;
        int maxS = INT_MIN;
        
        for(auto s: nums) {
            maxS = max(s, maxS);
            minS = min(s, minS);
        }
        
        function<int (int, int)> gcd;
        gcd = [&gcd](int a, int b) {
            if ( b == 0 ) return a;
            return (a > b) ? gcd(b, a - b): gcd(a, b - a);
        };
        
        return gcd(minS, maxS);
    }
};