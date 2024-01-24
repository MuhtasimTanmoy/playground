class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
//         for (auto i = 0; i < time.size() - 1; i++) 
//             for (auto j = i + 1; j < time.size(); j++) {
//                 auto sum = time[i] + time[j];
//                 if (sum % 60 == 0)
//                     res++;
//             }
//         return res;
        
        vector<int> c(60);
        int res = 0;
        for (int t : time)
            res += c[(600 - t) % 60], c[t % 60] += 1;
        return res;
    }
};