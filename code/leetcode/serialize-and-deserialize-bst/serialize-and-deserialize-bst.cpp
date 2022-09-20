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
    
    void encode(TreeNode* root, ostringstream &is) {
        if (!root) return;
        is << to_string(root->val) + " ";
        encode(root->left, is);
        encode(root->right, is);
    }
    
    TreeNode* decode(queue<int> &q, int min, int max) {
        if (q.empty() || q.front() <= min || q.front() >= max) return nullptr;
        auto val = q.front();
        q.pop();
        TreeNode* node = new TreeNode(val);
        node->left = decode(q, min, val);
        node->right = decode(q, val, max);
        return node;
    }
    
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream istream;
        encode(root, istream);
        return istream.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream istream(data);
        queue<int> q;
        string token;
        while(istream>>token) q.push(stoi(token));
        return decode(q, INT_MIN, INT_MAX);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;