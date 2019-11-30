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

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:    
	// template <typename T>
	// void printStack(stack<T> s) {
	//     cout << "STACK: TOP-> ";
	//     while (!s.empty()) {
	//         cout << s.top()->val << " ";
	//     }
	//     cout << "-------------\n";  
	// }
public:
	vector<int> postorderTraversal(TreeNode* root) {
		if (root == nullptr)  {return vector<int>();}
		TreeNode * curr = root;
		unordered_set<TreeNode *> s;
		vector<int> result;
		stack<TreeNode *> stk;
		stk.push(curr);
		while (!stk.empty()) {
			curr = stk.top();

			bool left = curr->left != nullptr;
			bool right = curr->right != nullptr;

			if ( !left && !right ) {
				result.push_back(curr->val);
				s.insert(curr);
				stk.pop();
			}
			else if ( left && s.find(curr->left) != s.end() ){
				result.push_back(curr->val);
				s.insert(curr);
				stk.pop();
			}
			else if ( right && s.find(curr->right) != s.end() ) {
				result.push_back(curr->val);
				s.insert(curr);
				stk.pop();
			}
			else {
				if (right) {
					stk.push(curr->right);
				}

				if (left) {
					stk.push(curr->left);
				}
			}
		}

		return result;
	}
};

int main(int argc, char *argv[]) {
	TreeNode * r = new TreeNode (37);
	r->left = new TreeNode (-34);
	r->left->right = new TreeNode (-100);
		
	r->right = new TreeNode (-48);
	r->right->left = new TreeNode (-100);
	r->right->right = new TreeNode (48);
	r->right->right->left = new TreeNode (-54);
	r->right->right->left->left = new TreeNode (-54);
	r->right->right->left->right = new TreeNode (-54);
	r->right->right->left->right->right = new TreeNode (8);

	Solution solution;		
	cout << "post(it): "; vector<int> post = solution.postorderTraversal(r);
	for (auto i : post) { cout << i << " " ; } cout << endl;
}