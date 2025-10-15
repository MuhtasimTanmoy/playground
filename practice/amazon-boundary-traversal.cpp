class Solution {
  public:
    
    bool isLeaf(Node *node) {
        return node->left == nullptr && node->right == nullptr;
    }
    
    void collectLeft(Node* root, vector<int>& res) {
        
        if (root == nullptr || isLeaf(root))
            return;
    	
      	res.push_back(root->data);
        if (root->left) 
            collectLeft(root->left, res);
        
        else if (root->right)
            collectLeft(root->right, res);
    }
    

    void collectLeaves(Node *root, vector<int> &res) {
        if (root == nullptr)
            return;
    	
        if (isLeaf(root)) {
            res.push_back(root->data);
            return;
        }
    
        collectLeaves(root->left, res);
        collectLeaves(root->right, res);
    }
    
    
    void collectRight(Node* root, vector<int>& res) {
      	
        if (root == nullptr || isLeaf(root)) 
            return;
    
        if (root->right)
            collectRight(root->right, res);
    
        else if (root->left) 
            collectRight(root->left, res);
    	
    	res.push_back(root->data);  
    }
    
    vector<int> boundaryTraversal(Node *root) {
    	vector<int> res;
    
        if (!root)
            return res;
    
        if (!isLeaf(root))
            res.push_back(root->data);
    
        collectLeft(root->left, res);
    
        collectLeaves(root, res);
    
        collectRight(root->right, res);
    
        return res;
    }
};
