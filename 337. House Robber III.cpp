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
public:
	int _max(const pair<int,int> p) {
		return p.first > p.second ? p.first : p.second;
	}
	
	// <!rot,rob>
	pair<int,int> helper(TreeNode * root) {
		if (root == nullptr) return {0,0};
		
		auto left = helper(root->left);
		auto right = helper(root->right);
		
		//         not rob root        ,   rob root+not rob left+not rob right
		return { _max(left)+_max(right), root->val + left.first + right.first };
	}
	
	int rob(TreeNode * root) {
		if (root == nullptr) return 0;
		return _max( helper(root) );
	}
	
	
//     unordered_map<TreeNode*, int> memo;
//     int rob(TreeNode * root) {
//         if (root == nullptr) return 0;
//         if (memo.count(root)) return memo[root];
		
//         int rob2 = root->val;
//         if (root->left != nullptr) rob2 += rob(root->left->left) + rob(root->left->right);
//         if (root->right != nullptr) rob2 += rob(root->right->left) + rob(root->right->right);
		
//         int keep = rob(root->left) + rob(root->right);
		
//         int currResult = max(rob2, keep);
//         memo[root] = currResult;
		
//         return currResult;
//     }
};