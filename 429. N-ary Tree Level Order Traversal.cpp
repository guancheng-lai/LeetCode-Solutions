// Definition for a Node.
class Node {
public:
	int val;
	vector<Node*> children;

	Node() {}
	
	Node(int _val, vector<Node*> _children) {
		val = _val;
		children = _children;
	}
};

class Solution {
public:
	vector<vector<int>> levelOrder(Node* root) {
		if(root == nullptr) { return vector<vector<int> >(); }
		
		vector<vector<int> > result;
		
		vector<Node *> currLevel{ root };
		vector<Node *> nextLevel;
		
		while (!currLevel.empty() || !nextLevel.empty()) {
			result.push_back(vector<int>());
			
			for (auto &node : currLevel) {
			    (result.back()).push_back(node->val);
			    nextLevel.insert(nextLevel.end(), (node->children).begin(), (node->children).end());
		    }
			
			currLevel = std::move(nextLevel);
			nextLevel.clear();
		}
		
		return result;

	}
};


int main(int argc, char *argv[]) {

}