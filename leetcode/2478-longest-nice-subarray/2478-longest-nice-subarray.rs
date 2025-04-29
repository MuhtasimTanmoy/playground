impl Solution {
    pub fn longest_nice_subarray(nums: Vec<i32>) -> i32 {
        let mut res = 0;
        let mut used = 0;
        let mut i = 0;

        for j in 0..nums.len() {
            while used & nums[j] != 0 {
                used ^= nums[i];
                i += 1;
            }
            used |= nums[j];
            res = res.max((j - i + 1) as i32);
        }

        res
    }
}
