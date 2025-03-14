use std::collections::BTreeMap;
impl Solution {
    pub fn merge_arrays(l: Vec<Vec<i32>>, r: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        // let mut tracker = new BtreeMap<i32, i32>;
        // for i in l {
        //     tracker[i[0]] += i[1];
        // }
        // for i in r {
        //     tracker[i[0]] += i[1];
        // }
        // let mut res = new Vec<Vec<i32>>;
        // for 

        let mut tracker = BTreeMap::new();
        for pair in l.iter().chain(r.iter()) {
            if let [key, value] = pair[..] {
                *tracker.entry(key).or_insert(0) += value;
            }
        }
        tracker.into_iter().map(|(k, v)| vec![k, v]).collect()
    }
}