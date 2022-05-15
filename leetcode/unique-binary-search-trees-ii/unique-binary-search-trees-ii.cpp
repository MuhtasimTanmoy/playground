class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) return {};
        vector<TreeNode*> ans = generateT(1, n);
        return ans;  
    }
    
    vector<TreeNode*> generateT(int l, int r) {
        
        if(l > r) return { nullptr };
        vector<TreeNode*> ans;
        
        for ( int i = l; i <= r; i++ ) 
            for ( TreeNode* left :generateT(l, i-1) )
                for (TreeNode* right :generateT(i+1, r)) {
                    auto node = new TreeNode(i);
                    ans.push_back(node);
                    node->left = left;
                    node->right = right;
                }
            
        return ans;
    }
};