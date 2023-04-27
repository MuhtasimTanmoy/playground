class Solution {
public:
    int maximumsSplicedArray(vector<int>& l, vector<int>& r) {
        auto go = [](vector<int>& l, vector<int>& r) {
            auto l_sum = accumulate(l.begin(), l.end(), 0), sum = 0;
            for (int i = 0, counting = 0; i < l.size(); i++)
                counting += r[i] - l[i],
                counting = max(counting, 0),
                sum = max(sum, counting);
            return l_sum + sum;
        };
        return max(go(l, r), go(r, l));
    }
};
