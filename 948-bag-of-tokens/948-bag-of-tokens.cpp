class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int left = 0, right = tokens.size() - 1;
        int score = 0;

        int curr = left;
        int res = 0;
        while (left <= right)
            if (tokens[left] <= power) {
                power -= tokens[left++];
                score++;
                res = max(res, score);
            } else
                if (score) {
                     power += tokens[right--];
                     score--;
                } else break;
        return res;
    }
};