impl Solution {
    pub fn minimize_xor(num1: i32, num2: i32) -> i32 {
        let (mut traverse, mut x) = (0, num1);
        let mut to_add_in_x = num2.count_ones() as i32 - num1.count_ones() as i32;
        while to_add_in_x != 0 {
            let is_one = x & (1 << traverse);
            if to_add_in_x > 0 && is_one == 0 {
                x |= 1 << traverse;
                to_add_in_x -= 1;
            }
            if to_add_in_x < 0 && is_one != 0 {
                x ^= 1 << traverse;
                to_add_in_x += 1;
            }
            traverse += 1;
        }
        x 
    }
}