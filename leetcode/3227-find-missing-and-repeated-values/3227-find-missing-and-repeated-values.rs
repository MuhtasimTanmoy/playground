use std::collections::HashSet;

impl Solution {
    pub fn find_missing_and_repeated_values(grid: Vec<Vec<i32>>) -> Vec<i32> {
        let n  = grid.len() as i32;
        let mut sum = ( (n * n) * (n * n + 1) ) / 2;
        let mut res: Vec<i32> = Vec::new();
        let mut bag: HashSet<i32> = HashSet::new();

        for row in grid {
            for i in row {
                if (bag.contains(&i)) {
                    res.push(i);
                    continue;
                }
                sum -= i;
                bag.insert(i);
            }
        }
        res.push(sum);
        return res;
    }
}