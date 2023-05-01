class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_set<int> bag;
        vector<int> res;
        for (int i = 0, counter = 0; i < A.size(); i++) {
            counter += A[i] == B[i] ? 1: bag.count(A[i]) + bag.count(B[i]);
            res.push_back(counter);
            bag.insert(A[i]);
            bag.insert(B[i]);
        }
        return res;
    }
};