class Solution {
public:
//     bool backspaceCompare(string l, string r) {
//         for (int li = l.size() - 1, ri = r.size() - 1, 
//              can_skip_l = 0, can_skip_r = 0; ;
//              li--, ri--) {
            
//             while (li >= 0 && l[li] == '#') can_skip_l++, li--;
//             while (li >= 0 && can_skip_l > 0) can_skip_l--, li--;
            
//             while (ri >= 0 && r[ri] == '#') can_skip_r++, ri--;
//             while (ri >= 0 && can_skip_r > 0) can_skip_r--, ri--;
            
//             if (li >= 0 && ri >= 0) if (l[li] != r[ri]) return false;
//             if (li < 0 && ri < 0) break;
//         }
//         return true;
//     }
    
    bool backspaceCompare(string S, string T) {
        int i = S.length() - 1, j = T.length() - 1;
        while (true) {
            int back = 0;
            while (i >= 0 && (back > 0 || S[i] == '#')) 
                back += S[i] == '#' ? 1 : -1,
                i--;
            
            back = 0;
            while (j >= 0 && (back > 0 || T[j] == '#')) 
                back += T[j] == '#' ? 1 : -1,
                j--;
            
            if (i >= 0 && j >= 0 && S[i] == T[j]) 
                i--, j--;
            else
                break;
        }
        return i == -1 && j == -1;
    }
};