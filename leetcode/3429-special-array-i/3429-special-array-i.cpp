class Solution {
public:
    bool isArraySpecial(vector<int>& N) {
        for (auto i = 1; i < N.size(); i++)
            if ((N[i] & 1 ) == (N[i - 1] & 1))
                return false;
        return true;
    }
};