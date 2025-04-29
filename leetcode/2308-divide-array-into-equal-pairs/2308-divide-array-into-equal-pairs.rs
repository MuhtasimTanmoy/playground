impl Solution {
    pub fn divide_array(n: Vec<i32>) -> bool {
        let mut nums = n;
        nums.sort();
        for i in (1..nums.len()).step_by(2) {
            if nums[i] != nums[i-1] {
                return false;
            }
        }
        return true;
    }
}