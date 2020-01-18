#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <list>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <limits>
#include <thread>
#include <mutex>
#include <fstream>
#include <memory>
using namespace std;

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

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
	vector<int> postorder(Node* root) {
		if (root == nullptr) { return vector<int>(); }
		if (root->children.size() == 0) { return vector<int>{ root->val }; }

		vector<int> result;
		stack< pair<Node *, int> > mainStk;
		stack<Node *> todoStk;

		mainStk.push( {root, (root->children).size()} );

		Node * rChild0 = root->children[0];
		mainStk.push( {rChild0, rChild0->children.size() } );
		for (int i = (root->children).size() - 1; i > 0; i--) {
			todoStk.push( (root->children)[i] );
		}

		while (!mainStk.empty() || !todoStk.empty()) {
			Node * curr;
			if (mainStk.top().second == 0) {
				result.push_back(mainStk.top().first->val);
				mainStk.pop();

				if (mainStk.empty()) break;

				(mainStk.top().second)--;
				if (mainStk.top().second == 0) {
					continue;
				}
				else {
					mainStk.push( {todoStk.top(), todoStk.top()->children.size()} );
					todoStk.pop();
					curr = mainStk.top().first;
				}
			}
			else {
				curr = mainStk.top().first;
			}
//            cout << curr->val << " ";

			if (curr->children.size() == 0) continue;

			mainStk.push( {(curr->children)[0],((curr->children)[0])->children.size() });

			for (int i = (curr->children).size() - 1; i > 0; i--) {
				todoStk.push((curr->children)[i]);
			}
		}

		return result;
	}
};

int main() {
	Node *n5 = new Node(5, vector<Node *>());
	Node *n6 = new Node(6, vector<Node *>());
	Node *n3 = new Node(3, vector<Node *>{n5, n6});
	Node *n2 = new Node(2, vector<Node *>());
	Node *n4 = new Node(4, vector<Node *>());
	Node *root = new Node(1, vector<Node *>{n3, n2, n4});

	Solution s;
	vector<int> result = s.postorder(root);
	for (auto &i : result) cout << i << " ";
}