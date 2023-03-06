impl Solution {
    pub fn find_kth_positive(arr: Vec<i32>, k: i32) -> i32 {
        let mut ans = k;
        for item in arr { 
            if (ans < item) { return ans; } 
            ans = ans + 1; 
        }
        return ans;
    }
}