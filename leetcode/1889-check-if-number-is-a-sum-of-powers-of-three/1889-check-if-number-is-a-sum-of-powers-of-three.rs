impl Solution {
    pub fn check_powers_of_three(mut n: i32) -> bool {
        while n > 0 && n % 3 != 2 {
            if n % 3 == 1 { n = n - 1; } else { n = n / 3; };
        }
        return n == 0;
    }
}