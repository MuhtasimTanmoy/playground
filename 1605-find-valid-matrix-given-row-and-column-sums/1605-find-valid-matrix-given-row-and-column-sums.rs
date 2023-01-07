impl Solution {
    pub fn restore_matrix(rs: Vec<i32>, cs: Vec<i32>) -> Vec<Vec<i32>> {
        let mut row_sum = rs;
        let mut col_sum = cs;
        let mut res: Vec<Vec<i32>> = vec![vec![0; col_sum.len()]; row_sum.len()];
        for i in 0..res.len() {
            for j in 0..res[0].len() {
                if row_sum[i] > 0 {
                    res[i][j] = std::cmp::min(row_sum[i], col_sum[j]);
                    row_sum[i] -= res[i][j];
                    col_sum[j] -= res[i][j];
                }
            }
        }
        res
    }
}