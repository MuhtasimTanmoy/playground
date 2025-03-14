impl Solution {
    pub fn maximum_count(nums: Vec<i32>) -> i32 {
        let l = nums.partition_point(|&x| x < 0);
        let r = nums.partition_point(|&x| x < 1);
        if l == r {
            if l == 0 || l == nums.len() {
                return nums.len() as i32;
            } 
        }
        l.max(nums.len() - r) as i32
    }
}
