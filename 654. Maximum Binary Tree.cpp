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
//     int getMaxValueIdx(const vector<int>& v, int start, int end) {
//         int currMax = v[start];
//         int currMaxIdx = start;
//         for (int i = start; i <= end; ++i) {                
//             if (v[i] > currMax) { 
//                 currMax = v[i];
//                 currMaxIdx = i;
//             }
//         }

//         return currMaxIdx;
//     };
	
//     TreeNode* construct(const vector<int>& nums, int i, int j) {
//         if (i > j)  return nullptr;
//         if (i == j) return new TreeNode(nums[i]);
//         int idx = getMaxValueIdx(nums, i , j);
		
//         TreeNode * result = new TreeNode( nums[idx]);
//         result->left = construct(nums, i, idx - 1);
//         result->right = construct(nums, idx + 1, j);
//         return result;
//     }
	
public:
	TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		if (nums.empty()) { return nullptr; }
		if (nums.size() == 1) return new TreeNode(nums[0]);
		
		// Divide and Conquer Approach
		// return construct(nums, 0, nums.size() - 1);
		
		// Mono Stack Approach
		stack<TreeNode *> stk;
		for (auto i : nums) {
			TreeNode * curr = new TreeNode(i);
			while (!stk.empty() && stk.top()->val < i) {
				curr->left = stk.top();
				stk.pop();
			}
			if (!stk.empty()) {
				stk.top()->right = curr;
			}
			stk.push(curr);
		}
		
		TreeNode * root = stk.top();
		while (!stk.empty()) {
			root = stk.top();
			stk.pop();
		}
		
		return root;
	}
};