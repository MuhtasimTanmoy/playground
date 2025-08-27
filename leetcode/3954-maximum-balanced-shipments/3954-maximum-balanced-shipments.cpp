class Solution {
public:
    int maxBalancedShipments(vector<int>& W) {
        int max_so_far = INT_MIN, res = 0;
        for (auto w: W) {
            max_so_far = max(w, max_so_far);
            if (w < max_so_far) res++, max_so_far = INT_MIN;
        }
        return res;
    }
};