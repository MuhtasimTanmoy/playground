/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "!|";
        string res = to_string(root->val) + "|";
        res += serialize(root->left);
        res += serialize(root->right);
        return res;
    }
    
    TreeNode* traverse(string& data, int& index) {
        if (index == data.size()) return NULL;
        
        string num = "";
        while (data[index] != '|') num += data[index++];
        if (num == "!") return NULL;
        
        TreeNode* root = new TreeNode(stoi(num));
        root->left = traverse(data, ++index);
        root->right = traverse(data, ++index);
        return root;
    }

    TreeNode* deserialize(string data) {
        int index = 0;
        return traverse(data, index);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));