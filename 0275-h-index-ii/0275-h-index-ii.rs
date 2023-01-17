impl Solution {
    pub fn h_index(citations: Vec<i32>) -> i32 {
        let mut ans = citations.len() as i32;
        for i in 0..citations.len() {
            if citations[i] >= ans {
                return ans;
            }
            ans -= 1
        }
        ans
    }
}