impl Solution {
    pub fn transform_array(mut nums: Vec<i32>) -> Vec<i32> {
        nums.iter_mut().for_each(|num| *num = if *num & 1 == 1 { 1 } else { 0 });
        nums.sort();
        nums
    }
}