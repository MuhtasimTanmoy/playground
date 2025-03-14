impl Solution {
    pub fn pivot_array(nums: Vec<i32>, pivot: i32) -> Vec<i32> {
        let mut pre = Vec::new();
        let mut now = Vec::new();
        let mut post = Vec::new();

        for num in nums {
            if num < pivot {
                pre.push(num);
            } else if num > pivot {
                post.push(num);
            } else {
                now.push(num);
            }
        }

        // Merge the three vectors
        pre.extend(now);
        pre.extend(post);
        
        pre
    }
}