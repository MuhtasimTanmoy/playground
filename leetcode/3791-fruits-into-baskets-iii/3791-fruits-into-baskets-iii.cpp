class Solution {
private:
    vector<int> seg;

    void build(vector<int>& baskets, int idx, int low, int high) {
        if (low == high) {
            seg[idx] = baskets[low];
            return;
        }

        int mid = (low + high) >> 1;

        build(baskets, 2 * idx + 1, low, mid);
        build(baskets, 2 * idx + 2, mid + 1, high);

        seg[idx] = max(seg[2 * idx + 1], seg[2 * idx + 2]);
    }

    int search(int idx, int low, int high, int k) {
        if (seg[idx] < k)
            return -1;
        if (low == high) {
            seg[idx] = -1;
            return low;
        }

        int mid = (low + high) >> 1;
        int pos;

        if (seg[2 * idx + 1] >= k)
            pos = search(2 * idx + 1, low, mid, k);
        else
            pos = search(2 * idx + 2, mid + 1, high, k);

        seg[idx] = max(seg[2 * idx + 1], seg[2 * idx + 2]);

        return pos;
    }

public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        int ans = 0;

        seg.assign(4 * n, 0);
        build(baskets, 0, 0, n - 1);

        for (auto fruit : fruits)
            if (search(0, 0, n - 1, fruit) == -1)
                ans++;

        return ans;
    }
};