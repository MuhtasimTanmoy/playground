class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
          long long sum = accumulate(beans.begin(), beans.end(), (long long)0);
        long long n = beans.size();
        sort(beans.begin(), beans.end());
        
        long long res = sum;
        for (int i=0; i<beans.size(); i++) {
            res = min(res, sum-beans[i]*(n-i));
        }
        return res;
    }
};