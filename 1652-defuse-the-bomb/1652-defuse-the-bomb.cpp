class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int sz = code.size();
        if (k == 0) return vector<int>(sz, 0);
        auto toIndex = [&sz](int i) { return (i + sz) % sz; };
        vector<int> res(sz, 0);
        for (int i = 0; i < sz; i++) {
            int sum = 0, limit = k;
            if (k > 0) {
                while(limit) {
                    sum += code[toIndex(i + limit)];
                    limit--;
                }
            } else {
                while(limit) {
                    sum += code[toIndex(i + limit)];
                    limit++;
                }
            }
            res[i] = sum;
        }
        return res;
    }
};