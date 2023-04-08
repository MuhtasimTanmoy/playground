class Solution {
public:
   long long makeSimilar(vector<int>& A, vector<int>& B) {
        sort(A.begin(), A.end()); sort(B.begin(), B.end());
       
        vector<int> oA, eA, oB, eB;
        for (int& x: A) (x % 2) ? oA.push_back(x) : eA.push_back(x);
        for (int& x: B) (x % 2) ? oB.push_back(x) : eB.push_back(x);
       
        auto incCount = [&](vector<int>& a, vector<int> &b, long long ans = 0) {
            for (int i = 0; i < a.size(); i++)
                if (a[i] > b[i]) ans += (a[i] - b[i]) / 2;
            return ans;
        };
        return incCount(oA, oB) + incCount(eA, eB);
    }
};