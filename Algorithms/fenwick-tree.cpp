class FenWickTree{
    vector<int> cnt;
    int lowbit(int x) {
		return (x) & (-x);
	}
    
	public:
	FenWickTree(int n): cnt(n+1, 0) {}

	void update(int i, int delt) {
		while (i < cnt.size()) {
			cnt[i] += delt;
			i += lowbit(i);
		}
	}

	int query(int a) {
		int sum = 0;
		while ( a > 0 ) {
			sum += cnt[a];
			a -= lowbit(a);
		}
		return sum;
	}
};


class NumArray {
public:
	FenWickTree FW;
	vector<int> num;
    
	NumArray(vector<int>& nums): FW(nums.size()) {
		int n = nums.size();
		num = nums;
		for(int i = 0; i < n; i++) FW.update(i + 1, num[i]);
	}

	void update(int i, int val) {
		FW.update(i + 1, val - num[i]);
		num[i] = val;
	}

	int sumRange(int i, int j) {
		return FW.query(j + 1) - FW.query(i);
	}
};