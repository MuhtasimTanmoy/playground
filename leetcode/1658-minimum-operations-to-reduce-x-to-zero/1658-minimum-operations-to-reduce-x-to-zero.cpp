class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
		auto sum = accumulate(nums.begin(), nums.end(), 0);
		if (sum < x) return -1;
		if (sum == x) return nums.size();
        
		auto target = sum - x, maxSize = 0;
		for (int i = 0, curr = 0, l = 0; i < nums.size(); i++) {
			curr += nums[i];
			while (curr > target) curr -= nums[l++];
			if (curr == target) maxSize = max(maxSize, i - l + 1);
		}
		return (maxSize == 0) ? - 1 : nums.size() - maxSize;
	}
};