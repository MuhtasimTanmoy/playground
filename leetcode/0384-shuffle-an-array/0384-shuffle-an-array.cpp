class Solution {
	vector<int> original;
	int n;
public:
	Solution(vector<int>& nums) {
		original = nums;
		n = original.size();
	}
	
	vector<int> reset() {
		return original;
	}
	
	vector<int> shuffle() {
        vector<int> shuffled = original;
        for (int i = n - 1, leftSize = n; i >= 0; i--, leftSize--) {
            int j = rand() % leftSize;
            swap(shuffled[i], shuffled[j]);
        }
        return shuffled;
	}
};