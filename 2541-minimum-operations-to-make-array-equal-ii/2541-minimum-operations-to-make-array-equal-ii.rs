impl Solution {
    pub fn min_operations(nums1: Vec<i32>, nums2: Vec<i32>, k: i32) -> i64 {
        let (mut steps, mut sum) = (0, 0);
        for i in 0..nums1.len() {
            let diff = nums2[i] - nums1[i];
            if k != 0 {
                if diff % k != 0 { return -1; }
                sum += diff;
                steps += (diff as i64).abs() / k as i64;
            } else if diff != 0 { return -1; }
        }
        if sum != 0 { return -1; }
        steps / 2
    }
}