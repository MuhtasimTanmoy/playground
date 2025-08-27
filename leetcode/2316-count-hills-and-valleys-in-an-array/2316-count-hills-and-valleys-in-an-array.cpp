class Solution {
public:
    int countHillValley(vector<int>& N) {
        int j = 1;
        for (auto i = 1; i < N.size(); i++) {
            if (N[i] == N[i - 1]) continue;
            N[j++] = N[i];
        }
        N.resize(j);
        int res = 0;
        for (auto i = 1; i < N.size() - 1; i++)
            if (N[i] > N[i-1] && N[i] > N[i+1]) res++;
            else if (N[i] < N[i-1] && N[i] < N[i+1]) res++;
        return res;
    }
};