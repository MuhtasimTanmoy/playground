class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        unordered_map<string, int> c;
        auto gen_key = [](auto l, auto ...r) {
            return (to_string(l) + ... + ("-" + to_string(r)));
        };
        function<int(int, int, bool)> go = [&](auto l, auto r, auto is_a) {
            if (l > r) return 0;
            
            auto key = gen_key(l, r, is_a);
            if (c.count(key)) return c[key];
            
            auto score_l = (is_a ? nums[l]: 0) + go(l + 1, r, !is_a),
                 score_r = (is_a ? nums[r]: 0) + go(l, r - 1, !is_a);
            return c[key] = is_a ? max(score_l, score_r): min(score_l, score_r);
        };
        auto score = go(0, nums.size() - 1, true);
        auto sum = accumulate(nums.begin(), nums.end(), 0);
        return score * 2 >= sum;
    }
};

// auto gen_key = [](auto l, auto ...r) {
//     return (to_string(l) + ... + ("-" + to_string(r)));
// };
// unordered_map<string, int> c;
// auto sum = accumulate(nums.begin(), nums.end(), 0);
// function<int(int, int, bool)> go = [&](auto l, auto r, auto is_a) {
//     if (l > r) return 0;
//     auto key = gen_key(l, r, is_a);
//     if (c.count(key)) return c[key];
//     auto l_taken = (is_a ? nums[l]: 0) + go(l + 1, r, !is_a),
//          r_taken = (is_a ? nums[r]: 0) + go(l, r - 1, !is_a);
//     return c[key] = is_a ? max(l_taken, r_taken): min(l_taken, r_taken);
// };
// auto a_score = go(0, nums.size() - 1, true);
// return 2 * a_score >= sum; 