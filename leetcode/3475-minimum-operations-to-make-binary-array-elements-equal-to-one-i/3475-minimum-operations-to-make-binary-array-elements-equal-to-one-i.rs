impl Solution {
    pub fn min_operations(n: Vec<i32>) -> i32 {
        let mut ops = 0;
        let mut nums = n;
        for i in 0..nums.len() - 2 {
            if nums[i] == 0 {
                nums[i] = 1 - nums[i];
                nums[i+1] = 1 - nums[i+1];
                nums[i+2] = 1 - nums[i+2];
                ops = ops + 1;
            }
        }

        if *nums.last().unwrap() == 0 || *nums.get(nums.len() - 2).unwrap() == 0 {
            return -1;
        }
        return ops;
    }
}