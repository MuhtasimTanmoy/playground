class SparseVector {
public:
    vector<int> list;
    SparseVector(vector<int> &nums) {
        list = nums;
    }
    
    int dotProduct(SparseVector& vec) {
        int res = 0;
        for (int i = 0; i < vec.list.size(); i++) {
            if (!list[i] || !vec.list[i]) continue;
            res += list[i] * vec.list[i];
        }
        return res;
    }    
};