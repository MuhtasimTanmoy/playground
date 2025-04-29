class Solution {
public:
    int partitionArray(vector<int>& N, int k) {
        sort(N.begin(), N.end());
        int res = 0, min_elem = 0;
        for (int i = 0; i < N.size(); i++) {
            if (N[i] - N[min_elem] > k) 
                res++,
                min_elem = i;
        }
        return res + 1;
    }
};