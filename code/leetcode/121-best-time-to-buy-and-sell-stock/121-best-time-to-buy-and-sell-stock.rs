impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        let mut res = 0;
        let mut minSoFar = prices[0];
        for price in prices {
            res = res.max(price - minSoFar);
            minSoFar = minSoFar.min(price);
        }
        res
    }
}