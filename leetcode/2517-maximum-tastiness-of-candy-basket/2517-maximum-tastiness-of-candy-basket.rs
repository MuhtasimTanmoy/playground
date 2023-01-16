impl Solution {
    pub fn maximum_tastiness(price: Vec<i32>, k: i32) -> i32 {
        let mut price = price.clone();
        price.sort();

        let check = |target: i32| {
            let (mut count, mut j) = (1, 0);
            for i in 1..price.len() {
                if price[i] - price[j] >= target {
                    j = i;
                    count += 1;
                }
            }
            count >= k
        };
        
        let (mut left, mut right) = (0, price.last().unwrap() - price.first().unwrap() + 1);
        while left < right {
            let mid = left + (right - left) / 2;
            if check(mid) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        left - 1
    }
}