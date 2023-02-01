class Solution {
public:
    int minDeletion(vector<int>& A) {
        int res = 0, pre = -1;
        for (int& a: A) {   
            if (a == pre) res++;
            else pre = pre < 0 ? a : -1;
        }
        return res + (pre >= 0);
    }
};