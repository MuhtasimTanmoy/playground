class Solution {
    int preIndex = 0, posIndex = 0;
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        auto root = new TreeNode(pre[preIndex++]);
        if (root->val != post[posIndex])
            root->left = constructFromPrePost(pre, post);
        if (root->val != post[posIndex])
            root->right = constructFromPrePost(pre, post);
        posIndex++;
        return root;
    }
};