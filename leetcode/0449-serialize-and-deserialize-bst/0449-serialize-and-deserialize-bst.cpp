class Codec {
    void encode(TreeNode* r, string &s) {
        if (!r) return;
        s += to_string(r->val) + " ",
        encode(r->left, s),
        encode(r->right, s);
    }
    
    TreeNode* decode(queue<int> &q, int min, int max) {
        if (q.empty()) return nullptr;
        auto is_in = q.front() > min && q.front() < max;
        if (!is_in) return nullptr;
        
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
        string s;
        encode(root, s);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        queue<int> q;
        string token;
        while (ss >> token) q.push(stoi(token));
        return decode(q, INT_MIN, INT_MAX);
    }
};