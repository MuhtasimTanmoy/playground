class Solution {
    const int UNDEFINED = -1;
public:
    int shortestWordDistance(vector<string>& words, string l, string r) {
        int res = INT_MAX;
        for (int i = 0, li= UNDEFINED, ri = UNDEFINED; i < words.size(); i++) {
            if (words[i] == l) {
                if (l == r) swap(li, ri);
                li = i;
            } else if (words[i] == r) ri = i;
            if (li != UNDEFINED && ri != UNDEFINED) res = min(res, abs(li - ri));
        }
        return res;
    }
};