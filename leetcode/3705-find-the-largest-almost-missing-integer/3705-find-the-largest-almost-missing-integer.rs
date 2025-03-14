use std::collections::{HashMap, HashSet};

impl Solution {
   pub fn largest_integer(nums: Vec<i32>, k: i32) -> i32 {
        let n = nums.len() as usize;
        let mut subarray_count: HashMap<i32, i32> = HashMap::new();

        for i in 0..=n - k as usize {
            let unique_nums: HashSet<i32> = nums[i..i + k as usize].iter().copied().collect();
            for &num in &unique_nums {
                *subarray_count.entry(num).or_insert(0) += 1;
            }
        }

        let mut ans = -1;
        for (&num, &count) in &subarray_count {
            if count == 1 && num > ans {
                ans = num;
            }
        }

        ans
    }
}