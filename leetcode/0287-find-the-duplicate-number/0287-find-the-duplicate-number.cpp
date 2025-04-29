class Solution {
public:
    int findDuplicate(vector<int>& N) {
        for (auto i = 0; i < N.size(); i++) {
            auto index = abs(N[i]);
            if (N[index] < 0) return abs(N[i]);
            N[index] = -abs(N[index]);
        }
        throw "error";
    }
};