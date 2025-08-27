class Solution {
public:
    vector<int> Helper(long n) {
        vector<int> num(10);
        while (n) num[n % 10]++, n = n / 10;
        return num;
    }
    
    bool reorderedPowerOf2(int n) {
        vector<int>v = Helper(n);
        for (int i = 0; i < 31; i++)
            if ( v == Helper( 1 << i) ) return true;
        return false;
    }
};