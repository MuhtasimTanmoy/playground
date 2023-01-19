class Solution {
public:
     vector<int> arrayChange(vector<int>& A, vector<vector<int>>& op) {
        unordered_map<int,int> store;
        for(int i = 0; i < A.size(); i++) store[A[i]] = i;
        for(auto i: op) {
            A[store[i[0]]] = i[1];           
            store[i[1]] = store[i[0]];
        }
        return A;
    }
};