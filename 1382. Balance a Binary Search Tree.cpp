/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
	vector<int> info;
	
	void getNodes(TreeNode * root) {
		if (root == nullptr) return;
		info.push_back(root->val);
		getNodes(root->left);
		getNodes(root->right);
	}
	
	TreeNode* construct(int start, int end) {
		if (info.empty() || (start > end)) return nullptr;
		if (start == end) {
			TreeNode * root = new TreeNode(info[start]);
			return root;
		}
		
		int mid = (start+end+1)/2;
		TreeNode * root = new TreeNode(info[mid]);
		root->left = construct(start, mid-1);
		root->right = construct(mid+1, end);
		return root;
	}
	
public:
	TreeNode* balanceBST(TreeNode* root) {
		if (root == nullptr) return nullptr;
		getNodes(root);
		sort(info.begin(), info.end());
		for (auto i : info) cout << i << " ";
		TreeNode * result = construct(0,info.size()-1);
		return result;
	}
};