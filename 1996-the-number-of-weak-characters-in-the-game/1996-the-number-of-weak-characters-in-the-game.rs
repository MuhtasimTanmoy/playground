impl Solution {
    pub fn number_of_weak_characters(mut properties: Vec<Vec<i32>>) -> i32 {
        const IDX_ATTACK: usize = 0;
        const IDX_DEFENSE: usize = 1;
        properties.sort_unstable_by_key(|p| (p[IDX_ATTACK], -p[IDX_DEFENSE]));
        let mut maxDef = 0;
        let mut count = 0;
        for idx in (0..properties.len()).rev() {
            let def = properties[idx][IDX_DEFENSE];
            count += (def < maxDef) as i32;
            maxDef = maxDef.max(def);
        }
        count
    }
}