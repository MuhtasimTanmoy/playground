/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// This wont work as nodes with lower depth will have priority
// class Solution {
//     map<int, vector<int>> li;
//     void traverse(TreeNode* root, int column) {
//         cout<<root->val<<endl;
//         li[column].push_back(root->val);
//         if (root->left) traverse(root->left, column - 1);
//         if (root->right) traverse(root->right, column + 1);
//     }
// public:
//     vector<vector<int>> verticalOrder(TreeNode* root) {
//         if (root) traverse(root, 0);
//         vector<vector<int>> res;
//         for(auto [key, val]: li) res.push_back(val);
//         return res;
//     }
// };



// With sorting
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
// class Solution {
//   public List<List<Integer>> verticalOrder(TreeNode root) {
//     List<List<Integer>> output = new ArrayList();
//     if (root == null) {
//       return output;
//     }

//     Map<Integer, ArrayList> columnTable = new HashMap();
//     Queue<Pair<TreeNode, Integer>> queue = new ArrayDeque();
//     int column = 0;
//     queue.offer(new Pair(root, column));

//     while (!queue.isEmpty()) {
//       Pair<TreeNode, Integer> p = queue.poll();
//       root = p.getKey();
//       column = p.getValue();

//       if (root != null) {
//         if (!columnTable.containsKey(column)) {
//           columnTable.put(column, new ArrayList<Integer>());
//         }
//         columnTable.get(column).add(root.val);

//         queue.offer(new Pair(root.left, column - 1));
//         queue.offer(new Pair(root.right, column + 1));
//       }
//     }

//     List<Integer> sortedKeys = new ArrayList<Integer>(columnTable.keySet());
//     Collections.sort(sortedKeys);
//     for(int k : sortedKeys) {
//       output.add(columnTable.get(k));
//     }

//     return output;
//   }
// }


// // Without sorting
// class Solution {
    
//   public List<List<Integer>> verticalOrder(TreeNode root) {
      
//     List<List<Integer>> output = new ArrayList();
//     if (root == null) { return output; }

//     Map<Integer, ArrayList> columnTable = new HashMap();
//     // Pair of node and its column offset
//     Queue<Pair<TreeNode, Integer>> queue = new ArrayDeque();
      
//     int column = 0;
//     queue.offer(new Pair(root, column));

//     int minColumn = 0, maxColumn = 0;
      
//     while (!queue.isEmpty()) {
//       Pair<TreeNode, Integer> p = queue.poll();
//       root = p.getKey();
//       column = p.getValue();

//       if (root != null) {
//         if (!columnTable.containsKey(column)) {
//           columnTable.put(column, new ArrayList<Integer>());
//         }
//         columnTable.get(column).add(root.val);
//         minColumn = Math.min(minColumn, column);
//         maxColumn = Math.max(maxColumn, column);

//         queue.offer(new Pair(root.left, column - 1));
//         queue.offer(new Pair(root.right, column + 1));
//       }
//     }

//     for(int i = minColumn; i < maxColumn + 1; ++i) {
//       output.add(columnTable.get(i));
//     }

//     return output;
//   }
// }


// class Solution {
//   Map<Integer, ArrayList<Pair<Integer, Integer>>> columnTable = new HashMap();
//   int minColumn = 0, maxColumn = 0;

//   private void DFS(TreeNode node, Integer row, Integer column) {
//     if (node == null)
//       return;

//     if (!columnTable.containsKey(column)) {
//       this.columnTable.put(column, new ArrayList<Pair<Integer, Integer>>());
//     }

//     this.columnTable.get(column).add(new Pair<Integer, Integer>(row, node.val));
//     this.minColumn = Math.min(minColumn, column);
//     this.maxColumn = Math.max(maxColumn, column);
//     // preorder DFS traversal
//     this.DFS(node.left, row + 1, column - 1);
//     this.DFS(node.right, row + 1, column + 1);
//   }

//   public List<List<Integer>> verticalOrder(TreeNode root) {
//     List<List<Integer>> output = new ArrayList();
//     if (root == null) {
//       return output;
//     }

//     this.DFS(root, 0, 0);

//     // Retrieve the resuts, by ordering by column and sorting by row
//     for (int i = minColumn; i < maxColumn + 1; ++i) {

//       Collections.sort(columnTable.get(i), new Comparator<Pair<Integer, Integer>>() {
//         @Override
//         public int compare(Pair<Integer, Integer> p1, Pair<Integer, Integer> p2) {
//           return p1.getKey() - p2.getKey();
//         }
//       });

//       List<Integer> sortedColumn = new ArrayList();
//       for (Pair<Integer, Integer> p : columnTable.get(i)) {
//         sortedColumn.add(p.getValue());
//       }
//       output.add(sortedColumn);
//     }

//     return output;
//   }
// }

class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if (!root) {
            return {};
        }
        vector<vector<int>> res;
        queue<pair<TreeNode *, int>> que;
        que.push({root, 0});
        unordered_map<int, vector<int>> map;
        int minx = 0, maxx = 0;
        while (que.size()) {
            auto qsize = que.size();
            while (qsize--) {
                auto now = que.front();
                minx = min(minx, now.second);
                maxx = max(maxx, now.second);
                que.pop();
                map[now.second].push_back(now.first->val);
                if (now.first->left) {
                    que.push({now.first->left, now.second-1});
                }
                if (now.first->right) {
                    que.push({now.first->right, now.second+1});
                }
            }
        }
        for (int i = minx; i <= maxx; ++i) {
            res.push_back(map[i]);
        }
        return res;
    }
};
