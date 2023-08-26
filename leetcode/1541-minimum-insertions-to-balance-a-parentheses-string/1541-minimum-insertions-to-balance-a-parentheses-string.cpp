class Solution {
public:
    int minInsertions(string s) {
        // int left_needed = 0, right_needed = 0;
        // for (auto c: s) 
        //     if (c == '(') right_needed += 2;
        //     else if (right_needed) right_needed--;
        //     else left_needed++, right_needed++;
        // return left_needed + right_needed;
        
        int res = 0, right = 0;
        for (char &c: s) {
            if (c == '(') {
                if (right % 2 > 0) right--, res++;
                right += 2;
            } else if (right) right--;
            else right++, res++;
        }
        return right + res;
    }
};