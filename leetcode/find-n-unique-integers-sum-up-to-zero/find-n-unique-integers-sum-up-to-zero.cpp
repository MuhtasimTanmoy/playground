class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res;
        if (n & 1) {
            res.push_back(0);
            n--;
        }
        
        int i = 1;
        while(n) {
            res.push_back(i);
            res.push_back(i * -1);
            n -= 2;
            i++;
        }
        
        return res;
    }
};