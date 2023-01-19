impl Solution {
    pub fn maximum_subarray_sum(nums: Vec<i32>, k: i32) -> i64 {
        let mut bag = std::collections::HashSet::new();
        let (mut res, mut j) = (0, 0);
        let mut counting_sum: i64 = 0;
        for i in 0..nums.len() {
            let curr = nums[i];
            while bag.contains(&curr) || bag.len() == k as usize {
                let to_erase = nums[j];
                j += 1;
                bag.remove(&to_erase);
                counting_sum -= to_erase as i64;
            }
            bag.insert(curr);
            counting_sum += curr as i64;
            if bag.len() == k as usize {
                res = std::cmp::max(res, counting_sum);
            }
        }
        res as i64
    }
}