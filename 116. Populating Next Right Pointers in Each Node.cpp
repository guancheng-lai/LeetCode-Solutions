/*
// Definition for a Node.
class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node* next;

	Node() : val(0), left(NULL), right(NULL), next(NULL) {}

	Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

	Node(int _val, Node* _left, Node* _right, Node* _next)
		: val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
	void bfs(Node* leftNode, Node* rightNode) {
		if (leftNode == nullptr) return ;
		
		leftNode->next = rightNode;
		bfs(leftNode->left, leftNode->right);
		if (rightNode) {
			bfs(leftNode->right, rightNode->left);
		} else {
			bfs(leftNode->right, nullptr);
		}
	}
	
	Node* connect(Node* root) {
		if (root == nullptr) return nullptr;
		
		bfs(root->left, root->right);
		bfs(root->right, nullptr);
		
		return root;
	}
};