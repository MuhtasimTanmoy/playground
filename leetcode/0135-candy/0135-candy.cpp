class Solution {
public:
    int candy(vector<int>& R) {
        int len = R.size();
        if (len == 1) return {1};

        vector<int> res(len, 1);

        for (auto i = 0; i < len; i++) {
            bool is_left_less = i ? R[i-1] < R[i]: false;
            if (is_left_less) res[i] = res[i-1] + 1;
        }

        for (int i = len - 1; i >= 0; i--) {
            bool is_right_less = i == (len - 1) ? false: R[i+1] < R[i];
            if (is_right_less) res[i] = max(res[i+1] + 1, res[i]);
        }
        
        return accumulate(res.begin(), res.end(), 0);
    }
};