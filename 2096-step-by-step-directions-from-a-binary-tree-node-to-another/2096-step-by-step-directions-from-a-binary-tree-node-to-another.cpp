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
class Solution {
    TreeNode* lcs(TreeNode* root, int startValue, int destValue) {
        if (!root || root->val == startValue || root->val == destValue) return root;
        auto left = lcs(root->left, startValue, destValue);
        auto right = lcs(root->right, startValue, destValue);
        if (left && right) return root;
        else return left ? left : right;
    }
    
    bool startPath(TreeNode* root, int startValue, string& path) {
        if (!root) return false;
        if (root->val == startValue) return true;
        auto isInLeft = (root->left) ? startPath(root->left, startValue, path): false;
        auto isInRight = (root->right) ? startPath(root->right, startValue, path): false;
        if (isInLeft || isInRight) path += "U";
        return isInLeft || isInRight;
    }
    
    bool endPath(TreeNode* root, int value, string& path) {
        if (!root) return false;
        if (root->val == value) return true;
        auto isInLeft = endPath(root->left, value, path);
        if (isInLeft) { path += 'L'; return isInLeft; }
        auto isInRight = endPath(root->right, value, path);
        if (isInRight) { path += 'R'; return isInRight; }
        return isInRight || isInLeft;
    }
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        auto lcsNode = lcs(root, startValue, destValue);
        string start = "";
        startPath(lcsNode, startValue, start);
        string end = "";
        endPath(lcsNode, destValue, end);
        reverse(end.begin(), end.end());
        return start + end;
    }
};

//         5,
//       1,  2,
//  3, null, 6,  4

// 3 6


// class Solution {
 
// public:
//     bool getPath(TreeNode* root, int val, string& path) {
        
//         if (root->val == val) return true;
        
//         if (root->left) {
//             path.push_back('L');
//             auto left = getPath(root->left, val, path);
//             if (left) return left;
//             path.pop_back();
//         }
        
//         if (root->right) {
//            path.push_back('R');
//            auto right = getPath(root->right, val, path);
//            if (right) return right;
//            path.pop_back();
//         }
        
//         return false;
//     }
    
//     TreeNode* findLCA(TreeNode* root, int s, int e){
//         if (!root) return root;
//         if (root->val == s || root->val==e) return root;
//         TreeNode* l = findLCA(root->left, s, e);
//         TreeNode* r = findLCA(root->right, s, e);
//         if(l && r) return root;
//         return l ? l : r;
//     }
    
//     string getDirections(TreeNode* root, int startValue, int destValue) {
//         auto lca = findLCA(root, startValue, destValue);
//         string pathToStart;
//         string pathToDest ;
//         getPath(lca, startValue, pathToStart);
//         getPath(lca, destValue, pathToDest);
//         string reverseDir;
//         for(auto ch : pathToStart) reverseDir +='U';
//         return reverseDir+pathToDest;
//     }
// };
