template <class T>
class BinaryTreeNode {
	T data;
public:
	BinaryTreeNode<T> *left;
	BinaryTreeNode<T> *right;
	BinaryTreeNode(T data) {
		this->data = data;
		left = NULL;
		right = NULL;
	}
};

void inorder(BinaryTreeNode<int> *root, 
			 BinaryTreeNode<int> *prev, 
			 BinaryTreeNode<int> *nroot) {
 
	if (!root) return;
	inorder(root->left, prev, nroot);
	if (prev == NULL) nroot = root;
	else {
		root->left = prev;
		prev->right = root;
	}

	prev = root;
	inorder(root->right, prev, nroot);
}

BinaryTreeNode<int> *BTtoDLL(BinaryTreeNode<int> *root) {
	BinaryTreeNode<int> *prev = NULL;
	BinaryTreeNode<int> *nroot = NULL;
	inorder(root, prev, nroot);
	return nroot;
}
