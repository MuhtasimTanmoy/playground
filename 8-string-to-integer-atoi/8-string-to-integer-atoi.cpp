class Solution {
public:
    int myAtoi(string s) {
        stringstream ss(s);
        long ans = 0;
        ss>>ans;
        if (ans > INT_MAX) return INT_MAX;
        else if (ans < INT_MIN) return INT_MIN;
        return ans;
    }
};