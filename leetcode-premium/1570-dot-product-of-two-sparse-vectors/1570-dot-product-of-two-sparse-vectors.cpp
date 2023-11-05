class SparseVector {
    vector<int> store;
public:
    SparseVector(vector<int> &nums) {
        store = nums;
    }
    
    int dotProduct(SparseVector& vec) {
        int res = 0;
        for (int i = 0; i < vec.len(); i++) res += store[i] * vec.get(i);
        return res;
    }
    
    int get(int i) {
        return store[i];
    }
    
    int len() {
        return store.size();
    }
};