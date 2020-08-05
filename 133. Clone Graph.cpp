/*
// Definition for a Node.
class Node {
public:
	int val;
	vector<Node*> neighbors;
	
	Node() {
		val = 0;
		neighbors = vector<Node*>();
	}
	
	Node(int _val) {
		val = _val;
		neighbors = vector<Node*>();
	}
	
	Node(int _val, vector<Node*> _neighbors) {
		val = _val;
		neighbors = _neighbors;
	}
};
*/

class Solution {
private:
	unordered_map<Node*,Node*> m;
	
public:
	Node* cloneGraph(Node* node) {
		if (node == nullptr) return nullptr;
		
		if (m.find(node) == m.end()) {
			m[node] = new Node(node->val);
			for (Node * n : node->neighbors) {
				m[node]->neighbors.push_back( cloneGraph(n) );
			}
		}
		
		return m[node];
	}
};














