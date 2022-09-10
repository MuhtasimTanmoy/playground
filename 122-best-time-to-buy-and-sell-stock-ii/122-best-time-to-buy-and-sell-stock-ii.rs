impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        let mut res: i32 = 0;
        for index in (1..prices.len()) {
            let gain = prices[index] - prices[index - 1];
            res += 0.max(gain);
        }
        res
    }
}