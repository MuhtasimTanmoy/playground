class NumArray {
public:
    NumArray(vector<int>& nums): p(nums) {
        for (auto i = 1; i < nums.size(); i++) p[i] += p[i-1];
    }
    
    int sumRange(int left, int right) {
        if (!left) return p[right];
        return p[right] - p[left - 1];
    }
private:
    vector<int> p;
};