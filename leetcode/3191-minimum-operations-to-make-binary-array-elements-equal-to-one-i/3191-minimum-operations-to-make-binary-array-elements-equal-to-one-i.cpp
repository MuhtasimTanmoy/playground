class Solution {
public:
    int minOperations(vector<int>& N) {
        int res = 0;
        for (auto i = 0; i < N.size(); i++) 
            if (!N[i]) {
                if (i + 2 >= N.size()) return -1;
                N[i] = 1;
                N[i + 1] = !N[i + 1];
                N[i + 2] = !N[i + 2];
                res++;
            }
        return res;
    }
};