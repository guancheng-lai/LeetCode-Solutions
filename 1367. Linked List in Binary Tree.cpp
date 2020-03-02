/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
	bool helper(ListNode* head, TreeNode* root) {
		if (root == nullptr && head != nullptr) return false;
		if (head == nullptr) return true;
		
		if (head->val == root->val) {
			return helper(head->next, root->left) || helper(head->next, root->right);
		}
		
		return false;
	}
	
	bool isSubPath(ListNode* head, TreeNode* root) {
		if (root == nullptr && head != nullptr) return false;
		if (head == nullptr) return true;
		
		bool tmp = false;
		if (head->val == root->val) {
			tmp = helper(head->next, root->left) || helper(head->next, root->right);
			if (tmp == true) return true;
		}
		
		return isSubPath(head, root->left) || isSubPath(head, root->right); 
	}
};





















