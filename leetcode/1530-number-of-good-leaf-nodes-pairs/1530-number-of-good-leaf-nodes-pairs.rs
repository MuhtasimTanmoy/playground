// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
// 
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }

use std::cell::RefCell;
use std::rc::Rc;
impl Solution {
    pub fn count_pairs(root: Option<Rc<RefCell<TreeNode>>>, distance: i32) -> i32 {
        fn dfs(root: &Option<Rc<RefCell<TreeNode>>>, distance: i32, ans: &mut i32) -> Vec<i32> {
            match root {
                None => vec![0; distance as usize + 1],
                Some(node) => {
                    let node = node.borrow();
                    if node.left.is_none() && node.right.is_none() {
                        let mut v = vec![0; distance as usize + 1];
                        v[1] += 1;
                        return v;
                    }
                    let left = dfs(&node.left, distance, ans);
                    let right = dfs(&node.right, distance, ans);
                    for i in 0..distance {
                        for j in (0..distance).rev() {
                            if i as i32 + j <= distance {
                                *ans += left[i as usize] * right[j as usize];
                            }
                        }
                    }
                    let mut v = vec![0; distance as usize + 1];
                    for i in (1..v.len() - 1).rev() {
                        v[i + 1] = left[i] + right[i];
                    }
                    v
                }
            }
        }
        let mut ans = 0;
        dfs(&root, distance, &mut ans);
        ans
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_num_splits() {
        let root = Some(Rc::new(RefCell::new(TreeNode {
            val: 1,
            left: Some(Rc::new(RefCell::new(TreeNode {
                val: 2,
                left: None,
                right: Some(Rc::new(RefCell::new(TreeNode::new(4)))),
            }))),
            right: Some(Rc::new(RefCell::new(TreeNode::new(3)))),
        })));
        assert_eq!(Solution::count_pairs(root, 3), 1)
    }

    #[test]
    fn test_num_splits_02() {
        let root = Some(Rc::new(RefCell::new(TreeNode {
            val: 1,
            left: Some(Rc::new(RefCell::new(TreeNode {
                val: 2,
                left: Some(Rc::new(RefCell::new(TreeNode::new(4)))),
                right: Some(Rc::new(RefCell::new(TreeNode::new(5)))),
            }))),
            right: Some(Rc::new(RefCell::new(TreeNode {
                val: 3,
                left: Some(Rc::new(RefCell::new(TreeNode::new(6)))),
                right: Some(Rc::new(RefCell::new(TreeNode::new(7)))),
            }))),
        })));
        assert_eq!(Solution::count_pairs(root, 3), 2)
    }

    #[test]
    fn test_num_splits_03() {
        let root = Some(Rc::new(RefCell::new(TreeNode {
            val: 1,
            left: Some(Rc::new(RefCell::new(TreeNode {
                val: 1,
                left: None,
                right: None,
            }))),
            right: Some(Rc::new(RefCell::new(TreeNode {
                val: 1,
                left: None,
                right: None,
            }))),
        })));
        assert_eq!(Solution::count_pairs(root, 2), 1)
    }

    #[test]
    fn test_num_splits_04() {
        let root = Some(Rc::new(RefCell::new(TreeNode {
            val: 100,
            left: None,
            right: None,
        })));
        assert_eq!(Solution::count_pairs(root, 1), 0)
    }
}