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

// height calculate, sort, insert
class Solution {
public:
    
    vector<pair<int, int>> pairs;
    
    int getHeight(TreeNode *root) {
        
        // return -1 for null nodes
        if (!root) return -1;
        
        // first calculate the height of the left and right children
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        
        // based on the height of the left and right children, obtain the height of the current (parent) node
        int currHeight = max(leftHeight, rightHeight) + 1;
        
        // collect the pair -> (height, val)
        this->pairs.push_back({currHeight, root->val});
        
        // return the height of the current node
        return currHeight;
    }
    
    vector<vector<int>> findLeaves(TreeNode* root) {
        this->pairs.clear();
        
        getHeight(root);
        
        // sort all the (height, val) pairs
        sort(this->pairs.begin(), this->pairs.end());
        
        int n = this->pairs.size(), height = 0, i = 0;
        vector<vector<int>> solution;
        while (i < n) {
            vector<int> nums;
            while (i < n && this->pairs[i].first == height) {
                nums.push_back(this->pairs[i].second);
                i++;
            }
            solution.push_back(nums);
            height++;
        }
        return solution;
    }
};


// keeping only vector, without sort
class Solution {
private:
    vector<vector<int>> solution;
public:
    int getHeight(TreeNode *root) {
        // return -1 for null nodes
        if (!root) return -1;

        // first calculate the height of the left and right children
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        
        // based on the height of the left and right children, 
        // obtain the height of the current (parent) node
        int currHeight = max(leftHeight, rightHeight) + 1;
        
        // create space for node located at `currHeight` if not already exists
        if (this->solution.size() == currHeight) this->solution.push_back({});

        // insert the value at the correct position in the solution array
        this->solution[currHeight].push_back(root->val);
        
        // return the height of the current node
        return currHeight;
    }
    
    vector<vector<int>> findLeaves(TreeNode* root) {
        this->solution.clear();
        getHeight(root);
        return this->solution;
    }
};



// traverse, mark
class Solution {
    
    bool isLeaf(TreeNode* root) {
        if (!root->left && !root->right) return true;
        return false;
    }
    
    vector<vector<int>> extractedLeaves(TreeNode* root) {
        vector<vector<int>> result;
        while(root && !isLeaf(root)) {
            auto leaves = getLeaves(root);
            result.push_back(leaves);
        }
        if (root) result.push_back({root->val});
        return result;
    }
    
    vector<int> getLeaves(TreeNode* root) {
        vector<int> leaves;
        if (root) preorder(root, leaves);
        return leaves;
    }
    
    bool preorder(TreeNode* root, vector<int>& leaves) {
        
        if (!root->left && !root->right) {
            leaves.push_back(root->val);
            return true;
        }
        
        auto isLeftLeaf = root->left ? preorder(root->left, leaves) : true;
        auto isRightLeaf = root->right ? preorder(root->right, leaves) : true;
        
        if (isLeftLeaf) root->left = NULL;
        if (isRightLeaf) root->right = NULL;
        
        return false;
    }
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        return extractedLeaves(root);
    }
};