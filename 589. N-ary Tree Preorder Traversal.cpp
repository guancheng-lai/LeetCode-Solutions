/*
// Definition for a Node.
class Node {
public:
	int val;
	vector<Node*> children;

	Node() {}

	Node(int _val) {
		val = _val;
	}

	Node(int _val, vector<Node*> _children) {
		val = _val;
		children = _children;
	}
};
*/

class Solution {
public:
	vector<int> preorder(Node* root) {
		if(root == nullptr) { return vector<int>(); }
		deque<Node *> q;
		q.push_back(root);
		
		vector<int> result;
		
		Node * curr;
		while (!q.empty()) {
			curr = q.front(); q.pop_front();
			result.push_back(curr->val);
			q.reserve(q.size() + (curr->children).size());
			for (auto rit = (curr->children).rbegin(); rit != (curr->children).rend(); rit++) {
				q.push_front(*rit);
			}
		}
		
		return result;
	}
};