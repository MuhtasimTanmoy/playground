class Solution {
public:
    // int longestAlternatingSubarray(vector<int>& n, int threshold) {
    //     int l = 0;
    //     while (l < n.size() && ((n[l] > threshold) || (n[l] & 1))) l++;
    //     int res = l < n.size();
    //     for (int r = l + 1, desired_state = 1; r < n.size(); r++) {
    //         auto now = (n[r] & 1);
    //         if (now == desired_state && n[r] <= threshold) 
    //             desired_state = 1 - desired_state,
    //             res = max(res, r - l + 1);
    //         else {
    //             l = r + desired_state ? 1: 0;
    //             while (l < n.size() && ((n[l] > threshold) || (n[l] & 1))) l++;
    //             r = l + 1;
    //             desired_state = 1;
    //         }
    //     }
    //     return res;
    // }
    
    int longestAlternatingSubarray(vector<int>& n, int threshold) {
        int res = 0;
        for (int l = 0, cnt = 0; l < n.size(); ++l) {
            if (n[l] <= threshold) {
                if (cnt)
                    cnt = n[l] % 2 == n[l - 1] % 2 ? 0 : cnt + 1;
                if (cnt == 0)
                    cnt = n[l] % 2 == 0;
            }
            else
                cnt = 0;
            res = max(res, cnt);
        }
        return res;
    }
};