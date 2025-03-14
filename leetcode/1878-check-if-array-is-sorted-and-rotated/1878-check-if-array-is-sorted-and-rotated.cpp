class Solution {
public:
    bool check(vector<int>& N) {
        N.push_back(N.front());
        bool found = false;
        for (auto i = 1; i < N.size(); i++)
            if (N[i-1] > N[i])
                if (found) return false;
                else found = true;
        return true;
    }
};