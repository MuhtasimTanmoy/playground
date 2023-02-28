impl Solution {
    pub fn ship_within_days(weights: Vec<i32>, days: i32) -> i32 {
        let count = |target_cap: i32| -> i32 {
            let (mut needed, mut sum) = (1, 0);
            for &w in weights.iter() {
                sum += w;
                if sum > target_cap {
                    needed += 1;
                    sum = w;
                }
            }
            needed
        };

        let (mut l, mut r) = (0, 0);
        for &w in weights.iter() {
            l = l.max(w);
            r += w;
        }

        while l < r {
            let m = l + (r - l) / 2;
            let day_need = count(m);
            if day_need > days {
                l = m + 1;
            } else {
                r = m;
            }
        }

        r
    }
}

