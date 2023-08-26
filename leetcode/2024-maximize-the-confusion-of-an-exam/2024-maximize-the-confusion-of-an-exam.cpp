class Solution {
public:
    int maxConsecutiveAnswers(string ans, int k) {
        unordered_map<int, int> count;
        int max_so_far = 0, res = 0;
        for (int i = 0, j = 0; i < ans.size(); i++) {
            max_so_far = max(max_so_far, ++count[ans[i]]);
            if (i - j - max_so_far >= k)
                --count[ans[j++]];
            res = max(res, i - j + 1);
        }
        return res;
    }
};