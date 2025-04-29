class Solution {
public:
    int numOfUnplacedFruits(vector<int>& F, vector<int>& B) {
        int res = F.size();
        for (auto f: F) 
            for (auto &b: B)
                if (f <= b) {
                    res--;
                    b = 0;
                    break;
                }
        return res;
    }
};