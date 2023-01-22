class Solution {
public:
    int getCommon(vector<int>& n1, vector<int>& n2, int i1 = 0, int i2 = 0) {
        while (i1 < n1.size() && i2 < n2.size()) {
            if (n1[i1] == n2[i2]) return n1[i1];
            else if (n1[i1] > n2[i2]) i2++;
            else i1++;
        }
        return -1;
    }
};