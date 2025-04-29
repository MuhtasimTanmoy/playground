class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& P, vector<int>& T) {
        sort(P.begin(), P.end(), greater<int>());
        sort(T.begin(), T.end(), greater<int>());

        int i = 0, count  = 0;
        for (auto t: T) {
            while (i < P.size() && P[i] > t) i++;
            if (i >= P.size()) break;
            count++;
            i++;
        }
        return count;
    }
};