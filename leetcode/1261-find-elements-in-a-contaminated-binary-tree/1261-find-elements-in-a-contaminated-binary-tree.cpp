/*
class FindElements {
    TreeNode* root;
public:
    FindElements(TreeNode* root): root(root) {}
    
    bool find(int target) {
        return go(root, target, 0);
    }
    
    bool go(TreeNode* root, int target, int now) {
        if (!root) return false;
        if (root->val == -1) root->val = now;
        
        if (now == target) return true;
        if (now > target) return false;
        
        auto l = go(root->left, target, 2 * now + 1);
        auto r = go(root->right, target, 2 * now + 2);
        return l || r;
    }
};
*/

class FindElements {
    unordered_set<int> set;
public:
    void recover(TreeNode* root, int x) {
        if (!root) return;
        root->val = x;
        set.emplace(x);
        recover(root->left, 2 * x + 1);
        recover(root->right, 2 * x + 2);
    }
    
    FindElements(TreeNode* root) {
        recover(root, 0);
    }
    
    bool find(int target) {
        return set.count(target);
    }
};