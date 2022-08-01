class SegmentTree {
public:
    int sz;
    vector <int> tree;
    
    SegmentTree(vector <int> &nums) {
        sz = nums.size();
        tree.resize(4 * (int)nums.size(), 0);
        build(1, 0, (int)nums.size() - 1, nums);   
    }
    
    void build(int node, int b, int e, vector <int> &nums) {
        if (b > e) return;
        if (b == e) {
            tree[node] = nums[b];
            return;
        }
        int l = node << 1, r = l | 1, m = (b + e) >> 1;
        build(l, b, m, nums);
        build(r, m + 1, e, nums);
        tree[node] = tree[l] + tree[r];
    }
    
    int query(int node, int b, int e, int left, int right) {
        if (left > e || right < b || b > e) return 0;
        if (left <= b && right >= e) return tree[node];
        int l = node << 1, r = l | 1, m = (b + e) >> 1;
        return query(l, b, m, left, right) + query(r, m + 1, e, left, right);
    }
    
    int query(int left, int right) {
        return query(1, 0, sz - 1, left, right);
    }
    
    void update(int node, int b, int e, int pos, int val) {
        if (b > e || pos > e || pos < b) return;
        if (b == e && b == pos) {
            tree[node] = val;
            return;
        }
        int l = node << 1, r = l | 1, m = (b + e) >> 1;
        update(l, b, m, pos, val);
        update(r, m + 1, e, pos, val);
        tree[node] = tree[l] + tree[r];
    }
    
    void update(int index, int val) {
        update(1, 0, sz - 1, index, val);
    }
};

class NumArray {
public:
    SegmentTree *tree;
    NumArray(vector<int>& nums) { tree = new SegmentTree(nums); }
    void update(int index, int val) { tree -> update(index, val); }
    int sumRange(int left, int right) { return tree -> query(left, right); }
};