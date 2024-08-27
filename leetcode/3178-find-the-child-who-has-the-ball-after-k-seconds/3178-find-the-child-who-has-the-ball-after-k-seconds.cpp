class Solution {
public:
    int numberOfChild(int n, int k) {
        bool is_reverse = false;
        while (k >= n) 
            k -= n - 1,
            is_reverse = !is_reverse;
        return is_reverse ? n - 1 - k: k;
    }
};