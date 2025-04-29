use std::collections::HashSet;

impl Solution {
    pub fn max_sum(mut nums: Vec<i32>) -> i32 {
        let mut sum = *nums.iter().max().unwrap();
        if sum < 0 { return sum; }

        let mut j = 0;
        for i in 0..nums.len() {
            if nums[i] > 0 {
                nums[j] = nums[i];
                j += 1;
            }
        }
        nums.truncate(j);

        let bag: HashSet<i32> = nums.into_iter().collect();
        sum = bag.iter().sum();
        
        sum
    }
}
